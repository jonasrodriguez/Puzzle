import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

ApplicationWindow  {
    id: gameWindow

    width: 1200
    height: 800
    visible: true
    visibility: Window.FullScreen
    title: qsTr("Puzzle Neni")

    menuBar: PuzzleMenuBar{}

    Dashboard {
        id: dashboard
        anchors.fill: parent
    }
}
