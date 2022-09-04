import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Home assistant")
    id: mainWindow

//    Connections
//    {
//        target: uiConnector
//        onDupa:{
//            textField2.text = qsTr("DUPA")
//        }

//    }

    TextField {
        id: textField1
        //placeholderText: qsTr("HELLO QT!")
        x: 100
        y: 80
        text: uiConnector.someVar
        onTextChanged:
        {
            uiConnector.sampleText = text

        }


    }

    TextField {
        id: textField2
        placeholderText: qsTr("HELLO QT!")
        x: 300
        y: 80
        onTextChanged:
        {
            text = uiConnector.sampleText
        }

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
        id: buttonProceed
        text: "Proceed"
        x: 100
        y: 100
        onClicked: uiConnector.setSomeVar("ABC")
    }

    SettingButton
    {
        x: mainWindow.width  - ( width  + 10 )
        y: mainWindow.height - ( height + 10 )
        width: 50
        height: 50
    }

    ConnectionStateControl{
        x: mainWindow.width  - ( 2*width + 20 )
        y: mainWindow.height - (  height + 10 )
        width: 50
        height: 50
    }
}
