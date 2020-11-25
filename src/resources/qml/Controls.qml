import QtQuick 2.0

Item {    
    Rectangle {
         height: parent.height * 0.8
         width: height

         border.width: 1

         anchors.centerIn: parent

         Grid {
             id: controlGrid

             property real controlButtonSize: height / 3

             columns: 3
             rows: 3

             anchors.fill: parent

             ControlButton {
                 rotationValue: -135
             }
             ControlButton {
                 rotationValue: -90
             }
             ControlButton {
                 rotationValue: -45
             }
             ControlButton {
                 rotationValue: 180
             }
            Item {
                height: controlGrid.controlButtonSize
                width: height

                Rectangle {
                    height: parent.height * 0.9
                    width: height

                    color: "steelblue"
                    anchors.centerIn: parent
                }
            }
             ControlButton {
                 rotationValue: 0
             }
             ControlButton {
                 rotationValue: 135
             }
             ControlButton {
                 rotationValue: 90
             }
             ControlButton {
                 rotationValue: 45
             }
         }
    }
}
