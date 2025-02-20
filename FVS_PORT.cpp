/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * Port-Funktionen
 * 
 * Autor: Böhringer
 * Datum: 03.05.2022
 * 
 * Bearbeitet: Tress
 * Datum: 20.02.2025
 * 
***************************************************************************/


#define  _FVS_PORT_C

#include "FVS_PORT.h"

//--- PORT-Steuerung ------

void portMode(uint8_t port, uint8_t mode)
{
  int i;
  fvs_p0[0] = FVS_S0;
  fvs_p0[1] = FVS_S1;
  fvs_p0[2] = FVS_S2;
  fvs_p0[3] = FVS_S3;
  fvs_p0[4] = FVS_S4;
  fvs_p0[5] = FVS_T0;
  fvs_p0[6] = FVS_T1;
  fvs_p0[7] = FVS_T2;
  fvs_p1[0] = FVS_LED0;
  fvs_p1[1] = FVS_LED1;
  fvs_p1[2] = FVS_LED2;
  fvs_p1[3] = FVS_LED3;
  fvs_p1[4] = FVS_LED4;
  fvs_p1[5] = FVS_LED5;
  fvs_p1[6] = FVS_LED6;
  fvs_p1[7] = FVS_LED7;
  
  if(mode == INPUT || mode == OUTPUT)
  {
    if (port == 0)
    {
      for(i=0; i<8 ; i++)
        pinMode(fvs_p0[i], mode);

      fvs_port0_mode = mode;
    }
    else if(port == 1)
    {
      for(i=0; i<8 ; i++)
        pinMode(fvs_p1[i], mode);

      fvs_port1_mode = mode;
    }
  }


}
void portWrite(uint8_t port,uint8_t value)
{
  int i;
  
  if (port == 0)
  {
    if(fvs_port0_mode == OUTPUT)
    {
      for(i=0; i<=7; i++)
      {
        digitalWrite(fvs_p0[i],bitRead(value,i));
      }
    }
  }
  else if (port == 1)
  {
    if(fvs_port1_mode == OUTPUT)
    {
      for(i=0; i<=7; i++)
      {
        digitalWrite(fvs_p1[i],bitRead(value,i));
      }
    }
  }
}
uint8_t portRead(uint8_t port)
{
  uint8_t value = 0;
  int i;
  
  if (port == 0)
  {
    if(fvs_port0_mode == INPUT)
    {
      for(i=0;i<8;i++)
        bitWrite(value,i,digitalRead(fvs_p0[i]));
    }
  }
  if (port == 1)
  {
    if(fvs_port1_mode == INPUT)
    {
      for(i=0;i<8;i++)
        bitWrite(value,i,digitalRead(fvs_p1[i]));
    }
  }

  return (value);
}