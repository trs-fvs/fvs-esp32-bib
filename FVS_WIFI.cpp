/***************************************************************************
* Ferdinand von Steinbeis-Schule Reutlingen
*
* W-LAN und mqtt Klassen Funktionen
*
* Autor: Tress
* Datum: 20.02.2025
*
* Bearbeitet: Tress
* Datum:
*
***************************************************************************/

#define  _FVS_WIFI_C

#include "FVS_WIFI.h"
#include "FVS_TFT.h"

fvs_wifi::fvs_wifi(char* ssid, char* pw, char* server, int port, char* user, char* key)
: fvsWifi_ssid(ssid),
  fvsWifi_pw(pw),
  mqtt_server(server),
  mqtt_port(port),
  mqtt_user(user),
  mqtt_pw(key)
{}

//Methoden Prototypen für Rückgabe der Werte

char* fvs_wifi::wlanSsid(void){return fvsWifi_ssid;}
char* fvs_wifi::wlanPw(void){return fvsWifi_pw;}
char* fvs_wifi::mqttServer(void){return mqtt_server;}
int fvs_wifi::mqttPort(void){return mqtt_port;}
char* fvs_wifi::mqttUser(void){return mqtt_user;};
char* fvs_wifi::mqttPw(void){return mqtt_pw;};

//Methoden WiFi

void fvs_wifi::wifiBegin(void) {

  //Alternativ kann für Tft. kann auch Serial. verwendet werden
  //Dazu muss dann Serial.begin(); im setup aufgerufen werden

  delay(10);
  // We start by connecting to a WiFi network
  Tft.setTextSize(2);  //Schriftgröße anpassen
  Tft.setCursorCharacter(1, 1);
  Tft.println();
  Tft.print("Connecting to ");
  Tft.println(fvsWifi_ssid);

  WiFi.begin(fvsWifi_ssid, fvsWifi_pw);  //W-Lan verbindung starten

  //warten bis W-Lan verbindung steht
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Tft.print(".");
  }

  Tft.println("");
  Tft.println("WiFi connected");
  Tft.println("IP address: ");
  Tft.println(WiFi.localIP());     //Ausgabe der IP-Adresse
  Tft.println(WiFi.macAddress());  //Ausgabe der MAC-Adresse
  delay(3000);
  Tft.fillScreen(TFT_BLACK);  //Display löschen
  Tft.setTextSize(4);  //Schriftgröße anpassen
}
