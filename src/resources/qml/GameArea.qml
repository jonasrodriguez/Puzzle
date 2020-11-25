import QtQuick 2.0

import com.engine 1.0

Rectangle {
    id: gameArea

    property real areaSize: parent.height * 0.95
    property real cellSize: areaSize * 0.05

    height: gameArea.areaSize
    width: height

    anchors.centerIn: parent

    border.width: 1

    Rectangle {
        height: gameArea.cellSize
        width: height

        x: Engine.position.posX * cellSize
        y: Engine.position.posY * cellSize

        color: "Red"

        Component.onCompleted: {
            console.log("Regular PosX="+Engine.posX)
            console.log("New PosX="+Engine.position.posX)
        }
    }
}
