# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"

// NOTE: Deploy function goes here
void flipOpen(){
  frontLiftUp(30);
  wait(50, msec);
  frontLiftDown(20);
}
void NGoalInFront(){
  setFrontLiftBrake(hold);
  wait(10, msec);
  flipOpen();
  goFwd(48, 100);
  frontLiftUp(30);
  slideBackNonBlock(36, 100);
  wait(200, msec);  // Lower goal after 200msec of driving back
  frontLiftDown(30);

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
