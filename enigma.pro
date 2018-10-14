TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    rotor.cpp \
    enigma.cpp \
    reflector.cpp

HEADERS += \
    rotor.h \
    enigma.h \
    utils.h \
    reflector.h
