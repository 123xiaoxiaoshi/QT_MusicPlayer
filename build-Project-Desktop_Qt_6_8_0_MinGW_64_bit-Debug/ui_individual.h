/********************************************************************************
** Form generated from reading UI file 'individual.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDIVIDUAL_H
#define UI_INDIVIDUAL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Individual
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_MyInformation;
    QPushButton *pushButton_SetPassword;
    QPushButton *pushButton_ExitLogin;
    QPushButton *pushButton_Back;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_8;
    QWidget *widget_7;
    QGridLayout *gridLayout_9;
    QWidget *widget_6;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_ChangePassword;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_NewPasswordTwo;
    QLineEdit *lineEdit_NewPassword;
    QLabel *label_NewPasswordTwo;
    QLabel *label_OldPassword;
    QLineEdit *lineEdit_OldPassword;
    QLabel *label_NewPassword;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_1;
    QGridLayout *gridLayout_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_Preserve;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_Account;
    QLineEdit *lineEdit_Account;
    QLabel *label_NickName;
    QLineEdit *lineEdit_NickName;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Individual)
    {
        if (Individual->objectName().isEmpty())
            Individual->setObjectName("Individual");
        Individual->resize(1100, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Yinyue.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Individual->setWindowIcon(icon);
        Individual->setStyleSheet(QString::fromUtf8("#Individual\n"
"{\n"
"border-image:url(:/Image/Beijing10.png)\n"
"}"));
        Individual->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        gridLayout_3 = new QGridLayout(Individual);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(Individual);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_MyInformation = new QPushButton(widget);
        pushButton_MyInformation->setObjectName("pushButton_MyInformation");
        pushButton_MyInformation->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Geren.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_MyInformation->setFlat(true);

        verticalLayout->addWidget(pushButton_MyInformation);

        pushButton_SetPassword = new QPushButton(widget);
        pushButton_SetPassword->setObjectName("pushButton_SetPassword");
        pushButton_SetPassword->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Mimashezhi.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_SetPassword->setFlat(true);

        verticalLayout->addWidget(pushButton_SetPassword);

        pushButton_ExitLogin = new QPushButton(widget);
        pushButton_ExitLogin->setObjectName("pushButton_ExitLogin");
        pushButton_ExitLogin->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Tuichu.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_ExitLogin->setFlat(true);

        verticalLayout->addWidget(pushButton_ExitLogin);

        pushButton_Back = new QPushButton(widget);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Fanhui.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Back->setFlat(true);

        verticalLayout->addWidget(pushButton_Back);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(Individual);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_8 = new QGridLayout(page);
        gridLayout_8->setObjectName("gridLayout_8");
        widget_7 = new QWidget(page);
        widget_7->setObjectName("widget_7");
        gridLayout_9 = new QGridLayout(widget_7);
        gridLayout_9->setObjectName("gridLayout_9");
        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName("widget_6");
        gridLayout_7 = new QGridLayout(widget_6);
        gridLayout_7->setObjectName("gridLayout_7");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        pushButton_ChangePassword = new QPushButton(widget_6);
        pushButton_ChangePassword->setObjectName("pushButton_ChangePassword");
        pushButton_ChangePassword->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Xiugaimima.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_ChangePassword->setFlat(true);

        gridLayout_7->addWidget(pushButton_ChangePassword, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_9->addWidget(widget_6, 2, 1, 1, 1);

        widget_2 = new QWidget(widget_7);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        lineEdit_NewPasswordTwo = new QLineEdit(widget_2);
        lineEdit_NewPasswordTwo->setObjectName("lineEdit_NewPasswordTwo");
        lineEdit_NewPasswordTwo->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(lineEdit_NewPasswordTwo, 2, 2, 1, 1);

        lineEdit_NewPassword = new QLineEdit(widget_2);
        lineEdit_NewPassword->setObjectName("lineEdit_NewPassword");
        lineEdit_NewPassword->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(lineEdit_NewPassword, 1, 2, 1, 1);

        label_NewPasswordTwo = new QLabel(widget_2);
        label_NewPasswordTwo->setObjectName("label_NewPasswordTwo");

        gridLayout->addWidget(label_NewPasswordTwo, 2, 0, 1, 2);

        label_OldPassword = new QLabel(widget_2);
        label_OldPassword->setObjectName("label_OldPassword");

        gridLayout->addWidget(label_OldPassword, 0, 0, 1, 2);

        lineEdit_OldPassword = new QLineEdit(widget_2);
        lineEdit_OldPassword->setObjectName("lineEdit_OldPassword");
        lineEdit_OldPassword->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(lineEdit_OldPassword, 0, 2, 1, 1);

        label_NewPassword = new QLabel(widget_2);
        label_NewPassword->setObjectName("label_NewPassword");

        gridLayout->addWidget(label_NewPassword, 1, 0, 1, 1);


        gridLayout_9->addWidget(widget_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_9->addItem(verticalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_9->addItem(verticalSpacer_4, 3, 1, 1, 1);


        gridLayout_8->addWidget(widget_7, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        gridLayout_5 = new QGridLayout(page_1);
        gridLayout_5->setObjectName("gridLayout_5");
        widget_5 = new QWidget(page_1);
        widget_5->setObjectName("widget_5");
        gridLayout_6 = new QGridLayout(widget_5);
        gridLayout_6->setObjectName("gridLayout_6");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_Preserve = new QPushButton(widget_4);
        pushButton_Preserve->setObjectName("pushButton_Preserve");
        pushButton_Preserve->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Image/Baocun1.png);\n"
"icon-size: 40px 40px;\n"
""));
        pushButton_Preserve->setFlat(true);

        gridLayout_4->addWidget(pushButton_Preserve, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_4, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 3, 1, 1, 1);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName("gridLayout_2");
        label_Account = new QLabel(widget_3);
        label_Account->setObjectName("label_Account");

        gridLayout_2->addWidget(label_Account, 0, 0, 1, 1);

        lineEdit_Account = new QLineEdit(widget_3);
        lineEdit_Account->setObjectName("lineEdit_Account");
        lineEdit_Account->setToolTipDuration(-1);
        lineEdit_Account->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(lineEdit_Account, 0, 2, 1, 1);

        label_NickName = new QLabel(widget_3);
        label_NickName->setObjectName("label_NickName");

        gridLayout_2->addWidget(label_NickName, 1, 0, 1, 2);

        lineEdit_NickName = new QLineEdit(widget_3);
        lineEdit_NickName->setObjectName("lineEdit_NickName");
        lineEdit_NickName->setToolTipDuration(-1);
        lineEdit_NickName->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout_2->addWidget(lineEdit_NickName, 1, 2, 1, 1);


        gridLayout_6->addWidget(widget_3, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_5, 0, 0, 1, 1);

        stackedWidget->addWidget(page_1);

        gridLayout_3->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(Individual);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Individual);
    } // setupUi

    void retranslateUi(QWidget *Individual)
    {
        Individual->setWindowTitle(QCoreApplication::translate("Individual", "\350\275\273\351\237\263\344\271\220", nullptr));
        pushButton_MyInformation->setText(QCoreApplication::translate("Individual", "\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        pushButton_SetPassword->setText(QCoreApplication::translate("Individual", "\345\257\206\347\240\201\350\256\276\347\275\256", nullptr));
        pushButton_ExitLogin->setText(QCoreApplication::translate("Individual", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        pushButton_Back->setText(QString());
        pushButton_ChangePassword->setText(QCoreApplication::translate("Individual", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_NewPasswordTwo->setText(QCoreApplication::translate("Individual", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        label_OldPassword->setText(QCoreApplication::translate("Individual", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        label_NewPassword->setText(QCoreApplication::translate("Individual", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_Preserve->setText(QCoreApplication::translate("Individual", "\344\277\235\345\255\230", nullptr));
        label_Account->setText(QCoreApplication::translate("Individual", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_NickName->setText(QCoreApplication::translate("Individual", "\346\230\265\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Individual: public Ui_Individual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDIVIDUAL_H
