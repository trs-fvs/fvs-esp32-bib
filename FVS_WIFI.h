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
***************************************************************************/

#ifndef _FVS_WIFI_H
#define _FVS_WIFI_H

#ifdef  _FVS_WIFI_C
  #define WIFI_EXT
#else
  #define WIFI_EXT extern
#endif

#include "WiFi.h"
//#include "PubSubClient.h" //Bibliothek für mqtt Verbindung
//#include "ArduinoJson.h" //Bibliothek für JSON Formatierung
//#include "ArduinoJson.hpp" //Bibliothek für JSON Formatierung

/*
const char *fvsWifi_ssid = "MPSK";
const char *fvsWifi_pw = "iotatfvs";
const char *mqtt_server = "10.190.2.13";
const char *topic_sub = "A134/esp32/leds";
const char *topic_pub = "A134/esp32/temperature";
const int mqtt_port = 1883;
*/

#endif