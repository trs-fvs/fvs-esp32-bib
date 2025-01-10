# Ferdinand-von-Steinbeis Schule Reutlingen
Bibliothek für den Microcontroller mit einem ESP32

## Inhaltsverzeichnis:

<!-- toc -->

- [WICHTIGE Hinweise](#wichtige-hinweise)
- [FVS Bibliothek](#fvs-bibliothek)
  - [Objekt für das Display](#objekt-für-das-display)
  - [Funktionen](#funktionen)
- [HAL Bibliothek für Elektroniker für GS](#hal-bibliothek-für-elektroniker-für-gs)
  - [Konstanten](#konstanten)
  - [I/O Funktionen](#i-o-funktionen)
  - [Display Funktionen](#display-funktionen)
  - [PWM Funktionen](#pwm-funktionen)
  - [ADC Funktionen](#adc-funktionen)
  - [Interrupt Funktionen](#interrupt-funktionen)
  - [Timer Funktionen](#timer-funktionen)
  - [I2C Funktionen](#i2c-funktionen)
- [Haftungsausschluss](#haftungsausschluss)

<!-- tocstop -->


## WICHTIGE Hinweise
Es muss das Board-Package esp32 von Espressif in der Version 2.0.17 installiert sein.
Es darf keine neue Version des Board-Package installiert sein, sonst funktionieren einige Funktionen/Methoden nicht mehr.

## FVS Bibliothek

Die Bibliothek besitzt unter anderem folgende Funktionen/Objekt:

### Objekt für das Display
Tft.

### Funktionen

- portMode für die Modiwahl eines Portes
  - portMode

- portWrite für das schreiben auf einen Port
  - portWrite

- portRead für das einlesen eines Ports
  - portRead

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





#### Haftungsausschluss
Ich übernehme keine Verantwortung oder Haftung für mögliche Fehler, Auslassungen öder Rechtsverletzungen in den bereitgestellten Inhalten.
