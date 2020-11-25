import QtQuick 2.0

Item {
    id: controlButton

    height: controlGrid.controlButtonSize
    width: height

    signal clicked

    property int rotationValue: 0

    Rectangle {
        height: parent.height * 0.9
        width: height

        color: "steelblue"

        anchors.centerIn: parent

        Image {
            source: "qrc:/images/arrow.png"
            anchors.fill: parent
            transformOrigin: Item.Center
            rotation: rotationValue
        }
    }
    MouseArea {
        id: button
        anchors.fill: parent
        onClicked: controlButton.clicked()
    }
}
