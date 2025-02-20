//**************************************************************************
//Ferdinand von Steinbeis-Schule Reutlingen
//
//C++ - Funktionen - für TFT - Anzeige                           03.05.2022
//Autor:          Böhringer
//**************************************************************************
// 
// letzte Änderung:     08.01.2025
// Autor:         Tress

#define  _FVS_C

#include "FVS.h"

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


//--- PORT-Steuerung ------------------------------------------

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

//======================================================================
//Funktionen aus HAL-Bibliothek Löhe

//*********************** I/O Funktionen ***********************************

hw_timer_t* timer1ms = NULL;

void delay_ms(uint16_t zeit)
{
  delay(zeit);
}

void delay_100us(uint16_t zeit)
{
  delay(zeit/10);
}

void bit_init(uint8_t port, uint8_t pin, uint8_t value)
{
if (port == 0)
  {
  if(pin>=0 && pin<=2)
    {pin = pin+25;}
  else if(pin>=3 && pin<=7)
    {pin = pin+29;}
  pinMode(pin, INPUT);
  }
else if (port == 1)
  {
  if(pin>=0 && pin<=4)
    {pin = pin+1;}
  else if(pin>=5 && pin<=7)
    {pin = pin+9;}
  pinMode(pin, OUTPUT);
  }
}

void byte_init(uint8_t port, uint8_t value)
{
uint8_t i;
  if (port == 0)
  {
    for ( i=25; i<=27 ; i++ )
      {pinMode(i,INPUT);}
    for ( i=32; i<=36 ; i++ )
      {pinMode(i,INPUT);}
  }
  else if (port == 1)
  {
    for ( i=1; i<=5 ; i++ )
      {pinMode(i,OUTPUT);}
    for ( i=14; i<=16 ; i++ )
      {pinMode(i,OUTPUT);}
  }
}

uint8_t bit_read(uint8_t port, uint8_t pin)
{
    uint8_t wert;
    if(pin>=0 && pin<=2)
      {wert = digitalRead(pin+25);}
    else if(pin>=3 && pin<=4)
      {wert = digitalRead(pin+29);}
    else if(pin>=5 && pin<=7)
      {wert = !digitalRead(pin+29);}
    return wert;
}

void bit_write(uint8_t lost, uint8_t pin, uint8_t value)
{
    if(pin>=0 && pin<=4)
        pin = pin+1;
    else if(pin>=5 && pin<=7)
        pin = pin+9;
    digitalWrite(pin,value);
}

uint8_t byte_read(uint8_t port)
{
    uint8_t wert=0;
    wert = digitalRead(25);
    wert = wert + 2*digitalRead(26);
    wert = wert + 4*digitalRead(27);
    wert = wert + 8*digitalRead(32);
    wert = wert + 16*digitalRead(33);
    wert = wert + 32*!digitalRead(34);
    wert = wert + 64*!digitalRead(35);
    wert = wert + 128*!digitalRead(36);
    return wert;
}

void byte_write(uint8_t port, uint8_t value)
{
    bit_write(port, 0,   1&value);
    bit_write(port, 1,   2&value);
    bit_write(port, 2,   4&value);
    bit_write(port, 3,   8&value);
    bit_write(port, 4,  16&value);
    bit_write(port, 5,  32&value);
    bit_write(port, 6,  64&value);
    bit_write(port, 7, 128&value);
}

//*********************** LCD Funktionen ***********************************

void lcd_init(void)
{
    Tft.begin();
}

void lcd_clear(void)
{
    Tft.begin();
}

void lcd_setcursor(uint8_t row, uint8_t column)
{
    Tft.setCursorCharacter(row,column);
}

void lcd_char(char data)
{
    Tft.print(data);
}

void lcd_print(uint8_t text[])
{
    char txt[171];
    uint8_t i;
  
    for(i=0;i<170;i++)
        txt[i]=' ';
    for(i=0;i<170;i++)
        txt[i]=text[i];       
    txt[170]='\0';
    Tft.print(txt);
}

void lcd_byte(uint8_t data)
{
    char txt[5];
    sprintf(txt,"%3d",data);
    Tft.print(txt);
}

void lcd_int(uint16_t data)
{
    char txt[10];
    sprintf(txt,"%5d",data);
    Tft.print(data);
}

//*********************** PWM Funktionen ***********************************

void pwm_init(void)
{
    ledcSetup(0,10000,8);
    ledcAttachPin(5,0);
    ledcWrite(0,127);
}

void pwm_start(void)
{
}

void pwm_stop(void)
{
    ledcDetachPin(5);
}

void pwm_duty_cycle(uint8_t value)
{
    ledcWrite(0,value);
}


//*********************** ADC Funktionen ***********************************

void adc_init(void)
{
    delay_ms(1);
}

uint8_t adc_in1(void)
{
    uint8_t value;
    const int analogPin = A0;
    
    value = analogRead(analogPin)/16;
    return value;
}

uint8_t adc_in2(void)
{
    uint8_t value;
    const int analogPin = A1;
    
    value = analogRead(analogPin)/16;
    return value;
}

//*********************** IR Funktionen ***********************************

void ext_interrupt_enable(void)
{}

void ext_interrupt_disable(void)
{}

void ext_interrupt1_enable(void)
{}

void ext_interrupt1_disable(void)
{}

void ext_interrupt_isr(void);

void ext_interrupt1_isr(void);

void ext_interrupt_init(void)
{
    attachInterrupt(34,ext_interrupt_isr,FALLING);
}

void ext_interrupt1_init(void)
{
    attachInterrupt(35,ext_interrupt1_isr,FALLING);
}

//*********************** TIMER Funktionen ***********************************

void timer1ms_isr();

void timer1ms_enable(void)
{
    timerAlarmEnable(timer1ms);
}

void timer1ms_disable(void)
{
    timerAlarmDisable(timer1ms);
}

void timer1ms_init(void)
{
    timer1ms = timerBegin(0,80,true);
    timerAttachInterrupt(timer1ms,&timer1ms_isr,true);
    timerAlarmWrite(timer1ms,10000,true);
}

//*********************** I2C Funktionen ***********************************

void i2c_init(void)
{
    Wire.begin();
}

void i2c_start(void)
{
}

void i2c_write(uint8_t value)
{
Wire.beginTransmission(value);
Wire.write(0);
Wire.endTransmission();
}

uint8_t i2c_read(uint8_t value)
{
Wire.requestFrom(0x48,2);
value = Wire.read();
Wire.read();
return value;
}

void i2c_stop(void)
{
}

//*********************** RS232 Funktionen ***********************************

