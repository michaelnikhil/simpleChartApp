#include "chartdata.h"
#include<QtMath>
#include<QTextStream>
#include <QtCharts/QBarSet>

ChartData::ChartData()
{

}

void ChartData::setLineSeries(QLineSeries *lineSeries)
{
    for (int i = 0; i < m_data1.size(); i++) {
        lineSeries->append(m_dates[i].toMSecsSinceEpoch(),m_data1[i]);
    }
}

void ChartData::setBarSeries(QBarSeries *barSeries)
{
        QStringList c;
        for (int i = 0; i < m_data2.size(); i++) {
            QBarSet *set = new QBarSet(m_categories[i]);
            *set << m_data2[i];
            barSeries->append(set);
        }
}

void ChartData::generateData()
{
    //generate data for line series
    for (int i = 0; i < 15; i++) {
        m_dates.append(QDateTime::fromString("2020/1/"+QString::number(i), "yyyy/M/d"));
        m_data1.append(qCos(0.5*i));
    }

    //generate data for bar series
    for (int i = 0; i < 8; i++) {
        m_categories.append("200" + QString::number(i));
        m_data2.append(2*i+1);
    }

    if (m_dates.size() > 0){
        emit dataGenerated();
    }
}
