#include <M5Atom.h>
#include "AtomMotion.h"

AtomMotion Atom;
int stat = 0;
const int angles[] = { 0, 90, 180, 90 };

void setup(){ 
  M5.begin(true, false, true);
  Atom.Init();
  for (int ch = 1; ch < 5; ch++) {
    Atom.SetServoAngle(ch, 0);
  }
}

void loop() {
    M5.update();
    if(M5.Btn.wasPressed()){
      stat = (stat + 1) % 4;
      for (int ch = 1; ch < 5; ch++) {
        Atom.SetServoAngle(ch, angles[stat]);
      }
    }
}
