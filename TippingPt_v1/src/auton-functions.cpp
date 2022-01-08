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
  drivePI(47);
  clawClose();
  drivePI(-23); // Aligns to ownG
  backLiftUpNonBlocking(95);
  turnLeft(90);
  wait(10, msec);
  alignToHeading(270);
  clawOpen();

  // Back into ownG
  drivePI(-11);

  // Hook on and Ring ownG
  backLiftDown(35);
  backClampOpen();

  // Drag it out
  goFwd(12, 40);

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
