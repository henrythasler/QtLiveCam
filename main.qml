import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: "mainwindow"
    visible: true
    color: "black"
    width: 640
    height: 480
    title: qsTr("QtLiveCam - " + GitID)

    Content {
        mainwindow: mainwindow
    }
}
