import QtQuick 2.12
import StyleModule 1.0
import ContactsModule.Base 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    //1) icon
    ImageBubble {
        id: contactBubble_id
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 15
        height: root.height - 15        
        image.source: Resources.contacts.defaultContactIcon //address of the icon
    }

    //2)name surname
    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: contactBubble_id.right
        anchors.leftMargin: Style.defaultOffset
        Row{
            spacing: Style.smallSpacing
            BaseText {
                text: name
            }
            BaseText{
                text: surname
            }
        }
        //3) phone
        BaseText {
            text: "+" + phoneNumber
            color: Style.primaryColor
        }
    }
}
