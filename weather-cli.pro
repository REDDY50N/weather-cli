QT          -= gui
QT          += core network

CONFIG      += c++17 console
CONFIG      -= app_bundle

TEMPLATE    = app
TARGET		= owmcli
DESTDIR     = $$PWD/bin
MOC_DIR     = ./generated/moc
OBJECTS_DIR = ./generated/obj

SOURCES += \
    commandline.cpp \
    main.cpp

HEADERS += \
    commandline.h

DISTFILES += \
    README.md \
    NOTES.md \
    .gitignore \
    .gitmodules
    
include( $$PWD/OpenWeatherMap-API/owm-api.pri )    
