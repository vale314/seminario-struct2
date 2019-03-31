TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    empleado.cpp \
    empresa.cpp \
    administracion.cpp

HEADERS += \
    cola.h \
    lsl.h \
    nodolsl.h \
    empleado.h \
    empresa.h \
    administracion.h
