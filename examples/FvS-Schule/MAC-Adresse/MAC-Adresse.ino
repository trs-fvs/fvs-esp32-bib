#include <FVS.h>
//#include <WiFi.h>

void setup() {
  Tft.begin();
  Tft.setTextSize(2);

  //LEDs deaktivieren
  portMode(1, OUTPUT);
  portWrite(1, 0);

  // Variable to store the MAC address
  uint8_t baseMac[6];

  // Get MAC address of the WiFi station interface
  esp_read_mac(baseMac, ESP_MAC_WIFI_STA);
  Tft.println("Station MAC: ");
  for (int i = 0; i < 5; i++) {
    Tft.printf("%02X:", baseMac[i]);
  }
  Tft.printf("%02X\n", baseMac[5]);

  // Get the MAC address of the Wi-Fi AP interface
  esp_read_mac(baseMac, ESP_MAC_WIFI_SOFTAP);
  Tft.println("SoftAP MAC: ");
  for (int i = 0; i < 5; i++) {
    Tft.printf("%02X:", baseMac[i]);
  }
  Tft.printf("%02X\n", baseMac[5]);

  // Get the MAC address of the Bluetooth interface
  esp_read_mac(baseMac, ESP_MAC_BT);
  Tft.println("Bluetooth MAC: ");
  for (int i = 0; i < 5; i++) {
    Tft.printf("%02X:", baseMac[i]);
  }
  Tft.printf("%02X\n", baseMac[5]);

  // Get the MAC address of the Ethernet interface
  esp_read_mac(baseMac, ESP_MAC_ETH);
  Tft.println("Ethernet MAC: ");
  for (int i = 0; i < 5; i++) {
    Tft.printf("%02X:", baseMac[i]);
  }
  Tft.printf("%02X\n", baseMac[5]);
}

void loop() {
  // put your main code here, to run repeatedly:
}
