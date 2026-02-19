// Qt headers
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import QtQuick.Window

// Project headers
import QML_Demo.ui.components as Components
import QML_Demo as Cpp

Page {
    padding: 20
    background: Rectangle {
        color: "transparent"
    }

    Cpp.PairModel {
        id: historyModel
    }

    ListView {
        id: historyView

        anchors.fill: parent
        spacing: 20

        model: historyModel
        delegate: RowLayout {
            required property string date
            required property string value

            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            Text {
                text: date
                Layout.alignment: Qt.AlignHCenter
                color: themeManager.textColor
            }

            Item {
                width: 50
                height: 50

                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter

                Rectangle {
                    anchors.fill: parent
                    color: value
                    radius: width
                    border.width: 2
                    border.color: themeManager.textColor
                }
            }
        }
    }

    Components.MyButton {
        height: 30
        width: 110
        x: parent.width / 2 - width / 2
        y: parent.height - height
        Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
        text: "Clear history"

        onClicked: {
            historyModel.clear();
        }
    }

    Connections {
        target: themeManager
        onAccentColorChanged: {
            historyModel.addItem(themeManager.accentColor)
        }
    }
}
