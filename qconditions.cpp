#include "qconditions.h"

#include <QRandomGenerator>
#include <QDebug>

static QConditions* g_pConditions = nullptr;

QConditions& conditions()
{
    if(!g_pConditions)
        g_pConditions = new QConditions;
    return *g_pConditions;
}

vSignals QConditions::generateConditions()
{
    vSignals ret;

    if(m_isChangingWidth)
        m_prevWidth = QRandomGenerator::global()->bounded(m_maxWidth - m_minWidth) + m_minWidth;
    if(m_isChaotic)
    {
        double maxPossible = m_max - m_prevWidth/2;
        double minPossible = m_min + m_prevWidth/2;
        m_prevPos = QRandomGenerator::global()->bounded(maxPossible - minPossible) + minPossible;
    }
    else
    {
        if(QRandomGenerator::global()->generateDouble() > 0.8)
            m_isCrawlingRight = !m_isCrawlingRight;
        m_prevPos += (m_crawlSpeed * (m_isCrawlingRight ? 1 : -1));
        m_prevPos = qBound(m_min + m_prevWidth, m_prevPos, m_max + m_prevWidth);
    }
    qDebug() << "Right answer: " << m_prevPos;
    qDebug() << "Width: " << m_prevWidth;
    ret << m_prevPos - m_prevWidth/2;
    ret << m_prevPos + m_prevWidth/2;
    return ret;
}
