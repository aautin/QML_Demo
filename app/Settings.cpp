#include "Settings.h"

// Qt headers
#include <QSettings>

//-----------------------------------//
// Constructors / Destructors        //
//-----------------------------------//
Settings::Settings(QObject *parent):
QObject(parent)
{
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
    m_pFirstName = firstName;
    emit firstNameChanged();
}

void Settings::setLastName(QString lastName)
{
    m_pLastName = lastName;
    emit lastNameChanged();
}

//-----------------------------------//
// Internal operations               //
//-----------------------------------//
void Settings::loadName()
{
    QSettings settings1;
    qDebug() << settings1.fileName();

    QSettings settings;
    settings.beginGroup("Name");

    setFirstName(settings.value("firstName", "John").toString());
    setLastName(settings.value("lastName", "Doe").toString());

    settings.endGroup();
}


