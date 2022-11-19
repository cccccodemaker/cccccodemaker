#ifndef PACKAGETABLE_H
#define PACKAGETABLE_H

#include <QWidget>

namespace Ui {
class PackageTable;
}

class PackageTable : public QWidget
{
    Q_OBJECT

public:
    explicit PackageTable(QWidget *parent = nullptr);
    ~PackageTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PackageTable *ui;
};

#endif // PACKAGETABLE_H
