TARGET  = Test

SOURCES += src/main.cpp

INCLUDEPATH +=  /usr/local/include
INCLUDEPATH += ../Curve/include

LIBS  += -L/usr/local/lib -lgtest -L../Curve -lCurve

CONFIG  +=  c++11
