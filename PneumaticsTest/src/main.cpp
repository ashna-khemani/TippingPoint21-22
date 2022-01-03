/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ashnakhemani                                              */
/*    Created:      Sun Jan 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  while (true){
    if(mainControl.ButtonR1.pressing()){
      Pist.set(false);
      wait(100, msec);
    }
    else{
      Pist.set(true);
      wait(100, msec);
    }
    wait(100, msec);
  }
  
  
}
