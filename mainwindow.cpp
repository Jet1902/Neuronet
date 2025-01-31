#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->minSpin, SIGNAL(valueChanged(double)), &conditions(), SLOT(setMin(double)));
    connect(ui->maxSpin, SIGNAL(valueChanged(double)), &conditions(), SLOT(setMax(double)));
    connect(ui->minWidthSpin, SIGNAL(valueChanged(double)), &conditions(), SLOT(setMinWidth(double)));
    connect(ui->maxWidthSpin, SIGNAL(valueChanged(double)), &conditions(), SLOT(setMaxWidth(double)));
    connect(ui->isChaoticCheck, SIGNAL(stateChanged(int)), &conditions(), SLOT(setIsChaotic(int)));
    connect(ui->isChangingWidthCheck, SIGNAL(stateChanged(int)), &conditions(), SLOT(setIsChangingWidth(int)));

//    CNeuroNet first({2, 3, 1}, tanh);
//    CNeuroNet second = first.mutate(1, 0.5);
//    CNeuroNet third = crossbreed(first, second);
//    for(int i = 0; i < first.layers().size(); ++i)
//        for(int j = 0; j < first.layers()[i].synapses().size(); ++j)
//        {
//            qDebug() << "First" << first.layers()[i].synapses()[j];
//            qDebug() << "Second" << second.layers()[i].synapses()[j];
//            qDebug() << "Third" << third.layers()[i].synapses()[j];
//        }
//    for(int i = 0; i < 1000; ++i)
//        m_vNets << CNeuroNet({2, 3, 1}, tanh);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent(QTimerEvent *event)
{
//    double min, max;
//    do
//    {
//        double v1 = QRandomGenerator::global()->bounded(100);
//        double v2 = QRandomGenerator::global()->bounded(100);
//        min = qMin(v1, v2);
//        max = qMax(v1, v2);
//    }while(min == max);

//    double rightAnswer = (max - min) / 2 + min;

//    vSignals in;
//    in << min << max;
//    QVector marks;
//    marks.reserve
//    foreach(const CNeuroNet net, m_vNets)
//    {
//        vSignals vResult = net.calc(in);
//        Q_ASSERT(vResult.size() == 1);
//        double result = vResult.first();
//        if(min < result && result < max)
//            qDebug() << "Failure";
//    }

}

void MainWindow::on_hideLayersSpin_valueChanged(int value)
{
    setSpinCount(value);
}

QVector<int> MainWindow::getHiddenLayersData()
{
    QFormLayout* form = qobject_cast<QFormLayout*>(ui->hiddenLayersGroup->layout());
    QVector<int> retVector;
    retVector << 2;
    for(int i = 0; i < form->rowCount(); ++i)
    {
        QSpinBox* newSpin = findChild<QSpinBox*>(QString("newSpin_%1").arg(i + 1));
        if(newSpin)
            retVector << newSpin->value();
    }
    retVector << 1;
    return retVector;
}

void MainWindow::setSpinCount(int value)
{
    QFormLayout* form = qobject_cast<QFormLayout*>(ui->hiddenLayersGroup->layout());
    if(!form)
        return;
    do
    {
        if(form->rowCount() < value)
        {
            QSpinBox* newSpin = new QSpinBox(ui->hiddenLayersGroup);
            newSpin->setObjectName(QString("newSpin_%1").arg(form->rowCount() + 1));
            form->addRow(new QLabel(QString("Слой %1").arg(form->rowCount() + 1), ui->hiddenLayersGroup), newSpin);
        }
        if(form->rowCount() > value)
            form->removeRow(value);
    } while(form->rowCount() != value);
}

void MainWindow::on_pushButton_clicked()
{
    for(int i = 0; i < 10; ++i)
    {
        conditions().generateConditions();
    }
}
