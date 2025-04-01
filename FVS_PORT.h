/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * Port Prototypen und Definitionen
 * 
 * Autor: Böhringer
 * Datum: 03.05.2022
 * 
 * Bearbeitet: Tress
 * Datum: 20.02.2025
 * 
***************************************************************************/

#ifndef _FVS_PORT_H
#define _FVS_PORT_H

#ifdef  _FVS_PORT_C
  #define PORT_EXT
#else
  #define PORT_EXT extern
#endif

#include <Arduino.h>

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
PORT_EXT uint8_t fvs_port0_mode;
PORT_EXT uint8_t fvs_port1_mode;

PORT_EXT uint8_t fvs_p0[8] ;//= {FVS_S0,FVS_S1,FVS_S2,FVS_S3,FVS_S4,FVS_T0,FVS_T1,FVS_T2};
PORT_EXT uint8_t fvs_p1[8] ;//= {FVS_LED0,FVS_LED1,FVS_LED2,FVS_LED3,FVS_LED4,FVS_LED5,FVS_LED6,FVS_LED7};

#endif