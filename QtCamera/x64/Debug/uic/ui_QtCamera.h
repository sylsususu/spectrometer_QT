/********************************************************************************
** Form generated from reading UI file 'QtCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCAMERA_H
#define UI_QTCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QtCameraClass
{
public:
    QGroupBox *groupBox;
    QComboBox *comboBox_camera;
    QPushButton *pushButton_connectCamera;
    QPushButton *pushButton_disConnectCamera;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_expTime;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_cameraWidth;
    QLabel *label_4;
    QLabel *label_imgShow;
    QCustomPlot *widget;
    QFrame *frame_7;
    QTextEdit *textEdit_Log;
    QPushButton *pushButton_ClearLog;
    QLabel *label_45;

    void setupUi(QDialog *QtCameraClass)
    {
        if (QtCameraClass->objectName().isEmpty())
            QtCameraClass->setObjectName(QStringLiteral("QtCameraClass"));
        QtCameraClass->resize(906, 801);
        groupBox = new QGroupBox(QtCameraClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 871, 500));
        comboBox_camera = new QComboBox(groupBox);
        comboBox_camera->setObjectName(QStringLiteral("comboBox_camera"));
        comboBox_camera->setGeometry(QRect(20, 20, 180, 25));
        pushButton_connectCamera = new QPushButton(groupBox);
        pushButton_connectCamera->setObjectName(QStringLiteral("pushButton_connectCamera"));
        pushButton_connectCamera->setGeometry(QRect(20, 60, 75, 23));
        pushButton_disConnectCamera = new QPushButton(groupBox);
        pushButton_disConnectCamera->setObjectName(QStringLiteral("pushButton_disConnectCamera"));
        pushButton_disConnectCamera->setGeometry(QRect(120, 60, 75, 23));
        pushButton_start = new QPushButton(groupBox);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(20, 190, 75, 23));
        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(110, 190, 75, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 171, 22));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_expTime = new QLineEdit(layoutWidget);
        lineEdit_expTime->setObjectName(QStringLiteral("lineEdit_expTime"));

        gridLayout->addWidget(lineEdit_expTime, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 150, 171, 22));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_cameraWidth = new QLineEdit(layoutWidget1);
        lineEdit_cameraWidth->setObjectName(QStringLiteral("lineEdit_cameraWidth"));

        gridLayout_2->addWidget(lineEdit_cameraWidth, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        label_imgShow = new QLabel(groupBox);
        label_imgShow->setObjectName(QStringLiteral("label_imgShow"));
        label_imgShow->setGeometry(QRect(260, 30, 580, 180));
        QFont font;
        font.setPointSize(30);
        label_imgShow->setFont(font);
        label_imgShow->setLayoutDirection(Qt::LeftToRight);
        label_imgShow->setAlignment(Qt::AlignCenter);
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(260, 170, 580, 180));
        frame_7 = new QFrame(QtCameraClass);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(-7, 641, 911, 161));
        frame_7->setStyleSheet(QStringLiteral(""));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        textEdit_Log = new QTextEdit(frame_7);
        textEdit_Log->setObjectName(QStringLiteral("textEdit_Log"));
        textEdit_Log->setEnabled(true);
        textEdit_Log->setGeometry(QRect(10, 50, 891, 101));
        textEdit_Log->setStyleSheet(QStringLiteral(""));
        pushButton_ClearLog = new QPushButton(frame_7);
        pushButton_ClearLog->setObjectName(QStringLiteral("pushButton_ClearLog"));
        pushButton_ClearLog->setGeometry(QRect(140, 10, 32, 32));
        pushButton_ClearLog->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"background: #252525;\n"
"             border-image: url(:/QtCamera/Image/\347\231\275\345\210\240\351\231\244-01.svg);\n"
"}\n"
"QPushButton:Hover{\n"
"			border-image:url(:/QtCamera/Image/\345\210\240\351\231\244.svg);\n"
"\n"
"}\n"
""));
        label_45 = new QLabel(frame_7);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(16, 10, 96, 22));
        QFont font1;
        label_45->setFont(font1);
        label_45->setStyleSheet(QLatin1String("font-size: 16px;\n"
""));

        retranslateUi(QtCameraClass);

        QMetaObject::connectSlotsByName(QtCameraClass);
    } // setupUi

    void retranslateUi(QDialog *QtCameraClass)
    {
        QtCameraClass->setWindowTitle(QApplication::translate("QtCameraClass", "QtCamera", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QtCameraClass", "GroupBox", Q_NULLPTR));
        pushButton_connectCamera->setText(QApplication::translate("QtCameraClass", "\350\277\236\346\216\245\347\233\270\346\234\272", Q_NULLPTR));
        pushButton_disConnectCamera->setText(QApplication::translate("QtCameraClass", "\346\226\255\350\277\236\347\233\270\346\234\272", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("QtCameraClass", "start", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("QtCameraClass", "stop", Q_NULLPTR));
        label->setText(QApplication::translate("QtCameraClass", "expsoure", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtCameraClass", "us", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtCameraClass", "\351\207\207\346\240\267Width", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtCameraClass", "pixel", Q_NULLPTR));
        label_imgShow->setText(QApplication::translate("QtCameraClass", "\345\233\276\347\211\207\346\230\276\347\244\272\345\214\272", Q_NULLPTR));
        textEdit_Log->setHtml(QApplication::translate("QtCameraClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI Light'; font-size:12px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_ClearLog->setText(QString());
        label_45->setText(QApplication::translate("QtCameraClass", "\350\275\257\344\273\266\346\211\247\350\241\214\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtCameraClass: public Ui_QtCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCAMERA_H
