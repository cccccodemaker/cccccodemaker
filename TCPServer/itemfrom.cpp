#include "itemfrom.h"
#include "ui_itemfrom.h"

itemfrom::itemfrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemfrom)
{
    ui->setupUi(this);
}

itemfrom::~itemfrom()
{
    delete ui;
}

void itemfrom::setPackageInfo(int id,int danhao,QString name,int telphome,QString address)
{
    ui->idLabel->setText(QString::number(id));
    ui->danhaoLabel->setText(QString::number(danhao));
     ui->nameLabel->setText(name);
      ui->telLabel->setText(QString::number(telphome));
      ui->addressLabel->setText(address);


}

