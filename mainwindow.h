#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Net/cneuronet.h>
#include <qconditions.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_hideLayersSpin_valueChanged(int value);
    QVector<int> getHiddenLayersData();
    void setSpinCount(int value);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
