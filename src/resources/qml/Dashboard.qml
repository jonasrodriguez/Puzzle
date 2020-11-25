import QtQuick 2.0
import com.jonas.puzzle 1.0

Item {
    Image {
        id: name
        source: gameWindow.imageName

        anchors.centerIn: parent
        height: parent.height * 0.95
        width: parent.width * 0.95
        fillMode: Image.PreserveAspectFit
    }
}
