/*********************************************************
W-Lan und mqtt verbindung zum Schulnetz IoT

Abfrage und Senden von Daten zum mqtt Broker

Tress Constantin 20. Feb 2025
*********************************************************/

#include "FVS.h"
#include "WiFi.h"
#include "PubSubClient.h"
#include "Temperature_LM75_Derived.h"
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

#define LEDs 1

const char *fvsWifi_ssid = "FVS-MPSK";
const char *fvsWifi_pw = "iotatfvs";
const char *mqtt_server = "mqtt01.pn.steinbeis.schule"; // nur innerhalb des Schulnetzes
const char *topic_sub = "A134/esp32/leds";
const char *topic_pub = "A134/esp32/temperature";
const int mqtt_port = 1883;

long lastMsg = 0;  //Variable für Zeitabfrage, um Daten zu senden

//Objekte erzeugen
WiFiClient espClient;            //W-LAN client Objekt
PubSubClient client(espClient);  //mqtt verbindung über W-Lan
Generic_LM75 tempSensor;         //Objekt für eingebauten Temperatursensor erzeugen

void setup() {
  portMode(LEDs, OUTPUT);  //alle LEDs als Output definieren

  Wire.begin();  //Verbindung zu Temperatursensor aufbauen

  Tft.begin();         //TFT initialisieren
  Tft.setTextSize(2);  //Schriftgröße anpassen

  setup_wifi();   //W-Lan initialisieren
  Tft.println();  //Leerzeile

  client.setServer(mqtt_server, mqtt_port);  //Verbindung zum MQTT-Server aufbauen
  client.setCallback(callback);              //Wenn neue Daten im Sub topic sind, dann Funktion callback aufrufen

  if (!client.connected()) {
    reconnect();
  }

  delay(2000);
  Tft.fillScreen(TFT_BLACK);
}

void loop() {
  //überprüfung ob mqtt Verbindung noch steht
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //Warten mit Datensenden, jede Sekunde. Kein Delay, da sonst der Empfang und die Abfrage nicht mehr vernünftig Funktioniert
  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;

    float temperature = tempSensor.readTemperatureC();  //Temperatur vom Sensor einlesen

    Tft.setCursor(0, 0);
    Tft.println("Temperatur: " + String(temperature));

    char tempString[8];  // umwandlung der Temperatur von float nach String
    dtostrf(temperature, 1, 2, tempString);
    client.publish(topic_pub, tempString);//Versenden der Daten
  }
}
