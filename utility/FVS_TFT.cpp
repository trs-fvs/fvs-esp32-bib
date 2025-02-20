/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * TFT Funktionen
 * 
 * Autor: Böhringer
 * Datum: 03.05.2022
 * 
 * Bearbeitet: Tress
 * Datum: 20.02.2025
 * 
***************************************************************************/

#define  _FVS_TFT_C

#include "FVS_TFT.h"

//------------Display initialisieren---------------------------
void Fvs_tft :: begin(void)
{
  init();
  setRotation(3);
  fillScreen(TFT_BLACK);  
  setTextColor(TFT_WHITE,TFT_BLACK); 
  setTextSize(FVS_FONT_SIZE);
  
}

void Fvs_tft :: setCursorCharacter(uint8_t row, uint8_t column)
{
  int x1;
  int y1;

  x1 = (column-1) * FVS_FONT_SIZE*6 + FVS_OFFSTET;
  y1 = (row-1) * FVS_FONT_SIZE*8 + FVS_OFFSTET;

  TFT_eSPI::setCursor(x1,y1);

}

void Fvs_tft :: clearDisplay(void)
{
  TFT_eSPI::fillScreen(this->textbgcolor);
}