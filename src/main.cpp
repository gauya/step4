#include <Arduino.h>
#include "step4.h"

long time;

#if 0

#define LH(cdata) (((cdata)? HIGH: LOW))

//////////////////////////////////////////////////////////////////////////////////

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

void stepper(int cycle,int de, int dir) {
  const uint16_t EV[] = { 0x1,0x3,0x2,0x6,0x4,0xc,0x8,0x9,0x0 };
  if( de < 1 ) de = 1;
  
  if( dir > 0 ) {
    for( int x=0; x<cycle; x++) {
      digitalWrite(IN1, LH(EV[x] & (uint16_t)0x8));
      digitalWrite(IN2, LH(EV[x] & (uint16_t)0x4));
      digitalWrite(IN3, LH(EV[x] & (uint16_t)0x2));
      digitalWrite(IN4, LH(EV[x] & (uint16_t)0x1));

      delay(2);
    }
  } else {
    for( int x=cycle-1; x>=0; x--) {
      digitalWrite(IN1, LH(EV[x] & (uint16_t)0x8));
      digitalWrite(IN2, LH(EV[x] & (uint16_t)0x4));
      digitalWrite(IN3, LH(EV[x] & (uint16_t)0x2));
      digitalWrite(IN4, LH(EV[x] & (uint16_t)0x1));

      delay(2);
    }
  }
}

void test_stepper() {
  int cnt=0;
  int cy=8;
  int de=1;
  while(cnt++ <180) {
    stepper(cy,de,1);
    delay(de);
  }
  while(cnt-->0) {
    stepper(cy,de,-1);
    delay(de);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  test_stepper();
}

#else

int motor1_pins[] = { 11,10,9,8,0 };
byj *B;

void setup() {
  Serial.begin(115200);

  B = (byj*)new byj((int *)motor1_pins);
}

void loop() {
  B->test();
}

#endif
