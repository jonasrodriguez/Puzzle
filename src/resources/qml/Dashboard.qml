import QtQuick 2.0
import com.jonas.puzzle 1.0

Item {
    anchors.centerIn: parent
    height: gameWindow.height * 0.95
    width: gameWindow.width * 0.95

    Image {
        id: name
        source: gameWindow.imageName
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        visible: !Puzzle.loadingPuzzle
    }

    Grid {
        columns: Puzzle.piecesColumn
        rows: Puzzle.piecesRow

        Repeater {
            model: 3000
            Image {
                height: 28
                width: 28

                source: (Puzzle.loadingPuzzle) ? "image://imageProvider/"+index : ""

                visible: Puzzle.loadingPuzzle
            }
        }
    }

}
