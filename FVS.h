//**************************************************************************
//Ferdinand von Steinbeis-Schule Reutlingen
//
//Klasse  - für TFT - Anzeige   (Grundeinstellungen)              03.05.2022
//Funktionen für Portsteuerung
//Autor:          Böhringer
//**************************************************************************
// 

// letzte Änderung:     08.01.2025
// Autor:         	Tress

#ifndef _FVS_H
#define _FVS_H

//#include <Arduino.h>
//#include <inttypes.h>
//#include "Print.h"
#include <TFT_eSPI.h>
#include "Wire.h"

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

//=============================================================================
// Definitionen von HAL Bibliothek Löhe

#define PORT0 0    // Zuweisung port
#define PORT1 1    // Zuweisung port
#define IN INPUT   // Zuweisung IN
#define OUT OUTPUT // Zuweisung OUT

#define A0 39  // GPIO39 ist A0 (Poti)
#define A1 40  // GPIO40 ist A1

hw_timer_t* timer1ms = NULL;

// Prototypen von HAL Bibliothek Löhe

//*********************** I/O Funktionen ***********************************

void delay_ms(uint16_t zeit);
void delay_100us(uint16_t zeit);
void bit_init(uint8_t port, uint8_t pin, uint8_t value);
void byte_init(uint8_t port, uint8_t value);
uint8_t bit_read(uint8_t port, uint8_t pin);
void bit_write(uint8_t lost, uint8_t pin, uint8_t value);
uint8_t byte_read(uint8_t port);
void byte_write(uint8_t port, uint8_t value);

//*********************** LCD Funktionen ***********************************

void lcd_init(void);
void lcd_clear(void);
void lcd_setcursor(uint8_t row, uint8_t column);
void lcd_char(char data);
void lcd_print(uint8_t text[]);
void lcd_byte(uint8_t data);
void lcd_int(uint16_t data);

//*********************** PWM Funktionen ***********************************

void pwm_init(void);
void pwm_start(void);
void pwm_stop(void);
void pwm_duty_cycle(uint8_t value);

//*********************** ADC Funktionen ***********************************

void adc_init(void);
uint8_t adc_in1(void);
uint8_t adc_in2(void);

//*********************** IR Funktionen ***********************************

void ext_interrupt_enable(void);
void ext_interrupt_disable(void);
void ext_interrupt1_enable(void);
void ext_interrupt1_disable(void);
void ext_interrupt_isr(void);
void ext_interrupt1_isr(void);
void ext_interrupt_init(void);
void ext_interrupt1_init(void);

//*********************** TIMER Funktionen ***********************************

void timer1ms_isr();
void timer1ms_enable(void);
void timer1ms_disable(void);
void timer1ms_init(void);

//*********************** I2C Funktionen ***********************************

void i2c_init(void);
void i2c_start(void);
void i2c_write(uint8_t value);
uint8_t i2c_read(uint8_t value);
void i2c_stop(void);

//*********************** RS232 Funktionen ***********************************