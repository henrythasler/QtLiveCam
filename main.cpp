#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QDebug>

#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QCameraCaptureDestinationControl>

#include "settings.h"
#include "databasehandler.h"
#include "livecam.h"
#include "webcam.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    appSettings settings;

    QQmlApplicationEngine engine;

    qmlRegisterType<Webcam>("webcam", 1, 0, "Webcam");


    engine.rootContext()->setContextProperty("settings", &settings);

    LiveCam cam;
    engine.rootContext()->setContextProperty("cam", &cam);

    DatabaseHandler *database = new DatabaseHandler();
    engine.addImageProvider(QLatin1String("database"), database);
    engine.rootContext()->setContextProperty("database", database);

    engine.rootContext()->setContextProperty("GitID", QStringLiteral(GIT_ID_LONG).left(7));

//    qDebug() << engine.importPathList();

    foreach(const QCameraInfo &item, QCameraInfo::availableCameras()) {
        qDebug() << item.deviceName() << item.description() << item.position() << "Orientation:" << item.orientation();
    }

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
