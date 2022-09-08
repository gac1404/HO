import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts 1.3

Item {

    id: root
    width: 540
    height: 380
    visible: false
    enabled: !animationFadeIn.running && !animationFadeOut.running
    onVisibleChanged: if (root.visible) animationFadeIn.restart()


    DropShadow {
        visible: true
        anchors.fill: root
        horizontalOffset: 3
        verticalOffset: 3
        radius: 15.0
        color: "#80000000"
        source: root

    }

    Rectangle{

        id: background
        anchors.fill: root
        color: "steelblue"
        border.color: "black"
        radius: 15

        NumberAnimation{
            id: animationFadeIn
            target: background
            property: "opacity"
            from: 0
            to: 1
            duration: 250
            easing.type: Easing.OutCubic
            running: false
        }

        NumberAnimation{
            id: animationFadeOut
            target: background
            property: "opacity"
            from: 1
            to: 0
            duration: 250
            easing.type: Easing.OutCubic
            onFinished: {
                console.log("onFinished");
                root.visible = false
            }
            running: false
        }

    }

    RowLayout
    {
        id: navigationButtons
        spacing: 5
        width: 200
        height: 25



        Button
        {
            Layout.fillHeight: true
            Layout.fillWidth: true;
            Layout.preferredWidth: 50
            id: connectButton
            text: "Connect"
            onClicked: console.log("clicked")
        }

        Button
        {
            Layout.fillHeight: true
            Layout.fillWidth: true;
            Layout.preferredWidth: 50
            id: saveButton
            text: "Save"
            onClicked: console.log("clicked")
        }

        Button
        {
            Layout.fillHeight: true
            Layout.fillWidth: true;
            Layout.preferredWidth: 50
            id: exitButton
            text: "Exit"
            onClicked:{
                animationFadeOut.restart()
            }
        }
    }



}
