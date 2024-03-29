#include "WPILib.h"
#include "Schematic.h"
#include "CompressorManager.h"
#include "DriveTrainManager.h"
#include "Shooter.h"
#include "NameSchematic.h"
#include "CandyShooter.h"
//#include "BasketBallShooterManager.h"
#include <string>

class RobotDemo : public SimpleRobot
{
private:
	
	Joystick PrimaryController;
	DigitalInput ShooterType;
	CompressorManager comp;
	DriveTrainManager DriveTrain;
	Shooter Shoot;
	CandyShooter CandyShotter;
	//BasketBallShooterManager BasketBallManager;
	
public:
	RobotDemo(void):
		PrimaryController(PRIMARY_CONTROLLER),
		ShooterType(SHOOT_TYPE)
	{

	}

	void Autonomous()
	{
	
	}


	void OperatorControl()
	{
		DriveTrain.StartDriveTrain();
		while (IsOperatorControl())
		{
			comp.checkCompressor();
			DriveTrain.RunDriveTrain(PrimaryController.GetRawAxis(JOYSTICK_FORWARD), PrimaryController.GetRawAxis(JOYSTICK_TWIST), (int)PrimaryController.GetRawButton(SHIFT_HIGH), (int)PrimaryController.GetRawButton(SHIFT_LOW), (int)PrimaryController.GetRawButton(HALF_SPEED_BUTTON));
			//CandyShotter.FireCandy(PrimaryController.GetRawButton(RIGHT_SHOOT_BTN), PrimaryController.GetRawButton(LEFT_SHOOT_BTN));
			//BasketBallManager.RunBasketBallShooterManager(PrimaryController.GetRawButton(TOGGLE_FLY_WHEEL), PrimaryController.GetRawButton(SHROUD_UP),  PrimaryController.GetRawButton(SHROUD_DOWN), PrimaryController.GetRawButton(BUTTON_FEEDER));
			Shoot.runShooter(PrimaryController.GetRawButton(SHOOT_BUTTON), PrimaryController.GetRawButton(FLY_WHEEL_TOGGLE), PrimaryController.GetRawButton(ANGLE_UP), PrimaryController.GetRawButton(ANGLE_DOWN));
			/*if (ShooterType.Get() == 1)
			{
				Frisbee.runFrisbeeShooter(PrimaryController.GetRawButton(SHOOT_BUTTON), PrimaryController.GetRawButton(FLY_WHEEL_TOGGLE), PrimaryController.GetRawButton(ANGLE_UP), PrimaryController.GetRawButton(ANGLE_DOWN));
			}
			if (ShooterType.Get() == 0)
			{*/
				//Basketball.runBasketballShooter(PrimaryController.GetRawButton(B_FLY_WHEEL_TOGGLE), PrimaryController.GetRawButton(B_ANGLE_UP), PrimaryController.GetRawButton(B_ANGLE_DOWN), PrimaryController.GetRawButton(COLLECTOR));
			//}
			SmartDashboard::PutNumber("Joystick Forward", PrimaryController.GetRawAxis(JOYSTICK_FORWARD));
			SmartDashboard::PutNumber("Joystick Sideways", PrimaryController.GetRawAxis(JOYSTICK_TWIST));
			
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
