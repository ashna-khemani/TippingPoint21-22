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
  drivePD(-25); // Aligns to ownG 25->28->25
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
void Skills_Plat(){
  // Set initial heading (270)
  //  InertialSensor.setHeading(270, deg);
  //  wait(100, msec);

  #if 0 // CHange this to #if 0 after testing. it is only for debug

    drivePD(24);
    wait(2000, msec);
    drivePD(-24);
    wait(2000, msec);
    turnRight(90);
    wait(2000, msec);
    alignToHeading(90);
    wait(2000, msec);
    turnLeftSlow(90);
    wait(2000, msec);
    alignToHeading(0);
    wait(2000, msec);
    turnLeft(90);
    wait(2000, msec);
    alignToHeading(270);
    wait(2000, msec);
    turnLeftSlow(90);
    wait(2000, msec);
    alignToHeading(180);
    wait(5000, msec);

  #endif


  drivePD(-4); //-2.5->-5
  wait(10, msec);
  backClampClose();
  wait(150, msec);
  backLiftUp(20);
  backLiftUpNonBlocking(60);
  wait(200, msec);
  alignToHeading(270); wait(50,msec); //testing

  // Align FrontLift to Left NGoal
  drivePD(12); //-2.25->-5-> 4 4->5 //-5->-5.5-7
  wait(50, msec);
  turnRight(90); 
  wait(50,msec);
  alignToHeading(0);
  wait(50, msec);
  // Push Left NGoal to other side HomeZone w/ FrontLift
  drivePD(36); //2/13 36->38
  turnRight(45);
  wait(50,msec);
  alignToHeading(45);
  wait(50,msec);
  drivePD(13); //43->46
  slideFwdNonBlock(4, 25);
  wait(500,msec);
  clawClose();
  wait(50,msec);
  alignToHeading(40);
  wait(50,msec);
  frontLiftUp(10);
  frontLiftUpAuto();
  wait(300, msec);
  //head to plat

  drivePD(57);
  wait(50, msec);
  turnLeft(70);
  wait(50,msec);
  slideFwdNonBlock(4, 25);
  wait(500,msec);
  frontLiftDown(15);
  wait(10, msec);
  clawOpen();

  
  //face plat and drop goal
  wait(400,msec);
  drivePD(-4); //-3->-4 
  wait(50,msec);
  frontLiftDown(85);

  //head to blue
  turnLeft(90 - 17); 
  wait(50,msec);
  alignToHeading(270);
  wait(50,msec);
  backLiftDown(80);
  wait(50, msec);
  backClampOpen();
  wait(50,msec);
  
  //get blue
  drivePD(25);
  wait(10, msec);
  turnRight(90);
  wait(10, msec);
  alignToHeading(0);
  wait(10, msec);
  drivePD(6);
  turnLeft(90);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);
  drivePD(18);  

  slideFwd(4, 30);
  wait(500,msec);
  clawClose();  // non-blocking so need time to close
  wait(500,msec);
  alignToHeading(270);
  wait(10, msec);
  frontLiftUp(10);
  
  //go get big
  drivePD(-20);
  wait(50,msec);
  turnRight(45);
  wait(50,msec);
  alignToHeading(315);
  wait(50,msec);
  drivePD(-28);
  wait(50,msec);
  slideBackNonBlock(6,40);
  wait(500,msec);
  backClampClose();       // Clamp the big neutral goal
  wait(500,msec);
  backLiftUpNonBlocking(20);
  drivePD(-80);
  wait(50,msec);
  backLiftDown(20);
  wait(50,msec);
  backClampOpen();      // Leave the big goal in corner
  backLiftUpNonBlocking(0);
  wait(100, msec);
  alignToHeading(315);

  drivePD(20);
  wait(10, msec);
  turnLeft(45);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);

  // Forget the platform for now  frontLiftUpAuto();
  drivePD(10);
  
  //  turnLeft(90);
  //  slideFwdNonBlock(2, 30);
  //  wait(500, msec);
  clawOpen();       // drop the blue goal
  //  wait(400, msec);
  //  drivePD(-2);
  //  turnRight(30);
  //  wait(10, msec);
  drivePD(-25);
  wait(10, msec);
  slideBackNonBlock(4, 30);
  wait(500, msec);
  backClampClose();
  wait(500, msec);
  backLiftUp(20);
  drivePD(22);

  turnRight(90);
  wait(10, msec);
  drivePD(30);
  wait(10, msec);
  slideFwdNonBlock(8, 25);
  wait(10, msec);
  clawClose();
  wait(20, msec);
  frontLiftUp(10);
  drivePD(36);
  turnRight(45);
  drivePD(24);
  frontLiftDown(10);
  clawOpen();
  drivePD(-12);
  turnLeft(90);
  backLiftDown(20);
  backClampOpen();
  


  /*//align to plat
  drivePD(-5);
  wait(50,msec);
  frontLiftUpAuto();
  wait(10,msec);
  turnLeft(125);
  wait(50,msec);
  alignToHeading(145);
  wait(50,msec);

  //go to plat
  drivePD(75);
  wait(50,msec);

  turnRight(35);
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  slideFwd(15, 50);
  wait(50,msec);
  clawOpen();
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  //get big
  slideFwd(-30, 40);
  wait(50,msec);
  backClampClose();
  wait(500,msec);
  turnLeft(30);
  wait(50,msec);
  alignToHeading(150);
  wait(50,msec);
  drivePD(50);
  */

  


}

