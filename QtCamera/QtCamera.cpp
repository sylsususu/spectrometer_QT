#include "QtCamera.h"

tCameraInfo CameraInfo;
CAM_HANDLE hCamera = NULL;

QtCamera::QtCamera(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
	initCmaera();
	initCameraCom();
	workthread = new workThread();
	// 在你的类的构造函数中安装事件过滤器
	ui.comboBox_camera->installEventFilter(this);
	// 将textEdit_Log设置为只读模式
	ui.textEdit_Log->setReadOnly(true);

	ui.pushButton_start->setEnabled(false);
	ui.pushButton_stop->setEnabled(false);

	connect(ui.pushButton_ClearLog, &QPushButton::clicked, this, &QtCamera::ClearLog);
	connect(ui.pushButton_connectCamera, &QPushButton::clicked, this, &QtCamera::connectCam);
	ui.pushButton_disConnectCamera->setEnabled(false);
	connect(ui.pushButton_disConnectCamera, &QPushButton::clicked, this, &QtCamera::disConnectCam);
	connect(ui.lineEdit_expTime, &QLineEdit::textChanged, this, &QtCamera::setExposureTime);
	connect(ui.lineEdit_cameraWidth, &QLineEdit::textChanged, this, &QtCamera::setCameraWidth);
	connect(ui.pushButton_start, &QPushButton::clicked, this, &QtCamera::startWork);
	connect(ui.pushButton_stop, &QPushButton::clicked, this, &QtCamera::stopWork);
	connect(workthread, &workThread::getMat, this, &QtCamera::processMat, Qt::QueuedConnection);

	/////////////////////坐标图CustomPlot初始化显示/////////////////////////////
	QBrush brush(QColor(6, 111, 217));
	ui.widget->xAxis->setBasePen(QPen(brush, 2));
	ui.widget->yAxis->setBasePen(QPen(brush, 2));
	ui.widget->xAxis->setTickPen(QPen(brush, 2));
	ui.widget->yAxis->setTickPen(QPen(brush, 2));
	ui.widget->setBackground(QBrush(QColor(0, 0, 0)));
	ui.widget->yAxis->setTickLabels(true);
	ui.widget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	ui.widget->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	ui.widget->xAxis->setSubTickPen(QPen(brush, 2));
	ui.widget->yAxis->setSubTickPen(QPen(brush, 2));

	QFont f;
	f.setPixelSize(18);
	f.setFamily("SimHei");
	ui.widget->xAxis->setLabelFont(f);
	ui.widget->xAxis->setLabelColor(QColor(Qt::white));
	ui.widget->yAxis->setLabelFont(f);
	ui.widget->yAxis->setLabelColor(QColor(Qt::white));
	QFont f_Tick;
	f_Tick.setPixelSize(14);
	f_Tick.setFamily("SimHei");
	ui.widget->xAxis->setTickLabelColor(Qt::white);
	ui.widget->yAxis->setTickLabelColor(Qt::white);
	ui.widget->xAxis->setTickLabelFont(f_Tick);
	ui.widget->yAxis->setTickLabelFont(f_Tick);
	//ui.widget->addGraph();
	ui.widget->xAxis->setLabel("Column");
	ui.widget->yAxis->setLabel("Pixel Value");
	ui.widget->setInteractions(QCP::iRangeZoom | QCP::Interaction::iRangeDrag | QCP::iSelectPlottables | QCP::iMultiSelect);
	ui.widget->yAxis->setRange(0,4096);
	ui.widget->xAxis->setRange(0,2048);
	ui.widget->replot();
	
}

QtCamera::~QtCamera()
{}

bool QtCamera::eventFilter(QObject * obj, QEvent * event)
{
	if (obj == ui.comboBox_camera) // 检查是否是你想要处理的控件
	{
		//qDebug() << event;
		if (event->type() == QEvent::MouseButtonPress) // 检查事件类型
		{
			// 处理鼠标按下事件
			initCameraCom();

		}
	}
	return QWidget::eventFilter(obj, event);
}

void QtCamera::initCmaera()
{
	addLogEntry("USB3_InitializeLibrary", ui.textEdit_Log);
	int nError = USB3_InitializeLibrary();
	if (nError != CAM_ERR_SUCCESS)
	{
		addLogEntry("USB3_InitializeLibrary Error!", ui.textEdit_Log);
	}
}

