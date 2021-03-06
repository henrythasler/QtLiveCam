TEMPLATE = app

QT += qml quick widgets multimedia

SOURCES += main.cpp \
    databasehandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    settings.h \
    databasehandler.h

VERSION = $$system(head -1 $${PWD}/.git/refs/heads/master | awk \'{print $1}\')
DEFINES += GIT_ID_LONG=\\\"\"$${VERSION}\"\\\"
