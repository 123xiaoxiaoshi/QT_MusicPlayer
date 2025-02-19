#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "SqlConnect.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private:
    Ui::Login *ui;

public:
    QSqlDatabase db;    //连接数据库
    void landing();     //登录到主界面
    //UserInformation *user;
    //UserInformation *getUserInformation();
     QString userName;
     QString userPassward;
     void paintEvent(QPaintEvent *event);


signals:
    void handoff();     //发送界面切换的信号
    void handoffMain(); //切换到主界面
    void backMain(); //返回到主界面
public slots:
    void thisShow();    //界面显示
};

#endif // LOGIN_H
