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

fvs_wifi::fvs_wifi(char* ssid, char* pw, char* server, int port)
  : fvsWifi_ssid(ssid),
    fvsWifi_pw(pw),
    mqtt_server(server),
    mqtt_port(port)
{

}

char* fvs_wifi::wlanSsid(void){ return fvsWifi_ssid;}
char* fvs_wifi::wlanPw(void){return fvsWifi_pw;}
char* fvs_wifi::mqttServer(void){return mqtt_server;}
int fvs_wifi::mqttPort(void){return mqtt_port;}