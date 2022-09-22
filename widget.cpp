#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->Status->setText(QCoreApplication::applicationDirPath());
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(QCoreApplication::applicationDirPath().append("/../../sqlite_demo/mydb.db"));
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Connect_clicked()
{
    if (!database.open())
    {
        ui->Status->setText(QString("Error: Failed to connect database.") + database.lastError().text());
    }
    else
    {
        ui->Status->setText(QString("SUCCESS"));
//        database.close();
    }
}


void Widget::on_Insert_clicked()
{
    QSqlQuery q;
    q.prepare("INSERT INTO test (name, age) VALUES (?, ?);");

    QVariantList names;
    names << "A3" << "A4";
    q.addBindValue(names);


    QVariantList ages;
    ages << 23 << 24;
    q.addBindValue(ages);

    if (!q.execBatch())
        ui->Status->setText( q.lastError().text());
    else
        ui->Status->setText(QString("INSERT SUCCESSFULLY"));
    database.close();
}


void Widget::on_ShowData_clicked()
{
    QSqlQuery query("SELECT * FROM test");
    QString names("");
    int fieldNo = query.record().indexOf("name");
    while (query.next()) {
        names += query.value(fieldNo).toString()+",";
    }
    ui->Status->setText(names);
    database.close();
}


void Widget::on_Remove_clicked()
{
    QSqlQuery query("DELETE "
                    "FROM test "
                    "WHERE name = \'A3\' "
                      "OR name = \'A4\'");
    query.exec();
    if (query.lastError().isValid())
        ui->Status->setText( query.lastError().text());
    else
        ui->Status->setText(QString("DELETE SUCCESSFULLY"));// 找不到也会报
    database.close();
}

