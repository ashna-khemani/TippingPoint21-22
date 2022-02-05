# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"



void NGoalInFront(){
  drivePD(48);  // change to 43
  wait(10, msec);
  slideFwdNonBlock(1, 25);
  wait(100, msec);
  clawClose();
  wait(200, msec);

  slideBackNonBlock(36, 100);
}

void NGoalInFrontL(){
  backClampClose();
  drivePD(49.5);
  clawClose();
  wait(200, msec);

  drivePD(-35); //36->38
  wait(1,sec);
  backLiftUpNonBlocking(95);
  turnLeft(50);
  alignToHeading(310);
  wait(1,sec);

  drivePD(-17);
  // Hook on and Ring ownG
  backLiftDown(35);
  backClampOpen();
  drivePD(14);
  backLiftUp(10); // To pop the ring out
  wait(100, msec);

  // Let go
  backLiftUp(40);
  goFwd(6, 100);
  clawOpen();
  goBack(4, 70);



}

void NGoalAndRAWP(){
  backClampClose();

  // Get NGoal
  drivePD(48); //49->48
  clawClose();
  wait(200, msec);
  drivePD(-28); // Aligns to ownG 25->28
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

void RAWPAndMiddleGoal(){
   backClampClose();

  // Get NGoal
  drivePD(48); //49->48
  clawClose();
  wait(200, msec);
  drivePD(-28); // Aligns to ownG 25->28
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
  drivePD(10);
  alignToHeading(270);
  wait(10,msec);
  drivePD(-4);

  //face mid
  turnRight(60);
  alignToHeading(330);
  wait(10,msec);
  drivePD(35);
  clawClose();
  wait(100,msec);
  frontLiftUp(20);
  goBack(45, 50);
  turnLeft(60);

}

void Skills_1(){    // Currently for pushing MGs into home zones
  // Set initial heading (270)
  InertialSensor.setHeading(270, deg);
  wait(10, msec);

  // AK 1/31: Can we remove some of the alignToHeading's so we can move faster? delete this if it was tested and necessary lol
  // Lift Red MG w/ BackLift
#if 0
  drivePD(2); // flip open
  alignToHeading(270);
  wait(10,msec);
  drivePD(-4.5); //-2.5->-5

#endif
  drivePD(-2.5); //-2.5->-5
  backClampClose(); wait(10, msec);
  backLiftUpNonBlocking(80);
  wait(10, msec);
  alignToHeading(270); wait(10,msec); //testing

  // Align FrontLift to Left NGoal
  drivePD(-5); //-2.25->-5->4 4->5
  wait(10, msec);
  turnRightSlow(90); 
  wait(3000,msec);
  alignToHeading(0);

  // Push Left NGoal to other side HZ w/ FrontLift
  drivePD(20);
  backLiftDownNonBlocking(80);
  drivePD(20); //43->46
  slideFwdNonBlock(4, 25);
  wait(500,msec);
  clawClose();
  alignToHeading(0);
 // frontLiftUp(5);
  drivePD(60); //68-65
  slideFwdNonBlock(5, 25);
  wait(500, msec);
  // frontLiftDown(5);
  clawOpen();

  // Back into corner and drop Red MG (BackLift)
  drivePD(-10);
  turnRight(135); alignToHeading(135);
  wait(10,msec);
  drivePD(-12);
  backClampOpen();

  // Align BackLift to Blue MG
  drivePD(12);
  turnLeft(45); alignToHeading(90);

  // Pick up Blue MG w/ BackLift
  drivePD(-16);
  backClampClose(); wait(200, msec);
  alignToHeading(90); wait(10,msec); //testing
  backLiftUpNonBlocking(85); wait(10,msec);

  drivePD(16);
  turnRight(45);
  alignToHeading(135);
  wait(10,msec);

  //pick up big
  drivePD(60);
  wait(10,msec);
  clawClose();

  turnRight(10);
  alignToHeading(145); wait(10,msec);

  drivePD(60);
  clawOpen();

  drivePD(-14);
  turnLeft(45);
  alignToHeading(90); wait(10,msec);
  backLiftDown(85);
  backClampOpen(); wait(10,msec);

  drivePD(15);
  clawClose();
  wait(10,msec);

  drivePD(-12); //...


}



void Skills_Push(){
    // move Skills_1 (currently for pushing) here once we move on to a platforming skills
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
