#include <Arduino.h>
#include "button.h"
#include "effects.h"

Button* btn = new Button(D2);
Effect* effects[7];
unsigned short effectIndex = 0;

bool singleClick() {
  effectIndex++;
  if (effectIndex>6) { effectIndex = 0; }
  effects[effectIndex]->Reset();
}
void longClick() {
  effects[effectIndex]->SecondaryAction();
}

void setup()
{
  Serial.begin(9600);

  effects[0] = new AllLedCycle();
  effects[1] = new AllLedOn();
  effects[2] = new FirstLedOn();
  effects[3] = new SecondLedOn();
  effects[4] = new ThirdLedOn();
  effects[5] = new FourthLedOn();
  effects[6] = new AllLedOff();

}

void loop()
{
  switch(btn->Check()) {
    case 1:
      singleClick();
      break;
    case 2:
      longClick();    
  }
  effects[effectIndex]->Action();
}