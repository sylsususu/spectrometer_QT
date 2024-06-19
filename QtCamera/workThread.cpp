#include "workThread.h"

extern tCameraInfo CameraInfo;

extern CAM_HANDLE hCamera;

#define MAX_TIMEOUT_ACQ_IN_MS				3000

workThread::workThread(QObject* parent) :
	QThread(parent)
{
	pause_status = true;
	quit = false;
	qRegisterMetaType<cv::Mat>("cv::Mat");

}

void workThread::run()
{
	quit = false;

	forever
	{
		if (!pause_status)
		{
			
			//start
			size_t iImageHeight = 100;
			size_t iNbOfBuffer = 30;
			if (USB3_SetImageParameters(hCamera, iImageHeight, iNbOfBuffer) != CAM_ERR_SUCCESS)
			{
				qDebug() << "USB3_SetImageParameters Error!";
			}
				
			if (CAM_ERR_SUCCESS==USB3_StartAcquisition(hCamera))
			{
				qDebug() << "USB3_StartAcquisition";
				tImageInfos ImageInfos;
				unsigned long ulNBImageAcquired = 0;

				tContextDataPerLine ContextDataPerLine;
				bool bFirstCounter = true;
				unsigned short u16MemoLineCounter = 0;
				while (1)
				{
					if (quit)
					{
						break;
					}
					int nError = USB3_GetBuffer(hCamera, &ImageInfos, MAX_TIMEOUT_ACQ_IN_MS);
					if (nError != CAM_ERR_SUCCESS)
					{
						qDebug() << "USB3_GetBuffer Error!" << nError;
						continue;
					}
					ulNBImageAcquired++;
					qDebug() << "Nb Image Acquired=" << ulNBImageAcquired;

					//test
					int type = CV_16UC1;
					uchar *data = static_cast<uchar*>(ImageInfos.pDatas);
					cv::Mat dst = cv::Mat(ImageInfos.iImageWidth, ImageInfos.iImageHeight, type, data);
					emit getMat(dst);
					// ******************************************
				// Do something with image ...
				// ImageInfos.pDatas => contains raw data buffers
				// ImageInfos.iImageWidth;
				// ImageInfos.iImageHeight;
				// ImageInfos.eImagePixelType;
				// ImageInfos.iImageSize
				// ImageInfos.iLinePitch
				// ImageInfos.iOffsetX;
				// ImageInfos.iHorizontalFlip;
				// ImageInfos.iNbMissedTriggers;
				// ImageInfos.iNbLineLost;
				// ImageInfos.iNbImageAcquired;
				// ******************************************

				// For example: check frame Contextual data and check that not lines were lost
					for (unsigned long ulLineNumber = 0; ulLineNumber < iImageHeight; ulLineNumber++)
					{
						nError = USB3_GetLineContextualData(hCamera, &ImageInfos, &ContextDataPerLine, ulLineNumber);
						if (nError != CAM_ERR_SUCCESS)
						{
							qDebug() << "USB3_GetLineContextualData Error!" << nError;
						}

						if (bFirstCounter)
						{
							bFirstCounter = false;
							qDebug() << "First LineCounter=" << ContextDataPerLine.u16LineCounter;
							
						}
						else
						{
							if (ContextDataPerLine.u16LineCounter != static_cast<unsigned short>(u16MemoLineCounter + 1))
							{
								
								qDebug() << "ImageInfos.iNbLineLost=" << ImageInfos.iNbLineLost;
							}
						}

						u16MemoLineCounter = ContextDataPerLine.u16LineCounter;
					}

					if (nError == CAM_ERR_SUCCESS)
					{
						nError = USB3_RequeueBuffer(hCamera, ImageInfos.hBuffer);
						if (nError != CAM_ERR_SUCCESS)
						{
							qDebug() << "USB3_RequeueBuffer Error!" << nError;
						}
							
					}


				}
				
				int nError = USB3_StopAcquisition(hCamera);
				if (nError != CAM_ERR_SUCCESS)
				{
					qDebug() << "USB3_StopAcquisition Error!" << nError;
				}
					

				

			}
			
			int nError = USB3_FlushBuffers(hCamera);
			if (nError != CAM_ERR_SUCCESS)
			{
				qDebug() << "USB3_FlushBuffers Error!" << nError;
			}
				
			break;


		}
		else
			usleep(1000);



	}

}

void workThread::stream()
{
	pause_status = false;
}

void workThread::pause()
{
	pause_status = true;
}

void workThread::stop()
{
	pause_status = false;
	quit = true;
}
