#include "datatable.h"
#include "ui_datatable.h"
#include <QTableWidgetItem>
#include "graph.h"

static int start = 1;
static int end = 52;

int array[52][2]={{1,46},{2,41},{3,21},{4,37},{5,38},{6,47},{7,36},{8,32},{9,37},{10,61},{11,106},{12,77},{13,99},{14,85},{15,112},{16,138},{17,88},{18,114},{19,119},{20,106},{21,113},{22,115},{23,107},{24,142},{25,118},{26,129},{27,136},{28,111},{29,132},{30,137},{31,135},{32,142},{33,141},{34,118},{35,153},{36,136},{37,162},{38,161},{39,146},{40,168},{41,179},{42,145},{43,25},{44,15},{45,14},{46,27},{47,57},{48,33},{49,27},{50,28},{51,43},{52,40}};

dataTable::dataTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataTable)
{
    ui->setupUi(this);
    this->setGeometry(600,400,1000,1000);
    ui->tableWidget->setColumnCount(2);

}

dataTable::~dataTable()
{
    delete ui;
}


void dataTable::on_pushButton_clicked()
{
    start = ui->lineEdit->text().toInt();
    end = ui->lineEdit_2->text().toInt();

    if(start<=0||start>52||end<=0||end>52){
        return;
    }
    ui->tableWidget->setRowCount(end-start+1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"week"<<"num");
    for(int row = 0;row <= end-start;row++){
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(array[row+start-1][0])));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::number(array[row+start-1][1])));
    }

}


void dataTable::on_pushButton_2_clicked()
{
    Graph *graph = new Graph(this,start,end);
    graph->show();
}

