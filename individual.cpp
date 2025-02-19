#include "individual.h"
#include "ui_individual.h"
#include "mainwindow.h"
Individual::Individual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Individual)
{
    ui->setupUi(this);
    CreateConnection(db3);      //连接到数据库
    ui->lineEdit_NickName->setMaxLength(16);
    ui->lineEdit_OldPassword->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));
    ui->lineEdit_NewPassword->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));
    ui->lineEdit_NewPasswordTwo->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9!@#$%^&*(),.?\":{}|<>]+$]{32}")));


    connect(ui->pushButton_Back, &QPushButton::clicked, [=](){this->hide(); emit Individual::back();});   //发送返回信号
    connect(ui->pushButton_ExitLogin, &QPushButton::clicked, [=](){this->hide(); emit Individual::exitLogin();});   //发送退出登录信号
    //页面切换
    ui->stackedWidget->setCurrentIndex(1);  //默认界面
    connect(ui->pushButton_MyInformation, &QPushButton::clicked, [=](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->pushButton_SetPassword, &QPushButton::clicked, [=](){ui->stackedWidget->setCurrentIndex(0);});

    //昵称修改
    connect(ui->pushButton_Preserve, &QPushButton::clicked, [=](){
        QSqlQuery query(db3);
        QString insterName = ui->lineEdit_NickName->text();
        QString str2 = QString("update UserTable set nickName='%0' where userName = '%1'").arg(insterName).arg(userName);
        query.exec(str2);
        QString str3 =  QString ("select nickName from  UserTable where userName = '%0' ").arg(userName);
        query.exec(str3);
        QString Qname;
        while(query.next())
        {
            Qname =  query.value(0).toString();
        }
        if(Qname == insterName)
        {
            QMessageBox::information(this, "提示", "修改成功", QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, "提示", "修改失败", QMessageBox::Ok);
        }
    });
    //密码修改
    connect(ui->pushButton_ChangePassword, &QPushButton::clicked, [=](){
        if(password != ui->lineEdit_OldPassword->text())
        {
            QMessageBox::information(this, "提示", "原密码错误", QMessageBox::Ok);
        }
        else
        {
            QString newPassword = ui->lineEdit_NewPassword->text();
            QString newPasswordTwo = ui->lineEdit_NewPasswordTwo->text();
            if(newPassword.isEmpty() || newPasswordTwo.isEmpty())
            {
                QMessageBox::information(this, "提示", "密码不能为空", QMessageBox::Ok);
            }
            else if(newPassword != newPasswordTwo)
            {
                QMessageBox::information(this, "提示", "两次输入密码不同请重新输入", QMessageBox::Ok);
            }
            else
            {
               QSqlQuery query(db3);
               QString str4 = QString("update UserTable set password='%0' where userName = '%1'").arg(newPassword).arg(userName);
               query.exec(str4);
               QString str5 =  QString ("select password from  UserTable where userName = '%0' ").arg(userName);
               query.exec(str5);
               QString Qpassword;
               while(query.next())
               {
                   Qpassword =  query.value(0).toString();
               }
               if(Qpassword == newPassword)
               {
                   QMessageBox::information(this, "提示", "修改成功", QMessageBox::Ok);
                   password = newPassword;
                   ui->lineEdit_OldPassword->clear();
                   ui->lineEdit_NewPassword->clear();
                   ui->lineEdit_NewPasswordTwo->clear();
                   db3.close();
               }
               else
               {
                   QMessageBox::information(this, "提示", "修改失败", QMessageBox::Ok);
               }
            }
        }
    });
}


//界面显示
void Individual::thisShow()
{
    this->show();
    //设置账号和昵称
    userName = ui->lineEdit_Account->text();
    qDebug() <<"1" << userName << nickName;
    QSqlQuery query(db3);
    QString str1 = QString("select * from UserTable where userName = '%0'").arg(userName);
    query.exec(str1);
    while(query.next())
    {
        userName = query.value(0).toString();
        password = query.value(1).toString();
        nickName = query.value(2).toString();
        qDebug() <<"2"<< userName << nickName;
    }
    ui->lineEdit_NickName->setText(nickName);
    ui->lineEdit_Account->setReadOnly(true);    //设置只读
    qDebug() << "3"<<userName << nickName;
}

void Individual::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


Individual::~Individual()
{
    delete ui;
}
