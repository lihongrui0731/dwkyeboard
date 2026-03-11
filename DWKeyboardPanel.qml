import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

Rectangle {
    id: root
    width: 800
    height: 300
    color: "transparent"

    Image {
        id: background
        anchors.fill: parent
        source: "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/keyboardBg.png"
        fillMode: Image.Tile
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: "#00C2EB"
        border.width: 1
        radius: 2
    }

    // Connect to the controller's candidate list changes
    Connections {
        target: inputController
        onCandidatesChanged: {
            candidateModel.clear()
            for (var i = 0; i < inputController.candidateCount; ++i) {
                candidateModel.append({ "text": inputController.candidateAt(i) })
            }
        }
        onLayoutChanged: {
            layoutTrigger = !layoutTrigger;
        }
    }

    // Toggle this to force property re-evaluation
    property bool layoutTrigger: false

    Component.onCompleted: {
        inputController.updateCandidates()
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 5

        // Candidate List
        ListView {
            id: candidateView
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            orientation: ListView.Horizontal
            clip: true
            model: ListModel { id: candidateModel }
            delegate: Rectangle {
                width: candidateText.width + 20
                height: 40
                color: mouseArea.pressed ? "#00CC6B" : "transparent"

                Text {
                    id: candidateText
                    anchors.centerIn: parent
                    text: model.text
                    color: mouseArea.pressed ? "#FFFFF0" : "#FFFFFF"
                    font.pixelSize: 20
                }
                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    onClicked: {
                        inputController.selectCandidate(index)
                    }
                }
            }
        }

        // Keyboard rows
        Repeater {
            model: 4
            RowLayout {
                id: row
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 5

                property int rowIndex: index

                Repeater {
                    model: inputController.keyCount(row.rowIndex)

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredWidth: inputController.keyWidthRatio(row.rowIndex, index) * 50 // Use a multiplier for relative sizing
                        Layout.fillHeight: true
                        color: keyMouseArea.pressed ? "#00CC6B" : "transparent"
                        radius: 3
                        border.color: "#0FF5F9"
                        border.width: 1

                        Image {
                            anchors.fill: parent
                            source: "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/BtnBg.png"
                            fillMode: Image.Tile
                        }

                        Image {
                            anchors.centerIn: parent
                            source: layoutTrigger || !layoutTrigger ? inputController.keyIcon(row.rowIndex, index) : ""
                            visible: source !== ""
                        }

                        Text {
                            anchors.centerIn: parent
                            text: layoutTrigger || !layoutTrigger ? inputController.keyText(row.rowIndex, index) : ""
                            color: keyMouseArea.pressed ? "#FFFFFF" : "#FDD71A"
                            font.pixelSize: 15
                            visible: layoutTrigger || !layoutTrigger ? inputController.keyIcon(row.rowIndex, index) === "" : true
                        }

                        MouseArea {
                            id: keyMouseArea
                            anchors.fill: parent
                            onPressed: {
                                inputController.keyPress(row.rowIndex, index)
                            }
                            onReleased: {
                                inputController.keyRelease(row.rowIndex, index)
                            }
                        }
                    }
                }
            }
        }
    }
}
