// Qt headers
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

// Project headers
import QML_Demo.ui.components as Components

Page {
    id: settingsPage
    padding: 20

    background: Rectangle {
        color: "transparent"
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Switch {
            text: "Dark Mode"
            checked: themeManager.darkMode
            onCheckedChanged: themeManager.darkMode = checked

            contentItem: Text {
                text: parent.text
                color: themeManager.textColor
                font.pixelSize: 14
                leftPadding: parent.indicator.width + parent.spacing
                verticalAlignment: Text.AlignVCenter
            }
        }

        Components.MyInput {
            id: firstName
            Layout.preferredWidth: 250
            accentColor: themeManager.accentColor

            placeholder: "Firstname"
        }

        Components.MyInput {
            id: lastName
            Layout.preferredWidth: 250
            accentColor: themeManager.accentColor

            placeholder: "Lastname"
        }

        Components.MyButton {
            Layout.alignment: Qt.AlignHCenter
            text: "Save"
            color: themeManager.accentColor
            onClicked: {
                settings.firstName = firstName.text
                settings.lastName = lastName.text
                firstName.text = ""
                lastName.text = ""
            }
        }
    }
}
