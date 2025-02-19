#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lyricsinterface.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("#centralwidget{border-image: url(:/Image/Beijing10.png);}");
    CreateConnection(DB);   //连接数据库
    //创建一个本地歌曲表以及个性化表
    //获取每台计算机的唯一标识
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"wmic csproduct get uuid");
    p.waitForStarted();
    p.waitForFinished();
    QString uuidInfo=QString::fromLocal8Bit(p.readAllStandardOutput());  //获得输出
    QStringList ulist = uuidInfo.split(" ");
    uuidInfo.remove(ulist.first(),Qt::CaseInsensitive);
    uuidInfo.remove(ulist.last());
    uuidInfo.replace("\r", "");
    uuidInfo.replace("\n", "");
    uuidInfo.remove(" ");
    uuidInfo.remove("-");
    thisUUIDLocalMusic = uuidInfo+"L";
    thisUUIDIndividuation = uuidInfo+"I";
    QSqlQuery query(DB);
    QString str = QString("SHOW TABLES LIKE '%0' ").arg(thisUUIDLocalMusic); //查询表是否存在
    query.exec(str);
    bool isLocalMusic = false;
    while(query.next())
    {
            isLocalMusic = true;
    }
    if(!isLocalMusic)   //如果表不存在创建表
    {
        QString str2 = QString("create table %0(musicName varchar(128), musicPath varchar(128)) ").arg(thisUUIDLocalMusic);
        query.exec(str2);
    }
    QString str3 = QString("SHOW TABLES LIKE '%0' ").arg(thisUUIDIndividuation); //查询表是否存在
    query.exec(str3);
    bool isIndividuation = false;
    while(query.next())
    {
            isIndividuation = true;
    }
    if(!isIndividuation)   //如果表不存在创建表
    {
        QString str3 = QString("create table %0 (r varchar(128), g varchar(128), b varchar(128), imgPath varchar(128)) ").arg(thisUUIDIndividuation);
        query.exec(str3);
        //插入初始值
        QString str4 = QString("insert into %0 (r, g, b, imgPath) values( '0', '255', '0', ':/Image/Beijing10.png');").arg(thisUUIDIndividuation);
        query.exec(str4);
    }


    //默认背景图片歌词字体颜色

    QString str1 = QString("select * from %0").arg(thisUUIDIndividuation);
    query.exec(str1);
    while(query.next())
    {
        ly->ui->widget_2->setStyleSheet(QString("color: rgb(%0, %1, %2);").arg(query.value(0).toInt()).arg(query.value(1).toInt()).arg(query.value(2).toInt()));
        this->setStyleSheet(QString("MainWindow{border-image: url(%0);}").arg(query.value(3).toString()));
        ly->setStyleSheet(QString("LyricsInterface{border-image: url(%0);}").arg(query.value(3).toString()));
    }
    this->setWindowTitle("轻音乐");
    ui->pushButton_ShowImage->setToolTip("查看歌词");       //鼠标悬浮在图片上方显示歌词界面提示
    ui->pushButton_Background->setToolTip("修改背景图片");
    ly->ui->pushButton_FontColor->setToolTip("修改字体颜色");
    ui->listWidget->installEventFilter(this); //安装事件过滤器
    ui->listWidget->setDragEnabled(true); //允许拖放操作
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
    //收藏按钮默认隐藏
    ui->pushButton_AddCollection->setVisible(false);
    ly->ui->pushButton_AddCollection->setVisible(false);

    //没有播放源各个控件不能操作
    ui->pushButton_Start->setEnabled(false);
    ui->pushButton_Next->setEnabled(false);
    ui->pushButton_Up->setEnabled(false);
    ui->pushButton_ShowImage->setEnabled(false);
    ui->horizontalSlider_Time->setEnabled(false);
    ui->horizontalSlider_Sound->setEnabled(false);
    ui->pushButton_Sound->setEnabled(false);
    ly->ui->pushButton_Sound->setEnabled(false);





    //列表项可在组件内部被拖放
    player= new QMediaPlayer(this);
    QAudioOutput *audioOutput= new QAudioOutput(this); //音频输出，指向默认的音频输出设备
    player->setAudioOutput(audioOutput); //设置音频输出


    Login *l = new Login();
    Enroll *e = new Enroll();
    //LyricsInterface *ly = new LyricsInterface();
    Individual *in = new Individual();


    networkManager1 = new QNetworkAccessManager();
    networkRequest1 = new QNetworkRequest();
    networkManager2 = new QNetworkAccessManager();
    networkRequest2 = new QNetworkRequest();
    networkManagerImg = new QNetworkAccessManager();
    networkRequestImg = new QNetworkRequest();




    connect(player,&QMediaPlayer::positionChanged, //播放位置发生变化
            this, &MainWindow::do_positionChanged);
    connect(player,&QMediaPlayer::durationChanged, //播放时长发生变化
            this, &MainWindow::do_durationChanged);
    connect(player, &QMediaPlayer::sourceChanged, //播放源发生变化
            this, &MainWindow::do_sourceChanged);
    connect(player, &QMediaPlayer::playbackStateChanged, //播放器状态发生变化
            this, &MainWindow::do_stateChanged);
    connect(player, &QMediaPlayer::metaDataChanged, //元数据发生变化
            this, &MainWindow::do_metaDataChanged);

    connect(networkManager1, &QNetworkAccessManager::finished, this, &MainWindow::databack);        //搜索请求
    connect(networkManagerImg, &QNetworkAccessManager::finished, this, &MainWindow::setImg);        //图片
    connect(networkManager2, &QNetworkAccessManager::finished, this, &MainWindow::setLyricsinter);  //歌词

    //界面切换 信号与槽的连接
    //登录、注册之间的界面切换
    QObject::connect(l, &Login::handoff, e, &Enroll::thisShow);
    QObject::connect(e, &Enroll::handoff, l, &Login::thisShow);
    //登录、主界面之间的界面切换
    QObject::connect(l, &Login::handoffMain, [=](){
        //接收到登录信号记录用户信息
        MainWindow::thisShow();
        this->userName = l->userName;
        this->userPassword = l->userPassward;
        in->ui->lineEdit_Account->setText(this->userName);
        //qDebug() << userName;
        isLogin = true;
        //按键文本改变 显示用户昵称 如果用户昵称为空则显示用户名
        QSqlQuery query(DB);
        //QString nickName;
        QString str1 = QString("select * from userTable where userName = '%0' ").arg(userName);
         query.exec(str1);
         while(query.next())
         {
           nickName = query.value(2).toString();
         }
         if(nickName.isEmpty())
         {
             ui->pushButton_Login->setText(userName);
         }
        else
         {
             ui->pushButton_Login->setText(nickName);
         }
    });
    QObject::connect(l, &Login::backMain, this, & MainWindow::thisShow);
    QObject::connect(this, &MainWindow::handoff, l, &Login::thisShow);
    //主界面、歌词界面之间的界面切换
    QObject::connect(this, &MainWindow::lyrics, ly, &LyricsInterface::thisShow);
    QObject::connect(ly, &LyricsInterface::handoff, this, &MainWindow::thisShow);
    //主界面与个人界面的切换
    QObject::connect(this, &MainWindow::individualFace, in, &Individual::thisShow);  //发送切换到个人界面信号
    QObject::connect(in, &Individual::back, this, [=](){
        //按键文本改变 显示用户昵称 如果用户昵称为空则显示用户名
        QSqlQuery query(DB);
        //QString nickName;
        QString str1 = QString("select * from userTable where userName = '%0' ").arg(userName);
         query.exec(str1);
         while(query.next())
         {
           nickName = query.value(2).toString();
         }
         if(nickName.isEmpty())
         {
             ui->pushButton_Login->setText(userName);
         }
        else
         {
             ui->pushButton_Login->setText(nickName);
         }
        MainWindow::thisShow();});   //接收到返回信号返回
    //接收到退出登录信号
    QObject::connect(in, &Individual::exitLogin,[=](){
        MainWindow::thisShow();
        isLogin = false;
        ui->pushButton_Login->setText("登录");
    });

    //切换收藏按键图标


    //点击登录切换到登录界面
    connect(ui->pushButton_Login, &QPushButton::clicked, [=](){
        //用户处于未登录状态
        if(ui->pushButton_Login->text() == "登录")
        {
            this->hide();
            emit MainWindow::handoff();
        }
        //用户处于已经登录状态跳转到个人界面
        else
        {
            //跳转到个人界面
            this->hide();
            emit MainWindow::individualFace();
        }
    });


    connect(ui->pushButton_ShowImage, &QPushButton::clicked, [=](){this->hide();
        if(ly->ui->label_4->text().isEmpty())
        {
             ly->ui->label_4->setText("暂无歌词信息");
        }
        emit MainWindow::lyrics();});     //切换到歌词界面
    //选择播放方式
    connect(ui->comboBox_PlayWay, &QComboBox::currentIndexChanged, [=](int index){
       switch(index)
       {
       case 0: playWay = 1; return;
       case 1: playWay = 2; return;
       case 2: playWay = 3; return;
       }
    });



    //按键触发
    //开始暂停
    connect(ui->pushButton_Start, &QPushButton::clicked, [=](){
        startAndstop++;
        if(startAndstop % 2 == 0)
        {
            ui->pushButton_Start->setStyleSheet("qproperty-icon: url(:/Image/Kaishi.png);icon-size: 40px 40px;");   //图片变化
            ly->ui->pushButton_Start->setStyleSheet("qproperty-icon: url(:/Image/Kaishi.png);icon-size: 40px 40px;");   //图片变化
            MainWindow::startMusic();
        }
        else
        {
            ui->pushButton_Start->setStyleSheet("qproperty-icon: url(:/Image/Zanting.png);icon-size: 40px 40px;");
            ly->ui->pushButton_Start->setStyleSheet("qproperty-icon: url(:/Image/Zanting.png);icon-size: 40px 40px;");
            MainWindow::stopMusic();
        }
        //startAndstop++;
    });
    connect(ly->ui->pushButton_Start, &QPushButton::clicked, [=](){
        startAndstop++;
        if(startAndstop % 2 == 0)
        {
            MainWindow::startMusic();
        }
        else
        {
            MainWindow::stopMusic();
        }
        //startAndstop++;
    });
    //上一首
    connect(ui->pushButton_Up, &QPushButton::clicked, [=](){
        MainWindow::upMusic();
    });
    connect(ly->ui->pushButton_Up, &QPushButton::clicked, [=](){
        MainWindow::upMusic();
    });
    //下一首
    connect(ui->pushButton_Next, &QPushButton::clicked, [=](){
        MainWindow::nextMusic();
    });
    connect(ly->ui->pushButton_Next, &QPushButton::clicked, [=](){
        MainWindow::nextMusic();
    });
    //音量调节
    connect(ui->horizontalSlider_Sound, &QAbstractSlider::sliderMoved, [=](int value){
        MainWindow::soundChange(value);
    });
    connect(ly->ui->horizontalSlider_Sound, &QAbstractSlider::sliderMoved, [=](int value){
        MainWindow::soundChange(value);
    });
    //时长变化
    connect(ui->horizontalSlider_Time, &QAbstractSlider::sliderMoved,[=](int value){
        MainWindow::timeChange(value);
    });
    connect(ly->ui->horizontalSlider_Time, &QAbstractSlider::sliderMoved,[=](int value){
        MainWindow::timeChange(value);
    });
    //倍速
    connect(ui->doubleSpinBox, &QDoubleSpinBox::valueChanged,[=](double value){
        MainWindow::speedChange(value);
    });
    connect(ly->ui->doubleSpinBox, &QDoubleSpinBox::valueChanged,[=](double value){
        MainWindow::speedChange(value);
    });
    //静音
    connect(ui->pushButton_Sound, &QPushButton::clicked, [=](){
        if(isSound)
        {
            soundValue = ui->horizontalSlider_Sound->value();
            ui->horizontalSlider_Sound->setValue(0);
            isSound = false;
            ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Jingyin.png);icon-size: 40px 40px;");
            ly->ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Jingyin.png);icon-size: 40px 40px;");
            player->audioOutput()->setVolume(0); //0～1
        }
        else
        {
            ui->horizontalSlider_Sound->setValue(soundValue);
            isSound = true;
            ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Shengyin.png);icon-size: 40px 40px;");
            ly->ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Shengyin.png);icon-size: 40px 40px;");
            player->audioOutput()->setVolume(soundValue/100.0); //0～1
        }
    });
    connect(ly->ui->pushButton_Sound, &QPushButton::clicked, [=](){
        if(isSound)
        {
            soundValue = ui->horizontalSlider_Sound->value();
            ui->horizontalSlider_Sound->setValue(0);
            isSound = false;
            ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Jingyin.png);icon-size: 40px 40px;");
            ly->ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Jingyin.png);icon-size: 40px 40px;");
            player->audioOutput()->setVolume(0); //0～1
        }
        else
        {
            ui->horizontalSlider_Sound->setValue(soundValue);
            isSound = true;
            ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Shengyin.png);icon-size: 40px 40px;");
            ly->ui->pushButton_Sound->setStyleSheet("qproperty-icon: url(:/Image/Shengyin.png);icon-size: 40px 40px;");
            player->audioOutput()->setVolume(soundValue/100.0); //0～1
        }
    });
    //切换音乐
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, [=](QListWidgetItem *item){
        MainWindow::  changeMusic(item);
    });
    //添加音乐
    connect(ui->pushButton_AddMusic, &QPushButton::clicked, [=](){
        if(isPage)  //处于本地界面
        {
            MainWindow::addFile();
        }
        else    //处于收藏界面
        {
            MainWindow::addCollection();
        }
    });
    //添加收藏
    connect(ui->pushButton_AddCollection, &QPushButton::clicked, [=](){
        if(!isLogin)
        {
            QMessageBox::information(this, "警告", QString("请先登录账号"), QMessageBox::Ok);
        }
        else
        {
            if(collection)    //处于收藏夹中删除
            {
                MainWindow::removeCollectionMusic();
            }
            else    //未处于收藏夹中添加收藏
            {
                MainWindow::addCollection();
            }
        }
    });
    //删除音乐
    connect(ui->pushButton_DeleteMusic, &QPushButton::clicked, [=](){
        if(isPage)      //处于本地界面
        {
            MainWindow::removeLocalMusic();
        }
        else    //处于收藏界面
        {
            MainWindow::removeCollectionMusic();
        }
    });
    //本地音乐
    connect(ui->pushButton_LocalMusic, &QPushButton::clicked, [=](){

        //处于搜索界面添加与删除可点击
        ui->pushButton_AddMusic->setEnabled(true);
        ui->pushButton_DeleteMusic->setEnabled(true);
        //ui->pushButton_AddCollection->setVisible(true);
        //ly->ui->pushButton_AddCollection->setVisible(true);
        isPage = true;
        isSearch = false;
        MainWindow::openLocalMusic();
    });
    //我的收藏
    connect(ui->pushButton_MyCollection, &QPushButton::clicked, [=](){
        if(!isLogin)
        {
            QMessageBox::information(this, "警告", QString("请先登录账号"), QMessageBox::Ok);
        }
        else
        {
            //处于搜索界面添加与删除可点击
            ui->pushButton_AddMusic->setEnabled(true);
            ui->pushButton_DeleteMusic->setEnabled(true);
            //ui->pushButton_AddCollection->setVisible(true);
            //ly->ui->pushButton_AddCollection->setVisible(true);
            isPage = false;
            isSearch = false;
            MainWindow::openMyCollection();
        }

    });
    //搜索
    connect(ui->pushButton_Search, &QPushButton::clicked, [=]()
    {
        //处于搜索界面添加与删除不能点击
        ui->pushButton_AddMusic->setEnabled(false);
        ui->pushButton_DeleteMusic->setEnabled(false);
        ui->pushButton_AddCollection->setVisible(false);
        ly->ui->pushButton_AddCollection->setVisible(false);
        isSearch = true;
        ui->listWidget->clear();    //先清空
        m_Img.clear();
        m_ID.clear();
        QString str = ui->lineEdit_Search->text();
        //网易云API
        QString search = QString("http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+str+"}&type=1&offset=0&total=true&limit=20");
        //http://openapi.music.163.com/openapi/music/basic/search/song/get/v2
        networkRequest1->setUrl(QUrl(search));
        networkManager1->get(*networkRequest1);
    });
    connect(ui->pushButton_Search2, &QPushButton::clicked, [=](){
        //处于搜索界面添加与删除不能点击
        ui->pushButton_AddMusic->setEnabled(false);
        ui->pushButton_DeleteMusic->setEnabled(false);
        ui->pushButton_AddCollection->setVisible(false);
        ly->ui->pushButton_AddCollection->setVisible(false);
        ui->listWidget->clear();    //先清空
        m_Img.clear();
        m_ID.clear();
        isSearch = true;
    });
    //更该背景图片
    connect(ui->pushButton_Background, &QPushButton::clicked, [=](){
        QString curPath= QDir::homePath(); //获取系统当前目录
        QString dlgTitle= "选择图片";
        QString filter= "图片(*.jpg *.png *.bmp);;所有文件(*.*)"; //文件过滤器
        QString file= QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if (file.isEmpty())
        {
            return;
        }
        else
        {
            //图片路径存入数据库中下次打开还是这张背景图
            QSqlQuery query(DB);
            QString str1 = QString("update %0 set imgPath = '%0'").arg(thisUUIDIndividuation).arg(file);
            query.exec(str1);
            this->setStyleSheet(QString("MainWindow{border-image: url(%0);}").arg(file));
            ly->setStyleSheet(QString("LyricsInterface{border-image: url(%0);}").arg(file));
        }
    });

    //修改歌词颜色
    connect(ly->ui->pushButton_FontColor, &QPushButton::clicked, [=](){
        QColor color = QColorDialog::getColor(Qt::red);
        QSqlQuery query(DB);
        QString str1 = QString("update %0 set r = '%1', g = '%2', b = '%3' ").arg(thisUUIDIndividuation).arg(color.red()).arg(color.green()).arg(color.blue());
        query.exec(str1);
        ly->ui->label_1->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_2->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_3->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_4->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 18pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_5->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_6->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_7->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_8->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_9->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
        ly->ui->label_10->setStyleSheet(QString("color: rgb(%0, %1, %2);font: 12pt;").arg(color.red()).arg(color.green()).arg(color.blue()));
    });

}

