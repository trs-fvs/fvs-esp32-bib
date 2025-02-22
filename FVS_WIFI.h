/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * W-LAN und mqtt Klassen und Definitionen
 * 
 * Autor: Tress
 * Datum: 20.02.2025
 * 
 * Bearbeitet: Tress
 * Datum:
 * 
 * Standartdefinition für Verbindung in der Schule:
 * W-Lan SSID: FVS-MPSK
 * Password: iotatfvs
 * mqtt-Server: 10.190.2.13 oder mqtt01.pn.steinbeis.schule, nur innerhalb des Schulnetztes erreichbar
 * mqtt-Port: 1883
 * 
***************************************************************************/

#ifndef _FVS_WIFI_H
#define _FVS_WIFI_H

#ifdef  _FVS_WIFI_C
  #define WIFI_EXT
#else
  #define WIFI_EXT extern
#endif

#include <WiFi.h>
//#include <PubSubClient.h> //Bibliothek für mqtt Verbindung
//#include <ArduinoJson.h> //Bibliothek für JSON Formatierung
//#include <ArduinoJson.hpp> //Bibliothek für JSON Formatierung

#define WIFI_SSID "FVS-MPSK"
#define WIFI_PW "iotatfvs"
#define MQTT_SERVER "10.190.2.13"
#define MQTT_PORT 1883
#define MQTT_USER ""
#define MQTT_KEY ""

class fvs_wifi{
public:

//Variablen
char *fvsWifi_ssid;
char *fvsWifi_pw;
char *mqtt_server;
int mqtt_port;
char* mqtt_user;
char* mqtt_pw;

//Konstruktor mit Standardwerte
fvs_wifi(char* ssid = WIFI_SSID, char* pw = WIFI_PW, char* server = MQTT_SERVER, int port = MQTT_PORT, char* user = MQTT_USER, char* key = MQTT_KEY); //Konstruktor mit Standard initialisierung

//Methoden Prototypen für Rückgabe der Werte
char* wlanSsid(void);
char* wlanPw(void);
char* mqttServer(void);
int mqttPort(void);
char* mqttUser(void);
char* mqttPw(void);

private:

};

WIFI_EXT fvs_wifi fvsWifi;

#endif