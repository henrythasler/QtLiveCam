TEMPLATE = app

QT += qml quick widgets multimedia sql

SOURCES += main.cpp \
    databasehandler.cpp \
    livecam.cpp \
    videosurface.cpp \
    webcam.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    settings.h \
    databasehandler.h \
    livecam.h \
    videosurface.h \
    webcam.h

DEFINES += GIT_ID_LONG=\\\"$$system(git log -1 --format='%H')\\\"
