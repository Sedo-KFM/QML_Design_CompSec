#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "geometry.h"
#include "labcore1.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Geometry geometry;
    engine.rootContext()->setContextProperty("geometry", &geometry);
    LabCore1 labCore1;
    engine.rootContext()->setContextProperty("labCore1", &labCore1);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ComputerSecurityLabs", "Main");

    return app.exec();
}
