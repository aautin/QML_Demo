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

    const QString executableName = QFileInfo(QCoreApplication::applicationFilePath()).baseName();

    //
    // Linking C++ objects to the engine so the QML can access to them
    //
    QQmlApplicationEngine engine;
    auto *themeManager = new ThemeManager(&app);
    auto *settings = new Settings(&app);

    engine.rootContext()->setContextProperty("settings", settings);
    engine.rootContext()->setContextProperty("themeManager", themeManager);
    engine.addImportPath(":/");

    //
    // Load the engine from the root QML and execute the app
    //
    auto rootQmlPath = QString("qrc:/qt/qml/%1/ui/view/Main.qml").arg(executableName);
    engine.load(rootQmlPath);
    if (engine.rootObjects().isEmpty())
    {
        std::cerr << QString("No object in the root QML (%1)\n").arg(rootQmlPath).toStdString();
        return EXIT_FAILURE;
    }
    return app.exec();
}
