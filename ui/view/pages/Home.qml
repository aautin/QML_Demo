// Qt headers
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

// Project headers
import QML_Demo.ui.components as Components
import QML_Demo

Page {
    padding: 20
    background: Rectangle {
        color: "transparent"
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Components.ColorPicker {
            Layout.alignment: Qt.AlignHCenter
            size: 250
            onColorSelected: function(selectedColor) {
                themeManager.accentColor = selectedColor
            }
        }

        Text {
            minimumPixelSize: 0
            text: "%1 %2".arg(settings.firstName).arg(settings.lastName)
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: 26
            color: themeManager.textColor
        }
    }
}
