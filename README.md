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
> Es muss das Board-Package esp32 von Espressif in der Version 2.0.17 installiert sein.
> Es darf keine neue Version des Board-Package installiert sein, sonst funktionieren einige Funktionen/Methoden nicht mehr. Insbesondere die Timer.

>[!IMPORTANT]
>Die Bibliothek benötigt für den Temperatursensor zwingend die Bibliothek `I2C Temperature Sensors derived from the LM75`.

Nur die Releases verwenden, welche auch auf GitHub vorhanden sind:\
1.0.0 -> ursprüngliche FVS-Bibliothek ohne TFT_eSPI\
1.0.2 -> ursprüngliche FVS-Bibliothek ohne TFT_eSPI Beschreibung angepasst\
1.1.0 -> ursprüngliche FVS-Bibliothek mit TFT_eSPI\
1.2.0 -> gelöscht\
1.2.1 -> gelöscht\
2.0.0 -> gelöscht\
2.0.1 -> FVS-Bibliothek mit TFT_eSPI und Funktionen für Elektroniker GS\
3.0.0 -> Bibliotheken getrennt für bessere Übersicht, W-Lan Bibliothek und Beispiele hinzugefügt
\
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

### Konstanten

- PORT0
- PORT1		
- IN		
- OUT		
- A0		
- A1		

### Methoden und Funktionen
#### I-O Funktionen
- delay_ms
- delay_100us
- bit_init
- byte_init
- bit_read
- bit_write
- byte_read
- byte_write

#### Display Funktionen
- lcd_init
- lcd_clear
- lcd_setcursor
- lcd_char
- lcd_print
- lcd_byte
- lcd_int

#### PWM Funktionen
- pwm_init
- pwm_start
- pwm_stop
- pwm_duty_cycle

#### ADC Funktionen
- adc_init
- adc_in1		
- adc_in2		

#### Interrupt Funktionen
- ext_interrupt_enable
- ext_interrupt_disable
- ext_interrupt1_enable
- ext_interrupt1_disable
- ext_interrupt_isr
- ext_interrupt1_isr
- ext_interrupt_init
- ext_interrupt1_init

#### Timer Funktionen
- timer1ms_isr		
- timer1ms_enable		
- timer1ms_disable
- timer1ms_init		

#### I2C Funktionen
- i2c_init
- i2c_start
- i2c_write
- i2c_read
- i2c_stop


## Status Arduino
Infos über den aktuellen [Status](https://downloads.arduino.cc/libraries/logs/github.com/FoltaBozZ/fvs-esp32-bib/).


#### Haftungsausschluss
Ich übernehme keine Verantwortung oder Haftung für mögliche Fehler, Auslassungen öder Rechtsverletzungen in den bereitgestellten Inhalten.
