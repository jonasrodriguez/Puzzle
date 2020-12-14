import QtQuick 2.0
import com.jonas.puzzle 1.0

Item {
    // Left border
    Rectangle {
        color: "black"
        width: 1
        height: piece.height
        anchors.left: borders.left

    }
    // Top border
    Rectangle {
        color: "black"
        width: piece.width
        height: 1
        anchors.top: borders.top
        z: 2
    }
    // Right border
    Rectangle {
        color: "black"
        width: 1
        height: piece.height
        anchors.right: borders.right
        z: 2
    }
    // Bottom border
    Rectangle {
        color: "black"
        width: piece.width
        height: 1
        anchors.bottom: borders.bottom
        z: 2
    }
}

