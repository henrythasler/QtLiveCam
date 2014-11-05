import QtQuick 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

Item {
    id: root
    property var mainwindow: NULL
    property var sidebarWidth: 200
    property var aspect: 1

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

    RowLayout {
        spacing: 2
        anchors.fill: parent
        VideoOutput {
            id: video
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: camera
            fillMode: VideoOutput.PreserveAspectCrop

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    if(camera.imageCapture.ready) {
                        root.aspect = video.sourceRect.width/video.sourceRect.height;
                        camera.imageCapture.capture();
                    }
                }
            }

            Camera {
                id: camera
                imageCapture {
                    onImageCaptured: {
                        list.model.append({"url": database.storeImage(preview)});
                        previews.visible = true;
                    }
                }
            }
        }
        ColumnLayout {
            id: previews
            visible: false
            spacing: 2
            Rectangle {
                color: "pink"
                Layout.alignment: Qt.AlignTop
                Layout.minimumWidth: root.sidebarWidth
                height: 0
            }
            ListView {
                id: list
                Layout.minimumWidth: root.sidebarWidth
                Layout.fillHeight: true
                clip: true
                spacing: 2
                boundsBehavior: Flickable.StopAtBounds

                model: ListModel{}
                delegate: Image {
                    width: root.sidebarWidth; height: root.sidebarWidth/root.aspect
                    fillMode: Image.PreserveAspectCrop
                    source: url

                    MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                        }
                    }
                }
            }
        }
    }
}
