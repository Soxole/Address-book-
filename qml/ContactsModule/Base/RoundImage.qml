import QtQuick 2.12
import QtGraphicalEffects 1.0

Image {
    id: root
    property bool rounded: true

    //решение для непрозрачных иконок; выход за границы иконки
    layer.enabled: true
    layer.effect: OpacityMask {
        maskSource: Item {
            width: root.width
            height: root.height
            Rectangle {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                radius: Math.min(height, width) / 2
            }
        }
    }

}
