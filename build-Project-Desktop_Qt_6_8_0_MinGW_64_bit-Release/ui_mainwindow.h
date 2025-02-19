/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Search2;
    QPushButton *pushButton_AddMusic;
    QPushButton *pushButton_DeleteMusic;
    QPushButton *pushButton_LocalMusic;
    QPushButton *pushButton_MyCollection;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_ShowImage;
    QLabel *label_MusicName;
    QPushButton *pushButton_AddCollection;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_Speed;
    QLabel *label_Time;
    QPushButton *pushButton_Start;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_PlayWay;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Sound;
    QSpacerItem *horizontalSpacer;
    QLabel *label_PassTime;
    QPushButton *pushButton_Up;
    QSlider *horizontalSlider_Sound;
    QPushButton *pushButton_Next;
    QSlider *horizontalSlider_Time;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_Search;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_Background;
    QPushButton *pushButton_Search;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Yinyue.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("MainWindow{\n"
"	border-image: url(:/Image/Beijing10.png)\n"
"}"));
        MainWindow->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("font: 16pt \"\344\273\277\345\256\213\";\n"
"background: transparent;"));
        listWidget->setSortingEnabled(false);

        gridLayout_2->addWidget(listWidget, 1, 2, 1, 2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_Search2 = new QPushButton(widget_3);
        pushButton_Search2->setObjectName("pushButton_Search2");
        pushButton_Search2->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Sousuo.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Search2->setFlat(true);

        verticalLayout->addWidget(pushButton_Search2);

        pushButton_AddMusic = new QPushButton(widget_3);
        pushButton_AddMusic->setObjectName("pushButton_AddMusic");
        pushButton_AddMusic->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Tianjia.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_AddMusic->setFlat(true);

        verticalLayout->addWidget(pushButton_AddMusic);

        pushButton_DeleteMusic = new QPushButton(widget_3);
        pushButton_DeleteMusic->setObjectName("pushButton_DeleteMusic");
        pushButton_DeleteMusic->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Shanchu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_DeleteMusic->setFlat(true);

        verticalLayout->addWidget(pushButton_DeleteMusic);

        pushButton_LocalMusic = new QPushButton(widget_3);
        pushButton_LocalMusic->setObjectName("pushButton_LocalMusic");
        pushButton_LocalMusic->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Bendi.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_LocalMusic->setFlat(true);

        verticalLayout->addWidget(pushButton_LocalMusic);

        pushButton_MyCollection = new QPushButton(widget_3);
        pushButton_MyCollection->setObjectName("pushButton_MyCollection");
        pushButton_MyCollection->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Aixin4.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_MyCollection->setFlat(true);

        verticalLayout->addWidget(pushButton_MyCollection);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 2);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setLayoutDirection(Qt::LeftToRight);
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_ShowImage = new QPushButton(widget_4);
        pushButton_ShowImage->setObjectName("pushButton_ShowImage");
        pushButton_ShowImage->setMinimumSize(QSize(50, 50));
        pushButton_ShowImage->setMaximumSize(QSize(50, 50));
        pushButton_ShowImage->setFlat(true);

        gridLayout_4->addWidget(pushButton_ShowImage, 0, 0, 2, 1);

        label_MusicName = new QLabel(widget_4);
        label_MusicName->setObjectName("label_MusicName");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_MusicName->sizePolicy().hasHeightForWidth());
        label_MusicName->setSizePolicy(sizePolicy);
        label_MusicName->setMinimumSize(QSize(150, 25));
        label_MusicName->setMaximumSize(QSize(100, 25));

        gridLayout_4->addWidget(label_MusicName, 0, 1, 1, 1);

        pushButton_AddCollection = new QPushButton(widget_4);
        pushButton_AddCollection->setObjectName("pushButton_AddCollection");
        pushButton_AddCollection->setMinimumSize(QSize(30, 30));
        pushButton_AddCollection->setMaximumSize(QSize(30, 30));
        pushButton_AddCollection->setLayoutDirection(Qt::LeftToRight);
        pushButton_AddCollection->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Aixin2.png);\n"
