#include "Arduino.h"
#include "motor.h"

void Motor::begin()
{
  //Phase and Frequency Correct PWM, TOP=ICR1
  TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (0<<COM1B0) | (0<<COM1C1) | (0<<COM1C0) | (0<<WGM11) | (0<<WGM10);
  TCCR1B=(0<<ICNC1) | (0<<ICES1) | (1<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
  
  setBitDepth(DEFAULT_FFB_BITDEPTH);
  
  OCR1A=0;
  OCR1B=0;
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  #ifdef MOTOR_ENABLE_PIN_WATCH
    pinMode(MOTOR_ENABLE_PIN_WATCH, OUTPUT);
    digitalWriteFast(MOTOR_ENABLE_PIN_WATCH, 0);
  #endif

  #ifdef MOTOR_ENABLE_PIN_ANTI_WATCH
    pinMode(MOTOR_ENABLE_PIN_ANTI_WATCH, OUTPUT);
    digitalWriteFast(MOTOR_ENABLE_PIN_ANTI_WATCH, 0);
  #endif
}

//values -16383..16383
void Motor::setForce(int16_t force)
{
  force=constrain(force,-16383,16383);

  #ifdef MOTOR_ENABLE_PIN_WATCH || MOTOR_ENABLE_PIN_ANTI_WATCH
  if (force<0)
  {
    delayMicroseconds(1000);
    digitalWriteFast(MOTOR_ENABLE_PIN_ANTI_WATCH, 0);
    digitalWriteFast(MOTOR_ENABLE_PIN_WATCH, 1);
  }
  else if(force>0)
  {
    delayMicroseconds(1000);
    digitalWriteFast(MOTOR_ENABLE_PIN_ANTI_WATCH, 1);
    digitalWriteFast(MOTOR_ENABLE_PIN_WATCH, 0);
  }
  else
  {
    OCR1A=0;
  }
  #endif

  if (force>0)
  {
    OCR1A=(1+force)>>bitShift;
  }

  else if (force<0)  
  {
    OCR1A=(1-force)>>bitShift;
  }
  else
  {
    OCR1A=0;
  }
}

void Motor::setBitDepth(uint8_t value)
{
  value=constrain(value,1,14);
  bitDepth=value;
  bitShift=14-bitDepth;
  ICR1=1<<bitDepth;
}
