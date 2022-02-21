// Const.s for auton
#define TURNING_SPEED       50 //65->50
#define TURNING_SPEED_SLOW  32
#define SLOW_TURNING_SPEED  20
#define WHEELDIAMETER       4.0      // Wheel diameter in inches
#define WHEELCIRCUMFERENCE  (WHEELDIAMETER * 3.145)
#define REVTOANGLERIGHT      (1.0/103)   //1 rotations to turn 93.5 degrees //100-103-95??
#define REVTOANGLELEFT      (1.0/105)   //1 rotations to turn 91.25 degrees 87.5 ->85 //1-5->108?? trying this
 

// Driving Weights
#define TURN_WEIGHT     0.75
#define AVAS_TURN_WEIGHT 0.6
#define DRIVE_WEIGHT    0.9

// Global variable
extern int ClawMotorRunning;

// Drive function declarations
void stopDriveTrain(void);
void setDrivetoBrakeType(vex::brakeType brakeValue);

void goFwd(float distance, float velocity);
void slideFwd(float distance, float velocity);
void slideFwdNonBlock(float distance, float velocity);
void goBack(float distance, float velocity);
void slideBackNonBlock(float distance, float velocity);

void turnLeft(float degree);
void turnRight(float degree);
void turnRightSlow(float degree);
void turnLeftSlow(float degree);
void alignToHeading(float targetHeading);
void drivePD(double targetDistance);
//void drivePDStraight(double targetDistance);


// Front Lift functions declarations
void setFrontLiftBrake(vex::brakeType brakeVal);
void frontLiftUpDrive(void);
void frontLiftDownDrive(void);

void frontLiftUp(double degrees);
void frontLiftDown(double degrees);
void frontLiftUpAuto();
void frontLiftDownAuto();
void frontLiftDownDegreesAuto(double degrees);


// Back Lift function declarations
void setBackLiftBrake(vex::brakeType brakeVal);
void backLiftUpDrive(void);
void backLiftDownDrive(void);

void backLiftUp(double degrees);
void backLiftDown(double degrees);

void backLiftAuto(void);
void backLiftUpNonBlocking(double degrees);
void backLiftDownNonBlocking(double degrees);
void backLiftAuto_stage1(void);
void backLiftAuto_stage2(void);


// Conveyor Belt function declarations
void conveyorBeltFwdDrive(void);
void conveyorBeltBackDrive(void);
void conveyorBeltFwd();
void conveyorBeltBack();


// Claw function declarations
void clawOpen();
void clawClose();
void clawDrive(void);
void setClawBrake(vex::brakeType brakeVal);


// Back Clamp function declarations
void backClampOpen();
void backClampClose();
void backClampDrive();


void autoBalance();
