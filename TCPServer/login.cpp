#include "login.h"
#include "ui_login.h"
#include "widget.h"



login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    this->setWindowTitle("智能驿站服务器登陆界面");
    ui->lepassward->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_pblogin_clicked()
{
    if(ui->lezhanghao->text() == "1"&&ui->lepassward->text() == "2")
    {
    QMessageBox *megbox = new QMessageBox(this);
    megbox->information(this,"通知消息","登陆成功");
    w.show();
    this ->close();


}else{

    QMessageBox *megbox = new QMessageBox(this);
    megbox->information(this,"通知消息","密码错误，登陆失败");


}





}
