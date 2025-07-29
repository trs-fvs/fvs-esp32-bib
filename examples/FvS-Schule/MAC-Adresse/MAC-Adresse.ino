/*********************************************************
Anzeigen der MAC-Adressen vom Schul uController

Tress Constantin 29. Jul 2025
*********************************************************/

#include <FVS.h>
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_log.h"

//variable to store mac-adress
uint8_t mac[6];

void setup() {
  Tft.begin();
  Tft.setTextSize(2);

  //LEDs deaktivieren
  portMode(1, OUTPUT);
  portWrite(1, 0);

  // Get the base MAC of the ESP chip (works always)
  Network.macAddress(mac);
  Tft.printf("MAC-Adresse:\n%02X:%02X:%02X:%02X:%02X:%02X\n",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  /*
  // Get the MAC address of WiFi STA (must first start interface)
  WiFi.STA.begin();
  WiFi.STA.macAddress(mac);
  Tft.printf("MAC-Adresse:\n%02X:%02X:%02X:%02X:%02X:%02X\n",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  // Get the MAC address of WiFi AP (must first start interface)
  WiFi.AP.begin();
  WiFi.AP.macAddress(mac);
  Tft.printf("MAC-Adresse:\n%02X:%02X:%02X:%02X:%02X:%02X\n",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  // Get the MAC address of ETH (must first start interface)
  ETH.begin();
  ETH.macAddress(mac);
  Tft.printf("MAC-Adresse:\n%02X:%02X:%02X:%02X:%02X:%02X\n",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
*/
}

void loop() {
  // put your main code here, to run repeatedly:
}
