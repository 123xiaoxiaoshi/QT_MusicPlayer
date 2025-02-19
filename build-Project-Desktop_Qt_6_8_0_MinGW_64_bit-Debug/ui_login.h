/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Account;
    QLineEdit *lineEdit_Account;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_Show;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Enroll;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_Back;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->setEnabled(true);
        Login->resize(1100, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Yinyue.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8("#Login{\n"
"border-image:url(:/Image/Beijing10.png)\n"
"}\n"
""));
        Login->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        widget_5 = new QWidget(Login);
        widget_5->setObjectName("widget_5");
        gridLayout_2 = new QGridLayout(widget_5);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Yinyue.png);\n"
"icon-size: 80px 80px;\n"
"font-size: 24pt;\n"
""));
        pushButton_2->setFlat(true);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 0, 2, 1, 1);


        gridLayout->addWidget(widget_5, 1, 0, 1, 1);

        widget_2 = new QWidget(Login);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_Account = new QLabel(widget_2);
        label_Account->setObjectName("label_Account");

        horizontalLayout_2->addWidget(label_Account);

        lineEdit_Account = new QLineEdit(widget_2);
        lineEdit_Account->setObjectName("lineEdit_Account");

        horizontalLayout_2->addWidget(lineEdit_Account);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(20, 20));
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;"));
        pushButton->setFlat(true);

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addWidget(widget_2, 2, 0, 1, 1);

        widget = new QWidget(Login);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_Password = new QLabel(widget);
        label_Password->setObjectName("label_Password");

        horizontalLayout->addWidget(label_Password);

        lineEdit_Password = new QLineEdit(widget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(lineEdit_Password);

        pushButton_Show = new QPushButton(widget);
        pushButton_Show->setObjectName("pushButton_Show");
        pushButton_Show->setMaximumSize(QSize(20, 20));
        pushButton_Show->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Xiaoyanjingbi.png);\n"
"icon-size: 20px 20px;\n"
""));
        pushButton_Show->setFlat(true);

        horizontalLayout->addWidget(pushButton_Show);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widget, 4, 0, 1, 1);

        widget_3 = new QWidget(Login);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_Login = new QPushButton(widget_3);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_Login);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_3, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        widget_4 = new QWidget(Login);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Fanhui.png);\n"
"icon-size: 40px 40px;\n"
""));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_Enroll = new QPushButton(widget_4);
        pushButton_Enroll->setObjectName("pushButton_Enroll");
        pushButton_Enroll->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Zhuce.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Enroll->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_Enroll);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        pushButton_Back = new QPushButton(widget_4);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_Back);


        gridLayout->addWidget(widget_4, 7, 0, 1, 1);


        retranslateUi(Login);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\350\275\273\351\237\263\344\271\220", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\350\275\273\351\237\263\344\271\220", nullptr));
        label_Account->setText(QCoreApplication::translate("Login", "\350\264\246\345\217\267\357\274\232", nullptr));
        pushButton->setText(QString());
        label_Password->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_Show->setText(QString());
        pushButton_Login->setText(QCoreApplication::translate("Login", "               \347\231\273\345\275\225               ", nullptr));
        pushButton_Enroll->setText(QString());
        pushButton_Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