void testSkills(void){
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);
    
    frontLiftUpAuto();

    drivePD(48);
    wait(5000, msec);
    drivePD(-24);
    wait(2000, msec);
    turnRight(90);
      mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);  
    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    alignToHeading(90);
     mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);   mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    turnLeftSlow(90);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    alignToHeading(0);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    turnLeft(90);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    alignToHeading(270);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    turnLeftSlow(90);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(2000, msec);
    alignToHeading(180);
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(1, 1);    mainControl.Screen.print("Angle %f", InertialSensor.heading(rotationUnits::deg));
    wait(5000, msec);
    return;

}
void Skills_Plat2(){
  // Set initial heading (270)

  InertialSensor.setHeading(270, deg);
  wait(100, msec);




  drivePD(-4); //-2.5->-5
  wait(10, msec);
  backClampClose();
  wait(150, msec);
  backLiftUp(20);
  backLiftUpNonBlocking(60);
  wait(200, msec);
  alignToHeading(270); wait(50,msec); //testing

  // Align FrontLift to Left NGoal
  drivePDSlow(12); //-2.25->-5-> 4 4->5 //-5->-5.5-7
  wait(50, msec);
  turnRightSlow(90); 
  wait(150,msec);
  alignToHeading(0);
  wait(50, msec);

  drivePDSlow(34); //2/13 36->38
  wait(150,msec);
  turnRightSlow(30);
  wait(50,msec);
  alignToHeading(30);
  wait(50,msec);
  drivePDSlow(13); //43->46
  slideFwdNonBlock(4, 25);
  wait(500,msec);
  clawClose();      // grab the left NGoal
  wait(200,msec);
  frontLiftUpAuto();  
  wait(10, msec);
  alignToHeading(30);
  wait(50,msec);

  wait(1000, msec);

  //head to plat
  drivePDSlow(55);
  wait(50, msec);
  turnLeft(30);
  wait(50,msec);
  mainControl.Screen.clearScreen();
  mainControl.Screen.setCursor(1,1);
  mainControl.Screen.print("1 %f", InertialSensor.heading());
  slideFwdNonBlock(6, 25);
  wait(1000, msec);
  frontLiftDown(40);
  wait(500, msec);
  clawOpen();     // drop the blue
  wait(500,msec);
  slideBackNonBlock(2, 25);
  wait(100, msec);
  frontLiftUp(40);
  drivePDSlow(-4); //-3->-4 
  wait(50,msec);
  frontLiftDownAuto();

  // turn around, pick red with front lift and head to blue
  turnLeft(90); 
  wait(50,msec);
  alignToHeading(270);
  wait(50,msec);
  backLiftDown(80);
  wait(50, msec);
  backClampOpen();
  wait(50,msec);
  alignToHeading(270);
  wait(10, msec);
  drivePDSlower(10); // move away so bot doesnt hit the red base
  wait(10,msec);
  turnLeft(180);
  wait(10,msec);
  alignToHeading(90);

  drivePDSlower(10);
  slideFwdNonBlock(4,25);
  wait(1000, msec);

  clawClose();
  wait(10, msec);
  frontLiftUpAuto();

  
  drivePDSlow(-32);
  slideBackNonBlock(10,25);
  wait(1200, msec);
  backClampClose();  // non-blocking so need time to close
  wait(500,msec);
  drivePDSlow(6);
  alignToHeading(90);
  backLiftUp(80);
  wait(10, msec);
  
  drivePDSlow(54); //20
  wait(50,msec);

  turnLeft(90);
  wait(10, msec);
  alignToHeading(0);
  drivePDSlow(6);
  slideFwdNonBlock(8, 25);
  wait(1000, msec);

  frontLiftDown(40);
  wait(500, msec);
  clawOpen();       // drop the red goal on plat
  wait(500,msec);
  slideBackNonBlock(2, 25);
  wait(100, msec);
  frontLiftUp(40);
  drivePDSlow(-4); //-3->-4 
  wait(50,msec);


  turnRight(90);
  alignToHeading(90);

  frontLiftDownAuto();

  // phase 2
  drivePDSlower(30);

  turnRight(90);

  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  drivePD(24);
  wait(50,msec);
  slideFwdNonBlock(8, 25);
  wait(500,msec);

  clawClose();      // grab the right NGoal
  wait(200,msec);
  frontLiftUpAuto();  
  wait(10, msec);
  turnRight(40);
  alignToHeading(220);
  wait(50,msec);

  wait(1000, msec);

  //head to plat 2
  drivePDSlow(55);
  wait(50, msec);
  turnLeft(40);
  wait(50,msec);
  mainControl.Screen.clearScreen();
  mainControl.Screen.setCursor(1,1);
  mainControl.Screen.print("1 %f", InertialSensor.heading());
  slideFwdNonBlock(6, 25);
  wait(1000, msec);
  frontLiftDown(40);
  wait(500, msec);
  clawOpen();       // drop the right ngoal on plat
  wait(500,msec);
  slideBackNonBlock(2, 25);
  wait(100, msec);
  frontLiftUp(40);
  drivePDSlow(-4); //-3->-4 
  wait(50,msec);
  frontLiftDownAuto();






  backClampClose();       // Clamp the big neutral goal
  wait(500,msec);
  backLiftUpNonBlocking(20);
  drivePD(-80);
  wait(50,msec);
  backLiftDown(20);
  wait(50,msec);
  backClampOpen();      // Leave the big goal in corner
  backLiftUpNonBlocking(0);
  wait(100, msec);
  alignToHeading(315);

  drivePD(20);
  wait(10, msec);
  turnLeft(45);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);

  frontLiftUpAuto();
  wait(100, msec);
