import QtQuick
import QtQuick.Controls


Image {
    id: settingButton
    fillMode: Image.PreserveAspectFit
    source: "/images/setting_off.png"

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: settingButton.source = "/images/setting_selected.png"
        onExited: settingButton.source = "/images/setting_off.png"
        onClicked:{
            var component = Qt.createComponent("main_setting.qml")
            var window2    = component.createObject()
            window2.show()

        }

    }

}
