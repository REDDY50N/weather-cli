QT          -= gui
QT          += core network

CONFIG      += c++11 console
CONFIG      -= app_bundle

TEMPLATE    = app
TARGET		= owmcli
DESTDIR     = $$PWD/bin
MOC_DIR     = ./generated/moc
OBJECTS_DIR = ./generated/obj

SOURCES += \
    main.cpp

HEADERS += \

DISTFILES += \
    README.md \
    NOTES.md
    
include( $$PWD/OpenWeatherMap-API/owm-api.pri )    
