#include "widget.h"
#include "ui_widget.h"
#include "datatable.h"
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include  <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开一个csv","","CSV(*.csv)");
    if(fileName.isEmpty()){
        return;
    }
    QFile file(fileName);
    this->ui->lineEdit->setText(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();

    QString content = QString(array);
    this->ui->plainTextEdit->setPlainText(content);



}


void Widget::on_pushButton_2_clicked()
{
    dataTable *table = new dataTable(this);
    table->show();
    this->hide();
}

