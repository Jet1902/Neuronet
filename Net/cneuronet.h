#ifndef CNEURONET_H
#define CNEURONET_H

#include "clayer.h"

class CNeuroNet
{

public:
    CNeuroNet();
    // nNeuronsInLayers[0] - количество входов
    // размер nNeuronsInLayers - число слоев + 1 (для входов)
    CNeuroNet(QVector<int> nNeuronsInLayers, activation_func funcForHidden, activation_func funcForOut = nullptr);

    const QVector<CLayer> layers() const
        { return m_layers; }

    vSignals calc(const vSignals& in) const;

    CNeuroNet mutate(double prob, double value) const;
    friend CNeuroNet crossbreed(const CNeuroNet &first, const CNeuroNet &second);



protected:

private:
    QVector<CLayer> m_layers;
};

#endif // CNEURONET_H
