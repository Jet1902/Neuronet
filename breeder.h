#ifndef BREEDER_H
#define BREEDER_H

#include <Net/cneuronet.h>
#include <qconditions.h>
#include <QRandomGenerator>

class Breeder
{
public:
    Breeder();

    void createNets(int count);
    void crossbreedNets(QVector<double> marks);

    void setMutationProb(double value)
        { mutationProb = value; }
    void setMutationValue(double value)
        { mutationValue = value; }
    void setTopNetsPctg(int value)
        { topNetsPctg = value; }

private:
    QVector<CNeuroNet> m_vNets;

    void mutateNets();

    double mutationProb;
    double mutationValue;
    int topNetsPctg;

};

#endif // BREEDER_H
