import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    anchors.centerIn: parent
    height: gameWindow.height
    width: gameWindow.width * 0.95

    color: "transparent"
//    border.width: 2

    Component.onCompleted: Puzzle.pieces.setImageRealSize(height, width)

    Loader {
        anchors.fill: parent
        sourceComponent: repeComp
        active: Puzzle.loadingPuzzle

    }

    Component {
        id: repeComp
        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.width: 2
            Repeater {
                model: Puzzle.pieces
                Rectangle {
                    x: posX
                    y: posY
                    width: dashboard.width / Puzzle.pieces.numColumns
                    height: dashboard.height / Puzzle.pieces.numRows
                    color: (index % 2) ? "red" : "yellow"
                    Component.onCompleted: console.log(index+" "+x+" "+y)
                }
            }
        }
    }
}

//    Grid {
//        rows: Puzzle.pieces.numRows
//        columns: Puzzle.pieces.numColumns
//        Repeater {
//            model: Puzzle.pieces.totalPieces
//            Rectangle {
//                width: dashboard.width / Puzzle.pieces.numColumns
//                height: dashboard.height / Puzzle.pieces.numRows
//                color: (index % 2) ? "red" : "yellow"
//            }
//        }
//    }

//    Repeater {
//        id: repe
//        model: Puzzle.pieces
//        Loader {
//            sourceComponent: pieceDelegate
//            onLoaded: {  item.posX = posX; item.posY = posY; }
//        }

////        Component {
////                id: pieceDelegate
////                Text {
////                    property real posX
////                    property real posY
////                    x: posX
////                    y: posY
////                    width: dashboard.width / Puzzle.pieces.numColumns
////                    height: dashboard.height / Puzzle.pieces.numRows
////                    color: (index % 2) ? "red" : "yellow"
////    //                Component.onCompleted: {console.log(index)}
////                }
////            }

////        Rectangle {
////            x: posX
////            y: posY
////            width: dashboard.width / Puzzle.pieces.numColumns
////            height: dashboard.height / Puzzle.pieces.numRows
////            color: (index % 2) ? "red" : "yellow"
////            Component.onCompleted: {console.log(index)}
////        }
//    }


//    Repeater {
//        model: 9
//        delegate: pieceComponent
//    }

//    Component {
//        id: pieceComponent
//        Item {
//            property int row: index / Puzzle.pieces.numRows
//            property int col: index % Puzzle.pieces.numColumns
//            x: col * (width)
//            y: row * (height)
//            width: dashboard.width / Puzzle.pieces.pieceWidth
//            height: dashboard.height / Puzzle.pieces.pieceHeight
//            clip: true

//            Text {
//                text: qsTr("H"+index)
//                anchors.centerIn: parent
//            }

//            MouseArea {
//                anchors.fill: parent
//                drag.target: parent
//            }
//        }
//    }

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

