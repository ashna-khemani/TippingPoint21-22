#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeftMotor = motor(PORT18, ratio18_1, false); //11->18
motor FrontRightMotor = motor(PORT6, ratio18_1, true);
motor BackLeftMotor = motor(PORT2, ratio18_1, false);
motor BackRightMotor = motor(PORT16, ratio18_1, true);

motor FrontLift = motor(PORT20, ratio36_1, true);

motor BackLift = motor(PORT12, ratio36_1, false);

motor ConveyorBelt = motor(PORT15, ratio18_1, true);

motor Claw = motor(PORT9, ratio18_1, false);

digital_out BackClamp = digital_out(Brain.ThreeWirePort.F);
encoder liftEncoder = encoder(Brain.ThreeWirePort.B);
limit armLim = limit(Brain.ThreeWirePort.E);

controller mainControl = controller(primary);
controller secondCtrl = controller(partner);

vex::inertial InertialSensor = vex::inertial(vex::PORT8);

motor_group leftDrive = motor_group( FrontLeftMotor, BackLeftMotor );
motor_group rightDrive = motor_group( FrontRightMotor, BackRightMotor );
// define the drivetrain
// this one is a smart drive which uses the InertialSensor
// we have 4 inch wheels
// drive is 14 inches wide between the left and right wheels
// drive has a 10 inch wheelbase (between fron and back wheel axles)
smartdrive    robotDrive = smartdrive( leftDrive, rightDrive, InertialSensor,4*3.14, 15, 10, distanceUnits::in );



void vexcodeInit( void ) {
}
