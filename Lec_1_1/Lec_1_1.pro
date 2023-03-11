TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += sanitizer sanitize_undefined sanitize_address

SOURCES += \
        main.cpp \
        man.cpp \
        man_test.cpp \
        test.cpp

LIBS += -L$$PWD/../../googletest/build-googletest-Desktop-Debug/ -lgoogletest

INCLUDEPATH += $$PWD/../../googletest/googletest/include
DEPENDPATH += $$PWD/../../googletest/googletest/include

LIBS += -L$$PWD/../../googletest/build-googlemock-Desktop-Debug/ -lgooglemock

INCLUDEPATH += $$PWD/../../googletest/googlemock/include
DEPENDPATH += $$PWD/../../googletest/googlemock/include

HEADERS += \
    isum.h \
    man.h
