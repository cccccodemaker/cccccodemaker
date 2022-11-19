#include "widget.h"
#include "ui_widget.h"
#include "login.h"
#include "packagetable.h"

#include "itemfrom.h"
#include<QListWidgetItem>


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include<qdebug.h>

#include<QTcpServer>
#include<QTcpSocket>

#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("智能驿站服务器界面");





    server = new QTcpServer;

    server ->listen(QHostAddress::AnyIPv4,PORT);

    //客户端发起连接，server发出信号
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandeler);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandeler()
{
    //建立TCP连接
    QTcpSocket *socket = server ->nextPendingConnection();
    socket ->peerAddress();//获取客户端地址
    socket ->peerPort();//获取客户端端口

    ui->ipLineEdit->setText(socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(socket->peerPort()));

    //服务器收到客户端发送的信息，socket发出readyread信号
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientiInfoSlot);

}


void Widget::clientiInfoSlot()
{
     //获取信号的发出者
//   QTcpSocket *s = (QTcpSocket *)sender();
     socket = (QTcpSocket *)sender();
    ui->showlineEdit->setText(QString(socket->readAll()));


}

void Widget::on_connectdb_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sqlite.db");
    if(!db.open())
    {
        ui->textBrowser ->setText(QString("NOT TO CONNECT"));
    }else{
        ui->textBrowser ->setText(QString("SUCCESS TO CONNECT"));

    }



}

void Widget::on_pushButton_clicked()
{
    p.show();

}



void Widget::on_selectdb_clicked() //查询数据
{
    QSqlQuery query;

    QString id = ui->idLineEdit->text();

    //向数据库下达查询数据的命令
    QString sqlSelect = QString("select from PackageList where id = %1;").arg(id.toInt());
    if(!query.exec(sqlSelect))
    {
        ui->textBrowser ->setText(QString("Errot select to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed select to data"));

    }


}

void Widget::on_insertdb_clicked()  //插入数据按钮
{
   //获取ui控件上的内容
//   QString id = ui->idLineEdit->text();
    QString danhao = ui->danhaoLineEdit->text();
    QString name = ui->nameLineEdit ->text();
     QString telphome = ui->telLineEdit ->text();
     QString address = ui->addressLineEdit->text();

      //通过数据库接口的访问，将数据库插入到数据库中
     QSqlQuery query;

     QString sqlInsert = QString("insert into PackageList(name)values('%1');").arg(name);

     if(!query.exec(sqlInsert))
     {
         ui->textBrowser ->setText(QString("Error insert to data"));
          qDebug()<<"Errot insert to data"<<db.lastError();

     }else{
         ui->textBrowser ->setText(QString("succeed insert to data"));

     }

}

void Widget::on_pushButton_2_clicked()    //查询数据按钮
{
    ui->listWidget->clear();//在查询数据之前，先清空列表上的内容
    QSqlQuery query;
    //向数据库下达查询数据的命令
    QString sqlSelect = QString("select *from PackageList;");
    if(!query.exec(sqlSelect))
    {
        ui->textBrowser ->setText(QString("Errot select to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed select to data"));

    }
    //遍历数据库记录
    while(query.next())
    {
        int id = query.value("id").toInt();
        int danhao = query.value("danhao").toInt();
        QString name = query.value("name").toString();
        int telphome = query.value("telphome").toInt();
        QString address = query.value("address").toString();

        //每遍历一条数据，便更新到ui控件上
        //创建一个列表条目
        itemfrom * PackageInitem = new itemfrom;
        PackageInitem->setPackageInfo(id,danhao,name,telphome,address);
        QListWidgetItem * item = new QListWidgetItem;
        item ->setSizeHint(QSize(748,37));



        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,PackageInitem);
    }


}

void Widget::on_pushButton_3_clicked()//手动插入数据操作
{
    QSqlQuery query;
    //向数据库下达查询数据的命令
    QString sqlinsert = QString("insert into PackageList(danhao,name,telphome,address)values(453452343,'小成',17876184596,'成都市成华区');");
    if(!query.exec(sqlinsert))
    {
        ui->textBrowser ->setText(QString("Errot select to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed select to data"));

    }
}

void Widget::on_pushButton_4_clicked()//更新数据
{
    QSqlQuery query;

    QString id = ui->idLineEdit->text();
    QString address = ui->addressLineEdit->text();
    QString danhao = ui->danhaoLineEdit->text();
    QString name = ui->nameLineEdit ->text();
     QString telphome = ui->telLineEdit ->text();


    //向数据库下达查询数据的命令.arg(name).arg(telphome.toInt())        name = '%2' telphome = %3
    QString sqlUpdate = QString("update PackageList set address = '%1' where id = %3;").arg(address).arg(id.toInt());
    if(!query.exec(sqlUpdate))
    {
        ui->textBrowser ->setText(QString("Errot update to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed update to data"));

    }
}

void Widget::on_removedb_clicked() //删除数据
{
    QSqlQuery query;

    int id = ui->idLineEdit->text().toInt();

    //向数据库下达删除数据的命令
    QString sqlDelete = QString("delete from PackageList where id = %1;").arg(id);
    if(!query.exec(sqlDelete))
    {
        ui->textBrowser ->setText(QString("Errot delete to data"));

    }else{
        ui->textBrowser ->setText(QString("succeed delete to data"));

    }

    ui->listWidget->takeItem(id-1);

}




void Widget::on_pushButton_5_clicked()
{
    QString str = ui->textEdit->toPlainText();
     socket->write(str.toUtf8());
}
