import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("DWKeyboard Demo")

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "Click below to activate keyboard"
            font.pixelSize: 20
        }

        TextField {
            id: inputField
            width: 300
            height: 40
            placeholderText: "Enter text here..."
        }
    }
}
