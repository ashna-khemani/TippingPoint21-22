#include "vex.h"
#include "bot-functions.h"
int anglerStage = 0;  //0 = resting, 1 = deposit started. Cycle between these 2 stages

// hey XD if you need to put more ints here do 'extern int IDK LOL;' in bot-functions.h


void setDrivetoBrake(void){
    BackLeftMotor.setStopping(vex::brakeType::brake);
    FrontLeftMotor.setStopping(vex::brakeType::brake);
    BackRightMotor.setStopping(vex::brakeType::brake);
    FrontRightMotor.setStopping(vex::brakeType::brake);
}

void setDrivetoBrakeType(vex::brakeType brakeValue){
    BackLeftMotor.setStopping(brakeValue);
    FrontLeftMotor.setStopping(brakeValue);
    BackRightMotor.setStopping(brakeValue);
    FrontRightMotor.setStopping(brakeValue);
}
void goFwd(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    BackLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct);
}

void slideFwd(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    setDrivetoBrakeType(coast);
    BackLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct);
    setDrivetoBrakeType(brake);
}


void slideFwdNonBlock(float distance, float velocity){
    setDrivetoBrakeType(coast);
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    BackLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}


void slideBackNonBlock(float distance, float velocity){
    setDrivetoBrakeType(coast);
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    BackLeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    BackRightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}

void goBack(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;

    BackLeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    BackRightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct);
}

void drivePI(double targetDistance) {
  // Brain.Screen.print("HEY BESTIE UWU");
  double motorspeed = 0, currentDistance = 0,
         error = (targetDistance - currentDistance), errorSum = 0, deltaE = 0,
         lastError = 0, maxAllowedError = 1.0, errorTimerMax = 50;
  double kP = 10, kI = 0.0, kD = 15; //working 8,0,20
  bool timerExpired = false;
  timer errorTimer = timer();
  errorTimer.clear();
  FrontRightMotor.resetRotation(); // used front right motor to control driving distance
  FrontLeftMotor.resetRotation();

  while ((fabs(error) > maxAllowedError) && (timerExpired == false)) {
    currentDistance = ((FrontRightMotor.rotation(rotationUnits::deg) +
                        FrontLeftMotor.rotation(rotationUnits::deg)) /
                       2 / 360) *
                      WHEELCIRCUMFERENCE;
    error = targetDistance - currentDistance;
    errorSum += error;
    deltaE = (error - lastError) / 5000;
    //** deltaE = (lastError - error)/-500? How do u get the value of the error
    //at a given time IN EQUAL INTERVALS)??
    motorspeed = (error * kP) + (errorSum * kI) + (deltaE * kD);

    BackLeftMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);
    FrontLeftMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);
    FrontRightMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);
    BackRightMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);

    lastError = error;
    
    if (fabs(error) > maxAllowedError) {
      errorTimer.clear();
    } else {
      if (errorTimer.time() > errorTimerMax) {
        timerExpired = true;
      }
    }
    vex::task::sleep(20);
  }
  BackLeftMotor.stop(brake);
  FrontLeftMotor.stop(brake);
  FrontRightMotor.stop(brake);
  BackRightMotor.stop(brake);
}

void stopDriveTrain(void) {
  BackLeftMotor.stop();
  FrontLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
}

void turnLeft(float degree){
    float numberOfRevs = degree * REVTOANGLELEFT;
    setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct);
    setDrivetoBrakeType(brake);
}

void turnLeftSlow(float degree){
    float numberOfRevs = degree * REVTOANGLELEFT;
    setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct);
    setDrivetoBrakeType(brake);
}

void turnLeftSlowSpeed(float degree, int speedRatio){
    float numberOfRevs = degree * REVTOANGLELEFT;
//    setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    FrontRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    BackRightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct);
//    setDrivetoBrakeType(brake);
}

void turnRight(float degree){
    float numberRev = degree * REVTOANGLERIGHT;
    setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    BackRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct);
    setDrivetoBrakeType(brake);

}


void turnRightSlow(float degree){
    float numberRev = degree * REVTOANGLERIGHT;
    setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    FrontRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    BackRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct);
    setDrivetoBrakeType(brake);

}

void turnRightSlowSpeed(float degree, int speedRatio){
    float numberRev = degree * REVTOANGLERIGHT;
  //  setDrivetoBrakeType(hold);
    BackLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    FrontLeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    FrontRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    BackRightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct);
  //  setDrivetoBrakeType(brake);
}

