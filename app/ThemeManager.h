//
// Created by kitbyte on 19.01.2025.
//

#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QString>
#include <QColor>

class ThemeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(bool darkMode READ darkMode WRITE setDarkMode NOTIFY darkModeChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor textColor READ textColor NOTIFY textColorChanged)

public:
    //-----------------------------------//
    // Constructors / Destructors        //
    //-----------------------------------//
    explicit ThemeManager(QObject *parent = nullptr);
    ~ThemeManager();

    //-----------------------------------//
    // Getters                           //
    //-----------------------------------//
    QColor accentColor() const { return m_accentColor; }
    bool darkMode() const { return m_darkMode; }
    QColor backgroundColor() const { return m_backgroundColor; }
    QColor textColor() const { return m_textColor; }

    //-----------------------------------//
    // Setters                           //
    //-----------------------------------//
    void setAccentColor(const QColor &color);
    void setDarkMode(bool enabled);

    //-----------------------------------//
    // Invokables                        //
    //-----------------------------------//
    Q_INVOKABLE void saveTheme();
    Q_INVOKABLE void loadTheme();

signals:
    void accentColorChanged();
    void darkModeChanged();
    void backgroundColorChanged();
    void textColorChanged();

private:
    //-----------------------------------//
    // Internal operations               //
    //-----------------------------------//
    void updateColors();

    //-----------------------------------//
    // Data                              //
    //-----------------------------------//
    QColor m_accentColor;
    bool m_darkMode;
    QColor m_backgroundColor;
    QColor m_textColor;
};



#endif //THEMEMANAGER_H
