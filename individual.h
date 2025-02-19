#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <QWidget>
#include "SqlConnect.h"
namespace Ui {
class Individual;
}

class Individual : public QWidget
{
    Q_OBJECT

public:
    explicit Individual(QWidget *parent = nullptr);
    ~Individual();

    QSqlDatabase db3;       //数据库连接

    QString userName;
    QString nickName;
    QString password;
    void paintEvent(QPaintEvent *event);


public:
    Ui::Individual *ui;

signals:
    void back();     //返回主界面
    void exitLogin(); //退出登录并返回主界面


public slots:
    void thisShow();    //界面显示
};

#endif // INDIVIDUAL_H
