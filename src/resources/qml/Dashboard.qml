import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    id: dashboard

    property bool gameStarted: false

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

        states: State {
           name: "GameStarted"; when: pieceLoader.onActiveChanged
           PropertyChanges { target: dashboard; gameStarted: true }
        }
    }

    Component {
        id: pieceRepeater

        Repeater {
            model: Puzzle.pieces
            Piece {}
        }
    }

    Rectangle {
        id: startDialog
        width: 300
        height: 100

        color: "silver"
        opacity: 0.7
        radius: 10

        border.width: 2
        anchors.centerIn: dashboard

        visible: dashboard.gameStarted && Puzzle.loadingPuzzle

        Text {
            text: qsTr("Start !")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                dashboard.gameStarted = false;
                Puzzle.pieces.startPuzzle();
            }
        }
    }
}
