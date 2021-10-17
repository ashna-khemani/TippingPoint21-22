#define TURNING_SPEED       65 //45
#define SLOW_TURNING_SPEED  20
#define WHEELDIAMETER       4.0      // Wheel diameter in inches
#define WHEELCIRCUMFERENCE  (WHEELDIAMETER * 3.145)
#define REVTOANGLERIGHT      (1.0/89.5)   //1 rotations to turn 93.5 degrees
#define REVTOANGLELEFT      (1.0/87.5)   //1 rotations to turn 91.25 degrees 87.5

#define TURN_WEIGHT     0.75  // Reduce turning sensitivity when driving. Forward/backward are not affected //april 11 was .6
#define DRIVE_WEIGHT    0.9  // Reduce driving sensitivity when driving. Forward/backward are not affected ap 11 .9

// Drive function declarations
void setDrivetoBrakeType(vex::brakeType brakeValue);
void goFwd(float distance, float velocity);
void slideFwd(float distance, float velocity);
void slideFwdNonBlock(float distance, float velocity);
void slideBackNonBlock(float distance, float velocity);
void setDrivetoBrake(void);
void stopDriveTrain(void);
void turnLeft(float degree);
void turnRight(float degree);
void alignToHeading(float targetHeading);
void drivePI(double targetDistance);

// Lift functions declarations
void setLiftBrake(vex::brakeType brakeVal);
void liftUpDrive(void);
void liftDownDrive(void);

void liftUp(double degrees);
void liftDown(double degrees);