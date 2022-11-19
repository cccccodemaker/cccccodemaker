#include "packagetable.h"
#include "ui_packagetable.h"
#include <QWidget>
#include "widget.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include<QTcpServer>
#include<QTcpSocket>

#include<QMessageBox>

PackageTable::PackageTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PackageTable)
{
    ui->setupUi(this);

    this->setWindowTitle("创建表格界面");
}

PackageTable::~PackageTable()
{
    delete ui;
}

void PackageTable::on_pushButton_clicked()
{
//    QSqlQuery query;
//    QString sqlCreate = QString("create table PackageList(id int,danhao int,name string,telphome int,adress string;");


//    if(!query.exec(sqlCreate)){

//        ui->textBrowser ->setText(QString("NOT TO create"));
//    }else{
//         ui->textBrowser ->setText(QString("succeed TO create"));
//    }
    QSqlQuery query;
    query.exec("create table if not exists PackageList(id INTEGER PRIMARY KEY,danhao INTEGER PRIMARY KEY,name TEXT,telphome INTEGER,address TEXT)");

    if(!query.exec("create table if not exists PackageList(id INTEGER PRIMARY KEY,danhao INTEGER,name TEXT,telphome INTEGER,address TEXT)"))
    {
        ui->textBrowser ->setText(QString("Errot select to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed select to data"));

    }


}

void PackageTable::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("create table PackageOutList(id int,danhao int,name string,telphome int,time string)");
}
