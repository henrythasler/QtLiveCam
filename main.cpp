#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <QtMultimedia/QCameraInfo>

#include "settings.h"
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    appSettings settings;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("settings", &settings);

    DatabaseHandler *database = new DatabaseHandler();
    engine.addImageProvider(QLatin1String("database"), database);
    engine.rootContext()->setContextProperty("database", database);

    engine.rootContext()->setContextProperty("GitID", QStringLiteral(GIT_ID_LONG).left(7));
    qDebug() << engine.importPathList();

    foreach(const QCameraInfo &item, QCameraInfo::availableCameras()) {
        qDebug() << item.deviceName() << item.description() << item.position() << "Orientation:" << item.orientation();
    }

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
