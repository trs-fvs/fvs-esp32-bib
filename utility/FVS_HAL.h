/***************************************************************************
 * Ferdinand von Steinbeis-Schule Reutlingen
 * 
 * Prototypen und Definitionen für Elektroniker Geräte und Systeme
 * 
 * Autor: Löhe
 * Datum: 
 * 
 * Bearbeitet: Tress
 * Datum: 20.02.2025
 * 
***************************************************************************/

#ifndef _FVS_HAL_H
#define _FVS_HAL_H

//===========================================================================
// Definitionen von HAL Bibliothek Löhe

#define PORT0 0    // Zuweisung port
#define PORT1 1    // Zuweisung port
#define IN INPUT   // Zuweisung IN
#define OUT OUTPUT // Zuweisung OUT

#define A0 39  // GPIO39 ist A0 (Poti)
#define A1 40  // GPIO40 ist A1

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
