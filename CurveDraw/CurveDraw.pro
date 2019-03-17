TARGET  = CurveDraw

SOURCES += src/main.cpp

INCLUDEPATH += /public/devel/2018/include/SDL2
INCLUDEPATH += ../Curve/include

LIBS  += $$system(pkg-config --libs sdl2)
LIBS  += -lGLU -L../Curve -lCurve

QMAKE_CXXFLAGS  +=  $$system(pkg-config --cflags sdl2)


