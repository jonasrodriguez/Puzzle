import QtQuick 2.0
import QtGraphicalEffects 1.15
import com.jonas.puzzle 1.0

Item {
    id: piece

    x: width * row
    y: height * column
    width: pieceLoader.pieceWidth
    height: pieceLoader.pieceHeigth

    clip: true

    transform: Rotation { angle: 90 * rotation }

    Image {
        x: row * (-piece.width)
        y: column * (-piece.height)
        width: dashboard.width
        height: dashboard.height
        fillMode: Image.Pad
        source: gameWindow.imageName
        z: 1
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent
    }

    PieceBorders {
        id: borders
        anchors.fill: piece
        z: 2
    }
}