//界面显示
void MainWindow::thisShow()
{
    this->show();
}
//事件过滤处理器
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() != QEvent::KeyPress)      //不是 KeyPress 事件，退出
        return QWidget::eventFilter(watched,event);
    QKeyEvent *keyEvent= static_cast<QKeyEvent *>(event);
    if (keyEvent->key() != Qt::Key_Delete)      //按下的不是 Delete 键，退出
        return QWidget::eventFilter(watched,event);
    if (watched == ui->listWidget)
    {
        QListWidgetItem *item= ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;
    }
    return true;
}
//播放的文件发生变化
void MainWindow::do_sourceChanged(const QUrl &media)
{
    //清空歌词信息
    ly->ui->label_1->setText("");
    ly->ui->label_2->setText("");
    ly->ui->label_3->setText("");
    ly->ui->label_4->setText("");
    ly->ui->label_5->setText("");
    ly->ui->label_6->setText("");
    ly->ui->label_7->setText("");
    ly->ui->label_8->setText("");
    ly->ui->label_9->setText("");
    ly->ui->label_10->setText("");
    //显示当前播放的曲目名称，不带路径
    ui->label_MusicName->setText(media.fileName());
    ly->ui->label_MusicName->setText(media.fileName());
    //判断当前文件是否处于收藏夹中
    if(isLogin)     //是否处于登录状态
    {
        QSqlQuery query(DB);
        QString musicName = media.fileName();

        QString  musicListName = userName + "CollectionPlayLists";    //收藏表名
        QString str1 = QString("select musicName from %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
        query.exec(str1);
        QString Qname;
        while(query.next())
        {
            Qname = query.value(0).toString();
        }
        qDebug() << musicName << "\t" << Qname;
        if(Qname == musicName)      //如果位于收藏夹中
        {
            collection = true;
            ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin1.png);icon-size: 30px 30px;");   //图片变化
            ly->ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin1.png);icon-size: 30px 30px;");   //图片变化
        }
        else
        {
            collection = false;
            ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/AiXin2.png);icon-size: 30px 30px;");   //图片变化
            ly->ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/AiXin2.png);icon-size: 30px 30px;");   //图片变化
        }
    }
}
//元数据变化时，显示歌曲对应的图片
void MainWindow::do_metaDataChanged()
{
    if(isSearch)            //处于搜索界面
    {
        QUrl url;
        QString str = m_Img.at(ui->listWidget->currentRow());
        url = QUrl(str);
        networkRequestImg->setUrl(url);
        networkManagerImg->get(*networkRequestImg);
    }
    else
    {
        QMediaMetaData metaData= player->metaData(); //元数据对象
        QVariant metaImg= metaData.value(QMediaMetaData::ThumbnailImage); //图片数据
        if (metaImg.isValid())
        {
            QImage img= metaImg.value<QImage>(); //QVariant 转换为 QImage
            QPixmap musicPixmp= QPixmap::fromImage(img);
            ui->pushButton_ShowImage->setIcon(musicPixmp);       //设置图片
            ui->pushButton_ShowImage->setIconSize(ui->pushButton_ShowImage->size());     //设置图片大小
            ly->ui->pushButton_ShowImage->setIcon(musicPixmp);       //设置图片
            ly->ui->pushButton_ShowImage->setIconSize(ui->pushButton_ShowImage->size());     //设置图片大小
        }
    }

}
//播放源时长发生变化时，更新进度显示
void MainWindow::do_durationChanged(qint64 duration)
{
    ui->horizontalSlider_Time->setMaximum(duration);
    ly->ui->horizontalSlider_Time->setMaximum(duration);
    int secs= duration/1000; //秒
    int mins= secs/60; //分钟
    secs= secs % 60; //取余数秒
    durationTime= QString::asprintf("%d:%d",mins,secs);
    //时长
    ui->label_Time->setText(durationTime);
    ui->label_PassTime->setText(positionTime);
    ly->ui->label_Time->setText(durationTime);
    ly->ui->label_PassTime->setText(positionTime);
}
//播放位置发生变化时，更新进度显示
void MainWindow::do_positionChanged(qint64 position)
{
    if (ui->horizontalSlider_Time->isSliderDown() || ly->ui->horizontalSlider_Time->isSliderDown()) //滑条正在被鼠标拖动
        return;
    ui->horizontalSlider_Time->setSliderPosition(position);
    ly->ui->horizontalSlider_Time->setSliderPosition(position);
    int secs= position/1000; //秒
    int mins= secs/60; //分钟
    secs= secs % 60; //取余数秒
    positionTime= QString::asprintf("%d:%d",mins,secs);
    ui->label_Time->setText(durationTime);
    ui->label_PassTime->setText(positionTime);
    ly->ui->label_Time->setText(durationTime);
    ly->ui->label_PassTime->setText(positionTime);

    int pos = position;
    QMap<int, QString>::iterator iter = lrcMap.begin();
    while (iter != lrcMap.end())
            {
                if(pos-50<=iter.key()&& pos+50>=iter.key())
                {
                        int j=0;
                        if(iter != lrcMap.begin())
                        {
                            iter--;
                            ly->ui->label_3->setText(iter.value());
                            j++;
                        }
                        if(iter != lrcMap.begin())
                        {
                            iter--;
                            ly->ui->label_2->setText(iter.value());
                            j++;
                        }

                        if(iter != lrcMap.begin())
                        {
                            iter--;
                            ly->ui->label_1->setText(iter.value());
                            j++;
                        }
                        for(;j>0;j--)
                        {
                            iter++;
                        }
                   //中间
                   ly->ui->label_4->setText(iter.value());
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_5->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_5->setText("");
                       return;
                   }
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_6->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_6->setText("");
                       return;
                   }
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_7->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_7->setText("");
                       return;
                   }
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_8->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_8->setText("");
                       return;
                   }
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_9->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_9->setText("");
                       return;
                   }
                   iter++;
                   if(iter != lrcMap.end())
                   {
                       ly->ui->label_10->setText(iter.value());
                   }
                   else
                   {
                       ly->ui->label_10->setText("");
                       return;
                   }
                }
                iter++;
            }
}
//播放器状态变化时，更新按钮状态，或播放下一曲
void MainWindow::do_stateChanged(QMediaPlayer::PlaybackState state)
{
    //有播放源各个控件能操作
    ui->pushButton_Start->setEnabled(true);
    ui->pushButton_Next->setEnabled(true);
    ui->pushButton_Up->setEnabled(true);
    ui->pushButton_ShowImage->setEnabled(true);
    ui->horizontalSlider_Time->setEnabled(true);
    ui->horizontalSlider_Sound->setEnabled(true);
    ui->pushButton_Sound->setEnabled(true);
    ly->ui->pushButton_Sound->setEnabled(true);

    ui->pushButton_AddCollection->setVisible(true);
    ly->ui->pushButton_AddCollection->setVisible(true);
    //处于搜索界面
    if(isSearch)
    {
        //列表循环
        if(playWay == 1 && (state == QMediaPlayer::StoppedState))
        {
            int count= ui->listWidget->count();
            int curRow= ui->listWidget->currentRow();
            curRow++;
            curRow= curRow>=count? 0:curRow;
            ui->listWidget->setCurrentRow(curRow);
            MainWindow::searchPlay();
        }
        //单曲循环
        if(playWay == 2 && (state == QMediaPlayer::StoppedState))
        {
            int curRow= ui->listWidget->currentRow();
            ui->listWidget->setCurrentRow(curRow);
            MainWindow::searchPlay();
        }
        //随机播放
        if(playWay == 3 && (state == QMediaPlayer::StoppedState))
        {
            int randomInRange = QRandomGenerator::global()->bounded(0, ui->listWidget->count()); //生成0到ui->listWidget->count()之间的随机数
            ui->listWidget->setCurrentRow(randomInRange);
            MainWindow::searchPlay();
        }
       if(player->playbackState() != QMediaPlayer::PlayingState)
       {
            QMessageBox::information(this, "警告", "暂无音频信息");
       }
    }
    else
    {
        //列表循环
        if(playWay == 1 && (state == QMediaPlayer::StoppedState))
        {
            int count= ui->listWidget->count();
            int curRow= ui->listWidget->currentRow();
            curRow++;
            curRow= curRow>=count? 0:curRow;
            ui->listWidget->setCurrentRow(curRow);
            player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
            player->play();
        }
        //单曲循环
        if(playWay == 2 && (state == QMediaPlayer::StoppedState))
        {
            int curRow= ui->listWidget->currentRow();
            ui->listWidget->setCurrentRow(curRow);
            player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
            player->play();
        }
        //随机播放
        if(playWay == 3 && (state == QMediaPlayer::StoppedState))
        {
            int randomInRange = QRandomGenerator::global()->bounded(0, ui->listWidget->count()); //生成0到ui->listWidget->count()之间的随机数
            ui->listWidget->setCurrentRow(randomInRange);
            player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
            player->play();
            qDebug() << randomInRange << ui->listWidget->count();
        }
    }
}
//返回 item 的用户数据
QUrl MainWindow::getUrlFromItem(QListWidgetItem *item)
{
    QVariant itemData= item->data(Qt::UserRole); //获取用户数据
    QUrl source= itemData.value<QUrl>(); //QVariant 转换为 QUrl 类型
    return source;
}
//“添加”按钮，添加文件  //数据添加到数据库中
void MainWindow::addFile()
{
    QString curPath= QDir::homePath(); //获取系统当前目录
    QString dlgTitle= "选择音频文件";
    QString filter= "音频文件(*.mp3 *.wav *.wma);;所有文件(*.*)"; //文件过滤器
    QStringList fileList= QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
    if (fileList.count()<1)
        return;
    //将数据写入本地音乐表中
    for(int i = 0; i < fileList.size(); i++)
    {
        QSqlQuery query(DB);
        QString aFile= fileList.at(i);
        QFileInfo fileInfo(aFile);
        QString musicName = fileInfo.fileName(); //文件名
        QString musicPath = aFile;  //完整路径
        //查看文件是否已经存在避免重复写入
        QString str1 = QString("select musicName from  %0 where musicName = '%1' ").arg(thisUUIDLocalMusic).arg(musicName);
        query.exec(str1);
        QString Qname;
        while(query.next())
        {
            Qname =  query.value(0).toString();
        }
        if(Qname == musicName)
        {
            QMessageBox::information(this, "警告", QString("%0已存在").arg(musicName), QMessageBox::Ok);
        }
        else
        {
            //向数据表中写入数据
            QString str2 = QString("insert into %0 (musicName, musicPath) values ('%1', '%2')").arg(thisUUIDLocalMusic).arg(musicName).arg(musicPath);
            query.exec(str2);
           //在表中查询有没有写入
            QString str3 =  QString ("select musicName from  %0 where musicName = '%1' ").arg(thisUUIDLocalMusic).arg(musicName);
            query.exec(str3);
            while(query.next())
            {
                Qname =  query.value(0).toString();

            }
            if(Qname == musicName)
            {
                //QMessageBox::information(this, "成功", QString("%0添加成功").arg(musicName), QMessageBox::Ok);
                //刷新界面
                MainWindow::openLocalMusic();
            }
            else
            {
                QMessageBox::information(this, "警告", QString("%0添加失败").arg(musicName), QMessageBox::Ok);
            }
        }
    }
}
 //添加收藏
 void MainWindow::addCollection()
 {
     QSqlQuery query(DB);
     QString musicName;
     QString musicPath;
     QListWidgetItem *item = ui->listWidget->currentItem(); //获取当前文件
     QVariant itemData= item->data(Qt::UserRole); //获取用户数据
     QUrl source= itemData.value<QUrl>(); //QVariant 转换为 QUrl 类
     musicName = item->text();  //获取文件名
     musicPath = source.toLocalFile();  //获取文件路径
     QString  musicListName = userName + "CollectionPlayLists";    //收藏表名
     //查看文件是否已经存在避免重复写入
     QString str1 = QString("select musicName from  %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
     query.exec(str1);
     QString Qname;

     while(query.next())
     {
         Qname =  query.value(0).toString();
     }
     if(Qname == musicName)
     {
         //QString str2 = QString("delete from %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
         //query.exec(str2);
         //QMessageBox::information(this, "提示", QString("%0已移出收藏夹").arg(musicName), QMessageBox::Ok);
         //ui->pushButton_AddCollection->setText("收藏");
     }
     else
     {
         qDebug() << musicListName;
         //向数据表中写入数据
         QString str2 = QString("insert into %0(musicName, musicPath) values ('%1', '%2')").arg(musicListName).arg(musicName).arg(musicPath);
         query.exec(str2);
        //在表中查询有没有写入
         QString str3 =  QString ("select musicName from  %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
         query.exec(str3);
         while(query.next())
         {
             Qname =  query.value(0).toString();

         }
         if(Qname == musicName)
         {
             //QMessageBox::information(this, "成功", QString("%0已添加至收藏").arg(musicName), QMessageBox::Ok);
             ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin1.png);icon-size: 30px 30px;");   //图片变化
             ly->ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin1.png);icon-size: 30px 30px;");   //图片变化
             //刷新界面
             MainWindow::openMyCollection();
         }
         else
         {
             QMessageBox::information(this, "警告", QString("%0添加至收藏失败").arg(musicName), QMessageBox::Ok);
         }
     }
 }
