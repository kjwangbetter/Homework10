#ifndef DATATABLE_H
#define DATATABLE_H

#include <QDialog>

namespace Ui {
class dataTable;
}

class dataTable : public QDialog
{
    Q_OBJECT

public:
    explicit dataTable(QWidget *parent = nullptr);
    ~dataTable();

public slots:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dataTable *ui;
};

#endif // DATATABLE_H
