# include "vex.h"
# include "bot-functions.h"
# include "auton-functions.h"

using namespace vex;
competition Competition;


// ------------- Auton Menu Setup -------------
int MenuItemSelected = 0;
int MenuItemHighlighted = 0;

enum Sides{
  RED, BLUE
};

enum MenuItems{
  N_GOAL_IN_FRONT,
  N_GOAL_IN_FRONT_L,
  N_GOAL_AND_R_AWP,
  MIDDLE_GOAL,
  SKILLS_1,
  SKILLS_PUSH,
  NO_ACTION,  // ALSO USED AS A TEST CODE
  MENU_LENGTH,
};

char MenuList[MENU_LENGTH][20] = {
  "NGoalInFront",
  "NGoalInFrontL",
  "NGoalAndRAWP",
  "MiddleGoal",
  "Skills 1",
  "SkillsPush",
  "No Action",

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


// --------- Filter function for driving ---------
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

  // Set so no air is passing through solenoid
  backClampOpen();

  // Set Lifts and Claw brakeTypes
  FrontLift.setStopping(hold);
  Claw.setStopping(hold);
  BackLift.setStopping(hold);



  mainControl.Screen.clearScreen();
  mainControl.Screen.setCursor(1, 1);
  Brain.Screen.setFont(fontType::mono20);

  // Select Auton from Menu
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
  mainControl.ButtonL1.pressed(frontLiftUpAuto);
  mainControl.ButtonL2.pressed(frontLiftDownAuto);
  mainControl.ButtonX.pressed(clawDrive);

  mainControl.ButtonL1.pressed(conveyorBeltFwdDrive);
  mainControl.ButtonL2.pressed(conveyorBeltBackDrive);


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
  switch(MenuItemHighlighted){

    /*
    case THING_FROM_MenuItems:
      autonFunctionName();
      break;
    case ....
    */
    case N_GOAL_IN_FRONT:
      NGoalInFront();
      break;
    case N_GOAL_IN_FRONT_L:
      NGoalInFrontL();
      break;
    case N_GOAL_AND_R_AWP:
      NGoalAndRAWP();
      break;
    case MIDDLE_GOAL:
      RAWPAndMiddleGoal();
      break;
    case SKILLS_1:
      Skills_1();
      break;
    case SKILLS_PUSH:
      Skills_Push();
      break;
    case NO_ACTION:
      turnRight(90);
      vex::task::sleep(3000);
      turnRightSlow(90);
      vex::task::sleep(3000);
      turnLeft(90);
      vex::task::sleep(3000);
      turnLeftSlow(90);
      vex::task::sleep(3000);
      turnRight(135);
      vex::task::sleep(10000);


  }
}


void usercontrol(void) {
  // User control code here, inside the loop
  setBackLiftBrake(hold);
  setFrontLiftBrake(hold);
  int fwd, trn;
  int leftPwr, rightPwr;
  while (1) {
    fwd = (filter(mainControl.Axis3.position()) - filter(secondCtrl.Axis3.position()) * AVAS_TURN_WEIGHT) * DRIVE_WEIGHT;
    trn = (filter(mainControl.Axis1.position()) + filter(secondCtrl.Axis1.position()) * AVAS_TURN_WEIGHT) * TURN_WEIGHT;
    leftPwr = (fwd + trn);
    rightPwr = (fwd - trn);


    FrontLeftMotor.spin(vex::directionType::fwd, leftPwr, vex::velocityUnits::pct);
    FrontRightMotor.spin(vex::directionType::fwd, rightPwr, vex::velocityUnits::pct);
    BackLeftMotor.spin(vex::directionType::fwd, leftPwr, vex::velocityUnits::pct);
    BackRightMotor.spin(vex::directionType::fwd, rightPwr, vex::velocityUnits::pct);

    vex::task::sleep(20); //Sleep to save resources :)

  }
}


int ClawMotorTask(void){

  while (1) {
    if (ClawMotorRunning){
      vex::task::sleep(400);
      Claw.setStopping(hold);
      Claw.stop();
      ClawMotorRunning = 0;
    }
    vex::task::sleep(25);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  vex::task t(ClawMotorTask);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
