import QtQuick 2.12
import StyleModule 1.0
import ContactsModule.Base 1.0
import Contacts 1.0

BaseListView {
    id: root

    model: ContactsModel {} //contain the data and it's structure

    delegate: ContactDelegate{
        width: root.width
        height: 100
    }
}
