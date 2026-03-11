import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import DWKeyboard 1.0

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

    // Connect virtual keyboard keystrokes to the active text field.
    Connections {
        target: InputController
        function onVirtualKeyPress(key, text, modifiers, isAutoRepeat) {
            // Only insert raw characters if we are NOT composing pinyin
            if (InputController.preeditText === "") {
                if (key === Qt.Key_Backspace) {
                    inputField.remove(inputField.cursorPosition - 1, inputField.cursorPosition)
                } else if (text !== "") {
                    inputField.insert(inputField.cursorPosition, text)
                }
            } else {
                // If we are composing, we only let backspace delete the raw characters from the preedit context.
                // The C++ backend handles the actual deletion from preedit. But if the input field also gets
                // the backspace, we should not delete the input field's committed text.
            }
        }

        function onCommitText(text) {
            if (text !== "") {
                inputField.insert(inputField.cursorPosition, text)
            }
        }
    }

    // Add the keyboard component to the bottom of the screen directly
    DWKeyboardPanel {
        id: keyboardPanel
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 300
    }
}
