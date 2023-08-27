QT += testlib
QT -= gui

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++17
CONFIG -= app_bundle
CONFIG += gcov

TEMPLATE = app

SOURCES +=  tst_compound_unit.cpp
            ../CU_source_code/base_unit.hpp
            ../CU_source_code/base_unit_traits.hpp
            ../CU_source_code/compound_unit.hpp
            ../CU_source_code/is_valid.hpp
