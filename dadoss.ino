#include "SevSeg.h"
#include <avr/eeprom.h>

void reseedRandom( uint32_t* address )
{
  static const uint32_t HappyPrime = 127807 /*937*/;
  uint32_t raw;
  unsigned long seed;

  // Read the previous raw value from EEPROM
  raw = eeprom_read_dword( address );

  // Loop until a seed within the valid range is found
  do
  {
    // Incrementing by a prime (except 2) every possible raw value is visited
    raw += HappyPrime;

    // Park-Miller is only 31 bits so ignore the most significant bit
    seed = raw & 0x7FFFFFFF;
  }
  while ( (seed < 1) || (seed > 2147483646) );

  // Seed the random number generator with the next value in the sequence
  srandom( seed );  

  // Save the new raw value for next time
  eeprom_write_dword( address, raw );
}

inline void reseedRandom( unsigned short address )
{
  reseedRandom( (uint32_t*)(address) );
}

void reseedRandomInit( uint32_t* address, uint32_t value )
{
  eeprom_write_dword( address, value );
}

inline void reseedRandomInit( unsigned short address, uint32_t value )
{
  reseedRandomInit( (uint32_t*)(address), value );
}


uint32_t reseedRandomSeed EEMEM = 0xFFFFFFFF;


SevSeg Display;
//botones
int button_D4 = 12;  //digital
int button_D6 = A4;  //analog (idk pin 13 doesn't work)
int button_D8 = A0;  //digital
int button_D10 = A1;  //analog
int button_D12 = A2;  //analog
int button_D20 = A3;  //analog

unsigned int number = 1;
const unsigned long period = 100; // in millisecond
unsigned long startMillis;
unsigned long currentMillis;

long roll;
int D4 = 4;
int D6 = 6;
int D8 = 8;
int D10 = 10;
int D12 = 12;
int D20 = 20;

void setup()
{
  byte numDigits = 2;
  byte digitPins[] = {11, 10};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  Display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelaysIn);
  Display.setBrightness(100);

  pinMode(12, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);


  reseedRandom( &reseedRandomSeed );
  roll = 0;
}

void loop()
{
  Display.setNumber(roll);
  Display.refreshDisplay();
  ////////////////// D4 ////////////////// 
  if (digitalRead(button_D4) == LOW){
    for( int j=0;j<200;j++){                          //rolling dice effect
      currentMillis = millis();                       //rolling dice effect
        if (currentMillis - startMillis >= period){   //rolling dice effect
          number = number + 1;                        //rolling dice effect
          startMillis = currentMillis;                //rolling dice effect
        }
      if (number > D4){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D4 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  }

////////////////// D6 //////////////////

  if (digitalRead(button_D6) == LOW){
    for( int j=0;j<200;j++){  
      currentMillis = millis();
        if (currentMillis - startMillis >= period){
          number = number + 1;
          startMillis = currentMillis;
        }
      if (number > D6){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D6 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  }

  ////////////////// D8 //////////////////

  if (digitalRead(button_D8) == LOW){
    for( int j=0;j<200;j++){  
      currentMillis = millis();
        if (currentMillis - startMillis >= period){
          number = number + 1;
          startMillis = currentMillis;
        }
      if (number > D8){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D8 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  }

  ////////////////// D10 //////////////////

  if (digitalRead(button_D10) == LOW){
    for( int j=0;j<200;j++){  
      currentMillis = millis();
        if (currentMillis - startMillis >= period){
          number = number + 1;
          startMillis = currentMillis;
        }
      if (number > D10){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D10 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  } 

  ////////////////// D12 //////////////////

  if (digitalRead(button_D12) == LOW){
    for( int j=0;j<200;j++){  
      currentMillis = millis();
        if (currentMillis - startMillis >= period){
          number = number + 1;
          startMillis = currentMillis;
        }
      if (number > D12){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D12 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  } 

  ////////////////// D20 //////////////////

  if (digitalRead(button_D20) == LOW){
    for( int j=0;j<200;j++){  
      currentMillis = millis();
        if (currentMillis - startMillis >= period){
          number = number + 1;
          startMillis = currentMillis;
        }
      if (number > D20){
        number  = 1;
      }
      Display.setNumber(number);
      Display.refreshDisplay();
    }
  roll = random(1,D20 + 1); 
    Display.setNumber(roll);
    Display.refreshDisplay();
  } 
  

}
























