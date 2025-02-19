#ifndef LYRICSINTERFACE_H
#define LYRICSINTERFACE_H

#include <QWidget>
#include <QAudioSource>
#include <QMediaDevices>
#include <QByteArray>
#include <QTimer>
#include <QPainter>
#include <QVector>

namespace Ui {
class LyricsInterface;
}

class LyricsInterface : public QWidget
{
    Q_OBJECT

public:
    explicit LyricsInterface(QWidget *parent = nullptr);
    ~LyricsInterface();

public:
    Ui::LyricsInterface *ui;
    void paintEvent(QPaintEvent *event);

signals:
    void handoff();     //发送界面切换的信号


public slots:
    void thisShow();    //界面显示


private:
    QVector<int> data;

private slots:
    void readAudioData();
    void updatePlot();

private:
    QAudioSource *audioSource;
    QIODevice *audioDevice;
    QByteArray audioBuffer;
    QTimer *timer;
    QVector<double> frequencyData;

    void performFFT(const QByteArray &data);
};

#endif // LYRICSINTERFACE_H
