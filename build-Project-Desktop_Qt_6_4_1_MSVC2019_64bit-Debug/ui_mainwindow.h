/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSlider *verticalSlider;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QSlider *horizontalSlider_2;
    QListWidget *listWidget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1177, 653);
        MainWindow->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("color : rgb(255, 255, 0);"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_2);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget_2);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout->addWidget(pushButton_8);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_12 = new QPushButton(widget_3);
        pushButton_12->setObjectName("pushButton_12");

        verticalLayout->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(widget_3);
        pushButton_13->setObjectName("pushButton_13");

        verticalLayout->addWidget(pushButton_13);

        pushButton_9 = new QPushButton(widget_3);
        pushButton_9->setObjectName("pushButton_9");

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget_3);
        pushButton_10->setObjectName("pushButton_10");

        verticalLayout->addWidget(pushButton_10);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        label = new QLabel(widget_4);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);


        gridLayout_2->addWidget(widget_4, 2, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        verticalSlider = new QSlider(widget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 8, 2, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 1, 6, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 1, 1, 5);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 6, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 1, 7, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 1, 3, 1, 1);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout->addWidget(pushButton_11, 1, 0, 1, 1);

        horizontalSlider_2 = new QSlider(widget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 1, 5, 1, 1);


        gridLayout_2->addWidget(widget, 2, 1, 1, 1);

        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setStyleSheet(QString::fromUtf8("\n"
"color : rgb(255, 255, 0);"));

        gridLayout_2->addWidget(listWidget_2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        widget_2->raise();
        widget_3->raise();
        widget_4->raise();
        widget->raise();
        listWidget_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1177, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\350\264\246\345\217\267", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\351\237\263\344\271\220", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\346\230\276\347\244\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\255\214\345\220\215", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\210\227\350\241\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\232\202\345\201\234", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\222\255\346\227\266\351\225\277", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\200\273\346\227\266\351\225\277", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\243\260\351\237\263", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\200\215\351\200\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\226\271\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
