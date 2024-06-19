#pragma once

#include <QtWidgets/QDialog>
#include <QDateTime>
#include <QLineEdit>
#include <QString>
#include <opencv2/opencv.hpp>
#include<QtConcurrent/qtconcurrentrun.h>

#include "ui_QtCamera.h"

#include "CamCmosOctUsb3.h"
#include "workThread.h"
#include"qcustomplot.h"
using namespace cv;
class QtCamera : public QDialog
{
    Q_OBJECT

public:
    QtCamera(QWidget *parent = nullptr);
    ~QtCamera();
protected:
	bool eventFilter(QObject* obj, QEvent* event);
private:
    Ui::QtCameraClass ui;
private:
	void initCmaera();
	void initCameraCom();
	//日志相关
	void addLogEntry(const QString &logMessage, QTextEdit *textEdit);
	void clearLog(QTextEdit *textEdit);
	void ClearLog();
	void connectCam();
	void disConnectCam();
	void initCameraValue();
	void setExposureTime(QString time);
	void setCameraWidth(QString time);
	void startWork();
	void stopWork();

public slots:
	
	void processMat(cv::Mat showMat);
	
private:
	workThread *workthread;
};
