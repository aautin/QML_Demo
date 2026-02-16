// STL headers
#include <iostream>

// Qt headers
#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// Project headers
#include <app/Settings.h>
#include <app/ThemeManager.h>

using namespace Qt::StringLiterals;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("aautin");
    QGuiApplication::setApplicationName("QML demo");

    //
    // Linking C++ objects to the engine so the QML can access to them
    //
    QQmlApplicationEngine engine;
    auto *themeManager = new ThemeManager(&app);
    auto *settings = new Settings(&app);
    engine.rootContext()->setContextProperty("settings", settings);
    engine.rootContext()->setContextProperty("themeManager", themeManager);

    //
    // Load the engine from the root QML and execute the app
    //
    const QString executableName = QFileInfo(QCoreApplication::applicationFilePath()).baseName();
    const QString qmlPath = QString("qrc:/qt/qml/%1/ui/view/Main.qml").arg(executableName);
    engine.load(QUrl(qmlPath));
    if (engine.rootObjects().isEmpty())
    {
        std::cerr << QString("No object in the root QML (%1)\n").arg(qmlPath).toStdString();
        return EXIT_FAILURE;
    }
    return app.exec();
}
