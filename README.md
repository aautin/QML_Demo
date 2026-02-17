# QML Components Demo
- A demo project showcasing Qt/QML application architecture with a proper project structure.
- This project serves as an example of creating reusable QML components and a clean separation between **UI** and **app logic**

## 📋 Features

- Custom QML components demonstration
- Theme management system (light/dark mode)
- Modern C++/QML application architecture
- Clean separation of UI and backend logic
- Dynamic color management
- Reusable components structure

## 🏗️ Project Structure

```
Qt_QML_Sample/
├── CMakeLists.txt
├── main.cpp
├── app/
│   └── .... infrastructure
└── ui/
    ├── components/
    │   └── .... UI-components
    └── view/
        └── .... pages, modals, windows, etc.
```

## 🛠️ Building prerequisites

- Qt 6.5.0 or higher
- CMake 3.16 or higher
- C++17 compatible compiler
- QtCreator is optional but is strongly recommended

## 🎨 Components

### C++ ThemeManager
A class that manages application theming:
- Accent color
- Dark mode
- Background and font colors depending on dark mode

### C++ Settings
A class that manages a firstname and a lastname:
- Storing and getting from QSettings for persistent changes
- Firstname and lastname accessibles through Q_PROPERTY 

### Custom QML Components
- **ColorPicker.qml**: Color selection component
- and so on...


## ©️ Licences
The basis of the project was taken from : `MIT License Copyright © 2025`
- Author [k1tbyte](https://github.com/k1tbyte)
- Repository [Qt-QML-Sample] (https://github.com/k1tbyte/Qt-QML-Sample)

This project is now licensed under the MIT License of mine - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📚 Resources
- [Qt Documentation](https://doc.qt.io/)
- [QML Reference](https://doc.qt.io/qt-6/qmlreference.html)
- [Qt Quick Controls](https://doc.qt.io/qt-6/qtquickcontrols-index.html)

---

*This project serves as an example of modern Qt/QML application architecture and component design.
Feel free to use it as a reference for your own projects.*