void QtCamera::initCameraCom()
{
	unsigned long ulNbCameras;
	addLogEntry("USB3_UpdateCameraList", ui.textEdit_Log);
	int nError = USB3_UpdateCameraList(&ulNbCameras);
	if (nError != CAM_ERR_SUCCESS)
	{
		addLogEntry("USB3_UpdateCameraList Error!", ui.textEdit_Log);
	}
	addLogEntry("USB3_UpdateCameraList Error!", ui.textEdit_Log);
	QString logEntry = QString::number(ulNbCameras) + "camera(s) found";
	addLogEntry(logEntry, ui.textEdit_Log);

	for (unsigned long ulIndex = 0; ulIndex < ulNbCameras; ulIndex++)
	{
	
		nError = USB3_GetCameraInfo(ulIndex, &CameraInfo);
		if (nError == CAM_ERR_SUCCESS)
		{
			ui.comboBox_camera->addItem(CameraInfo.pcID);
		}
		
	}
	
}

void QtCamera::addLogEntry(const QString & logMessage, QTextEdit * textEdit)
{
	// 获取当前时间
	QDateTime currentDateTime = QDateTime::currentDateTime();
	QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

	// 构建日志条目，包括时间、操作内容和换行
	QString logEntry = currentDateTimeString + " - " + logMessage;
	// 将日志条目追加到QTextEdit中
	textEdit->append(logEntry);
}

void QtCamera::clearLog(QTextEdit * textEdit)
{
	textEdit->clear();
}

void QtCamera::ClearLog()
{
	clearLog(ui.textEdit_Log);
}

void QtCamera::connectCam()
{
	addLogEntry("USB3_OpenCamera", ui.textEdit_Log);
	int nError = USB3_OpenCamera(&CameraInfo, &hCamera);
	if (nError != CAM_ERR_SUCCESS)
	{
		addLogEntry("USB3_OpenCamera Error!", ui.textEdit_Log);
	}
	else
	{
		
		ui.pushButton_connectCamera->setEnabled(false);
		ui.pushButton_disConnectCamera->setEnabled(true);
		ui.pushButton_start->setEnabled(true);
		//连接相机成功，初始化界面变量
		initCameraValue();
	}
}

void QtCamera::disConnectCam()
{
	addLogEntry("USB3_CloseCamera", ui.textEdit_Log);
	int nError = USB3_CloseCamera(hCamera);
	if (nError != CAM_ERR_SUCCESS)
	{
		addLogEntry("USB3_CloseCamera Error!", ui.textEdit_Log);
	}
	else
	{
		ui.pushButton_connectCamera->setEnabled(true);
		ui.pushButton_disConnectCamera->setEnabled(false);
	}
}

void QtCamera::initCameraValue()
{
	unsigned long ulAddress = 0x0000;
	unsigned long ulValue;
	size_t iSize = sizeof(ulValue);

	//读取exp time 0x12108
	ulAddress = 0x12108;
	int nError = USB3_ReadRegister(hCamera, ulAddress, &ulValue, &iSize);
	ui.lineEdit_expTime->setText(QString::number(ulValue));

	//读取采样宽度 0x20030
	ulAddress = 0x20030;
	nError = USB3_ReadRegister(hCamera, ulAddress, &ulValue, &iSize);
	ui.lineEdit_cameraWidth->setText(QString::number(ulValue));
}

void QtCamera::setExposureTime(QString time)
{

	unsigned long ulAddress = 0x0000;
	unsigned long ulValue;
	size_t iSize = sizeof(ulValue);

	//写exp time 0x12108
	ulAddress = 0x12108;
	ulValue = ui.lineEdit_expTime->text().toULong();
	int nError = USB3_WriteRegister(hCamera, ulAddress, &ulValue, &iSize);
	
}

void QtCamera::setCameraWidth(QString time)
{
	unsigned long ulAddress = 0x0000;
	unsigned long ulValue;
	size_t iSize = sizeof(ulValue);

	//写采样宽度 0x20030
	ulAddress = 0x20030;
	ulValue = ui.lineEdit_cameraWidth->text().toULong();
	int nError = USB3_WriteRegister(hCamera, ulAddress, &ulValue, &iSize);
}

void QtCamera::startWork()
{
	ui.pushButton_start->setEnabled(false);
	ui.pushButton_stop->setEnabled(true);
	workthread->start();
	workthread->stream();
	
}

void QtCamera::stopWork()
{
	ui.pushButton_start->setEnabled(true);
	ui.pushButton_stop->setEnabled(false);
	workthread->stop();
}

void QtCamera::processMat(cv::Mat showMat)
{
	//CV_16UC1
	//显示开图片
	cv::Mat tmp;
	cv::resize(showMat, tmp, cv::Size(ui.label_imgShow->width(), ui.label_imgShow->height()));
	tmp /= 64;
	tmp.convertTo(tmp, CV_8U);
	QImage img(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8);
	ui.label_imgShow->setPixmap(QPixmap::fromImage(img));
	ui.label_imgShow->show();
	return;
}