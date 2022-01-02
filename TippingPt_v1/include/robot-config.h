//#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
extern brain  Brain;

// VEXcode device constructors

extern motor BackLeftMotor;
extern motor BackRightMotor;
extern motor FrontLeftMotor;
extern motor FrontRightMotor;

extern motor FrontLift;

extern motor BackLift;
extern motor ConveyorBelt;

extern motor Claw;

extern pneumatics Pist;

extern controller mainControl;
extern controller secondCtrl;
extern vex::inertial InertialSensor;
extern motor_group   leftDrive;
extern motor_group   rightDrive;
extern smartdrive    robotDrive;



// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) ;
