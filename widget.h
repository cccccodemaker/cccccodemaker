#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Connect_clicked();

    void on_Insert_clicked();


    void on_ShowData_clicked();

    void on_Remove_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase database;
};
#endif // WIDGET_H
