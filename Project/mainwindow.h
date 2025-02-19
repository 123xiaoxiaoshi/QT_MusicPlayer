#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_lyricsinterface.h"
#include"ui_individual.h"
#include "SqlConnect.h"
#include "login.h"
#include "enroll.h"
#include "individual.h"
#include "lyricsinterface.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QtMultimedia>
#include <QListWidgetItem>
#include <QListWidget>
#include <QUrl>
#include <QFileDialog>
#include <QRandomGenerator>
#include <QComboBox>
#include <QDoubleSpinBox>
#include<QVariant>
#include<QByteArray>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QPixmap>
#include<QSize>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QVector>
#include <QMap>
#include <QRegularExpression>
#include <QPalette>
#include <QPixmap>
#include<QColorDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(LyricsInterface *parent);
    ~MainWindow();
    LyricsInterface *ly = new LyricsInterface();


private:
    Ui::MainWindow *ui;

signals:
    void handoff();     //发送界面切换的信号
    void lyrics(); //切换到歌词界面
    void individualFace();  //跳转到个人界面

public slots:
    void thisShow();    //界面显示
    void do_stateChanged(QMediaPlayer::PlaybackState state); //播放器状态发生变化
    void do_sourceChanged(const QUrl &media); //播放源发生变化
    void do_durationChanged(qint64 duration); //播放时长发生变化
    void do_positionChanged(qint64 position); //播放位置发生变化
    void do_metaDataChanged(); //元数据发生变化

    void addFile(); //添加文件
    void addCollection(); //添加收藏
    void removeLocalMusic();  //移除本地音乐
    void removeCollectionMusic();   //移除收藏音乐
    void clearFile();       //清空播放列表
    void changeMusic(const QModelIndex &index); //切换音乐
    void upMusic(); //上一首
    void nextMusic();   //下一首
    void startMusic();  //开始
    void stopMusic();   //暂停
    void soundChange(int value);  //音量调节
    void timeChange(int value); //时长变化
    void speedChange(double value); //倍速变化
    void changeMusic(QListWidgetItem *index);   //切换音乐
    void openLocalMusic();      //打开本地音乐
    void openMyCollection();    //打开我的收藏
    void changeBackgroundImg(QString imgPath);  //修改背景图片
    void changeFontColor(int r, int g, int b);  //修改字体颜色
private:
    QSqlDatabase DB;    //连接数据库
    bool isLogin  = false;  //检测用户是否处于登录状态
    bool isPage = true;     //检测用户是处于本地音乐界面还是收藏界面 默认打开就处于本地音乐界面
    //记录登陆的用户信息     默认信息
    QString userName = "小时";
    QString userPassword = "77777777";
    QString nickName = "";
    bool collection = false;    //判断是否处于收藏夹中
    bool isSound= true; //静音控制
    int soundValue = 0; //记录静音之前的声音值
    QMediaPlayer *player; //播放器
    int playWay= 1; //播放方式
    int startAndstop = 0; //控制开始暂停
    QString durationTime; //总时长，mm:ss 字符串
    QString positionTime; //当前播放到的位置，mm:ss 字符串
    QUrl getUrlFromItem(QListWidgetItem *item); //获取 item 的用户数据
    bool eventFilter(QObject *watched, QEvent *event); //事件过滤处理
    QString thisUUIDLocalMusic; //本机UUID本地音乐
    QString thisUUIDIndividuation; //本机UUID个性化


private:
    QNetworkAccessManager *networkManager1;    //网络管理
    QNetworkRequest *networkRequest1;  //网络请求
    QNetworkAccessManager *networkManager2;     //歌词获取
    QNetworkRequest * networkRequest2;
    QNetworkAccessManager *networkManagerImg;    //网络管理 图片
    QNetworkRequest *networkRequestImg;  //图片请求
    QVector<QString> m_Img; //存放图片地址
    QVector<int> m_ID;  //存放音乐ID

    int musicId,musicDuration,mvId;
    QString musicName,singerName,albumName;
    QByteArray searchInfo;
    QByteArray lyricsinter; //歌词
    QString imgUrl;
    bool isSearch = true;   //是否处于搜索界面
    void searchPlay();   //搜素播放
    QMap<int, QString> lrcMap;



private slots:
    //void replyFinished(QNetworkReply *reply);
    //void parseJson(QString json);
    //void replyFinished2(QNetworkReply *reply);
    //void parseJsonSongInfo(QString json);
    void databack(QNetworkReply *reply);
    void setImg(QNetworkReply *reply);  //设置图片
    void setLyricsinter(QNetworkReply *reply);  //歌词

};
#endif // MAINWINDOW_H
