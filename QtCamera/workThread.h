#pragma once
#include <QThread>
#include "CamCmosOctUsb3.h"
#include <QDebug>
#include <QImage>
#include <opencv2/opencv.hpp>
#include<QtConcurrent/qtconcurrentrun.h>
class workThread : public QThread
{
	Q_OBJECT
public:
	explicit workThread(QObject* parent = 0);

public:
	void run();
	void stream();
	void pause();
	void stop();

signals:
	void getMat(cv::Mat mat);
private:
	
	bool pause_status;
	bool quit;
};

