#ifndef SCHEMATIC_H
#define SCHEMATIC_H

// Primary Controller
#define PRIMARY_CONTROLLER 1
#define SECONDARY_CONTROLLER 2
#define LEFT_JOYSTICK 2
#define RIGHT_JOYSTICK 4
#define BUTTON_COLLECT_IN 2
#define BUTTON_COLLECT_STOP 3
#define BUTTON_COLLECT_OUT 4
#define BUTTON_COLLECT_OUT2 12
#define BUTTON_COLLECTOR_RETRACT 5
#define BUTTON_COLLECTOR_DEPLOY 6
#define BUTTON_LOW_DRIVE_SHIFT 7
#define BUTTON_HIGH_DRIVE_SHIFT 8

// Secondary Controller
#define BUTTON_GOAL_SHOT 5
#define BUTTON_RESET_SHOT 6
#define LEFT_JOYSTICK 2
#define BUTTON_LATCH_ON 1
#define BUTTON_LATCH_OFF 2
#define BUTTON_CHARGE_SHOOTER 3
#define BUTTON_BACK 9
#define BUTTON_START 10
#define BUTTON_PID_DISABLE 3

// Robot Victors
#define LEFT_DRIVE_MOTOR 1,1
#define RIGHT_DRIVE_MOTOR 1,2
#define COLLECTOR_MOTOR 1,3
#define SHOOTER_MOTOR 1,4

// Robot Compressor
#define COMPRESSOR_SWITCH 1,2
#define COMPRESSOR_RELAY 1,7

// Robot Digital Inputs
#define AUTONOMOUS_SWITCH 1,2
#define RIGHT_DRIVE_ENCODER 1,3,1,4
#define LEFT_DRIVE_ENCODER 1,5,1,6
#define SHOOTER_ENCODER 1,7,1,8
#define SHOOTER_LIMIT_SWITCH 1,12

// Robot Digital Outputs
#define DRIVE_SHIFT 1,1
#define COLLECTOR_RETRACT 1,2
#define COLLECTOR_DEPLOY 1,3
#define SHOOTER_MOTOR_SHIFTER 1,4
#define SHOOTER_CHARGE 1,5
#define LATCH 1,6

#define LEFT_DRIVE_DIRECTION 1
#define RIGHT_DRIVE_DIRECTION -1

// Robot Drive Directions - PRACTICE SETTINGS
//#define LEFT_DRIVE_PID 0.015
//#define RIGHT_DRIVE_PID -0.02
//#define LEFT_PID_ADJUST -1
//#define RIGHT_PID_ADJUST -1

// Robot Drive Directions - COMPETITION SETTINGS
#define LEFT_DRIVE_PID -0.015
#define RIGHT_DRIVE_PID -0.015
#define LEFT_PID_ADJUST 1
#define RIGHT_PID_ADJUST -1


#endif
