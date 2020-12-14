import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    id: dashboard

    anchors.centerIn: parent
    height: gameWindow.height
    width: gameWindow.width * 0.95

    color: "transparent"

    Loader {
        id: pieceLoader

        property real pieceHeigth: dashboard.height / Puzzle.pieces.numRows
        property real pieceWidth: dashboard.width / Puzzle.pieces.numColumns

        anchors.fill: parent
        sourceComponent: pieceRepeater
        active: Puzzle.loadingPuzzle
    }

    Component {
        id: pieceRepeater
        Repeater {
            model: Puzzle.pieces
            Piece {}
        }
    }
}
