TARGET=CurveDraw
SOURCES+=main.cpp\
         ../Curve/src/Curve.cpp\


QMAKE_CXXFLAGS+=$$system(pkg-config --cflags sdl2)
LIBS+= $$system(pkg-config --libs sdl2)
LIBS+= -lGLU
INCLUDEPATH+= /public/devel/2018/include/SDL2
INCLUDEPATH+= ../Curve/include/
