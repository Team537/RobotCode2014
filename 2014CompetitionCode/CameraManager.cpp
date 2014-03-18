#include "CameraManager.h"
#include "Schematic.h"
#include "NameSchematic.h"
#include "nivision.h"
#include "WPILib.h"

bool CameraManager::IsHotGoal()
{
		AxisCamera& camera = AxisCamera::GetInstance();
		SmartDashboard::PutNumber("counter", Counter);

		/*if (!camera.IsFreshImage())
		{
			SmartDashboard::PutString("Image", "Not Fresh");
			return LastValue;
		}*/
		if(Counter * Rate >= CameraTimer.Get())
		{
			return LastValue;
		}
	
		ColorImage *CurrentImage = camera.GetImage();
		/*if (Counter == 16)
		{
			CurrentImage->Write("AutoImage1.bmp");	
		}
		if (Counter == 32)
		{
			CurrentImage->Write("AutoImage2.bmp");
		}*/
		SmartDashboard::PutString("Image", "Fresh");	
		BinaryImage* ThresholdImage = CurrentImage->ThresholdHSL(15, 55, 50, 255, 50, 255);
		ImageInfo info;
		Image *img = ThresholdImage->GetImaqImage();
		imaqGetImageInfo(img, &info);
		
		int yellowCount = 0;
		unsigned char * pixels = (unsigned char *) info.imageStart;
		int y, x;
		for (y = 0; y < info.yRes; y++){
			for (x = 0; x < info.xRes; x++){
				int bitmapIndex = (info.pixelsPerLine *y) + x;
				if (pixels[bitmapIndex] == 1)
				{
					yellowCount++;
				}
			}
		}
		SmartDashboard::PutNumber("y res", y);
		SmartDashboard::PutNumber("x res", x);
		LastValue = yellowCount > YELLOW_PIXEL_THRESHOLD;
		
		SmartDashboard::PutNumber("Yellow Count", yellowCount);
		delete CurrentImage;
		delete ThresholdImage;
		Counter++;
		return LastValue;
	}
	void CameraManager::CameraInitialize()
	{
		AxisCamera& camera = AxisCamera::GetInstance();
	}
	void CameraManager::CameraStart()
	{
		
		CameraTimer.Start();
	}
	void CameraManager::CameraStop()
	{
		CameraTimer.Stop();
		CameraTimer.Reset();
		AxisCamera::DeleteInstance();
	}

//  rcoe@wi.rr.com
//   first4me2011  

