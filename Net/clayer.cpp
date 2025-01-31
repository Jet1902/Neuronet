#include "clayer.h"

#include <QRandomGenerator>

CLayer::CLayer()
{

}

CLayer::CLayer(int nSynapses, activation_func func) : m_activation(func)
{
    m_synapses.resize(nSynapses);
    fillRand(-1, 1);
}

void CLayer::fillRand(double min, double max)
{
    for(int i = 0; i < m_synapses.size(); ++i)
        m_synapses[i] = QRandomGenerator::global()->bounded(max - min) + min;
}

vSignals CLayer::calc(const vSignals& in) const
{
    // к нам пришло N сигналов
    // размер data / N - размер выходного массива сигналов

    vSignals out;
    out.resize(m_synapses.size() / in.size());

    int signal_idx = 0;
    foreach(double in_signal, in)
    {
        for(int out_idx = 0; out_idx < out.size(); ++out_idx)
            out[out_idx] = in_signal * m_synapses[signal_idx * out.size() + out_idx];
        ++signal_idx;
    }

    for(int i =0; i < out.size(); ++i)
        out[i] = (*m_activation)(out[i]);

    return out;
}
