// Qt headers
import QtQuick
import QtQuick.Effects

Rectangle {
    id: root

    property color selectedColor: themeManager.accentColor
    property int size: 200
    property bool expanded: false

    signal colorSelected(color newColor)

    width: size
    height: size
    radius: width / 2
    color: "transparent"
    border.color: "lightgrey"
    border.width: 1

    property var colors: [
        "#F44336", "#E91E63", "#9C27B0", "#673AB7",
        "#3F51B5", "#2196F3", "#03A9F4", "#00BCD4",
        "#009688", "#4CAF50", "#8BC34A", "#CDDC39"
    ]

    Rectangle {
        id: centerCircle
        width: root.width * 0.3
        height: width
        radius: width / 2
        color: root.expanded ? themeManager.textColor : root.selectedColor
        anchors.centerIn: parent
        scale: root.expanded ? 0.8 : 1

        layer.enabled: true
        layer.effect: MultiEffect {
            shadowEnabled: true
            shadowColor: "#80000000"
            shadowHorizontalOffset: 0
            shadowVerticalOffset: 0
            shadowBlur: 8
        }

        Behavior on scale {
            PropertyAnimation {
                duration: 300
                easing.type: Easing.InOutBack
            }
        }

        Behavior on color {
            ColorAnimation { duration: 200 }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: root.expanded = !root.expanded
        }
    }

    Repeater {
        model: colors.length

        ColorItem {}
    }
}
