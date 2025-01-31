#include "cneuronet.h"

#include <QRandomGenerator>

CNeuroNet::CNeuroNet()
{

}

CNeuroNet::CNeuroNet(QVector<int> nNeuronsInLayers, activation_func funcForHidden, activation_func funcForOut)
{
    Q_ASSERT(nNeuronsInLayers.size() > 2);  // 2 - без скрытых слоев

    for(int i = 1; i < nNeuronsInLayers.size(); ++i)
    {
        if(funcForOut && i == nNeuronsInLayers.size() - 1)
            m_layers << CLayer(nNeuronsInLayers[i - 1] * nNeuronsInLayers[i], funcForOut);
        else
            m_layers << CLayer(nNeuronsInLayers[i - 1] * nNeuronsInLayers[i], funcForHidden);
    }
}

vSignals CNeuroNet::calc(const vSignals& in) const
{
    vSignals sig = in;
    foreach(const CLayer& layer, m_layers)
        sig = layer.calc(sig);
    return sig;
}

CNeuroNet CNeuroNet::mutate(double prob, double value) const
{
    CNeuroNet retNet = *this;
    for(int i = 0; i < m_layers.size(); ++i)
        for(int j = 0; j < m_layers[i].synapses().size(); ++j)
            if(QRandomGenerator::global()->bounded(1.) < prob)
            {
                double newWeight = retNet.m_layers[i].synapses()[j] + QRandomGenerator::global()->bounded(value * 2) - value;
                retNet.m_layers[i].changeSynapse(j, qBound(-1., newWeight, 1.));
            }
    return retNet;
}

CNeuroNet crossbreed(const CNeuroNet &first, const CNeuroNet &second)
{
    CNeuroNet retNet = first;
    for(int i = 0; i < retNet.layers().size(); ++i)
        for(int j = 0; j < retNet.layers()[i].synapses().size(); ++j)
            if(QRandomGenerator::global()->bounded(1.) < 0.5)
                retNet.m_layers[i].changeSynapse(j, second.m_layers[i].synapses()[j]);
    return retNet;
}