// Forget the platform for now  frontLiftUpAuto();
  drivePD(22);
  wait(10, msec);
  turnLeft(90);
  wait(10, msec);
  alignToHeading(180);
  wait(10, msec);
  drivePD(4);
  wait(10, msec);
  slideFwdNonBlock(4, 25);
  wait(500, msec);
  frontLiftDown(10);
  
//  turnLeft(90);
//  slideFwdNonBlock(2, 30);
//  wait(500, msec);
  clawOpen();       // drop the blue goal
//  wait(400, msec);
//  drivePD(-2);
//  turnRight(30);
//  wait(10, msec);

  drivePD(-6);
  wait(10, msec);
  turnRight(90);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);

  frontLiftDownAuto();

  drivePD(-39);
  wait(10, msec);
  slideBackNonBlock(6, 30);
  wait(500, msec);
  backClampClose();
  wait(500, msec);
  backLiftUp(20);
  drivePD(20);

  turnRight(90);
  wait(10, msec);
  alignToHeading(0);
  wait(10, msec);
  drivePD(30);
  wait(10, msec);
  slideFwdNonBlock(8, 25);
  wait(10, msec);
  clawClose();
  wait(20, msec);
  frontLiftUp(10);
  drivePD(30);
  turnRight(45);
  drivePD(24);
  frontLiftDown(10);
  clawOpen();
  drivePD(-2);
  backLiftDown(20);
  backClampOpen();
  


  /*//align to plat
  drivePD(-5);
  wait(50,msec);
  frontLiftUpAuto();
  wait(10,msec);
  turnLeft(125);
  wait(50,msec);
  alignToHeading(145);
  wait(50,msec);

  //go to plat
  drivePD(75);
  wait(50,msec);

  turnRight(35);
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  slideFwd(15, 50);
  wait(50,msec);
  clawOpen();
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  //get big
  slideFwd(-30, 40);
  wait(50,msec);
  backClampClose();
  wait(500,msec);
  turnLeft(30);
  wait(50,msec);
  alignToHeading(150);
  wait(50,msec);
  drivePD(50);
  */

  


}


