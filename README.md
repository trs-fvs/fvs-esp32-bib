# Ferdinand-von-Steinbeis Schule Reutlingen
## Bibliothek für den Microcontroller mit einem ESP32


**WICHTIG:**
Es muss das Board-Package esp32 von Espressif in der Version 2.0.17 installiert sein.
Es darf keine neue Version des Board-Package installiert sein, sonst funktionieren einige Funktionen/Methoden nicht mehr.

Die Bibliothek besitzt unter anderem folgende Funktionen/Objekt:

### Objekt für das Display:
Tft.

### Funktionen:

- portMode für die Modiwahl eines Portes
void portMode(uint8_t port, uint8_t mode);  //(1 oder 0, INPUT/OUTPUT)

- portWrite für das schreiben auf einen Port
void portWrite(uint8_t port,uint8_t value);

- portRead für das einlesen eines Ports
uint8_t portRead(uint8_t port);



integrierte Bibliotheken:
https://github.com/Bodmer/TFT_eSPI/tree/V2.5.43
Diese Bibliothek ist aufgrund von Speicherplatz Einsparung stark reduziert.

HAL- Bibliothek für Elektroniker für GS












Ich übernehme keine Haftung für die Bibliothek oder deren Inhalt.