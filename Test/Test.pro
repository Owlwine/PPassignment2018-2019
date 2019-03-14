TARGET=Test
SOURCES+= main.cpp \
../Curve/src/ControlPoint.cpp \
../Curve/src/Curve.cpp

INCLUDEPATH+=/usr/local/include
INCLUDEPATH+= ../Curve/include
LIBS+= -L/usr/local/lib -lgtest
CONFIG+=c++11
