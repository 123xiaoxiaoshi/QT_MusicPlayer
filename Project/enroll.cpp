#include "enroll.h"
#include "ui_enroll.h"
#include "mainwindow.h"
Enroll::Enroll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enroll)
{
    ui->setupUi(this);
    //限制输入字符以及输入长度
    ui->lineEdit_Account->setMaxLength(16);
    ui->lineEdit_Password->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));
    ui->lineEdit_ConfirmPassword->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));
    CreateConnection(db2);      //连接到数据库

    connect(ui->pushButton_Back, &QPushButton::clicked, [=](){this->hide(); emit Enroll::handoff();});     //点击返回隐藏此界面跳转到登录界面
    connect(ui->pushButton_Enroll, &QPushButton::clicked, [=](){Enroll::registeAccount();});        //用户注册


    //实现点击密码可见再次点击不可见
    //ui->pushButton_Show->setCheckable(true);    //toggled()：设置 setCheckable(true) 后再单击按钮才会触发该信号
    connect(ui->pushButton_Show, &QPushButton::clicked, [=]() {
        if (!judge)
        {
            ui->pushButton_Show->setStyleSheet("qproperty-icon: url(:/Image/Xiaoyanjingkai.png);icon-size: 20px 20px;");
            ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);
            ui->lineEdit_ConfirmPassword->setEchoMode(QLineEdit::Normal);
            judge = true;
        }
        else
        {
            ui->pushButton_Show->setStyleSheet("qproperty-icon: url(:/Image/Xiaoyanjingbi.png);icon-size: 20px 20px;");
            ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
            ui->lineEdit_ConfirmPassword->setEchoMode(QLineEdit::Password);
            judge = false;
        }
    });


}



void Enroll::registeAccount()
{
    QSqlQuery query(db2);
    QString name = ui->lineEdit_Account->text();
    QString password = ui->lineEdit_Password->text();
    QString confirmPassword = ui->lineEdit_ConfirmPassword->text();
    if(name.isEmpty())
    {
        QMessageBox::information(this, "警告", "用户名不能为空", QMessageBox::Ok);
    }
    else if(password.isEmpty() || confirmPassword.isEmpty())
    {
        QMessageBox::information(this, "警告", "密码不能为空", QMessageBox::Ok);
    }
    else if(password != confirmPassword)
    {
        QMessageBox::information(this, "警告", "两次输入密码不同请重新输入", QMessageBox::Ok);
    }
    else
    {
        QString str = QString ("select userName from  UserTable where userName = '%0' ").arg(name);
        query.exec(str);
        QString Qname;

        //QString Qpassword;
        while(query.next())
        {
            Qname =  query.value(0).toString();
        }
        if(Qname == name)
        {

            QMessageBox::information(this, "警告", "用户名已被占用请重新输入", QMessageBox::Ok);

            ui->lineEdit_Account->clear();
            //下划线
            ui->lineEdit_Account->setFocus();
            ui->lineEdit_Password->clear();
            ui->lineEdit_ConfirmPassword->clear();
            ui->lineEdit_Account->setFocus();
        }
        else
        {
            //向数据表中写入数据
            QString str2 = QString("insert into UserTable (userName, password) values ('%0', '%1')").arg(name).arg(password);
            query.exec(str2);
           //在表中查询有没有写入
            QString str3 =  QString ("select userName from  UserTable where userName = '%0' ").arg(name);
            query.exec(str3);
            while(query.next())
            {
                Qname =  query.value(0).toString();

            }
            if(Qname == name)
            {
                //一个用户注成功应该具有自己的一个歌单 一个本地歌单 一个收藏歌单  包含歌曲名 作者 文件路径
                //创建本地歌单
                //QString musicListName = name + "LocalPlayLists";
                //QString str4 = QString("create table %0 (musicName varchar(128), musicPath varchar(128)) ").arg(musicListName);
                //query.exec(str4);
                //创建收藏歌单
                QString  musicListName = name + "CollectionPlayLists";
                QString str5 = QString("create table %0 (musicName varchar(128), musicPath varchar(128)) ").arg(musicListName);
                query.exec(str5);

                QMessageBox::information(this, "成功", "注册成功请返回主界面登录吧", QMessageBox::Ok);
                ui->lineEdit_Account->clear();
                ui->lineEdit_Password->clear();
                ui->lineEdit_ConfirmPassword->clear();
                //db2.close();
            }
            else
            {
                QMessageBox::information(this, "警告", "注册失败", QMessageBox::Ok);
            }
        }
    }
}

//界面显示
void Enroll::thisShow()
{
    this->show();
}


//在QWidget所在类重写paintEvent函数
void Enroll::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);


}






Enroll::~Enroll()
{
    delete ui;
}

