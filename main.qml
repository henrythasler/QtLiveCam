import QtQuick 2.3
import QtMultimedia 5.0
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QtLiveCam")

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