//“移除”按钮，移除本地音乐
void MainWindow::removeLocalMusic()
{
    int index= ui->listWidget->currentRow();
    if (index >=0)
    {
        QListWidgetItem *item= ui->listWidget->takeItem(index);
        QSqlQuery query(DB);
        QString musicName = item->text();
        QString str1 = QString("delete from %0 where musicName = '%1' ").arg(thisUUIDLocalMusic).arg(musicName);
        query.exec(str1);
        //在表中查询有没有移除
        QString Qname;
         QString str3 =  QString ("select musicName from  %0 where musicName = '%1' ").arg(thisUUIDLocalMusic).arg(musicName);
         query.exec(str3);
         while(query.next())
         {
             Qname =  query.value(0).toString();

         }
         if(Qname != musicName)
         {
             QMessageBox::information(this, "成功", QString("%0移除成功").arg(musicName), QMessageBox::Ok);
             delete item;
         }
         else
         {
             QMessageBox::information(this, "警告", QString("%0移除失败").arg(musicName), QMessageBox::Ok);
         }

    }
}
//移除收藏音乐
void MainWindow::removeCollectionMusic()
{
    int index= ui->listWidget->currentRow();
    if (index >=0)
    {
        QListWidgetItem *item= ui->listWidget->takeItem(index);
        QSqlQuery query(DB);
        QString musicName = item->text();
        QString  musicListName = userName + "CollectionPlayLists";    //收藏表名
        QString str1 = QString("delete from %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
        query.exec(str1);
        //在表中查询有没有移除
        QString Qname;
         QString str3 =  QString ("select musicName from  %0 where musicName = '%1' ").arg(musicListName).arg(musicName);
         query.exec(str3);
         while(query.next())
         {
             Qname =  query.value(0).toString();
         }
         if(Qname != musicName)
         {
             QMessageBox::information(this, "成功", QString("%0取消收藏").arg(musicName), QMessageBox::Ok);
             ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin2.png);icon-size: 30px 30px;");   //图片变化
             ly->ui->pushButton_AddCollection->setStyleSheet("qproperty-icon: url(:/Image/Aixin2.png);icon-size: 30px 30px;");   //图片变化
         }
         else
         {
             QMessageBox::information(this, "警告", QString("%0移除失败").arg(musicName), QMessageBox::Ok);
         }
    }
}
//“清空”按钮，清空播放列表
void MainWindow::clearFile()
{
    //loopPlay= false; //防止 do_stateChanged()里切换曲目
    ui->listWidget->clear();
    player->stop();
}
//切换音乐
void MainWindow::changeMusic(const QModelIndex &index)
{
    Q_UNUSED(index);
    int temp = playWay;
    playWay= 0; //暂时设置为 false，防止 do_stateChanged()切换曲目
    player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
    player->play();
    playWay =  temp;
}
//上一曲
void MainWindow::upMusic()
{
    int curRow= ui->listWidget->currentRow();
    curRow--;
    curRow = curRow<0? 0:curRow;
    ui->listWidget->setCurrentRow(curRow); //设置当前行
    if(isSearch)    //处于搜索页
    {
        MainWindow::searchPlay();
    }
    else
    {
        int temp = playWay;
        playWay = 0; //暂时设置为 false，防止 do_stateChanged()切换曲目
        player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
        player->play();
        playWay =  temp;
    }
}
//下一曲
void MainWindow::nextMusic()
{
    int tt = ui->listWidget->count()-1;
    int curRow= ui->listWidget->currentRow();
    curRow++;
    curRow = curRow>tt?  tt:curRow;
    ui->listWidget->setCurrentRow(curRow); //设置当前行
    if(isSearch)    //处于搜索页
    {
        MainWindow::searchPlay();
    }
    else
    {
        int temp = playWay;
        playWay = 0;//暂时设置为 false，防止 do_stateChanged()切换曲目
        player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
        player->play();
        playWay =  temp;
    }
}
//开始
void MainWindow::startMusic()
{
    //如果歌曲处于暂停状态点击开始继续播放
    if(player->playbackState() == QMediaPlayer::PausedState)
    {
        player->play();
        return;
    }
    //开始播放
     if (ui->listWidget->currentRow() < 0) //没有选择曲目则播放第一个
     ui->listWidget->setCurrentRow(0);
     player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
     player->play();
}
//暂停
void MainWindow::stopMusic()
{
     player->pause();
}
//音量调节
void MainWindow::soundChange(int value)
{
     player->audioOutput()->setVolume(value/100.0); //0～1
}
//时长变化
void MainWindow::timeChange(int value)
{
    player->setPosition(value);
}
//倍速
void MainWindow::speedChange(double value)
{
    player->setPlaybackRate(value);
}
 //双击 listWidget 时切换曲目
