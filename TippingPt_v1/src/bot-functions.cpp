#include "vex.h"
#include "bot-functions.h"


// hey XD if you need to put more ints here do 'extern int IDK LOL;' in bot-functions.h -- declare them using 'extern' in header file


void setDrivetoBrake(void){
    LeftMotor.setStopping(vex::brakeType::brake);
    RightMotor.setStopping(vex::brakeType::brake);
}

void setDrivetoBrakeType(vex::brakeType brakeValue){
    LeftMotor.setStopping(brakeValue);
    RightMotor.setStopping(brakeValue);
}
void goFwd(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    LeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    RightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct);
}

void slideFwd(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    setDrivetoBrakeType(coast);
    LeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    RightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct);
    setDrivetoBrakeType(brake);
}


void slideFwdNonBlock(float distance, float velocity){
    setDrivetoBrakeType(coast);
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    LeftMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    RightMotor.rotateFor(numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}


void slideBackNonBlock(float distance, float velocity){
    setDrivetoBrakeType(coast);
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;
    LeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    RightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}

void goBack(float distance, float velocity){
    float numberDeg;
    numberDeg = (distance/WHEELCIRCUMFERENCE)*360;

    LeftMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
    RightMotor.rotateFor(directionType:: rev, numberDeg,rotationUnits::deg,velocity,velocityUnits::pct, false);
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
  RightMotor.resetRotation(); // used front right motor to control driving distance
  LeftMotor.resetRotation();

  while ((fabs(error) > maxAllowedError) && (timerExpired == false)) {
    currentDistance = ((RightMotor.rotation(rotationUnits::deg) +
                        LeftMotor.rotation(rotationUnits::deg)) /
                       2 / 360) *
                      WHEELCIRCUMFERENCE;
    error = targetDistance - currentDistance;
    errorSum += error;
    deltaE = (error - lastError) / 5000;
    //** deltaE = (lastError - error)/-500? How do u get the value of the error
    //at a given time IN EQUAL INTERVALS)??
    motorspeed = (error * kP) + (errorSum * kI) + (deltaE * kD);

    LeftMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);
    RightMotor.spin(directionType::fwd, motorspeed, velocityUnits::pct);

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
  LeftMotor.stop(brake);
  RightMotor.stop(brake);
}

void stopDriveTrain(void) {
  LeftMotor.stop();
  RightMotor.stop();
}

void turnLeft(float degree){
    float numberOfRevs = degree * REVTOANGLELEFT;
    setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    RightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}

void turnLeftSlow(float degree){
    float numberOfRevs = degree * REVTOANGLELEFT;
    setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    RightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);
}

void turnLeftSlowSpeed(float degree, int speedRatio){
    float numberOfRevs = degree * REVTOANGLELEFT;
//    setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(directionType::rev, numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    RightMotor.rotateFor(numberOfRevs,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
//    setDrivetoBrakeType(brake);
}

void turnRight(float degree){
    float numberRev = degree * REVTOANGLERIGHT;
    setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    RightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);

}


void turnRightSlow(float degree){
    float numberRev = degree * REVTOANGLERIGHT;
    setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    RightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/2,velocityUnits::pct, false);
    setDrivetoBrakeType(brake);

}

void turnRightSlowSpeed(float degree, int speedRatio){
    float numberRev = degree * REVTOANGLERIGHT;
  //  setDrivetoBrakeType(hold);
    LeftMotor.rotateFor(numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
    RightMotor.rotateFor(directionType::rev, numberRev,rotationUnits::rev,TURNING_SPEED/(1+speedRatio),velocityUnits::pct, false);
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
  LeftBackLift.setBrake(brakeVal);
  RightBackLift.setBrake(brakeVal);
}

bool BackLiftRunning = false;

void backLiftUpDrive(){
  if(!BackLiftRunning){
    LeftBackLift.spin(directionType::fwd);
    RightBackLift.spin(directionType::fwd);
    BackLiftRunning = true;
  }
  else{
    LeftBackLift.stop();
    RightBackLift.stop();
    BackLiftRunning = false;
  }
}

void backLiftDownDrive(){
  if(!BackLiftRunning){
    LeftBackLift.spin(directionType::rev);
    RightBackLift.spin(directionType::rev);
    BackLiftRunning = true;
  }
  else{
    LeftBackLift.stop();
    RightBackLift.stop();
    BackLiftRunning = false;
  }
}

void backLiftUp(double degrees){
  LeftBackLift.rotateFor(degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
  RightBackLift.rotateFor(degrees, rotationUnits::deg, 85, velocityUnits::pct, true);
}

void backLiftDown(double degrees){
  LeftBackLift.rotateFor(-degrees, rotationUnits::deg, 85, velocityUnits::pct, false);
  RightBackLift.rotateFor(-degrees, rotationUnits::deg, 85, velocityUnits::pct, true);
}