"icon-size: 30px 30px;\n"
""));
        pushButton_AddCollection->setFlat(true);

        gridLayout_4->addWidget(pushButton_AddCollection, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget_4, 2, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimumSize(QSize(75, 25));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("background: transparent;"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.500000000000000);
        doubleSpinBox->setMaximum(2.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);
        doubleSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox, 1, 9, 1, 1);

        label_Speed = new QLabel(widget);
        label_Speed->setObjectName("label_Speed");
        label_Speed->setStyleSheet(QString::fromUtf8("image: url(:/Image/Beisu.png);\n"
"icon-size: 40px 40px;\n"
""));

        gridLayout->addWidget(label_Speed, 1, 8, 1, 1);

        label_Time = new QLabel(widget);
        label_Time->setObjectName("label_Time");

        gridLayout->addWidget(label_Time, 0, 8, 1, 1);

        pushButton_Start = new QPushButton(widget);
        pushButton_Start->setObjectName("pushButton_Start");
        pushButton_Start->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Kaishi.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Start->setFlat(true);

        gridLayout->addWidget(pushButton_Start, 1, 2, 1, 1);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMaximumSize(QSize(200, 16777215));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        verticalLayout_2 = new QVBoxLayout(widget_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        comboBox_PlayWay = new QComboBox(widget_5);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/Shunxu.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        comboBox_PlayWay->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/Xunhuan.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        comboBox_PlayWay->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/Suiji.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        comboBox_PlayWay->addItem(icon3, QString());
        comboBox_PlayWay->setObjectName("comboBox_PlayWay");
        comboBox_PlayWay->setMaximumSize(QSize(200, 16777215));
        comboBox_PlayWay->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        comboBox_PlayWay->setFrame(true);

        verticalLayout_2->addWidget(comboBox_PlayWay);


        gridLayout->addWidget(widget_5, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 10, 1, 1);

        pushButton_Sound = new QPushButton(widget);
        pushButton_Sound->setObjectName("pushButton_Sound");
        pushButton_Sound->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Shengyin.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Sound->setFlat(true);

        gridLayout->addWidget(pushButton_Sound, 1, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 7, 1, 1);

        label_PassTime = new QLabel(widget);
        label_PassTime->setObjectName("label_PassTime");

        gridLayout->addWidget(label_PassTime, 0, 0, 1, 1);

        pushButton_Up = new QPushButton(widget);
        pushButton_Up->setObjectName("pushButton_Up");
        pushButton_Up->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Shangyiqu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Up->setFlat(true);

        gridLayout->addWidget(pushButton_Up, 1, 1, 1, 1);

        horizontalSlider_Sound = new QSlider(widget);
        horizontalSlider_Sound->setObjectName("horizontalSlider_Sound");
        horizontalSlider_Sound->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_Sound->setValue(70);
        horizontalSlider_Sound->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_Sound, 1, 6, 1, 1);

        pushButton_Next = new QPushButton(widget);
        pushButton_Next->setObjectName("pushButton_Next");
        pushButton_Next->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Xiayiqu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Next->setFlat(true);

        gridLayout->addWidget(pushButton_Next, 1, 3, 1, 1);

        horizontalSlider_Time = new QSlider(widget);
        horizontalSlider_Time->setObjectName("horizontalSlider_Time");
        horizontalSlider_Time->setStyleSheet(QString::fromUtf8("background: transparent;"));
        horizontalSlider_Time->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_Time, 0, 1, 1, 7);


        gridLayout_2->addWidget(widget, 2, 3, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        lineEdit_Search = new QLineEdit(widget_2);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setStyleSheet(QString::fromUtf8("background: transparent;"));

        gridLayout_3->addWidget(lineEdit_Search, 0, 0, 1, 1);

        pushButton_Login = new QPushButton(widget_2);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Zhanghao.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Login->setFlat(true);

        gridLayout_3->addWidget(pushButton_Login, 0, 3, 1, 1);

        pushButton_Background = new QPushButton(widget_2);
        pushButton_Background->setObjectName("pushButton_Background");
        pushButton_Background->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Beijing1.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Background->setFlat(true);

        gridLayout_3->addWidget(pushButton_Background, 0, 2, 1, 1);

        pushButton_Search = new QPushButton(widget_2);
        pushButton_Search->setObjectName("pushButton_Search");
        pushButton_Search->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Sousuo.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Search->setFlat(true);

        gridLayout_3->addWidget(pushButton_Search, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 3, 1, 1);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName("widget_6");
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget_6);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        pushButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Yinyue.png);\n"
"icon-size: 80px 80px;\n"
"font-size: 24pt;"));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        gridLayout_2->addWidget(widget_6, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\275\273\351\237\263\344\271\220", nullptr));
        pushButton_Search2->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        pushButton_AddMusic->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_DeleteMusic->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_LocalMusic->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260", nullptr));
        pushButton_MyCollection->setText(QCoreApplication::translate("MainWindow", "\346\224\266\350\227\217", nullptr));
        pushButton_ShowImage->setText(QString());
        label_MusicName->setText(QString());
        pushButton_AddCollection->setText(QString());
        label_Speed->setText(QString());
        label_Time->setText(QCoreApplication::translate("MainWindow", "0\357\274\23200", nullptr));
        pushButton_Start->setText(QString());
        comboBox_PlayWay->setItemText(0, QCoreApplication::translate("MainWindow", "\351\241\272\345\272\217\346\222\255\346\224\276", nullptr));
        comboBox_PlayWay->setItemText(1, QCoreApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        comboBox_PlayWay->setItemText(2, QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));

        pushButton_Sound->setText(QString());
        label_PassTime->setText(QCoreApplication::translate("MainWindow", "0\357\274\23200", nullptr));
        pushButton_Up->setText(QString());
        pushButton_Next->setText(QString());
        lineEdit_Search->setText(QString());
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton_Background->setText(QString());
        pushButton_Search->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\275\273\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
