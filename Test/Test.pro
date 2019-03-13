TARGET=Test
SOURCES+= main.cpp \
../Curve/src/ControlPoint.cpp

INCLUDEPATH+=/usr/local/include
INCLUDEPATH+= ../Curve/include
LIBS+= -L/usr/local/lib -lgtest
CONFIG+=c++11
