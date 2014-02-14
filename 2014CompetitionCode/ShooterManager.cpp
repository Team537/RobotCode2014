#include "ShooterManager.h"
#include "Schematic.h"
#include "NameSchematic.h"
#include <cmath>

void ShooterManager::PracticeShooter(float ShooterAxis, int GoalButton)
{
	if (fabs(ShooterAxis) < 0.1)
		ShooterAxis = 0;
	ShooterMotor.Set(ShooterAxis);
	if ((GoalButton == 1) && (Safe == true))
	{
		ShooterMotorShifter.Set(0);
		ShooterMotor.Set(-.5);
	}
}
/*void ShooterManager::StartShooterAuto ()
{
	ShooterState = 3;
}
void ShooterManager::StartShooterTeleop ()
{
	ShooterState = 1;
}
void ShooterManager::RunShooter (int PrimeButton, int GoalButton, int TrussButton)
{
	RunPrime (PrimeButton);
	RunGoalShot (GoalButton);
	RunTrussShot (TrussButton);
}
void ShooterManager::RunPrime (int PrimeBtn)
{
	if ((PrimeBtn == PRESSED) && (ShooterState == 1) && (Safe == true))
	{
		ShooterState = 2;
		ShooterMotor.Set(-1);
	}
	else if ((ShooterState == 2) && (ShooterLimitSwitch.Get() == PRESSED) && (Safe == true))
	{
		ShooterState = 3;
		Flappers.Set(FLAPPERS_ON);
		ShooterMotor.Set(0);
	}
}
void ShooterManager::RunGoalShot (int GoalBtn)
{
	if ((GoalBtn == PRESSED) && (ShooterState == 3) && (Safe == true))
	{
		ShooterState = 4;
	}
	else if ((ShooterState == 4) && (Safe == true))
	{
		ShooterMotor.Set(-1);
		Flappers.Set(FLAPPERS_OFF);
		ShooterTimer.Stop();
		ShooterTimer.Reset();
	}
	else if ((ShooterState == 4) && (ShooterLimitSwitch.Get() == PRESSED) && (Safe == true))
	{
		ShooterState = 5;
		ShooterMotorShifter.Set(0);
		ShooterMotor.Set(1);  // THROW THE BALL
	}
	else if ((ShooterState == 5) && (ShooterTimer.Get() > 1) && (Safe == true))
	{
		ShooterState = 1;
		ShooterMotorShifter.Set(1);
	}
}
void ShooterManager::RunTrussShot (int TrussBtn)
{
	if ((TrussBtn == PRESSED) && (ShooterState == 3) && (Safe == true))
		{
			ShooterState = 4;
		}
		else if ((ShooterState == 4) && (Safe == true))
		{
			ShooterMotor.Set(-1);
			Flappers.Set(FLAPPERS_OFF);
			ShooterTimer.Stop();
			ShooterTimer.Reset();
		}
		else if ((ShooterState == 4) && (ShooterLimitSwitch.Get() == PRESSED) && (Safe == true))
		{
			ShooterState = 5;
			ShooterEncoder.Reset();
			ShooterEncoder.Start();
			ShooterMotor.Set(0);
		}
		else if ((ShooterState == 5) && (Safe == true) && (ShooterEncoder.Get() >= TRUSS_ENCODER_SPOT))
		{
			ShooterMotorShifter.Set(0);
			ShooterMotor.Set(1);  // THROW THE BALL
		}
		else if ((ShooterState == 5) && (ShooterTimer.Get() > 1) && (Safe == true))
		{
			ShooterState = 1;
			ShooterMotorShifter.Set(1);
		}
}*/


