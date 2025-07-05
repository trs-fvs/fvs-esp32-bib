s# Ferdinand-von-Steinbeis Schule Reutlingen
Bibliothek für den Microcontroller mit einem ESP32

## Inhaltsverzeichnis:

<!-- toc -->

- [WICHTIGE Hinweise](#hinweise)
- [Beispielprogramme](#beispielprogramme)
- [FVS Bibliothek](#fvs-bibliothek)
  - [Objekt für das Display](#objekt-für-das-display)
  - [Funktionen](#funktionen)
- [Bibliothek für Elektroniker für GS](#bibliothek-für-elektroniker-für-gs)
  - [Konstanten](#konstanten)
  - [I/O Funktionen](#i-o-funktionen)
  - [Display Funktionen](#display-funktionen)
  - [PWM Funktionen](#pwm-funktionen)
  - [ADC Funktionen](#adc-funktionen)
  - [Interrupt Funktionen](#interrupt-funktionen)
  - [Timer Funktionen](#timer-funktionen)
  - [I2C Funktionen](#i2c-funktionen)
- [Status Arduino](#status-arduino)
- [Haftungsausschluss](#haftungsausschluss)

<!-- tocstop -->


## Hinweise
> [!CAUTION]
> Ab Release 4.x muss Board-Package esp32 von Espressif in der Version 3.2.x installiert sein.
> Es darf keine neue Version des Board-Package installiert sein, sonst funktionieren einige Funktionen/Methoden nicht mehr.

Nur die Releases verwenden, welche auch auf GitHub vorhanden sind:\
1.0.0 -> ursprüngliche FVS-Bibliothek ohne TFT_eSPI\
1.0.2 -> ursprüngliche FVS-Bibliothek ohne TFT_eSPI Beschreibung angepasst\
1.1.0 -> ursprüngliche FVS-Bibliothek mit TFT_eSPI V2.5.43\
1.2.0 -> gelöscht\
1.2.1 -> gelöscht

2.0.0 -> gelöscht\
2.0.1 -> FVS-Bibliothek mit TFT_eSPI und Funktionen für Elektroniker GS\
3.0.0 -> Bibliotheken getrennt für bessere Übersicht, W-Lan Bibliothek und Beispiele hinzugefügt\
3.0.1 -> Beispielprogramme für TFT-Display hinzugefügt\
4.0.0 -> neue Boardversion 3.2.X wird unterstützt, 2.X.X wird nicht mehr unterstützt\
4.0.1 -> Umzug auf neue Adresse

Mehr Infos bei den Releases.

## Beispielprogeamme
- MAC-Adresse
  - Auslesen und Anzeigen der MAC-Adressen des esp32
- mqtt
  - Beispielprogramm für mqtt Verbindung über W-LAN
- Testprogramm_4.0
  - Hardware Test

## FVS Bibliothek

Die Bibliothek besitzt unter anderem folgende Funktionen/Objekte:

### Objekte
- TFT-Display
  - `Tft`
- W-Lan Konfiguration
  - `FvsWifi`

### Funktionen

- portMode für die Modiwahl eines Portes
  - `portMode`

- portWrite für das schreiben auf einen Port
  - `portWrite`

- portRead für das einlesen eines Ports
  - `portRead`

### Methoden der Klasse `fvs_wifi`

- W-Lan Name (SSID)
  - `wlanSsid`

- W-Lan Passwort
  - `wlanPw`

- mqtt Server
  - `mqttServer`

- mqtt Port
  - `mqttPort`

- mqtt Benutzer
  - `mqttUser`

- mqtt Passwort
  - `mqttPw`

integrierte Bibliotheken:
https://github.com/Bodmer/TFT_eSPI/tree/V2.5.43
Diese Bibliothek ist aufgrund von Speicherplatz Einsparung stark reduziert.

## Bibliothek für Elektroniker für GS
unter Vorlage der FVS-Bibliothek.

## Status Arduino
Infos über den aktuellen [Status](https://downloads.arduino.cc/libraries/logs/github.com/trs-fvs/fvs-esp32-bib/).


#### Haftungsausschluss
Wir übernehmen keine Verantwortung oder Haftung für mögliche Fehler, Auslassungen oder Rechtsverletzungen in den bereitgestellten Inhalten.
