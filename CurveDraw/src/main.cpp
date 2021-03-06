///
/// @file main.cpp
/// @brief generate curves without drawing


#include <GL/glu.h>
#include <SDL.h>

#include "Surface.h"


int main()
{
    std::cout<<"Curve Draw\n";

//------------------------------------------------------------------------------------------------------------------
    if( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        std::cerr<<"cant init SDL\n";
        exit( EXIT_FAILURE) ;
    }
//------------------------------------------------------------------------------------------------------------------


//Create a window by 1024*720
//------------------------------------------------------------------------------------------------------------------
    SDL_Window *window= SDL_CreateWindow("Curve",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         1024,
                                         720,
                                         SDL_WINDOW_OPENGL);
    if( !window )
    {
        std::cerr<<"unable rto open window\n";
                   exit( EXIT_FAILURE );
    }

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY );
    SDL_GLContext glcontext=SDL_GL_CreateContext( window );

    SDL_GL_MakeCurrent( window,glcontext );
//------------------------------------------------------------------------------------------------------------------


/*
//set points quantity to 20000 when generating a curve
//------------------------------------------------------------------------------------------------------------------
    size_t numCurvePoints = 100;

    //set the control points to generate the curve
    const std::vector<Vec3> controlPoints = { { -10.0f, -10.0f, 0.0f }, { -20.0f, -15.0f, 20.0f },
                                              { -10.0f, 10.0f, 0.0f }};

    //construct a curve
    //Curve c( controlPoints , numCurvePoints );

    //evaluate the bezier curve point
    // c.evaluateBezierCurve();
//------------------------------------------------------------------------------------------------------------------
*/


//generate a surface
//---------------------------------------------------    
    Surface s( 3, 3, 40,
    { { -7.0f, 7.0f, 14.0f }, { -8.0f, 10.0f, 9.0f }, { -10.0f, 13.0f, 4.0f },
      { 7.0f, 10.0f, 15.0f }, { 5.0f, 10.0f, 8.0f }, { 10.0f, 10.0f, 3.0f },
      { 15.0f, -5.0f, 16.0f }, { 7.0f, -7.0f, 7.0f }, { 10.0f, -10.0f, 2.0f } });
    s.evaluateSurfacePoints();
//--------------------------------------------


//------------------------------------------------------------------------------------------------------------------
    glMatrixMode( GL_PROJECTION );
    gluPerspective( 45.0f, 1024.0f / 720.0f, 0.1f, 100.0f );
    glMatrixMode( GL_MODELVIEW );

    //set eye/camera position to (0, 0, 0), look at the original point, and rotate a certain angle
    gluLookAt( 0, 0, 100, 0, 0, 0, 1, 1, 0 );

    //set the background colour
    glClearColor( 0.8f, 0.8f, 0.8f, 1.0f );

    bool quit = false;
    while( !quit )
    {        
        glClear( GL_COLOR_BUFFER_BIT );

        //render the curve
        //c.renderCurve();

        //render the surface
        s.renderSurface();

        SDL_GL_SwapWindow( window );
    }
//------------------------------------------------------------------------------------------------------------------

}
