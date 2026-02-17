// Qt headers
import QtQuick
import QtQuick.Effects

Rectangle {
    id: colorItem
    width: root.width * 0.15
    height: width
    radius: width / 2
    color: colors[index]
    visible: root.expanded || distance > 0
    border.width: themeManager.accentColor === color ? 3 : 0
    border.color: themeManager.textColor


    property real angle: (index * 360 / colors.length) * (Math.PI / 180)
    property real distance: root.expanded ? root.width * 0.35 : 0

    x: root.width/2 - width/2 + Math.cos(angle) * distance
    y: root.height/2 - height/2 + Math.sin(angle) * distance

    Behavior on distance {
        NumberAnimation {
            duration: 300
            easing.type: Easing.OutBack
        }
    }

    scale: colorMouseArea.containsMouse ? 1.2 : 1
    Behavior on scale {
        NumberAnimation { duration: 100 }
    }

    MouseArea {
        id: colorMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            root.selectedColor = colors[index]
            root.expanded = false
            root.colorSelected(colors[index])
        }
    }

    layer.enabled: true
    layer.effect: MultiEffect {
        shadowEnabled: true
        shadowColor: "#80000000"
        shadowHorizontalOffset: 0
        shadowVerticalOffset: 0
        shadowBlur: 4
    }
}
