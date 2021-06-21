#include <M5Atom.h>
#include "AtomMotion.h"

AtomMotion Atom;

void setup(){ 
  M5.begin(true, false, true);
  Atom.Init();
}

void loop() {
}
