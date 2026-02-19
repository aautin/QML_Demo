#pragma once

// Qt headers
#include <QObject>
#include <QPair>
#include <QVector>
#include <QString>
#include <QAbstractListModel>
#include <QtQml>

class PairModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    //-----------------------------------//
    // Definitions                       //
    //-----------------------------------//
    enum Roles {
        FirstRole = Qt::UserRole + 1,
        SecondRole
    };

    //-----------------------------------//
    // Constructors / Destructors        //
    //-----------------------------------//
    explicit PairModel(QObject* parent = nullptr);
    ~PairModel();

    //-----------------------------------//
    // Invokables                        //
    //-----------------------------------//
    Q_INVOKABLE int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant               data(const QModelIndex& index, int role) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void                   addItem(const QString& value);
    Q_INVOKABLE void                   clear();

private:
    //-----------------------------------//
    // Data                              //
    //-----------------------------------//
    QVector<QPair<QString, QString>> m_pData;
};
