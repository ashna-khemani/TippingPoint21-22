/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ashnakhemani                                              */
/*    Created:      Sun Jan 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DigitalOutC          digital_out   C               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  while (true){
    if(Controller1.ButtonR1.pressing()){
      DigitalOutC.set(true);
    }
    else{
      DigitalOutC.set(false);
    }
    wait(100, msec);
  }
  
  
}
