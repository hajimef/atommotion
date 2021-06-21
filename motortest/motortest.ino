#include <M5Atom.h>
#include "AtomMotion.h"

#define SPEED 80

AtomMotion Atom;
int stat = 0;

void setup(){ 
  M5.begin(true, false, true);
  Atom.Init();
}

void loop() {
  int speed, dir;
    
  M5.update();
  if(M5.Btn.wasPressed()){
    stat = (stat + 1) % 8;
    dir = stat > 4 ? -1 : 1;
    speed = SPEED * dir;
    if (stat == 0 || stat == 4) {
      Atom.SetMotorSpeed(1, 0);
      Atom.SetMotorSpeed(2, 0);
    }
    else if (stat == 1 || stat == 5) {
      Atom.SetMotorSpeed(1, speed);
      Atom.SetMotorSpeed(2, 0);
    }
    else if (stat == 2 || stat == 6) {
      Atom.SetMotorSpeed(1, 0);
      Atom.SetMotorSpeed(2, speed);
    }
    else if (stat == 3 || stat == 7) {
      Atom.SetMotorSpeed(1, speed);
      Atom.SetMotorSpeed(2, speed);
    }
  }
}
