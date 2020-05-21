#ifndef CHARTDATA_H
#define CHARTDATA_H

#include <QObject>
#include <QtCharts/QLineSeries>
#include<QtCharts/QBarSeries>
#include<QDate>

QT_CHARTS_USE_NAMESPACE

class ChartData : public QObject
{
    Q_OBJECT
public:
    ChartData();
public slots:
    void setLineSeries(QLineSeries* lineSeries);
    void setBarSeries(QBarSeries* barSeries);
    void generateData();

signals:
    void dataGenerated();

private:
    QVector<QDateTime> m_dates;
    QVector<double> m_data1;
    QStringList m_categories;
    QVector<int> m_data2;
};

#endif // CHARTDATA_H
