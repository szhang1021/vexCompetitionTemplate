
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  vexcodeInit();

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  
  Drivetrain.setDriveVelocity(100,vex::velocityUnits::pct);
  Drivetrain.driveFor(1000, vex::distanceUnits::mm,true);
  wait(3000,msec);
  Drivetrain.turnToHeading(90,vex::rotationUnits::deg,true);

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

void initMotors(){
  LeftDriveSmart.setVelocity(0,vex::pct);
  LeftDriveSmart.spin(forward);

  RightDriveSmart.setVelocity(0,vex::pct);
  RightDriveSmart.spin(forward);

  leftGrabMotor.setVelocity(0,vex::pct);
  leftGrabMotor.spin(forward);

  rightGrabMotor.setVelocity(0,vex::pct);
  rightGrabMotor.spin(forward);

  RightDriveSmart.resetPosition();
  LeftDriveSmart.resetPosition();
}

void teleDrive(){
  LeftDriveSmart.setVelocity(Controller1.Axis3.position(vex::pct),vex::pct);
  RightDriveSmart.setVelocity(Controller1.Axis2.position(vex::pct),vex::pct);
}

void grab(){
  if(Controller1.ButtonL1.pressing()){
    leftGrabMotor.setVelocity(50,vex::pct);
    rightGrabMotor.setVelocity(50,vex::pct);
  }
  else if(Controller1.ButtonR1.pressing()){
    leftGrabMotor.setVelocity(-50,vex::pct);
    rightGrabMotor.setVelocity(-50,vex::pct);
  }else{
    leftGrabMotor.setVelocity(0,vex::pct);
    rightGrabMotor.setVelocity(0,vex::pct);
  }
}

//-----------------custom auton drive----------------------------------------------


// float position = 0;

// /*****/ float wheel_radius = 0.05; // need to measure and change, consider gear ratios
// /*****/ int ticks; // number of ticks from encoder

// int distance = 50; // target distance is in m

float vel = 50;

// void vex::timer::reset();

void autonDrive(){

  // Brain.Timer;
  // while(Brain.Timer. <= milliseconds){
  //   LeftDriveSmart.setVelocity(vel,vex::pct);
  //   RightDriveSmart.setVelocity(vel,vex::pct);
  // }

  // LeftDriveSmart.setVelocity(0,vex::pct);
  // RightDriveSmart.setVelocity(0,vex::pct);

}


//----------------------------------------------------------------------------------


void usercontrol(void) {
  // User control code here, inside the loop
  initMotors();

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    
    teleDrive();
    grab();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
  initMotors();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
