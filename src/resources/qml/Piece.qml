import QtQuick 2.0
import QtGraphicalEffects 1.15
import com.jonas.puzzle 1.0

Item {
    id: piece

    property int rot: 0
    property bool pressed: false

    x: width * row
    y: height * column
    width: pieceLoader.pieceWidth
    height: pieceLoader.pieceHeigth

    state: "BASE"

    clip: true

    transform: Rotation{
        angle: 90 * rot
        origin.x: piece.width / 2
        origin.y: piece.height / 2
    }

    states: [
        State {
            name: "BASE"
            PropertyChanges { target: pieceMouseArea; drag.target: undefined}
        },
        State {
            name: "ACTIVE"
            PropertyChanges { target: piece; z: 10}
            PropertyChanges { target: pieceMouseArea; drag.target: piece}
            PropertyChanges { target: borders; borderColor: "red"; borderSize: 4}
        }
    ]

    Image {
        x: row * (-piece.width)
        y: column * (-piece.height)
        width: dashboard.width
        height: dashboard.height
        fillMode: Image.Pad
        source: gameWindow.imageName
    }

    MouseArea {
        id: pieceMouseArea
        anchors.fill: parent
        drag.smoothed: true
        onWheel: wheelie(wheel.angleDelta.y)
        onPressed: {
            piece.state = "ACTIVE"
            Puzzle.pieces.pressedPiece(index);
        }
        onReleased: piece.state = "BASE"
    }

    PieceBorders {
        id: borders
        z: 2
    }

    Connections {
        target: Puzzle.pieces
        function onRandomizePieces(id, x, y, rot) {
            if (id === index) {
                if ( x > (dashboard.width - piece.width)) {
                    x = 0;
                }
                piece.x = x;
                if ( y > (dashboard.height - piece.height)) {
                    y = 0;
                }
                piece.y = y;
                piece.rot = rot;
            }
        }
    }

    // Mouse wheel control function
    function wheelie(angle) {
        if (piece.state == "ACTIVE") {
            if (angle > 0) {
                piece.rot--;
                if (piece.rot < 0) {
                    piece.rot = 3;
                }
            }
            else {
                piece.rot++;
                if (piece.rot > 4) {
                    piece.rot = 0;
                }
            }
        }
    }
}