#define MAX_TURNING_ERROR 1.6//1.0,1.1


void alignToHeading(float targetHeading){
    int count = 0;
    float error = 0;
    float currentHeading = InertialSensor.heading(rotationUnits::deg);
    error = targetHeading - currentHeading;
    if (error < -315) {
      error = error + 360;  //modulo 360
    }

    if (fabs(error) > 45) {
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("aToHd c%f er%f", currentHeading, error);
    //  return;
    }
    setDrivetoBrakeType(brakeType::hold);

    while ((fabs(error) > MAX_TURNING_ERROR) && count < 3) {
	  count++;
      if (error > 0) {        // +ve error means not turned sufficient right
        turnRightSlowSpeed(error, count);
      }
      else{
        turnLeftSlowSpeed(-error, count);
      }
      wait(10, msec);
      currentHeading = InertialSensor.heading(rotationUnits::deg);
      error = targetHeading - currentHeading;
      if (error < -315) {
        error = error + 360;  //modulo 360
      }
    }
    setDrivetoBrakeType(brakeType::hold);
}

// Front MoGo Lift Functions  // TODO chuck these into main preauton and header
void setFrontLiftBrake(vex::brakeType brakeVal){ //TODO: put this in main
  LeftFrontLift.setBrake(brakeVal);
  RightFrontLift.setBrake(brakeVal);
}

bool FrontLiftRunning = false;

void frontLiftUpDrive(){
  if(!FrontLiftRunning){
    LeftFrontLift.spin(directionType::fwd);
    RightFrontLift.spin(directionType::fwd);
    FrontLiftRunning = true;
  }
  else{
    LeftFrontLift.stop();
    RightFrontLift.stop();
    FrontLiftRunning = false;
  }
}

void frontLiftDownDrive(){
  if(!FrontLiftRunning){
    LeftFrontLift.spin(directionType::rev);
    RightFrontLift.spin(directionType::rev);
    FrontLiftRunning = true;
  }
  else{
    LeftFrontLift.stop();
    RightFrontLift.stop();
    FrontLiftRunning = false;
  }
}

void frontLiftUp(double degrees){
  LeftFrontLift.rotateFor(degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
  RightFrontLift.rotateFor(degrees, rotationUnits::deg, 85, velocityUnits::pct, true);
}

void frontLiftDown(double degrees){
  LeftFrontLift.rotateFor(-degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
  RightFrontLift.rotateFor(-degrees, rotationUnits::deg, 85, velocityUnits::pct, true);
}


// ------Back MoGo Lift Functions  // TODO chuck these into main preauton and header
void setBackLiftBrake(vex::brakeType brakeVal){ //TODO: put this in main
  BackLift.setBrake(brakeVal);
}

bool BackLiftRunning = false;

void backLiftUpDrive(){
  if(!BackLiftRunning){
    BackLift.spin(directionType::fwd);
    BackLiftRunning = true;
  }
  else{
    BackLift.stop();
    BackLiftRunning = false;
  }
}

void backLiftDownDrive(){
  if(!BackLiftRunning){
    BackLift.spin(directionType::rev);
    BackLiftRunning = true;
  }
  else{
    BackLift.stop();
    BackLiftRunning = false;
  }
}

void backLiftUp(double degrees){
  BackLift.rotateFor(degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
}

void backLiftDown(double degrees){
  BackLift.rotateFor(-degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
}

void angler_deposit(void){
  if (anglerStage == 0) {
    angler_deposit_stage1();
    anglerStage = 1;
  }
  else{
    angler_deposit_stage2();
    anglerStage = 0;
  }
}

void angler_deposit_stage1(void) {
 BackLift.setBrake(brakeType::hold);
 BackLift.rotateFor(240, rotationUnits::deg,50, velocityUnits::pct, false);
}

void angler_deposit_stage2(void) {
  BackLift.rotateFor(-240, rotationUnits::deg,-50, velocityUnits::pct, false);
}

bool ConveyerRunning = false;
void conveyerBeltFwd(){

  if(!ConveyerRunning){
    ConveyerBelt.spin(directionType::rev);
    ConveyerBelt.setVelocity(-35, velocityUnits::pct);
    ConveyerRunning = true;
  }
  else{
    ConveyerBelt.stop();
    ConveyerRunning = false;
  }
}