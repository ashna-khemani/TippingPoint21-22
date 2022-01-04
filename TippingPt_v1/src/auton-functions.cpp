# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"



void NGoalInFront(){
  setFrontLiftBrake(hold);
  setClawBrake(hold);
  wait(10, msec);

  slideFwd(45, 100);
  clawClose();

  slideBackNonBlock(36, 100);
  
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
