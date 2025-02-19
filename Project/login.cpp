#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //限制输入字符以及输入长度
    ui->lineEdit_Account->setMaxLength(16);
    ui->lineEdit_Password->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));
     CreateConnection(db);      //连接到数据库

    connect(ui->pushButton_Enroll, &QPushButton::clicked, [=](){this->hide(); emit Login::handoff();});     //点击注册隐藏此界面跳转到注册界面
    connect(ui->pushButton_Login, &QPushButton::clicked, [=](){Login::landing();});     //点击登录切换到主界面
    connect(ui->pushButton_Back, &QPushButton::clicked, [=](){this->hide(); emit Login::backMain();});    //取消登录到主界面

    //实现点击密码可见再次点击不可见
    ui->pushButton_Show->setCheckable(true);    //toggled()：设置 setCheckable(true) 后再单击按钮才会触发该信号
    connect(ui->pushButton_Show, &QPushButton::toggled, [=](bool checked) {
        if (checked)
        {
            ui->pushButton_Show->setStyleSheet("qproperty-icon: url(:/Image/Xiaoyanjingkai.png);icon-size: 20px 20px;");
            ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);
        }
        else
        {
            ui->pushButton_Show->setStyleSheet("qproperty-icon: url(:/Image/Xiaoyanjingbi.png);icon-size: 20px 20px;");
            ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
        }
    });
}

//登录到主界面
void Login::landing()
{
    QString name = ui->lineEdit_Account->text();
    QString password = ui->lineEdit_Password->text();
    if(name.isEmpty())
    {
        QMessageBox::information(this, "警告", "用户名不能为空", QMessageBox::Ok);
    }
    else if(password.isEmpty())
    {
        QMessageBox::information(this, "警告", "密码不能为空", QMessageBox::Ok);
    }
    else
    {
        QSqlQuery query(db);

        QString str = QString ("select * from  UserTable where userName = '%0' and password = '%1'").arg(name).arg(password);
        query.exec(str);

        QString Qname;
        QString Qpassword;
        while(query.next())
        {
            Qname =  query.value(0).toString();
            Qpassword = query.value(1).toString();
        }
        if(Qname != name || Qpassword != password)
        {
            QMessageBox::information(this, "警告", "用户名或密码错误", QMessageBox::Ok);
            //下划线
            ui->lineEdit_Account->setFocus();
            ui->lineEdit_Password->clear();     //清空密码
            ui->lineEdit_Account->setFocus();
        }
        else
        {

            //记录登录的用户信息
            userName = name;
            userPassward = password;
            //发送信号登录主界面
            this->hide();
            emit Login::handoffMain();
            //db.close();
        }

    }
}

//UserInformation* Login::getUserInformation()
//{
  //  return this->user;
//}



//界面显示
void Login::thisShow()
{
    this->show();
}

void Login::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}





Login::~Login()
{
    delete ui;
}
