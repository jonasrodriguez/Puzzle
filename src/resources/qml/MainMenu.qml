import QtQuick 2.0

Item {
    // Game Screen
    Item {
        height: parent.height - controls.height
        width: parent.width

        anchors.bottom: controls.top
        GameArea {
        }
    }

    // Controls
    Controls {
        id: controls

        height: parent.height / 3
        width: parent.width

        anchors.bottom: parent.bottom


    }
}
