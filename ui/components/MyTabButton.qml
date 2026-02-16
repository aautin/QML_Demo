// Qt headers
import QtQuick
import QtQuick.Controls

TabButton {
    required text

    id: settingsTab
    height: parent.height

    background: Rectangle {
        color: "transparent"
    }

    contentItem: Text {
        text: parent.text
        font.pixelSize: 14
        color: parent.checked ? themeManager.accentColor : themeManager.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle {
        width: parent.width
        height: 2
        color: themeManager.accentColor
        anchors.bottom: parent.bottom
        visible: parent.checked
    }
}
