import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls.Basic

import QML_Demo.ui.view.pages as Pages
import QML_Demo.ui.components as Components

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "QML Components Demo"

    color: themeManager.backgroundColor

    header: Rectangle {
        color: themeManager.darkMode ? "#424242" : "white"
        height: 32

        layer.enabled: true

        TabBar {
            id: tabBar
            width: parent.width
            height: parent.height
            position: TabBar.Header

            background: Rectangle {
                color: "transparent"
            }

            Components.MyTabButton {
                text: "Home"
            }

            Components.MyTabButton {
                text: "History"
            }

            Components.MyTabButton {
                text: "Settings"
            }
        }
    }

    StackLayout {
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Pages.Home {}
        Pages.History {}
        Pages.Settings {}
    }
}
