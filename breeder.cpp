#include "breeder.h"

Breeder::Breeder()
{

}

void Breeder::createNets(int count)
{
    m_vNets.clear();
    for(int i = 1; i < count; ++i)
        m_vNets << CNeuroNet({2, 3, 1}, tanh);
}

void Breeder::mutateNets()
{
    QVector<CNeuroNet> tempNets;
    for(int i = 0; i < m_vNets.size(); ++i)
    {
        tempNets << m_vNets[i].mutate(mutationProb, mutationValue);
    }
    m_vNets = tempNets;
}

void Breeder::crossbreedNets(QVector<double> marks)
{
    QVector<CNeuroNet> parentNets;

    int i = 1;
    int idx2Return = 1;
    while (i < m_vNets.size())
    {
        if(i == 0)
            ++i;
        if(marks[i] < marks[i - 1])
        {
            CNeuroNet tmpNet = m_vNets[i];
            m_vNets[i] = m_vNets[i - 1];
            m_vNets[i - 1] = tmpNet;

            double tmpMark = marks[i];
            marks[i] = marks[i - 1];
            marks[i - 1] = tmpMark;

            if(i > idx2Return)
                idx2Return = i;
            --i;
        }
        else {
            if(i < idx2Return)
                i = idx2Return;
            ++i;
        }

    }

    for(int i = 0; i < (int)(m_vNets.size() * topNetsPctg / 100); ++i)
    {
        parentNets << m_vNets.last();
        m_vNets.pop_back();
    }

    m_vNets.clear();

    int j = 0;
    for(int i = 0; i < parentNets.size() - 1; ++i)
        do
            j = QRandomGenerator::global()->bounded(0, parentNets.size());
        while  (j == i);

    m_vNets << crossbreed(parentNets[i], parentNets[j]);

    mutateNets();
}
