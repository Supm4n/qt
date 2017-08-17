QMAKE_CXX = /usr/bin/llvm-g++

QT       += core gui xml

QMAKE_INFO_PLIST = settings/Info.plist

INCLUDEPATH += /Users/supm4n/System/Qt511/5.1.1/clang_64/include/QtCore/

include(lib/qtsingleapplication/qtsingleapplication.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OneVCard

TEMPLATE = app

HEADERS  += settings/settings.hpp \
    helpers/uihelper.hpp \
		controllers/applicationcontroller.hpp \
    ui/windows/mainwindow.hpp

SOURCES += main.cpp\
    settings/settings.cpp \
    helpers/uihelper.cpp \
		controllers/applicationcontroller.cpp \
    ui/windows/mainwindow.cpp

win32 {
    CONFIG(debug, debug|release) {
        DESTDIR = bin/win/debug
    }
    else {
        DESTDIR = bin/win/release
    }
}

macx {
#		ICON = ui/images/qt.icns
    CONFIG(debug, debug|release) {
        DESTDIR = bin/osx/debug
    }
    else {
        DESTDIR = bin/osx/release
    }
}

#RESOURCES += \
#    ui/qt_assets.qrc