void Skills_Plat2A(){
  // Set initial heading (270)

  InertialSensor.setHeading(270, deg);
  wait(100, msec);


  drivePD(-4); //-2.5->-5
  wait(10, msec);
  backClampClose();
  wait(150, msec);
  backLiftUp(20);
  backLiftUpNonBlocking(60);
  wait(200, msec);
  alignToHeading(270); wait(50,msec); //testing

  // Align FrontLift to Left NGoal
  drivePDSlow(12); //-2.25->-5-> 4 4->5 //-5->-5.5-7
  wait(50, msec);
  turnRightSlow(90); 
  wait(150,msec);
  alignToHeading(0);
  wait(50, msec);
  // Push Left NGoal to other side HomeZone w/ FrontLift
  drivePD(34); //2/13 36->38
  wait(150,msec);
  turnRightSlow(30);
  wait(50,msec);
  alignToHeading(30);
  wait(50,msec);
  drivePDSlow(13); //43->46
  slideFwdNonBlock(4, 25);
  wait(500,msec);
  clawClose();      // grab the left NGoal
  wait(200,msec);
//  frontLiftUp(10);
  frontLiftUpAuto();  
//  turnRightSlow(10);
  wait(10, msec);
  alignToHeading(30);
  wait(50,msec);

  wait(500, msec);

  //head to plat

  drivePDSlow(55);
  wait(50, msec);

  turnRight(60);
   wait(10, msec);
  alignToHeading(90);
  wait(50,msec); 
  

  turnLeft(40);
  wait(50,msec);
  mainControl.Screen.clearScreen();
  mainControl.Screen.setCursor(1,1);
  mainControl.Screen.print("1 %f", InertialSensor.heading());
  slideFwdNonBlock(6, 25);
  wait(500, msec);
//  turnLeft(30);
  //  slideBackNonBlock(1, 25);
  //  wait(100, msec);
  frontLiftDown(40);
  //  slideFwdNonBlock(2, 25);
  wait(500, msec);
  clawOpen();
  wait(500,msec);
  slideBackNonBlock(2, 25);
  wait(100, msec);
  frontLiftUp(40);
  drivePDSlow(-4); //-3->-4 
  wait(50,msec);
  frontLiftDownAuto();

  //head to blue
  turnLeft(90); 
  wait(50,msec);
  alignToHeading(270);
  wait(50,msec);
  backLiftDown(80);
  wait(50, msec);
  backClampOpen();
  wait(50,msec);
  
  drivePD(50);
  slideFwdNonBlock(10, 30);
  // wait(500,msec);
  clawClose();  // non-blocking so need time to close
  wait(500,msec);
  alignToHeading(270);
  wait(10, msec);
  frontLiftUp(10);
  
  //go get big
  drivePD(-17); //20
  wait(50,msec);
  turnRight(45);
  wait(50,msec);
  alignToHeading(315);
  wait(50,msec);
  drivePD(-28);
  wait(50,msec);
  slideBackNonBlock(6,40);
  wait(500,msec);
  backClampClose();       // Clamp the big neutral goal
  wait(500,msec);
  backLiftUpNonBlocking(20);
  drivePD(-80);
  wait(50,msec);
  backLiftDown(20);
  wait(50,msec);
  backClampOpen();      // Leave the big goal in corner
  backLiftUpNonBlocking(0);
  wait(100, msec);
  alignToHeading(315);

  drivePD(20);
  wait(10, msec);
  turnLeft(45);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);

  frontLiftUpAuto();
  wait(100, msec);
