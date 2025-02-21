void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
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
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Tft.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Tft.println("connected");
      // Subscribe
      client.subscribe(topic_sub);
    } else {
      Tft.print("failed, rc=");
      Tft.print(client.state());
      Tft.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char *topic, byte *message, unsigned int length) {
  Tft.fillScreen(TFT_BLACK);
  Tft.setCursor(0, 0);
  Tft.print("Message arrived on topic: ");
  Tft.print(topic);
  Tft.print(". Message: ");
  String messageTempString;  //Deklaration eines Strings für Empfang von Daten

  //Daten als einzelne Zeichen in String einfügen
  for (int i = 0; i < length; i++) {
    Tft.print((char)message[i]);
    messageTempString += (char)message[i];
  }

  //Abfrage was gemacht werden soll, Daten und topic übereinstimmem
  if (String(topic) == topic_sub) {
    uint8_t messageTemp = atoi(messageTempString.substring(1, 3).c_str());  //LEDs anhand von empfangenen Daten leuchten lassen
    portWrite(LEDs, messageTemp);
  }
}