#include <iostream>
#include "ControlPoint.h"
#include "Curve.h"
int main()
{
    std::cout<<"Curve main.cpp\n";
  //  ControlPoint P0();
    ControlPoint p({1.0f,2.0f,3.0f});
    p.render();

}
