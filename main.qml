import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: "mainwindow"
    visible: true
    color: "black"
    width: 640
    height: 480
    title: qsTr("QtLiveCam - " + GitID)

    menuBar: MenuBar
    {
        Menu {
            title: "File"
            MenuItem { text: "Open..." }
            MenuItem { text: "Close" }
        }

        Menu
        {
            title: "Camera"
            MenuItem {
                text: "Start"
                onTriggered: content.webcam.start();
            }
            MenuItem {
                text: "Stop"
                onTriggered: content.webcam.stop();
            }
            MenuItem {
                text: "Resolution..."
                onTriggered: ;
            }
        }
    }

    Content {
        id: content
        mainwindow: mainwindow
    }
}
