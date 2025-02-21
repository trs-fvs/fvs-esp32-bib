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

class fvs_wifi{
public:

char *fvsWifi_ssid;
char *fvsWifi_pw;
char *mqtt_server;
int mqtt_port;

fvs_wifi(char* ssid = "FVS-MPSK", char* pw = "iotatfvs", char* server = "10.190.2.13", int port = 1883); //Konstruktor mit Standard initialisierung
char* wlanSsid(void);
char* wlanPw(void);
char* mqttServer(void);
int mqttPort(void);

private:

};

WIFI_EXT fvs_wifi fvsWifi;

#endif