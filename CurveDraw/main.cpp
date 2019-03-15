#include <iostream>
#include <SDL.h>
#include <GL/gl.h>
#include<GL/glu.h>
#include "Curve.h"
void render(const Curve &_Curve);

int main()
{
    std::cout<<"Curve Draw\n";
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        std::cerr<<"cant init SDL\n";
        exit(EXIT_FAILURE);
    }

    SDL_Window *window= SDL_CreateWindow("Particle",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         1024,
                                         720,
                                         SDL_WINDOW_OPENGL);
    if(!window)
    {
        std::cerr<<"unable rto open window\n";
                   exit(EXIT_FAILURE);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GLContext glcontext=SDL_GL_CreateContext(window);

    SDL_GL_MakeCurrent(window,glcontext);

    bool quit=false;
    SDL_Event event;

    size_t numControlPoints = 4;
    size_t numCurvePoints =100;
    const std::vector<Vec3> controlPoints ={{2.0,4.0,0.0}, {1.0,5.0,0.0},{3.0,6.0,0.0},{2.0,7.0,0.0}};
    Curve c;
    c.BezierCurve(controlPoints,numControlPoints,numCurvePoints);
    //std::cout<<c.getControlPointsNumber()<<' '<< c.getCurvePointsNumber()<<"\n";
    //c.showControlPoints();
    //std::vector<size_t> C(numControlPoints);
    //std::vector<Vec3> curvePoints(numCurvePoints);//={{0,0,0}};
    //c.binomialCoeffs(numControlPoints-1, C);
    /*
    for(auto c : C)
      std::cout<<"coef "<<c<<'\n';
      */
    c.evaluateBezierCurve(controlPoints);
    //c.getCurvePoints(curvePoints);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f,1024.0f/720.0f,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(50,50,50,0,0,0,0,1,0);

    glClearColor(0.8f,0.8f,0.8f,1.0f);
    while(!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT : quit =true ; break;
            /*
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_LEFT : Curve.updatePos(-1.0f,0,0);break;
                case SDLK_RIGHT : Curve.updatePos(1.0f,0,0);break;
                case SDLK_UP : Curve.updatePos(0.0f,1.0,0);break;
                case SDLK_DOWN : Curve.updatePos(0.0f,-1.0,0);break;
                }
            }
            */
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        //Curve.update();

        //render(c);
        c.renderGL();
        SDL_GL_SwapWindow(window);
    }
}

void render(const Curve &_Curve)
{
    /*
    glPointSize(24.0);
    glBegin(GL_POINTS);
        auto p=_Curve.getPos();
        glColor3f(1.0,0.0,0.0);
        glVertex3f(p.x,p.y,p.z);
    glEnd();
    */

    glPointSize(100.0);
    glBegin(GL_POINTS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0,0,0);
    _Curve.renderGL();
    glEnd();
}