void MainWindow::changeMusic(QListWidgetItem *index)
{
        Q_UNUSED(index);
        int temp = playWay;
        playWay = 0;//暂时设置为 false，防止 do_stateChanged()切换曲目
        if(isSearch)    //处于搜索界面
        {
            MainWindow::searchPlay();
        }
        else
        {
            player->setSource(getUrlFromItem(ui->listWidget->currentItem()));
            player->play();
            playWay = temp;
        }
}
//打开本地音乐
void MainWindow::openLocalMusic()
{
    ui->listWidget->clear();        //先清空 避免列表内容重复
    QSqlQuery query(DB);
    QString str1= QString("select * from %0").arg(thisUUIDLocalMusic);
    query.exec(str1);
    while(query.next())
    {

        QListWidgetItem *aItem= new QListWidgetItem(query.value(0).toString()); //文件名
        aItem->setIcon(QIcon(":/images/images/musicFile.png"));
        aItem->setData(Qt::UserRole, QUrl::fromLocalFile(query.value(1).toString())); //设置用户数据 文件的完整路径
        ui->listWidget->addItem(aItem); //添加到界面上的列表
    }
}
//打开我的收藏
void MainWindow::openMyCollection()
{
    ui->listWidget->clear();        //先清空 避免列表内容重复
    QSqlQuery query(DB);
    QString  musicListName = userName + "CollectionPlayLists";    //收藏表名
    QString str1= QString("select * from %0").arg(musicListName);
    query.exec(str1);
    while(query.next())
    {
        QListWidgetItem *aItem= new QListWidgetItem(query.value(0).toString()); //文件名
        aItem->setIcon(QIcon(":/images/images/musicFile.png"));
        aItem->setData(Qt::UserRole, QUrl::fromLocalFile(query.value(1).toString())); //设置用户数据 文件的完整路径
        ui->listWidget->addItem(aItem); //添加到界面上的列表
    }
}
 //搜索
