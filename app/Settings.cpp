#include "Settings.h"

// Qt headers
#include <QSettings>

//-----------------------------------//
// Constructors / Destructors        //
//-----------------------------------//
Settings::Settings(QObject *parent):
QObject(parent),
m_pFirstName("John"),
m_pLastName("Doe")
{
    emit firstNameChanged();
    emit lastNameChanged();
}

Settings::~Settings()
{
}

//-----------------------------------//
// Setters                           //
//-----------------------------------//
void Settings::setFirstName(QString firstName)
{
    m_pFirstName = firstName;
    emit firstNameChanged();
}

void Settings::setLastName(QString lastName)
{
    m_pLastName = lastName;
    emit lastNameChanged();
}
