# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"



void NGoalInFront(){
  drivePD(40);  // change to 43
  clawClose();
  wait(200, msec);

  slideBackNonBlock(36, 100);
}

void NGoalInFrontL(){
  drivePD(49.5);
  clawClose();
  wait(200, msec);

  slideBackNonBlock(36, 100);
}

void NGoalAndRAWP(){
  backClampClose();

  // Get NGoal
  drivePD(49);
  clawClose();
  wait(200, msec);
  drivePD(-25); // Aligns to ownG
  backLiftUpNonBlocking(95);
  turnLeft(90);
  clawOpen();
  wait(200, msec);
  alignToHeading(270);
  

  // Back into ownG
  drivePD(-11);

  // Hook on and Ring ownG
  backLiftDown(35);
  backClampOpen();

  // Drag it out
  goFwd(17, 40);
  backLiftUp(10); // To pop the ring out
  wait(1000, msec);

  // Let go
  backLiftUp(40);
  goFwd(10, 100);

}

void Skills_1(){
  InertialSensor.setHeading(270, deg);  // Robot starts facing 270

  drivePD(-2.5);
  backClampClose();
  turnLeft(90); alignToHeading(0);

  drivePD(50);
  clawClose();
}

// Idea: -- Master Plan
  // deploy back lift
  // zoom fwd to NGoal
  // up back lift
  // go back
  // turn to WP Goal
  // lift WP goal out of zone
  // Go back, align to tall NGoal
  // turn to NGoal
  // Let go of goal on back
  // Take Ngoal into zone
