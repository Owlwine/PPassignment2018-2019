# PPassignment2018-2019
Before operating this program:
1.Make sure that related libraries exist. Include paths might need to be modified.
2.Please retain the structure of the folders and files.



System information:
Linux(64) Centos Redhat
Qt Creator based on Qt 5.11.1 



Guide to operate this program:

1)
compile the files
-make clean
-qmake
-make

2)
In CurveDraw folder, main.cpp is the file you could modify the value to generate curves or surfaces, using the related Curve functions or Surface functions.

class Curve's constructor and public functions:
    Curve( const std::vector<Vec3> &_controlPoints, const size_t _numCurvePoints );

    size_t              getControlPointsNumber() const;
    size_t              getCurvePointsNumber() const;
    std::vector<Vec3>   getControlPoints() const;
    void                showControlPoints() const;

    //calculate binomial coefficient
    void                binomialCoeffs( std::vector<size_t> &io_c );

    void                evaluateBezierCurve();
    std::vector<Vec3>   getCurvePoints() const;
    void                showCurvePoints() const;

    //render the curve points after calculation
    void                renderCurve() const;

private members (with default values):
    size_t              m_numControlPoints = 4;
    size_t              m_numCurvePoints = 1000;
    std::vector<Vec3>   m_controlPoints = {{1.0f,1.0f,0.0f}, {2.0f,2.0f,0.0f}, {3.0f,2.0f,0.0f}, {4.0f,1.0f,0.0f}};
    std::vector<Vec3>   m_curvePoints;


class Surface's constructor and public functions:
    Surface(const size_t _nRow, const size_t _nColumn,
             const size_t _numCurvePoints, const std::vector<Vec3> &_controlPoints);

    size_t              getSurfaceRow() const;
    size_t              getSurfaceColumn() const;
    size_t              getEdgePointsNumber() const;
    size_t              getSurfacePointsNumber() const;
    std::vector<Vec3>   getSurfaceControlPoints() const;
    std::vector<Vec3>   getSurfacePoints() const;

    //evaluate the points on the surface, according to the control points
    void                evaluateSurfacePoints();

    void                renderSurface() const;


private members;
    size_t              m_row = 4;
    size_t              m_column = 3;
    size_t              m_edgePointsNumber = 100;
    size_t              m_surfacePointsNumber = 100 * 100;
    std::vector<Vec3>   m_surfaceControlPoints = { { -10.0f, -10.0f,13.0f }, { -5.0f, -9.0f, 10.0f }, { -12.0f,-11.0f, 5.0f },
                                                 { -7.0f, 7.0f, 14.0f }, { -8.0f, 10.0f, 9.0f }, { -10.0f, 13.0f, 4.0f },
                                                 { 7.0f, 10.0f, 15.0f }, { 5.0f, 10.0f, 8.0f }, { 10.0f, 10.0f, 3.0f },
                                                 { 15.0f, -5.0f, 16.0f }, { 7.0f, -7.0f, 7.0f }, { 10.0f, -10.0f, 2.0f } };

    //Store the curves to use functions,like showing control point hall
    std::vector<Curve>  m_curves;

    std::vector<Vec3>   m_surfacePoints;
};



To generate a curve(currently bezier curve avaliable), you could input a vector of control points.Though the control points amount is not limited, please be aware that it will be expensive if the quantity of control poits reachs too large. Simply follow these steps:
-const std::vector<Vec3> controlPoints = { { -10.0f, -10.0f, 0.0f }, { more_control_points },... };
-size_t numCurvePoints = type_a_value;
-Curve c( controlPoints , numCurvePoints );
-c.evaluateBezierCurve();
-c.renderCurve();

To generate a surface, the steps are simliar (currently only compute with default value, could modify the quantity of points to generate the curves which would build a surface) :
-size_t numCurvePoints = type_a_value;
-Surface s( numCurvePoints );
-s.renderSurface();




If any query or suggesstion, please email "s4928285@bournemouth.ac.uk".


Date: March 18 2019


