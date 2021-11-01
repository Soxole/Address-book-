import QtQuick 2.12
import QtQuick.Window 2.12
import ContactsModule.Impl 1.0
import ContactsModule.Base 1.0
import StyleModule 1.0

//https://app.moqups.com/7rKJ9MUgVby37z3X5Daf4bVESsTwOJ5x/edit/page/aa458c046

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Address book")


    ContactsView {
        anchors.fill: parent
    }

    //set background color uses a custom style from Style
    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }

}
