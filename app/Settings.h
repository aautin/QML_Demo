#pragma once

// Qt headers
#include <QObject>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)

public:
    //-----------------------------------//
    // Constructors / Destructors        //
    //-----------------------------------//
    explicit Settings(QObject *parent = nullptr);
    ~Settings();

    //-----------------------------------//
    // Getters                           //
    //-----------------------------------//
    QString getFirstName() const { return m_pFirstName; }
    QString getLastName() const { return m_pLastName; }

    //-----------------------------------//
    // Setters                           //
    //-----------------------------------//
    void setFirstName(QString firstName);
    void setLastName(QString lastName);

signals:
    void firstNameChanged() const;
    void lastNameChanged() const;

private:
    //-----------------------------------//
    // Internal operations               //
    //-----------------------------------//
    void loadName();

    //-----------------------------------//
    // Data                              //
    //-----------------------------------//
    QString m_pFirstName;
    QString m_pLastName;
};
