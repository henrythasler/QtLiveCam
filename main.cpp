#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    appSettings settings;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("settings", &settings);
    engine.rootContext()->setContextProperty("GitID", QStringLiteral(GIT_ID_LONG).left(7));
    qDebug() << engine.importPathList();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
