import QtQuick 2.3
import QtMultimedia 5.0
import QtQuick.Controls 1.2

ApplicationWindow {
    id: "mainwindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("QtLiveCam - " + GitID)

    Component.onCompleted: {
        mainwindow.x = settings.value("WindowPos/x", 100)
        mainwindow.y = settings.value("WindowPos/y",100)
        mainwindow.width = settings.value("WindowPos/width", 640)
        mainwindow.height = settings.value("WindowPos/height", 480)
    }
    Component.onDestruction: {
        settings.beginGroup("WindowPos");
            settings.setValue("x", mainwindow.x);
            settings.setValue("y", mainwindow.y);
            settings.setValue("width", mainwindow.width);
            settings.setValue("height", mainwindow.height);
        settings.endGroup();
    }

    VideoOutput {
        source: camera
        anchors.fill: parent
        id: video
        fillMode: VideoOutput.PreserveAspectCrop
        Camera {
            id: camera
        }
    }

}
