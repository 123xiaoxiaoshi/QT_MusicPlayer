#ifndef AUDIOPROCESSOR_H
#define AUDIOPROCESSOR_H

#include <QObject>
#include <QAudioSource>
#include <QIODevice>
#include <QVector>

class AudioProcessor : public QObject
{
    Q_OBJECT

public:
    explicit AudioProcessor(QObject *parent = nullptr);
    ~AudioProcessor();

    void start();
    void stop();

signals:
    void spectrumDataUpdated(const QVector<double> &spectrumData);

private slots:
    void readAudioData();

private:
    QAudioSource *audioSource;
    QIODevice *audioDevice;
    QVector<double> processAudioBuffer(const QByteArray &buffer);
};

#endif // AUDIOPROCESSOR_H
