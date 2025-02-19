#ifndef SQLCONNECT_H
#define SQLCONNECT_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QRegularExpressionValidator>

static bool CreateConnection(QSqlDatabase &db){

    db = QSqlDatabase::addDatabase( "QMYSQL");//需要使用的数据库驱动和联检建立的名称（方便建立多个数据库连接【使用不同的数据库时】区分）
    db.setHostName("192.168.159.1");//连接地址
    db.setUserName("root");//数据库账户
    db.setPassword("123456");//密码
    db.setPort(3306);//端口
    db.setDatabaseName("musicdemo");//需要用到的数据库

    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
                              "Unable to establish a database connection", QMessageBox::Cancel);
        return false;
    }
    else
    {
        //QMessageBox::critical(0, "Succse open database",
        //                     "成功打开", QMessageBox::Cancel);

        return true;
    }
}
#endif // SQLCONNECT_H
