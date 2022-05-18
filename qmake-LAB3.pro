TEMPLATE = subdirs

CONFIG -= app_bundle
CONFI -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = lab3 tests

CONFIG += ordered
