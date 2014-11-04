import QtQuick 2.3
import QtMultimedia 5.0
import QtQuick.Controls 1.2

ApplicationWindow {
    id: "mainwindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("QtLiveCam - " + GitID)

    Item {
        focus: true
        anchors.fill: parent
        Keys.onEscapePressed: {
            camera.stop();
            Qt.quit();
        }
        Component.onCompleted: {
            mainwindow.x = settings.value("WindowPos/x", 100);
            mainwindow.y = settings.value("WindowPos/y", 100);
            mainwindow.width = Math.min(Math.max(settings.value("WindowPos/width", 640), 320), 10000);
            mainwindow.height = Math.min(Math.max(settings.value("WindowPos/height", 480), 200), 10000);
            mainwindow.visibility = (settings.value("WindowPos/visibility", 1) == 4) ? 4 : 1;
        }
        Component.onDestruction: {
            settings.beginGroup("WindowPos");
                settings.setValue("visibility", mainwindow.visibility);
                if(mainwindow.visibility != 4) {
                    settings.setValue("x", mainwindow.x);
                    settings.setValue("y", mainwindow.y);
                    settings.setValue("width", mainwindow.width);
                    settings.setValue("height", mainwindow.height);
                }
            settings.endGroup();
        }
        VideoOutput {
            source: camera
            anchors.fill: parent
            id: video
            fillMode: VideoOutput.PreserveAspectCrop
            Camera {
                id: camera
                imageCapture {
                    onImageCaptured: {
                        console.log("snap");
                    }
                }
            }
        }
    }
}
