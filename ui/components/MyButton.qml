// Qt headers
import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    property string text: "Button"

    signal clicked()

    opacity: mouseArea.pressed ? 0.9 : 1
    scale: mouseArea.pressed ? 0.9 : 1
    width: buttonText.width + 32
    height: 40
    radius: 4
    color: "#2196F3"
    border.color: themeManager.textColor
    border.width: 0

    Text {
        id: buttonText
        anchors.centerIn: parent
        text: root.text
        color: themeManager.textColor
        font.pixelSize: 14
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: root.clicked()
    }

    HoverHandler {
        onHoveredChanged: {
            root.border.width = hovered ? 1 : 0
        }
    }

    Behavior on scale {
        NumberAnimation {
            duration: 100
        }
    }

    Behavior on opacity {
        NumberAnimation {
            duration: 100
        }
    }
}
