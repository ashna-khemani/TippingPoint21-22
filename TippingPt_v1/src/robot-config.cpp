#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor BackLeftMotor = motor(PORT20, ratio18_1, false);
motor BackRightMotor = motor(PORT2, ratio18_1, true);
motor FrontLeftMotor = motor(PORT13, ratio18_1, false);
motor FrontRightMotor = motor(PORT16, ratio18_1, true);

controller mainControl = controller(primary);
controller secondCtrl = controller(partner);
vex::inertial InertialSensor = vex::inertial(vex::PORT10);
motor_group leftDrive = motor_group( BackLeftMotor, FrontLeftMotor );
motor_group rightDrive = motor_group( BackRightMotor, FrontRightMotor );
// define the drivetrain
// this one is a smart drive which uses the InertinalSensor
// gyro and all motors were defined using graphical config
// we have 4 inch wheels
// drive is 14 inches wide between the left and right wheels
// drive has a 10 inch wheelbase (between fron and back wheel axles)
smartdrive    robotDrive = smartdrive( leftDrive, rightDrive, InertialSensor,4*3.14, 15, 10, distanceUnits::in );



// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}