import QtQuick 2.12

ListView {
    spacing: 1
    section.criteria: ViewSection.FirstCharacter
    section.property: "name"
}
