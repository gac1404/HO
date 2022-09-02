import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Home assistant")
    id: mainWindow

    TextField {
        placeholderText: qsTr("HELLO QT!")
        x: 100
        y: 80
        onTextChanged: uiConnector.sampleText = text
    }

    Button
    {
        text: "Close"
        x: 150
        y: 100
        onClicked: mainWindow.close()
    }

    Button
    {
        text: "Proceed"
        x: 100
        y: 100
        onClicked:{
            var component = Qt.createComponent("main_setting.qml")
            var window2    = component.createObject()
            window2.show()

        }
    }

    SettingButton
    {
        x: mainWindow.width  - ( width  + 10 )
        y: mainWindow.height - ( height + 10 )
        width: 50
        height: 50
    }
}
