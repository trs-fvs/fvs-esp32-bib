/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * TFT Klasse, Prototypen und Definitionen
 * 
 * Autor: Böhringer
 * Datum: 03.05.2022
 * 
 * Bearbeitet: Tress
 * Datum: 20.02.2025
 * 
***************************************************************************/

#ifndef _FVS_TFT_H
#define _FVS_TFT_H

#include "TFT_eSPI.h"

#ifdef  _FVS_TFT_C
  #define TFT_EXT
#else
  #define TFT_EXT extern
#endif

//------- DISPLAY -------------
//------- Defines -------------


#define FVS_FONT_SIZE 3 //Standardschriftgröße
#define FVS_OFFSTET 0   //Offset vom oberen, linken Rank

//-------- Klassen erstellen --------

class Fvs_tft : public TFT_eSPI
{ 
  private:
   
  public:

    void begin(void);   
    void setCursorCharacter(uint8_t row, uint8_t column);
    void clearDisplay(void);
};


//globale Objekte erzeugen
TFT_EXT Fvs_tft Tft;

#endif