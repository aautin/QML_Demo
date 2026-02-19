#include "Settings.h"

//-----------------------------------//
// Constructors / Destructors        //
//-----------------------------------//
Settings::Settings(QObject *parent):
QObject(parent)
{
    m_pSettings.beginGroup("Name");
    loadName();
}

Settings::~Settings()
{
}

//-----------------------------------//
// Setters                           //
//-----------------------------------//
void Settings::setFirstName(QString firstName)
{
    if (firstName.isEmpty())
    {
        emit emptyField();
        return;
    }

    m_pFirstName = firstName;
    m_pSettings.setValue("firstName", m_pFirstName);
    emit firstNameChanged();
}

void Settings::setLastName(QString lastName)
{
    if (lastName.isEmpty())
    {
        emit emptyField();
        return;
    }

    m_pLastName = lastName;
    m_pSettings.setValue("lastName", m_pLastName);
    emit lastNameChanged();
}

//-----------------------------------//
// Internal operations               //
//-----------------------------------//
void Settings::loadName()
{
    setFirstName(m_pSettings.value("firstName", "John").toString());
    setLastName(m_pSettings.value("lastName", "Doe").toString());
}


