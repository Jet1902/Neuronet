#ifndef QCONDITIONS_H
#define QCONDITIONS_H

#include <QObject>
#include "Net/clayer.h"

class QConditions : public QObject
{
    Q_OBJECT
public:
    explicit QConditions(QObject *parent = nullptr){}

    vSignals generateConditions();

public slots:
    void setMin(double min)
        { m_min = min; }

    void setMax(double max)
        { m_max = max; }

    void setMinWidth(double minWidth)
        { m_minWidth = qMax(minWidth, m_prevWidth); }

    void setMaxWidth(double maxWidth)
        { m_maxWidth = qMin(maxWidth, m_prevWidth); }

    void setIsChaotic(int isChaotic)
        { m_isChaotic = isChaotic; }

    void setIsChangingWidth(int isChangingWidth)
        { m_isChangingWidth = isChangingWidth; }

private:
    double m_min = -1;                          //Минимальное значение центра
    double m_max = 1;                           //Максимальное значение центра
    double m_minWidth = 0.1;                    //Минимальная ширина
    double m_maxWidth = 0.15;                   //Максимальная ширина
    double m_crawlSpeed = 0.1;                  //Скорость изменения положения диапазона
    bool m_isCrawlingRight = true;                //Направление изменения положения диапазона
    bool m_isChaotic = true;                    //Центр меняется хаотично или постепенно двигается
    bool m_isChangingWidth = false;             //Ширина изменяется в пределах допустимых значений или нет

    double m_prevPos = 0;                       //Центр диапазона
    double m_prevWidth = 0.1;                   //Ширина диапазона
};

QConditions& conditions();

#endif // QCONDITIONS_H
