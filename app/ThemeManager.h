#pragma once

// Qt headers
#include <QObject>
#include <QString>
#include <QColor>

class ThemeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor accentColor READ getAccentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(bool darkMode READ getDarkMode WRITE setDarkMode NOTIFY darkModeChanged)
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor textColor READ getTextColor NOTIFY textColorChanged)

public:
    //-----------------------------------//
    // Constructors / Destructors        //
    //-----------------------------------//
    explicit ThemeManager(QObject *parent = nullptr);
    ~ThemeManager();

    //-----------------------------------//
    // Parameters                        //
    //-----------------------------------//
    QColor getAccentColor() const { return m_accentColor; }
    bool   getDarkMode() const { return m_darkMode; }
    QColor getBackgroundColor() const { return m_backgroundColor; }
    QColor getTextColor() const { return m_textColor; }

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
