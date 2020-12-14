import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    id: piece

    x: width * row
    y: height * column
    width: pieceLoader.pieceWidth
    height: pieceLoader.pieceHeigth
    border.width: 2

    clip: true

    Image {
        x: row * (- piece.width)
        y: column * (- piece.height)
        width: dashboard.width
        height: dashboard.height
        fillMode: Image.Pad
        source: gameWindow.imageName
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent
    }
}
