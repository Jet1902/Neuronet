#ifndef CLAYER_H
#define CLAYER_H

#include "activation.h"

#include <QVector>

typedef QVector<double> vSignals;

class CLayer
{
public:
    CLayer();
    CLayer(int nSynapses, activation_func func);

    vSignals calc(const vSignals& in) const;
    const vSignals synapses() const
        { return m_synapses; }
    void changeSynapse(int idx, double value)
        { m_synapses[idx] = value; }

protected:
    void fillRand(double min, double max);

private:
    vSignals m_synapses; // Веса связей с предыдущим слоем 0-0, 0-1, 0-2, ..., 1-1,
                        // предыдущий   наш
                        //    0          0
                        //    1          1
                        //    2          2
    activation_func m_activation = nullptr;
};
#endif // CLAYER_H
