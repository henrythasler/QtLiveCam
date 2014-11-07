import QtQuick 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

import webcam 1.0

Item {
    id: root
    property var mainwindow: NULL
    property var sidebarWidth: 200
    property var aspect: 1

    focus: true
    anchors.fill: parent
    Keys.onEscapePressed: {
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
        spacing: 5
        anchors.fill: parent
        Webcam {
            id: webcam
            Layout.fillWidth: true
            Layout.fillHeight: true
//            width: 1280
//            height: 720
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    webcam.frameSize = Qt.size(160,120);
                }
            }
        }

/*
        VideoOutput {
            id: video
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: cam
            fillMode: VideoOutput.PreserveAspectCrop

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log("clicked");
                    cam.snap();
//                    if(camera.imageCapture.ready) {
//                        console.log(video.sourceRect.width+"x"+video.sourceRect.height)
//                        root.aspect = video.sourceRect.width/video.sourceRect.height;
//                        camera.imageCapture.capture();
//                    }
                }
            }
            Camera {
                id: camera
                videoRecorder.resolution: "864x480"
                imageCapture {
                    onImageCaptured: {
                        list.model.append({"url": database.storeImage(preview)});
                        previews.visible = true;
                    }
                }


                onError: {
                    console.log(errorString);
                }
            }
        }
*/
        ColumnLayout {
            id: previews
            visible: false
            spacing: parent.spacing

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
                spacing: parent.spacing
                boundsBehavior: Flickable.StopAtBounds
//                Behavior on Layout.minimumWidth { PropertyAnimation {} }

                model: ListModel{}
                delegate: Image {
                    width: root.sidebarWidth; height: root.sidebarWidth/root.aspect
                    fillMode: Image.PreserveAspectCrop
                    source: url

                    MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                            list.Layout.minimumWidth = 400
                        }
                    }
                }
            }
        }
    }
}
