import QtQuick.Controls 2.15
import com.jonas.puzzle 1.0

MenuBar {
    Menu {
        title: qsTr("&File")
        Action { text: qsTr("&New...") }
        Action {    text: qsTr("&Load Image...");
                    onTriggered: Puzzle.loadNewImage(gameWindow.imageName);}
        Action { text: qsTr("&Save") }
        MenuSeparator { }
        Action { text: qsTr("&Quit"); onTriggered: Qt.quit(); }
    }
}

