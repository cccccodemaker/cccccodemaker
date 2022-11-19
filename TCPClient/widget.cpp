#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket; //创建socket对象
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_cancelButton_clicked()
{
    this->close();
}

void Widget::on_connectButton_clicked()
{
    //获取ip地址和端口号
    QString IP = ui ->ipLineEdit ->text();
    QString port = ui ->portLineEdit ->text();

    //连接服务器
    socket ->connectToHost(QHostAddress(IP),port.toShort());

    //连接服务器成功，socket对象会发出信号,等待服务器给客户端发送消息
   connect(socket,&QTcpSocket::readyRead,this,&Widget::receiverMessage);



  }



void Widget::on_pushButton_clicked()
{
  QString str = ui->sendedit->toPlainText();
  socket->write(str.toUtf8());



}

void Widget::receiverMessage()
{
//   QByteArray arr = socket->readAll();

//   QString str = arr.data();
//   ui->receiveredit->setText(str);
//   if(str == "a")
//   {
//       ui->textBrowser->setText("你好");

//   }




//    socket = (QTcpSocket *)sender();
//     ui->lineEdit->setText(QString(socket->readAll()));
//     if(QString(socket->readAll()) == "a")
//     {
//         ui->textBrowser->setText("您的快递已到达");

//     }



  QByteArray arr = socket->readAll();

     QString str = arr.data();
     ui->lineEdit->setText(str);
     if(str == "a")
     {
           ui->textBrowser->setText("您的快递以到达");

     }



}




