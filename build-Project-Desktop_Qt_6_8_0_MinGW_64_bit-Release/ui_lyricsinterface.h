/********************************************************************************
** Form generated from reading UI file 'lyricsinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRICSINTERFACE_H
#define UI_LYRICSINTERFACE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LyricsInterface
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_1;
    QLabel *label_15;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_4;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_3;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_7;
    QLabel *label_14;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *label_11;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_Up;
    QPushButton *pushButton_Next;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Time;
    QLabel *label_PassTime;
    QPushButton *pushButton_Sound;
    QSlider *horizontalSlider_Sound;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_Start;
    QSlider *horizontalSlider_Time;
    QLabel *label_Speed;
    QPushButton *pushButton_FontColor;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_ShowImage;
    QPushButton *pushButton_AddCollection;
    QLabel *label_MusicName;

    void setupUi(QWidget *LyricsInterface)
    {
        if (LyricsInterface->objectName().isEmpty())
            LyricsInterface->setObjectName("LyricsInterface");
        LyricsInterface->setEnabled(true);
        LyricsInterface->resize(1500, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Yinyue.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        LyricsInterface->setWindowIcon(icon);
        LyricsInterface->setLayoutDirection(Qt::RightToLeft);
        LyricsInterface->setStyleSheet(QString::fromUtf8(""));
        LyricsInterface->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        verticalLayout = new QVBoxLayout(LyricsInterface);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(LyricsInterface);
        widget_2->setObjectName("widget_2");
        widget_2->setLayoutDirection(Qt::RightToLeft);
        widget_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_1 = new QLabel(widget_2);
        label_1->setObjectName("label_1");
        label_1->setEnabled(true);
        label_1->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_1, 0, 0, 1, 1);

        label_15 = new QLabel(widget_2);
        label_15->setObjectName("label_15");

        gridLayout_2->addWidget(label_15, 9, 0, 1, 1);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 10, 0, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 16, 0, 1, 1);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 5, 0, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("\n"
"font: 18pt;"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        label_19 = new QLabel(widget_2);
        label_19->setObjectName("label_19");

        gridLayout_2->addWidget(label_19, 17, 0, 1, 1);

        label_18 = new QLabel(widget_2);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 13, 0, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_16 = new QLabel(widget_2);
        label_16->setObjectName("label_16");

        gridLayout_2->addWidget(label_16, 11, 0, 1, 1);

        label_17 = new QLabel(widget_2);
        label_17->setObjectName("label_17");

        gridLayout_2->addWidget(label_17, 15, 0, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setEnabled(true);
        label_7->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 12, 0, 1, 1);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");

        gridLayout_2->addWidget(label_14, 7, 0, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 8, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 14, 0, 1, 1);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 18, 0, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 19, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font:12pt;"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(LyricsInterface);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_Up = new QPushButton(widget_3);
        pushButton_Up->setObjectName("pushButton_Up");
        pushButton_Up->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Shangyiqu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Up->setFlat(true);

        gridLayout_3->addWidget(pushButton_Up, 1, 1, 1, 1);

        pushButton_Next = new QPushButton(widget_3);
        pushButton_Next->setObjectName("pushButton_Next");
        pushButton_Next->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Xiayiqu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Next->setFlat(true);

        gridLayout_3->addWidget(pushButton_Next, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 6, 1, 1);

        label_Time = new QLabel(widget_3);
        label_Time->setObjectName("label_Time");

        gridLayout_3->addWidget(label_Time, 0, 7, 1, 1);

        label_PassTime = new QLabel(widget_3);
        label_PassTime->setObjectName("label_PassTime");

        gridLayout_3->addWidget(label_PassTime, 0, 0, 1, 1);

        pushButton_Sound = new QPushButton(widget_3);
        pushButton_Sound->setObjectName("pushButton_Sound");
        pushButton_Sound->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Shengyin.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Sound->setFlat(true);

        gridLayout_3->addWidget(pushButton_Sound, 1, 4, 1, 1);

        horizontalSlider_Sound = new QSlider(widget_3);
        horizontalSlider_Sound->setObjectName("horizontalSlider_Sound");
        horizontalSlider_Sound->setValue(70);
        horizontalSlider_Sound->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_Sound, 1, 5, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget_3);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimumSize(QSize(75, 25));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.500000000000000);
        doubleSpinBox->setMaximum(2.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);
        doubleSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox, 1, 8, 1, 1);

        pushButton_Start = new QPushButton(widget_3);
        pushButton_Start->setObjectName("pushButton_Start");
        pushButton_Start->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Kaishi.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Start->setFlat(true);

        gridLayout_3->addWidget(pushButton_Start, 1, 2, 1, 1);

        horizontalSlider_Time = new QSlider(widget_3);
        horizontalSlider_Time->setObjectName("horizontalSlider_Time");
        horizontalSlider_Time->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_Time, 0, 1, 1, 6);

        label_Speed = new QLabel(widget_3);
        label_Speed->setObjectName("label_Speed");
        label_Speed->setStyleSheet(QString::fromUtf8("image: url(:/Image/Beisu.png);\n"
"icon-size: 40px 40px;\n"
""));

        gridLayout_3->addWidget(label_Speed, 1, 7, 1, 1);

        pushButton_FontColor = new QPushButton(widget_3);
        pushButton_FontColor->setObjectName("pushButton_FontColor");
        pushButton_FontColor->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Zitiyanse.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_FontColor->setFlat(true);

        gridLayout_3->addWidget(pushButton_FontColor, 0, 8, 1, 1);


        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
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


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);


        retranslateUi(LyricsInterface);

        QMetaObject::connectSlotsByName(LyricsInterface);
    } // setupUi

    void retranslateUi(QWidget *LyricsInterface)
    {
        LyricsInterface->setWindowTitle(QCoreApplication::translate("LyricsInterface", "\350\275\273\351\237\263\344\271\220", nullptr));
        label_1->setText(QString());
        label_15->setText(QString());
        label_6->setText(QString());
        label_9->setText(QString());
        label_13->setText(QString());
        label_4->setText(QString());
        label_19->setText(QString());
        label_18->setText(QString());
        label_3->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_7->setText(QString());
        label_14->setText(QString());
        label_5->setText(QString());
        label_8->setText(QString());
        label_10->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_12->setText(QString());
        label_11->setText(QString());
        pushButton_Up->setText(QString());
        pushButton_Next->setText(QString());
        label_Time->setText(QCoreApplication::translate("LyricsInterface", "0\357\274\23200", nullptr));
        label_PassTime->setText(QCoreApplication::translate("LyricsInterface", "0\357\274\23200", nullptr));
        pushButton_Sound->setText(QString());
        pushButton_Start->setText(QString());
        label_Speed->setText(QString());
        pushButton_FontColor->setText(QString());
        pushButton_ShowImage->setText(QString());
        pushButton_AddCollection->setText(QString());
        label_MusicName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LyricsInterface: public Ui_LyricsInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRICSINTERFACE_H
