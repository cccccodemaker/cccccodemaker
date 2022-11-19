#ifndef ITEMFROM_H
#define ITEMFROM_H

#include <QWidget>

namespace Ui {
class itemfrom;
}

class itemfrom : public QWidget
{
    Q_OBJECT

public:
    explicit itemfrom(QWidget *parent = nullptr);
    ~itemfrom();

    void setPackageInfo(int id,int danhao,QString name,int telphome,QString address);

private:
    Ui::itemfrom *ui;
};

#endif // ITEMFROM_H
