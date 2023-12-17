
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
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/



void autonomous(void) {
  /*---------------------------------------------------------------------------*/
  /*                        Offensive Zone(left)                               */
  /*---------------------------------------------------------------------------*/


  // Drivetrain.setDriveVelocity(60,vex::velocityUnits::pct);
  // Drivetrain.setTurnVelocity(50,vex::velocityUnits::pct);

  
  // Drivetrain.driveFor(130, vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(90, vex::rotationUnits::deg,true);
  // Drivetrain.setDriveVelocity(50,vex::velocityUnits::pct);
  // Drivetrain.driveFor(10, vex::distanceUnits::cm,true);

  // wait(500,msec);
  // //spit
  //   leftGrabMotor.setVelocity(-50,vex::pct);
  //   rightGrabMotor.setVelocity(-50,vex::pct);
  //   wait(1500,msec);
  //   Drivetrain.driveFor(5,vex::distanceUnits::cm,true);
  //   leftGrabMotor.setVelocity(0,vex::pct);
  //   rightGrabMotor.setVelocity(0,vex::pct);


  // Drivetrain.driveFor(-15, vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(180,vex::rotationUnits::deg);
  // Drivetrain.driveFor(-15, vex::distanceUnits::cm,true);

  // // Drivetrain.driveFor(reverse,10,vex::distanceUnits::cm,true);
  // // wait(1000,msec);
  // Drivetrain.driveFor(10,vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(-90,vex::rotationUnits::deg);
  // Drivetrain.driveFor(130,vex::distanceUnits::cm,true);

  // //park
  // Drivetrain.turnFor(90,vex::rotationUnits::deg);
  // Drivetrain.setDriveVelocity(100,vex::pct);
  // Drivetrain.driveFor(60,vex::distanceUnits::cm,true);
















//   /*---------------------------------------------------------------------------*/
//   /*                        Defensive Zone(right)                              */
//   /*---------------------------------------------------------------------------*/


  // Drivetrain.setDriveVelocity(60,vex::velocityUnits::pct);
  // Drivetrain.setTurnVelocity(50,vex::velocityUnits::pct);

  
  // Drivetrain.driveFor(130, vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(-90, vex::rotationUnits::deg,true);
  // Drivetrain.setDriveVelocity(50,vex::velocityUnits::pct);
  // Drivetrain.driveFor(10, vex::distanceUnits::cm,true);

  // wait(500,msec);
  // //spit
  //   leftGrabMotor.setVelocity(-50,vex::pct);
  //   rightGrabMotor.setVelocity(-50,vex::pct);
  //   wait(1500,msec);
  //   Drivetrain.driveFor(5,vex::distanceUnits::cm,true);
  //   leftGrabMotor.setVelocity(0,vex::pct);
  //   rightGrabMotor.setVelocity(0,vex::pct);


  // Drivetrain.driveFor(-15, vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(-180,vex::rotationUnits::deg);
  // Drivetrain.driveFor(-15, vex::distanceUnits::cm,true);

  // // Drivetrain.driveFor(reverse,10,vex::distanceUnits::cm,true);
  // // wait(1000,msec);
  // Drivetrain.driveFor(10,vex::distanceUnits::cm,true);
  // Drivetrain.turnFor(90,vex::rotationUnits::deg);
  // Drivetrain.driveFor(130,vex::distanceUnits::cm,true);

  // //park
  // Drivetrain.turnFor(-90,vex::rotationUnits::deg);
  // Drivetrain.setDriveVelocity(100,vex::pct);
  // Drivetrain.driveFor(40,vex::distanceUnits::cm,true);






  // Drivetrain.setDriveVelocity(50,vex::velocityUnits::pct);
  // Drivetrain.driveFor(80,vex::distanceUnits::cm,true);

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
  if(Controller1.ButtonR1.pressing()){
    leftGrabMotor.setVelocity(-100,vex::pct);
  }else{
    leftGrabMotor.setVelocity(0,vex::pct);
  }
}

void test(){
  /*---------------------------------------------------------------------------*/
  /*                        Offensive Zone(left)                               */
  /*---------------------------------------------------------------------------*/
  Drivetrain.setDriveVelocity(50,vex::velocityUnits::pct);
  Drivetrain.setTurnVelocity(50,vex::velocityUnits::pct);

  
  Drivetrain.driveFor(170, vex::distanceUnits::cm,true);
  Drivetrain.turnFor(90, vex::rotationUnits::deg,true);
  Drivetrain.setDriveVelocity(50,vex::velocityUnits::pct);
  Drivetrain.driveFor(10, vex::distanceUnits::cm,true);

  wait(500,msec);
  //spit
  leftGrabMotor.setVelocity(-50,vex::pct);
  rightGrabMotor.setVelocity(-50,vex::pct);
  wait(1500,msec);
  Drivetrain.driveFor(5,vex::distanceUnits::cm,true);
  leftGrabMotor.setVelocity(0,vex::pct);
  rightGrabMotor.setVelocity(0,vex::pct);


  Drivetrain.driveFor(-10, vex::distanceUnits::cm,true);
  Drivetrain.turnFor(180,vex::rotationUnits::deg);
  wait(1000,msec);

  // Drivetrain.driveFor(reverse,10,vex::distanceUnits::cm,true);
  // wait(1000,msec);
  Drivetrain.setDriveVelocity(100,vex::pct);
  Drivetrain.driveFor(-15,vex::distanceUnits::cm,true);
  Drivetrain.turnFor(-90,vex::rotationUnits::deg);
  Drivetrain.setDriveVelocity(50,vex::pct);
  Drivetrain.driveFor(100,vex::distanceUnits::cm,true);
}


//----------------------------------------------------------------------------------


void usercontrol(void) {
  // User control code here, inside the loop
  initMotors();
  //test();
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




