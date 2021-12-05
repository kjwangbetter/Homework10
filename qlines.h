#ifndef QLINES_H
#define QLINES_H

#include <QObject>

class QLines : public QLineSeries
{
    Q_OBJECT
public:
    explicit QLines(QObject *parent = nullptr);

signals:

};

#endif // QLINES_H
