TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += game.cpp \
        enemy_class.cpp\
        get_command.cpp \
        hero_class.cpp \
        map_class.cpp


HEADERS += \
	game.h 

DISTFILES += \
        map.txt


QMAKE_CFLAGS += -Wall -Wextra

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov -lncurses
