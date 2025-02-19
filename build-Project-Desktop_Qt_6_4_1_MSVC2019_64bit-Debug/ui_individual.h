/********************************************************************************
** Form generated from reading UI file 'individual.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDIVIDUAL_H
#define UI_INDIVIDUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Individual
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
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

    void setupUi(QWidget *Individual)
    {
        if (Individual->objectName().isEmpty())
            Individual->setObjectName("Individual");
        Individual->resize(811, 526);
        gridLayout_2 = new QGridLayout(Individual);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea = new QScrollArea(Individual);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 787, 417));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        widget = new QWidget(Individual);
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


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(Individual);

        QMetaObject::connectSlotsByName(Individual);
    } // setupUi

    void retranslateUi(QWidget *Individual)
    {
        Individual->setWindowTitle(QCoreApplication::translate("Individual", "Form", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Individual", "\345\210\227\350\241\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Individual", "\345\274\200\345\247\213\346\232\202\345\201\234", nullptr));
        label_5->setText(QCoreApplication::translate("Individual", "\345\267\262\346\222\255\346\227\266\351\225\277", nullptr));
        label_2->setText(QCoreApplication::translate("Individual", "\346\200\273\346\227\266\351\225\277", nullptr));
        label_4->setText(QCoreApplication::translate("Individual", "\345\243\260\351\237\263", nullptr));
        pushButton->setText(QCoreApplication::translate("Individual", "\344\270\212\344\270\200\351\246\226", nullptr));
        label_6->setText(QCoreApplication::translate("Individual", "\345\200\215\351\200\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Individual", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Individual", "\346\222\255\346\224\276\346\226\271\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Individual: public Ui_Individual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDIVIDUAL_H
