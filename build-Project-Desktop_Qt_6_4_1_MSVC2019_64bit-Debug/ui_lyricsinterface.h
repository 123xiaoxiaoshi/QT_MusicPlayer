/********************************************************************************
** Form generated from reading UI file 'lyricsinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRICSINTERFACE_H
#define UI_LYRICSINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LyricsInterface
{
public:

    void setupUi(QWidget *LyricsInterface)
    {
        if (LyricsInterface->objectName().isEmpty())
            LyricsInterface->setObjectName("LyricsInterface");
        LyricsInterface->resize(537, 444);

        retranslateUi(LyricsInterface);

        QMetaObject::connectSlotsByName(LyricsInterface);
    } // setupUi

    void retranslateUi(QWidget *LyricsInterface)
    {
        LyricsInterface->setWindowTitle(QCoreApplication::translate("LyricsInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LyricsInterface: public Ui_LyricsInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRICSINTERFACE_H
