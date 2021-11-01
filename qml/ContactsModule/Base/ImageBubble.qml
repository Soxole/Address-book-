import QtQuick 2.0
import StyleModule 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    property alias image: internalImage_id

    color: "transparent"
    radius: width / 2
    border.width: 1
    border.color: Style.primaryColor

    RoundImage {
        id: internalImage_id
        anchors.fill: root
        anchors.margins: Style.mediumOffset
        //Выставляем размер иконки, чтобы не пикселилась(была более четкой)
        sourceSize.height: height
        sourceSize.width: width
    }

    ColorOverlay {
        anchors.fill: internalImage_id
        source: root.image
        color: Style.themeInvertedColor
        antialiasing: true
    }
}
