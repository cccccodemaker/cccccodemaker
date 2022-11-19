#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include<QTcpServer>
#include<QTcpSocket>

#include<QMessageBox>
#include "packagetable.h"



#define PORT  8000


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    PackageTable p;




private slots:
  void newClientHandeler();
  void clientiInfoSlot();

  void on_connectdb_clicked();

  void on_pushButton_clicked();



  void on_selectdb_clicked();

  void on_insertdb_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_removedb_clicked();





  void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QTcpServer *server;
   QTcpSocket *socket;

};




#endif // WIDGET_H
