import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects


Image {

    id: root

    property bool isConnected: false

    fillMode: Image.PreserveAspectFit
    source: "/images/connection_status_disconnected.png"
    scale: mouseArea.containsMouse ? 1.5 : 1
    signal clicked()

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            root.clicked()
        }
    }

    Behavior on scale {
        NumberAnimation {
            duration: 250
            easing.type: Easing.InOutQuart
        }
    }


    ColorOverlay {
        anchors.fill: root
        source: root
        color: "steelblue"

        opacity: root.isConnected

        Behavior on opacity {
            NumberAnimation {
                duration: 500
                easing.type: Easing.InOutQuart
            }
        }
    }
}