// Forget the platform for now  frontLiftUpAuto();
  drivePD(22);
  wait(10, msec);
  turnLeft(90);
  wait(10, msec);
  alignToHeading(180);
  wait(10, msec);
  drivePD(4);
  wait(10, msec);
  slideFwdNonBlock(4, 25);
  wait(500, msec);
  frontLiftDown(10);
  
//  turnLeft(90);
//  slideFwdNonBlock(2, 30);
//  wait(500, msec);
  clawOpen();       // drop the blue goal
//  wait(400, msec);
//  drivePD(-2);
//  turnRight(30);
//  wait(10, msec);

  drivePD(-6);
  wait(10, msec);
  turnRight(90);
  wait(10, msec);
  alignToHeading(270);
  wait(10, msec);

  frontLiftDownAuto();

  drivePD(-39);
  wait(10, msec);
  slideBackNonBlock(6, 30);
  wait(500, msec);
  backClampClose();
  wait(500, msec);
  backLiftUp(20);
  drivePD(20);

  turnRight(90);
  wait(10, msec);
  alignToHeading(0);
  wait(10, msec);
  drivePD(30);
  wait(10, msec);
  slideFwdNonBlock(8, 25);
  wait(10, msec);
  clawClose();
  wait(20, msec);
  frontLiftUp(10);
  drivePD(30);
  turnRight(45);
  drivePD(24);
  frontLiftDown(10);
  clawOpen();
  drivePD(-2);
  backLiftDown(20);
  backClampOpen();
  


  /*//align to plat
  drivePD(-5);
  wait(50,msec);
  frontLiftUpAuto();
  wait(10,msec);
  turnLeft(125);
  wait(50,msec);
  alignToHeading(145);
  wait(50,msec);

  //go to plat
  drivePD(75);
  wait(50,msec);

  turnRight(35);
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  slideFwd(15, 50);
  wait(50,msec);
  clawOpen();
  wait(50,msec);
  alignToHeading(180);
  wait(50,msec);
  //get big
  slideFwd(-30, 40);
  wait(50,msec);
  backClampClose();
  wait(500,msec);
  turnLeft(30);
  wait(50,msec);
  alignToHeading(150);
  wait(50,msec);
  drivePD(50);
  */

  


}


void Skills_1(){    // Currently for pushing MGs into home zones
  // Set initial heading (270)
  InertialSensor.setHeading(270, deg);
  wait(100, msec);

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
  drivePD(55); //60-55
  wait(10,msec);
  clawClose();

  turnRight(20); //10-20
  alignToHeading(155); wait(10,msec);
  //drop big 
  drivePD(60); 
  wait(10,sec); //new
  clawOpen();
  

  drivePD(-14);
  turnLeft(55); //45-55
  alignToHeading(90); wait(10,msec);
  backLiftDown(85);
  backClampOpen(); wait(10,msec);
  //go for red
  drivePD(15);
  clawClose();
  wait(10,msec);

  //position for neutral
  drivePD(-12); 
  turnRight(90);
  alignToHeading(180);
  wait(100,msec);
  //grap n drop N
  drivePD(-70);
  backClampClose();
  turnRight(45);
  alignToHeading(225);
  wait(10,msec);
  drivePD(-20);
  backClampOpen();
  wait(10,msec);
}

void Middle_goal(){
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

void Skills_Push(){

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
