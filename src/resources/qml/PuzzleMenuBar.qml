import QtQuick.Controls 2.15

MenuBar {
    Menu {
        title: qsTr("&File")
        Action { text: qsTr("&New...") }
        Action { text: qsTr("&Open...") }
        Action { text: qsTr("&Save") }
        MenuSeparator { }
        Action { text: qsTr("&Quit"); onTriggered: Qt.quit(); }
    }
}
