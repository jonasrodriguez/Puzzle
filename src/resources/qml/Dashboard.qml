import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    anchors.centerIn: parent
    height: gameWindow.height * 0.95
    width: gameWindow.width * 0.95

    color: "transparent"
    border.width: 2

//    Image {
//        id: puzzleImage
//        source: gameWindow.imageName
//        anchors.fill: parent
//        fillMode: Image.PreserveAspectFit
//        visible: !Puzzle.loadingPuzzle
//    }

//    Grid {
//        columns: Puzzle.piecesColumn
//        rows: Puzzle.piecesRow

//        Repeater {
//            model: 3000
//            Image {
//                height: 28
//                width: 28

//                source: (Puzzle.loadingPuzzle) ? "image://imageProvider/"+index : ""

//                visible: Puzzle.loadingPuzzle
//            }
//        }
//    }
//    Item {
//        id: imageRepeater
//        visible: Puzzle.loadingPuzzle
//        height: Puzzle.pieces.imageHeight
//        width: Puzzle.pieces.imageWidth
//        x:0
//        y:0

//        Component {
//            id: imgComponent
//            Item {
//                property int row: index / Puzzle.pieces.numRows
//                property int col: index % Puzzle.pieces.numColumns
//                x: col * (Puzzle.pieces.pieceWidth)
//                y: row * (Puzzle.pieces.pieceHeight)
//                width: Puzzle.pieces.pieceWidth
//                height: Puzzle.pieces.pieceHeight
//                clip: true
//                Image {
//                    x: col * (-Puzzle.pieces.pieceWidth)
//                    y: row * (-Puzzle.pieces.pieceHeight)
//                    width: imageRepeater.width
//                    height: imageRepeater.height
//                    fillMode: Image.Pad
//                    source: gameWindow.imageName
//                    Component.onCompleted: {
////                        console.log("row: "+row+" x")
//                        console.log(row, col);
//                    }
//                }
//                MouseArea {
//                    anchors.fill: parent
//                    drag.target: parent
//                }
//            }
//        }

//        Repeater {
//            model: Puzzle.pieces.totalPieces
//            delegate: imgComponent
//        }
//    }
}
