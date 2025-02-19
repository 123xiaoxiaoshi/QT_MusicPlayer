#include "audioprocessor.h"
#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioFormat>
#include <QDebug>
#include <cmath>

AudioProcessor::AudioProcessor(QObject *parent)
    : QObject(parent)
{
    // 设置音频格式
    QAudioFormat format;
    format.setSampleRate(44100); // 44.1 kHz
    format.setChannelCount(1);   // 单声道
    format.setSampleFormat(QAudioFormat::Int16); // 16 位 PCM

    // 获取默认音频输入设备
    QAudioDevice inputDevice = QMediaDevices::defaultAudioInput();
    if (!inputDevice.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying nearest format.";
        format = inputDevice.preferredFormat();
    }

    // 创建 QAudioSource
    audioSource = new QAudioSource(inputDevice, format, this);
    audioDevice = audioSource->start(); // 开始捕获音频数据

    // 连接读取数据的槽函数
    connect(audioDevice, &QIODevice::readyRead, this, &AudioProcessor::readAudioData);
}

AudioProcessor::~AudioProcessor()
{
    audioSource->stop();
    delete audioSource;
}

void AudioProcessor::start()
{
    audioSource->start();
}

void AudioProcessor::stop()
{
    audioSource->stop();
}

void AudioProcessor::readAudioData()
{
    // 读取音频数据
    QByteArray buffer = audioDevice->readAll();

    // 处理音频数据并计算频谱
    QVector<double> spectrumData = processAudioBuffer(buffer);

    // 发送频谱数据
    emit spectrumDataUpdated(spectrumData);
}

QVector<double> AudioProcessor::processAudioBuffer(const QByteArray &buffer)
{
    QVector<double> spectrumData;

    // 将原始音频数据转换为 double 类型
    const qint16 *data = reinterpret_cast<const qint16 *>(buffer.constData());
    int frameCount = buffer.size() / sizeof(qint16);

    // 简单示例：计算幅度的平均值
    double sum = 0.0;
    for (int i = 0; i < frameCount; ++i) {
        sum += qAbs(data[i]) / 32768.0; // 归一化
    }
    double average = sum / frameCount;

    // 模拟频谱数据
    for (int i = 0; i < 64; ++i) {
        spectrumData.append(average * (1.0 + 0.1 * qSin(i)));
    }

    return spectrumData;
}
