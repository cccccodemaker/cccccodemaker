#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QMessageBox>
#include "widget.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    Widget w;
private slots:
    void on_pblogin_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
