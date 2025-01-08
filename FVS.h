//**************************************************************************
//Ferdinand von Steinbeis-Schule Reutlingen
//
//Klasse  - für TFT - Anzeige   (Grundeinstellungen)              03.05.2022
//Funktionen für Portsteuerung
//Autor:          Böhringer
//**************************************************************************
// 

// letzte Änderung:     08.01.2025
// Autor:         Böhringer/Tress

#ifndef _FVS_H
#define _FVS_H

//#include <Arduino.h>
//#include <inttypes.h>
//#include "Print.h"
#include <TFT_eSPI.h>
#include <HAL.h>	//Bib von Löhe für Elektroniker GS

#ifdef  _FVS_C
  #define TFT_EXT
#else
  #define TFT_EXT extern
#endif

//------- DISPLAY -------------
//------- Defines -------------


#define FVS_FONT_SIZE 3 //Standardschriftgröße
#define FVS_OFFSTET 0   //Offset vom oberen, linken Rank

class Fvs_tft : public TFT_eSPI
{ 
  private:
   
  public:

    void begin(void);   
    void setCursorCharacter(uint8_t row, uint8_t column);
    void clearDisplay(void);
};

//globales Objekt erzeugen
TFT_EXT Fvs_tft Tft;



//--------- PORT-Zugriff ---------
#define FVS_LED0 1
#define FVS_LED1 2
#define FVS_LED2 3
#define FVS_LED3 4
#define FVS_LED4 5
#define FVS_LED5 14
#define FVS_LED6 15
#define FVS_LED7 16
#define FVS_S0  25
#define FVS_S1  26
#define FVS_S2  27
#define FVS_S3  32
#define FVS_S4  33
#define FVS_T0  34
#define FVS_T1  35
#define FVS_T2  36

//--- Funktionen
void portMode(uint8_t port, uint8_t mode);  //(1 oder 0, INPUT/OUTPUT)
void portWrite(uint8_t port,uint8_t value);
uint8_t portRead(uint8_t port);

//--- globale Variablen
TFT_EXT uint8_t fvs_port0_mode;
TFT_EXT uint8_t fvs_port1_mode;

TFT_EXT uint8_t fvs_p0[8] ;//= {FVS_S0,FVS_S1,FVS_S2,FVS_S3,FVS_S4,FVS_T0,FVS_T1,FVS_T2};
TFT_EXT uint8_t fvs_p1[8] ;//= {FVS_LED0,FVS_LED1,FVS_LED2,FVS_LED3,FVS_LED4,FVS_LED5,FVS_LED6,FVS_LED7};
#endif
