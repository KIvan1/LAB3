include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS += tests.h \
        ../lab3/game.h

SOURCES += main.cpp \
        ../lab3/enemy_class.cpp \
        ../lab3/hero_class.cpp \
        ../lab3/map_class.cpp \
        ../lab3/get_command.cpp

INCLUDEPATH += ../lab3

DISTFILES += \
        maps/map.txt \
        maps/map1.txt \
        maps/map2.txt

LIBS += -lgcov -lncurses
