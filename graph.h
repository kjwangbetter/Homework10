#ifndef GRAPH_H
#define GRAPH_H
#include "ui_graph.h"
#include "datatable.h"
#include <QObject>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QMainWindow>

namespace Ui {
class Graph;
}

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr,int start=1,int end=52);
    ~Graph();

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
