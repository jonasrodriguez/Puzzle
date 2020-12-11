import QtQuick 2.0
import com.jonas.puzzle 1.0

Rectangle {
    x: width * row
    y: height * column
    width: dashboard.width / Puzzle.pieces.numColumns
    height: dashboard.height / Puzzle.pieces.numRows
    color: (index % 2) ? "red" : "yellow"
}
