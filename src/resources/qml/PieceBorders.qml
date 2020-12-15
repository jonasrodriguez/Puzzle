import QtQuick 2.0
import com.jonas.puzzle 1.0

Item {
    property int borderSize: 1
    property color borderColor: "black"

    anchors.fill: piece

    // Left border
    Rectangle {
        color: borders.borderColor
        width: borders.borderSize
        height: piece.height
        anchors.left: borders.left
    }
    // Top border
    Rectangle {
        color: borders.borderColor
        width: piece.width
        height: borders.borderSize
        anchors.top: borders.top
    }
    // Right border
    Rectangle {
        color: borders.borderColor
        width: borders.borderSize
        height: piece.height
        anchors.right: borders.right
    }
    // Bottom border
    Rectangle {
        color: borders.borderColor
        width: borders.width
        height: borders.borderSize
        anchors.bottom: borders.bottom
    }
}

