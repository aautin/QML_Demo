#include "PairModel.h"

// Qt headers
#include <QDateTime>

//-----------------------------------//
// Constructors / Destructors        //
//-----------------------------------//
PairModel::PairModel(QObject* parent):
QAbstractListModel(parent)
{
    QSettings history;
    int size = history.beginReadArray("historyColor");

    beginResetModel();
    for (int i = 0; i < size; ++i) {
        history.setArrayIndex(i);
        m_pData.push_back(
            qMakePair(history.value("date").toString(),
                      history.value("value").toString()));
    }
    history.endArray();
    endResetModel();
}

PairModel::~PairModel()
{
    QSettings history;
    history.beginWriteArray("historyColor");

    beginResetModel();
    for (qsizetype i = 0; i < m_pData.size(); ++i) {
        history.setArrayIndex(i);
        history.setValue("date", m_pData.at(i).first);
        history.setValue("value", m_pData.at(i).second);
    }
    history.endArray();
    endResetModel();
}

//-----------------------------------//
// Operations                        //
//-----------------------------------//
int PairModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return m_pData.size();
}

QVariant PairModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= m_pData.size())
        return {};

    const auto& pair = m_pData[index.row()];
    switch (role)
    {
        case FirstRole:
        {
            return pair.first;
        }

        case SecondRole:
        {
            return pair.second;
        }
    }
    return {};
}

QHash<int, QByteArray> PairModel::roleNames() const
{
    return {
        { FirstRole,  "date"  },
        { SecondRole, "value" }
    };
}

void PairModel::addItem(const QString& value)
{
    beginResetModel();
    m_pData.insert(0, qMakePair(QDateTime::currentDateTime().toString(), value));
    endResetModel();
}

void PairModel::clear()
{
    beginResetModel();
    {
        m_pData.clear();

        QSettings history;
        history.beginGroup("historyColor");
        history.clear();
    }
    endResetModel();
}
