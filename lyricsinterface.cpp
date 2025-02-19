#include "lyricsinterface.h"
#include "ui_lyricsinterface.h"
#include "mainwindow.h"
LyricsInterface::LyricsInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LyricsInterface)
{
    ui->setupUi(this);
    \
    ui->pushButton_ShowImage->setToolTip("收起歌曲详情页");    //跳转到主界面

    connect(ui->pushButton_ShowImage, &QPushButton::clicked, [=](){this->hide(); emit LyricsInterface::handoff();}); //切换到主界面


    //直方图
    data << 20 << 60 << 30 << 50 << 100 << 80;
    // 设置音频格式
    QAudioFormat format;
    format.setSampleRate(44100); // 采样率
    format.setChannelCount(1);   // 单声道
    format.setSampleFormat(QAudioFormat::Int16); // 采样格式

    // 获取默认音频输入设备
    QAudioDevice device = QMediaDevices::defaultAudioInput();
    if (device.isNull()) {
        qWarning() << "No default audio input device found!";
        return;
    }

    // 创建音频输入对象
    audioSource = new QAudioSource(device, format, this);
    audioDevice = audioSource->start(); // 开始捕获音频数据

    // 初始化定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LyricsInterface::updatePlot);
    timer->start(30); // 每 30 毫秒刷新一次

    // 连接音频数据读取信号
    connect(audioDevice, &QIODevice::readyRead, this, &LyricsInterface::readAudioData);

}



//界面显示
void LyricsInterface::thisShow()
{
    this->show();
}


LyricsInterface::~LyricsInterface()
{

    delete ui;
}


void LyricsInterface::readAudioData()
{
    // 读取音频数据
    audioBuffer.append(audioDevice->readAll());

    // 如果数据足够，进行 FFT 处理
    if (audioBuffer.size() >= 4096) { // 使用 4096 个样本进行 FFT
        performFFT(audioBuffer.left(4096));
        audioBuffer.remove(0, 4096); // 移除已处理的数据
    }
}

void LyricsInterface::performFFT(const QByteArray &data)
{
    // 将音频数据转换为浮点数
    QVector<double> samples;
    const int16_t *ptr = reinterpret_cast<const int16_t *>(data.constData());
    for (int i = 0; i < data.size() / 2; ++i) {
        samples.append(static_cast<double>(ptr[i]) / 32768.0); // 归一化
    }

    // 简单的 FFT 实现（实际项目中可以使用 FFTW 或 KissFFT）
    frequencyData.resize(samples.size() / 2);
    for (int i = 0; i < frequencyData.size(); ++i) {
        frequencyData[i] = std::abs(samples[i]); // 计算幅度
    }
}

void LyricsInterface::updatePlot()
{
    // 更新 UI
    update();
}



//在QWidget所在类重写paintEvent函数
void LyricsInterface::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
/*
    //直方图
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 设置背景颜色
    //painter.fillRect(rect(), Qt::white);

    // 设置直方图的颜色
    painter.setBrush(Qt::green);
    //painter.setPen(Qt::blue);
    if (frequencyData.isEmpty()) {
            return; // 如果为空，直接返回
        }
    // 绘制直方图
    //int barWidth = width() / frequencyData.size();
    int barWidth = width() /frequencyData.size() +4;
   // int color = 0;
    for (int i = 0; i < frequencyData.size(); ++i) {
        int barHeight = static_cast<int>(frequencyData[i] * height());
      int color = barHeight % 6;
        switch(color)
        {
            case 0:painter.setBrush(Qt::green);break;
            case 1:painter.setBrush(Qt::red);break;
            case 2:painter.setBrush(Qt::blue);break;
            case 3:painter.setBrush(Qt::cyan);break;
            case 4:painter.setBrush(Qt::yellow);break;
            case 5:painter.setBrush(Qt::gray);break;
            default : painter.setBrush(Qt::transparent);break;

        }
        qDebug() << "Height: " << barHeight << "\n";
        qDebug() << "Width: " << barHeight << "\n";

        //QColor color = QColor::fromHsvF(barHeight % 9, 0, 9); // HSV 颜色模型
        //painter.setBrush(color);

        barHeight = barHeight / 2;
        if(i * barWidth+285 < 1350)
        {
            painter.drawRect(i * barWidth+285, height() - barHeight-110, 6, barHeight);
        }
        //audioSource->stop();
        //audioDevice = audioSource->start();
    }
    /*
    // 计算直方图的宽度和间距
    int barWidth = width() / 100;
    qDebug() << width() << "\n";
    int spacing = 5;

    // 绘制直方图
    for (int i = 0; i < data.size(); ++i)
    {
        int barHeight = (data[i] * height()) / 300; // 根据数据计算高度
        int x = i * (barWidth + spacing);
        int y = height() - barHeight;
       qDebug() << y;
        painter.drawRect(x+300, y-110, barWidth, barHeight);
    }
    */
}
