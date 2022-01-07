# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"



void NGoalInFront(){
  slideFwd(47, 100);
  clawClose();

  slideBackNonBlock(36, 100);
  
}

void NGoalAndRAWP(){
  backClampClose();

  // Get NGoal
  slideFwd(47, 100);
  clawClose();
  goBack(8.5, 100);
  clawOpen();

  // Align w/ ownG
  goBack(7.5, 100);
  turnLeft(90);
  slideBackNonBlock(17, 100);
  backLiftUp(90);
  wait(300, msec);
  goBack(3, 100);

  // Hook on and Ring ownG
  backLiftDown(20);
  backClampOpen();

  // Drag it out
  goFwd(12, 100);

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
