#include <FVS.h>

void setup() {
  Tft.begin();
  fvsWifi.wifiBegin();
}

void loop() {
  //überprüfung ob W-Lan Verbindung noch aktiv ist, ansonsten erneut verbinden
  if ((WiFi.status() != WL_CONNECTED)) {
    delay(500);
    WiFi.reconnect();
  }
}