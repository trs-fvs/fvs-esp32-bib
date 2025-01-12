// einbinden der FVS Bibliothek
#include <FVS.h>

// Definition der Pins zu den LEDs -> Port1
#define LED0  1
#define LED1  2
#define LED2  3
#define LED3  4
#define LED4  5
#define LED5  14
#define LED6  15
#define LED7  16

// Definition der Pins zu den Eingängen -> Port0
#define S0  25
#define S1  26
#define S2  27
#define S3  32
#define S4  33
#define T0  34
#define T1  35
#define T2  36
#define POTI 39


Generic_LM75 Temperature;
// Array für Ein/-Ausgänge
unsigned char leds[8]={LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
unsigned char schalter[8]={S0,S1,S2,S3,S4,T0,T1,T2};


void setup() {
  int i;
  uint16_t calData[5];
  //initialisierung des Displays -> Tft.begin
  //Objekt wird in FVS-Bibliothe erstellt
  Tft.init();
   Tft.setRotation(3);
  Tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
  Tft.setTouch(calData);
  Tft.fillScreen(TFT_WHITE);  
  Tft.setTextColor(TFT_BLUE,TFT_WHITE); 
  Tft.setTextSize(2);
 
  //Mode für Ein/-Ausgänge festlegen
  for(i=0; i<8; i++)
  { 
    pinMode(leds[i],OUTPUT);
    pinMode(schalter[i],INPUT);
  }
  Tft.fillRoundRect(46, 176, 100, 40, 10, TFT_DARKGREY);
  Wire.begin(); //I2C-Bus für LM75
}

void loop() {
  int i;
  uint16_t x, y;

  // See if there's any touch data for us
  //Eingabeprüfung Touch
  if (Tft.getTouch(&x, &y))
  {
    //y=239-y;
    //+x=319-x;
    if(x>46 && x<146)
    { 
        if(y >176 && y <216)
        { 
          Tft.fillRoundRect(46, 176, 100, 40, 10, TFT_GREEN);
          delay(2000);
          Tft.fillRoundRect(46, 176, 100, 40, 10, TFT_DARKGREY);
        }
    }
  }
  
  //Ausgabe auf dem Display
  Tft.setTextColor(TFT_GREEN,TFT_WHITE);
  Tft.drawCentreString("Testprogramm",160,0,2);
  Tft.setCursor(0, 40, 2);
  Tft.setTextColor(TFT_BLUE,TFT_WHITE);
  //Ausgabe Analogwert
  Tft.println("AD-Wert: " + (String)analogRead(POTI)+"   ");
  Tft.println("Spannung: " + (String)(analogRead(POTI)*3.3/4095) + "V  ");
  //Ausgabe Zustände der Schalter
  for(i=0; i<8; i++)
  { 
   digitalWrite(leds[i],digitalRead(schalter[i]));
  }
  //Ausgabe Temperatur
  Tft.setTextColor(TFT_RED,TFT_WHITE); 
  Tft.print("Temperatur: ");
  Tft.print(Temperature.readTemperatureC());
  Tft.println(" C  ");
 
  }
