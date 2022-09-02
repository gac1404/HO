import QtQuick
import QtQuick.Controls

Window {
    width: 320
    height: 240
    visible: true
    title: qsTr("Settings")
    id: settingsWindow
    flags: Qt.WindowStaysOnTopHint


    TextField {
        placeholderText: qsTr("HELLO QT!")
        x: 100
        y: 80
        onTextChanged: uiConnector.sampleText = text
    }

    Button
    {
        text: "Close"
        x: 100
        y: 100
        onClicked: settingsWindow.close()
    }
}
