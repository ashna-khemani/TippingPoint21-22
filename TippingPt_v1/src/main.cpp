# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"

using namespace vex;
competition Competition;


// Auton Menu Setup
int MenuItemSelected = 0;
int MenuItemHighlighted = 0;  // originally 1

enum Sides{
  RED, BLUE
};

enum MenuItems{
  //ITEM_NOT_USED,
  N_GOAL_IN_FRONT,
  NO_ACTION,
  MENU_LENGTH,
};

char MenuList[MENU_LENGTH][20] = {
  //"",                   //0 ITEM_NOT_USED
  "NGoalInFront",
  "No Action",           // NO_ACTION

};

void MenuDown(void){
  MenuItemHighlighted++;
  if(MenuItemHighlighted > (MENU_LENGTH - 1)){
    MenuItemHighlighted = 1;
  }
}

void MenuSelect(void){
  MenuItemSelected = 1;
}

// //Filter function for driving ---------
int filter (int value) {
  if (abs(value) > 16) {
    return (value);
  } else {
    return (0);
  }
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


  backClampOpen();  // Set so no air is passing through solenoid

  // Set to hold so it stays down before deploying
  mainControl.Screen.clearScreen();
  mainControl.Screen.setCursor(1, 1);

  FrontLift.setStopping(hold);
  Claw.setStopping(hold);


  // Select Auton from Menu
  Brain.Screen.setFont(fontType::mono20);

  mainControl.ButtonDown.pressed(MenuDown);
  mainControl.ButtonRight.pressed(MenuSelect);
  while (!MenuItemSelected){  // Allow for selection while program is not selected
    mainControl.Screen.clearScreen();
    mainControl.Screen.setCursor(2, 1);
    mainControl.Screen.print("%s", MenuList[MenuItemHighlighted]);
    vex::task::sleep(64);
  }
  
  mainControl.Screen.setCursor(2, 1); // Show selected program once prog has been selected
  mainControl.Screen.print("%s selected", MenuList[MenuItemHighlighted]);

  // Drive buttons
  mainControl.ButtonR1.pressed(frontLiftUpDrive);
  mainControl.ButtonR2.pressed(frontLiftDownDrive);
  mainControl.ButtonX.pressed(clawDrive);

  mainControl.ButtonUp.pressed(conveyorBeltFwdDrive);
  mainControl.ButtonDown.pressed(conveyorBeltBackDrive);


  secondCtrl.ButtonR1.pressed(backLiftUpDrive);
  secondCtrl.ButtonR2.pressed(backLiftDownDrive);
  secondCtrl.ButtonLeft.pressed(backLiftAuto);
  secondCtrl.ButtonX.pressed(backClampDrive);

  



  // Inertial Sensor setup
  int limitLoop = 0;
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating() && (limitLoop < 25)) {  // Wait for sensor to finish; timeout if taking too long
    limitLoop++;
    wait(100, msec);
  }
  if (limitLoop == 25) {  // Print error message if taking too long to calibrate
    mainControl.Screen.setCursor(1, 1);
    mainControl.Screen.print("ERR: Inertial Timeout");
  }
  InertialSensor.resetRotation();
  InertialSensor.resetHeading();
  // InertialSensor.setHeading(315, deg); // Set starting heading to 315
}

void autonomous(void) {
  // TO DO: add Deploy
  switch(MenuItemHighlighted){

    /*case THING_FROM_MenuItems:
      autonFunctionName();
      break;
    case ....
    */
    case N_GOAL_IN_FRONT:
      NGoalInFront();
      break;
    case NO_ACTION:
      vex::task::sleep(10000);


  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  setBackLiftBrake(hold);
  setFrontLiftBrake(hold);
  int fwd, trn;
  int leftPwr, rightPwr;
  while (1) {
    //origial code
    fwd = (filter(mainControl.Axis3.position()) - filter(secondCtrl.Axis3.position()) * AVAS_TURN_WEIGHT) * DRIVE_WEIGHT;
    trn = (filter(mainControl.Axis1.position()) + filter(secondCtrl.Axis1.position())) * TURN_WEIGHT;
    leftPwr = (fwd + trn);
    rightPwr = (fwd - trn);


    FrontLeftMotor.spin(vex::directionType::fwd, leftPwr, vex::velocityUnits::pct);
    FrontRightMotor.spin(vex::directionType::fwd, rightPwr, vex::velocityUnits::pct);
    BackLeftMotor.spin(vex::directionType::fwd, leftPwr, vex::velocityUnits::pct);
    BackRightMotor.spin(vex::directionType::fwd, rightPwr, vex::velocityUnits::pct);

    vex::task::sleep(20); //Sleep to save resources :)

  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
