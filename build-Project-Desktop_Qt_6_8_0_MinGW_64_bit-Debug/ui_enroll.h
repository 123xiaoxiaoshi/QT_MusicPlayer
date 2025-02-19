/********************************************************************************
** Form generated from reading UI file 'enroll.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLL_H
#define UI_ENROLL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enroll
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_6;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Account;
    QLineEdit *lineEdit_Account;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_ConfirmPassword;
    QLineEdit *lineEdit_ConfirmPassword;
    QPushButton *pushButton_Show;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_Enroll;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_Back;

    void setupUi(QWidget *Enroll)
    {
        if (Enroll->objectName().isEmpty())
            Enroll->setObjectName("Enroll");
        Enroll->resize(1100, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Yinyue.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Enroll->setWindowIcon(icon);
        Enroll->setStyleSheet(QString::fromUtf8("#Enroll\n"
"{\n"
"border-image:url(:/Image/Beijing10.png)\n"
"}"));
        Enroll->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        gridLayout = new QGridLayout(Enroll);
        gridLayout->setObjectName("gridLayout");
        widget_6 = new QWidget(Enroll);
        widget_6->setObjectName("widget_6");
        gridLayout_4 = new QGridLayout(widget_6);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(widget_6);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Yinyue.png);\n"
"icon-size: 80px 80px;\n"
"font-size: 24pt;"));
        pushButton_5->setFlat(true);

        gridLayout_4->addWidget(pushButton_5, 0, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_15, 0, 2, 1, 1);


        gridLayout->addWidget(widget_6, 0, 0, 2, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        widget = new QWidget(Enroll);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_Account = new QLabel(widget);
        label_Account->setObjectName("label_Account");

        horizontalLayout->addWidget(label_Account);

        lineEdit_Account = new QLineEdit(widget);
        lineEdit_Account->setObjectName("lineEdit_Account");

        horizontalLayout->addWidget(lineEdit_Account);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(20, 20));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        gridLayout->addWidget(widget, 2, 0, 1, 1);

        widget_2 = new QWidget(Enroll);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_Password = new QLabel(widget_2);
        label_Password->setObjectName("label_Password");

        horizontalLayout_2->addWidget(label_Password);

        lineEdit_Password = new QLineEdit(widget_2);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(20, 20));
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout->addWidget(widget_2, 3, 0, 1, 1);

        widget_3 = new QWidget(Enroll);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_ConfirmPassword = new QLabel(widget_3);
        label_ConfirmPassword->setObjectName("label_ConfirmPassword");

        horizontalLayout_3->addWidget(label_ConfirmPassword);

        lineEdit_ConfirmPassword = new QLineEdit(widget_3);
        lineEdit_ConfirmPassword->setObjectName("lineEdit_ConfirmPassword");
        lineEdit_ConfirmPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_ConfirmPassword);

        pushButton_Show = new QPushButton(widget_3);
        pushButton_Show->setObjectName("pushButton_Show");
        pushButton_Show->setMaximumSize(QSize(20, 20));
        pushButton_Show->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Xiaoyanjingbi.png);\n"
"icon-size: 20px 20px;\n"
""));
        pushButton_Show->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_Show);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_3, 4, 0, 1, 1);

        widget_4 = new QWidget(Enroll);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_Enroll = new QPushButton(widget_4);
        pushButton_Enroll->setObjectName("pushButton_Enroll");
        pushButton_Enroll->setStyleSheet(QString::fromUtf8(""));
        pushButton_Enroll->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_Enroll);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        gridLayout->addWidget(widget_4, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        widget_5 = new QWidget(Enroll);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        pushButton_Back = new QPushButton(widget_5);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Fanhui.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Back->setFlat(true);

        horizontalLayout_5->addWidget(pushButton_Back);


        gridLayout->addWidget(widget_5, 7, 0, 1, 1);


        retranslateUi(Enroll);

        QMetaObject::connectSlotsByName(Enroll);
    } // setupUi

    void retranslateUi(QWidget *Enroll)
    {
        Enroll->setWindowTitle(QCoreApplication::translate("Enroll", "\350\275\273\351\237\263\344\271\220", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Enroll", "\350\275\273\351\237\263\344\271\220", nullptr));
        label_Account->setText(QCoreApplication::translate("Enroll", "       \350\264\246\345\217\267\357\274\232", nullptr));
        pushButton->setText(QString());
        label_Password->setText(QCoreApplication::translate("Enroll", "       \345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_2->setText(QString());
        label_ConfirmPassword->setText(QCoreApplication::translate("Enroll", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_Show->setText(QString());
        pushButton_Enroll->setText(QCoreApplication::translate("Enroll", "          \346\263\250\345\206\214          ", nullptr));
        pushButton_Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Enroll: public Ui_Enroll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLL_H
