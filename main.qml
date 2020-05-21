import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtCharts 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
     chartdata.generateData()
    }

    Connections{
        target: chartdata
        onDataGenerated: {
            addLineSeries()
            addBarSeries()
        }
    }

    ColumnLayout{
        id:buttonLayout
        anchors.fill: parent
        spacing: 20

        ChartView {
            id:lineSeriesChart
            Layout.fillWidth: true
            Layout.fillHeight: true
            antialiasing: true

            DateTimeAxis {
                id:xTime
                format: "dd MM yyyy"
                tickCount: 5
                min: new Date(2019,12,1)
                max: new Date(2020,1,1)
            }

            ValueAxis {
                id:yValues
                min:-1
                max:1
            }
        }

        ChartView {
            id: barSeriesChart
            Layout.fillWidth: true
            Layout.fillHeight: true
            antialiasing: true
            legend.alignment: Qt.AlignBottom

            BarCategoryAxis {
                id: myCategories
            }

            ValueAxis{
                id: myBarValues
                min: -10
                max: 10
            }
        }
    }

    function addLineSeries()
    {
        var mySeries = lineSeriesChart.createSeries(ChartView.SeriesTypeLine, "my line series", xTime, yValues);
        chartdata.setLineSeries(mySeries)
    }

    function addBarSeries()
    {
        var mySeries = barSeriesChart.createSeries(ChartView.SeriesTypeBar,"my bar series", myCategories, myBarValues)
        chartdata.setBarSeries(mySeries)
        mySeries.barWidth = 0.1

    }

}
