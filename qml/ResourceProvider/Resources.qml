pragma Singleton
import QtQuick 2.12

Item {
    property alias contacts: contacts_id
    QtObject {
        id: contacts_id
        readonly property string defaultContactIcon: "qrc:/qml/resources/211605_contact_icon.svg"
    }
}
