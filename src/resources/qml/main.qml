import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15

ApplicationWindow  {
    id: gameWindow

    width: 1200
    height: 800
    visible: true
    visibility: Window.FullScreen
    title: qsTr("Puzzle Neni")

    property string imageName: "qrc:/images/japanPuzzle";

    menuBar: PuzzleMenuBar{}

    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            Item {
                //Separator
                width: 5
            }
            Label {
                text: "Title"
//                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        }
    }

    Dashboard {}
}