void MainWindow::databack(QNetworkReply *reply)
{

    searchInfo=reply->readAll();    //读取返回的全部数据
    QJsonParseError err;        //错误信息对象
    QJsonDocument json_recv = QJsonDocument::fromJson(searchInfo,&err);     //将json文本转换为 json 文件对象
    if(err.error != QJsonParseError::NoError)       //判断是否符合语法
    {
        qDebug() <<"搜索歌曲Json获取格式错误"<< err.errorString();
        return;
    }
    QJsonObject totalObject = json_recv.object();
    QStringList keys = totalObject.keys();                                                                                  // 列出json里所有的key
    if(keys.contains("result"))                                                                                                   //如果有结果
    {                                                                                                                                           //在 json 文本中 {}花括号里面是QJsonObject对象, []方括号里面是QJsonArray
        QJsonObject resultObject = totalObject["result"].toObject();                                       //就将带 result 的内容提取后转换为对象
        QStringList resultKeys = resultObject.keys();                                                              //保存所有key
        if(resultKeys.contains("songs"))                                                                                 //如果 key 为songs ,代表找到了歌曲
        {
            QJsonArray array = resultObject["songs"].toArray();
            for(auto i : array)                                                                                                 //开始获取歌曲中的信息
            {
                QJsonObject object = i.toObject();                                                                                                                                      //用Vector保存每首歌曲的album_id
                musicId = object["id"].toInt();                                                                         // 音乐id
                 m_ID.append(musicId);
                musicDuration = object["duration"].toInt();                                                     // 音乐长度
                musicName = object["name"].toString();                                                       // 音乐名
                mvId = object["mvid"].toInt();                                                                       // mvid
                QStringList artistsKeys = object.keys();
                if(artistsKeys.contains("artists"))                                                                     //如果result中包含了 artists
                {
                    QJsonArray artistsArray = object["artists"].toArray();                                  //将 artist 的内容提取后保存
                    for(auto j : artistsArray)
                    {
                        QJsonObject object2 = j.toObject();
                        singerName = object2["name"].toString();                                                 // 歌手名
                        imgUrl = object2["img1v1Url"].toString();
                        m_Img.append(imgUrl);
                        //qDebug() << imgUrl;
                    }
                }
                QString time = QString("%1:%2").arg(musicDuration/60000).arg(musicDuration/1000%60);
                QString str7 = musicName  + "--"+ singerName + "--"+ time;
                QListWidgetItem *aItem= new QListWidgetItem(str7);                                      //文件名
                ui->listWidget->addItem(aItem);                                                                         //添加到界面上的列表
            }
        }
    }
}
//搜索播放
void MainWindow::searchPlay()
{

    QString url;
    int temp = playWay;
    playWay = 0;
    url=QString("https://music.163.com/song/media/outer/url?id=%0").arg(m_ID.at(ui->listWidget->currentRow()));//通过网网易云API传入之前返回的歌曲的ID实现播放
    player->setSource(QUrl(url)); //添加一音乐到播放列表中
    ui->label_MusicName->setText(musicName); //用于显示
    ly->ui->label_MusicName->setText(musicName); //用于显示
    player->play();
    /*if(player->source().fileName())
    {
        QMessageBox::information(this, "警告", "暂无音频信息");
    }*/


    playWay = temp;
    //网易云API    获取歌词
    QString search = QString("Http://music.163.com/api/song/media?id=%0").arg(m_ID.at(ui->listWidget->currentRow()));
    networkRequest2->setUrl(QUrl(search));
    networkManager2->get(*networkRequest2);
}
//搜索图片设置
void MainWindow::setImg(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray data_bytes = reply->readAll();
        QPixmap* musicPixmp =new QPixmap();
        musicPixmp->loadFromData(data_bytes);
        ui->pushButton_ShowImage->setIcon(*musicPixmp); //设置图片
        ui->pushButton_ShowImage->setIconSize(ui->pushButton_ShowImage->size());     //设置图片大小
        ly->ui->pushButton_ShowImage->setIcon(*musicPixmp); //设置图片
        ly->ui->pushButton_ShowImage->setIconSize(ui->pushButton_ShowImage->size());     //设置图片大小
    }
}
//歌词
void MainWindow::setLyricsinter(QNetworkReply *reply)
{
    lrcMap.clear();
    lyricsinter=reply->readAll();    //读取返回的全部数据
    QJsonParseError jsonError;               //错误信息对象
    QJsonDocument jsonDocument = QJsonDocument::fromJson(lyricsinter,&jsonError);//将json文本转换为 json 文件对象 读写JSON文档
    if(jsonError.error != QJsonParseError::NoError)             //判断
    {
        qDebug() <<"搜索歌曲Json获取格式错误"<<  jsonError.errorString();
        return;
    }
    else
    {
        if(jsonDocument.isObject())
        {
            QJsonObject rootObj = jsonDocument.object();
            if(rootObj.contains("lyric"))
            {
                QJsonValue value = rootObj.value("lyric");
                if(value.isString())
                {
                    QString play_lrcStr = value.toString();
                    if (play_lrcStr != "")
                    {	//将整个歌词给s
                        QString s = play_lrcStr;
                        // s1 用列表的形式保存每一句歌词
                        QStringList s1 = s.split("\n");
                        for (int i = 1; i < s1.size() - 1; i++)
                        {
                            QString ss1 = s1.at(i);
                            QRegularExpression regularExpression("\\[(\\d+)?:(\\d+)?(\\.\\d+)?\\](.*)?");
                            int index = 0;
                            QRegularExpressionMatch match;
                            match = regularExpression.match(ss1,index);
                            if(match.hasMatch()) {
                                int totalTime;
                                totalTime = match.captured(1).toInt() * 60000 + match.captured(2).toInt() * 1000;                    /*  计算该时间点毫秒数            */
                                QString currentText =QString::fromStdString(match.captured(4).toStdString());      /*   获取歌词文本*/
                                lrcMap.insert(totalTime, currentText);
                            }

                        }
                    }
                }
                QMap<int, QString>::iterator iter = lrcMap.begin();
                for(int i = 0; i < 7; i++)
                {

                    if(i==0 &&iter != lrcMap.end())
                    {
                        ly->ui->label_4->setText(iter.value());
                    }
                    if(i==1 &&iter != lrcMap.end())
                    {
                        ly->ui->label_5->setText(iter.value());
                    }
                    if(i==2 &&iter != lrcMap.end())
                    {
                        ly->ui->label_6->setText(iter.value());
                    }
                    if(i==3 &&iter != lrcMap.end())
                    {
                        ly->ui->label_7->setText(iter.value());
                    }
                    if(i==4 &&iter != lrcMap.end())
                    {
                        ly->ui->label_8->setText(iter.value());
                    }
                    if(i==5 &&iter != lrcMap.end())
                    {
                        ly->ui->label_9->setText(iter.value());
                    }
                    if(i==6 &&iter != lrcMap.end())
                    {
                        ly->ui->label_10->setText(iter.value());
                    }
                    iter++;
                }

            }

            else
            {
                ly->ui->label_4->setText("暂无歌词信息");
                qDebug() << "暂无歌词信息";
            }
        }
        else
        {
            qDebug() << "错误";
        }
    }
}
//修改背景图片
void MainWindow::changeBackgroundImg(QString imgPath)
{
    QPalette pal;
    QPixmap pix(imgPath);
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pal.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(pal);
}
//修改歌词字体颜色
void MainWindow::changeFontColor(int r, int g, int b)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

