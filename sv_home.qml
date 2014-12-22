import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0

ApplicationWindow {
    id: root
    visible: true
    color: "white"
    width: 640
    height: 480
    property int dpi: Screen.pixelDensity*25.4

    toolBar: BorderImage {
        id: name
        source: "artwork/qrc-grey-line.png"
        width: parent.width;
        height: 60
        border.bottom: 5

        RowLayout {
            Item {
                id: button
                width: 60
                Layout.alignment: Qt.AlignTop
                Image{
                    id: img_glow
                    source: "artwork/qrc-round-glow-90.png"
                    opacity: mouse_back.pressed ? 1.0 : 0.0
                    Behavior on opacity {
                        NumberAnimation {
                            duration: img_glow.opacity ? 500 : 50
                        }
                    }
                }
                Image {
                    source: "artwork/qrc-back-btn-90.png"
                    MouseArea {
                        id: mouse_back
                        anchors.fill: parent
                    }
                }
            }
            Text {
                Layout.fillWidth: true
                font.pixelSize: 42
                Behavior on x { NumberAnimation{ easing.type: Easing.OutCubic} }
                anchors.verticalCenter: parent.verticalCenter
                color: "#808080"
                text: "Home"
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        focus: true
        Component.onCompleted: stackView.push(Qt.resolvedUrl("Content.qml"))
    }
}
