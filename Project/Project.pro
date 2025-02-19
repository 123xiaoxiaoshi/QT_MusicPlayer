QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17
QT += sql
QT += multimedia
QT += network


#TARGET = music

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audioprocessor.cpp \
    enroll.cpp \
    individual.cpp \
    login.cpp \
    lyricsinterface.cpp \
    main.cpp \
    mainwindow.cpp \
    thirdparty/kissfft/kiss_fft.c \
    thirdparty/kissfft/kiss_fftr.c
# 添加 KissFFT 的源文件
#SOURCES += thirdparty/kissfft/kiss_fft.c \
  #         thirdparty/kissfft/kiss_fftr.c \
           #thirdparty\kissfft\_kiss_fft_guts.h \
           #thirdparty\kissfft\kiss_fft_log.h
     # 添加 KissFFT 的头文件路径
     INCLUDEPATH += thirdparty/kissfft

    # 如果需要使用浮点数版本的 FFT，可以定义以下宏
    DEFINES += KISS_FFT_USE_FLOAT
HEADERS += \
    SqlConnect.h \
    audioprocessor.h \
    enroll.h \
    individual.h \
    login.h \
    lyricsinterface.h \
    mainwindow.h \
    thirdparty/kissfft/_kiss_fft_guts.h \
    thirdparty/kissfft/kiss_fft.h \
    thirdparty/kissfft/kiss_fft_log.h \
    thirdparty/kissfft/kiss_fftr.h

FORMS += \
    enroll.ui \
    individual.ui \
    login.ui \
    lyricsinterface.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc

DISTFILES += \
    MyIcon.rc

RC_FILE = MyIcon.rc






