#include "graph.h"
#include "ui_graph.h"
#include "datatable.h"
#include <QObject>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
QT_CHARTS_USE_NAMESPACE

int array1[52][2]={{1,46},{2,41},{3,21},{4,37},{5,38},{6,47},{7,36},{8,32},{9,37},{10,61},{11,106},{12,77},{13,99},{14,85},{15,112},{16,138},{17,88},{18,114},{19,119},{20,106},{21,113},{22,115},{23,107},{24,142},{25,118},{26,129},{27,136},{28,111},{29,132},{30,137},{31,135},{32,142},{33,141},{34,118},{35,153},{36,136},{37,162},{38,161},{39,146},{40,168},{41,179},{42,145},{43,25},{44,15},{45,14},{46,27},{47,57},{48,33},{49,27},{50,28},{51,43},{52,40}};

Graph::Graph(QWidget *parent,int start,int end) :
    QMainWindow(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    this->setGeometry(600,400,1000,1000);
     QChartView *chartView  = new QChartView(this);
     QChart *chart = new QChart();
     chart->setTitle("The Graph");
     chartView->setChart(chart);
     setCentralWidget(chartView);
     QLineSeries *series = new QLineSeries;
     chart->addSeries(series);
     for(int i = 0;i <= end - start;i++){
         series->append(array1[i][0],array1[i][1]);
     }
     QValueAxis *axisX = new QValueAxis;
     axisX->setRange(start,end);
     chart->setAxisX(axisX,series);
     QValueAxis *axisY = new QValueAxis;
     axisY->setRange(0,300);
     chart->setAxisY(axisY,series);

}

Graph::~Graph()
{
    delete ui;
}
