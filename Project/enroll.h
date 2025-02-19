#ifndef ENROLL_H
#define ENROLL_H

#include <QWidget>
#include "SqlConnect.h"


namespace Ui {
class Enroll;
}

class Enroll : public QWidget
{
    Q_OBJECT

public:
    explicit Enroll(QWidget *parent = nullptr);
    ~Enroll();
    bool judge = false;
    void paintEvent(QPaintEvent *event);



    QSqlDatabase db2;
    void registeAccount();      //用户注册

private:
    Ui::Enroll *ui;

signals:
    void handoff();     //发送界面切换的信号


public slots:
    void thisShow();    //界面显示



};

#endif // ENROLL_H
