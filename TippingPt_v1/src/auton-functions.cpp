# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"



void NGoalInFront(){
  slideFwd(45, 100);
  clawClose();

  slideBackNonBlock(36, 100);
  
}

void NGoalAndRAWP(){
  backClampClose();

  // Get NGoal
  drivePI(49);
  Claw.setBrake(hold);
  clawClose();
  drivePI(-25); // Aligns to ownG
  backLiftUpNonBlocking(95);
  turnLeft(90);
  clawOpen();
  wait(10, msec);
  alignToHeading(270);
  

  // Back into ownG
  drivePI(-11);

  // Hook on and Ring ownG
  backLiftDown(35);
  backClampOpen();

  // Drag it out
  goFwd(17, 40);
  backLiftUp(10); // To pop the ring out

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
