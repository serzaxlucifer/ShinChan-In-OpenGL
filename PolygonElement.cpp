#include "PolygonElement.h"

float scaleValue(float value, float minVal, float maxVal)
{
    return 2.0f * (value - minVal) / (maxVal - minVal) - 1.0f;
}


void scaleArray(float** arr, float size, int dim2, float minX, float minY, float maxX, float maxY)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i][0] = scaleValue(arr[i][0], minX, maxX);
        arr[i][1] = scaleValue(arr[i][1], minY, maxY);
    }
}


CubicBezierCurve::CubicBezierCurve(float** CtrlPoints)
{
    int dim1 = 4, dim2 = 2, numPoints = 500;
    controlPoints = CtrlPoints;
    this->dim1 = dim1;
    this->numControlPoints = dim1;
    this->dim2 = dim2;
    bezierSmoothness = numPoints;

    if (dim1 != 4 || dim2 != 2)
    {
        std::cout << "FATAL: Cubic Bezier Curve must have 4 control points and 2 dimensions ONLY. Exiting...\n";
        exit(1);
    }

    renderPoints = new GLfloat[bezierSmoothness * 3];
    if (enableDebug)
        std::cout << "Cubic Bezier Curve Created Storage created of size = " << bezierSmoothness * 3 << "!\n";
}

CubicBezierCurve::CubicBezierCurve(float CtrlPoints[4][2])
{
    int dim1 = 4, dim2 = 2, numPoints = 100;
    controlPoints = new float* [dim1];
    for (int i = 0; i < dim1; i++)
    {
        controlPoints[i] = new float[dim2];
        for (int j = 0; j < dim2; j++)
        {
            controlPoints[i][j] = CtrlPoints[i][j];
        }
    }

    this->dim1 = dim1;
    this->numControlPoints = dim1;
    this->dim2 = dim2;
    bezierSmoothness = numPoints;

    if (dim1 != 4 || dim2 != 2)
    {
        std::cout << "FATAL: Cubic Bezier Curve must have 4 control points and 2 dimensions ONLY. Exiting...\n";
        exit(1);
    }

    renderPoints = new GLfloat[bezierSmoothness * 3];
}

void CubicBezierCurve::normalizeControlPoints(float maxX, float maxY, float minX, float minY)
{
    if (enableDebug)
        std::cout << "Insize Bezier Normalizer\n";
    if (!normalized)
    {
        normalized = true;
        scaleArray(controlPoints, numControlPoints, dim2, minX, minY, maxX, maxY);
    }
    else
    {
        std::cout << "WARNING: Control points already normalized for Bezier Curve. Skipping...\n";
    }
}

GLfloat* CubicBezierCurve::getRenderPoints()
{
    cubicBezierGenerator();
    return renderPoints;
}

void CubicBezierCurve::Delete()
{
    delete[] renderPoints;
    delete[] controlPoints;
}

int CubicBezierCurve::getNumRenderPoints()
{
    return bezierSmoothness * 3;
}

void CubicBezierCurve::cubicBezierGenerator()
{
    float u = 0;
    for (int i = 0; i < bezierSmoothness; i++)
    {
        u = (float)(bezierSmoothness - 1 - i) / (bezierSmoothness - 1);

        float lerp1X = u * controlPoints[0][0] + (1 - u) * controlPoints[1][0];
        float lerp1Y = u * controlPoints[0][1] + (1 - u) * controlPoints[1][1];
        float lerp2X = u * controlPoints[1][0] + (1 - u) * controlPoints[2][0];
        float lerp2Y = u * controlPoints[1][1] + (1 - u) * controlPoints[2][1];
        float lerp3X = u * controlPoints[2][0] + (1 - u) * controlPoints[3][0];
        float lerp3Y = u * controlPoints[2][1] + (1 - u) * controlPoints[3][1];

        float lerp4X = u * lerp1X + (1 - u) * lerp2X;
        float lerp4Y = u * lerp1Y + (1 - u) * lerp2Y;
        float lerp5X = u * lerp2X + (1 - u) * lerp3X;
        float lerp5Y = u * lerp2Y + (1 - u) * lerp3Y;

        float lerp6X = u * lerp4X + (1 - u) * lerp5X;
        float lerp6Y = u * lerp4Y + (1 - u) * lerp5Y;

        renderPoints[i * 3 + 0] = lerp6X;
        renderPoints[i * 3 + 1] = lerp6Y;
        renderPoints[i * 3 + 2] = 0.0f;
    }
}


StraightLine::StraightLine(std::vector<float> p1, std::vector<float> p2)
{
    if (p1.size() != 3 || p2.size() != 3)
    {
        std::cout << "FATAL: Straight Line must have 2 points with 3 dimensions each. Exiting...\n";
        exit(1);
    }

    pt1[0] = p1[0];
    pt1[1] = p1[1];
    pt1[2] = p1[2];
    pt2[0] = p2[0];
    pt2[1] = p2[1];
    pt2[2] = p2[2];

    renderPoints = new GLfloat[6];
}

void StraightLine::normalizeControlPoints(float maxX, float maxY, float minX, float minY)
{
    if (!normalized)
    {
        normalized = true;
        pt1[0] = scaleValue(pt1[0], minX, maxX);
        pt1[1] = scaleValue(pt1[1], minY, maxY);
        pt2[0] = scaleValue(pt2[0], minX, maxX);
        pt2[1] = scaleValue(pt2[1], minY, maxY);

        if (enableDebug)
            std::cout << pt1[0] << "  " << pt1[1] << " " << pt1[0] <<  "   " << pt2[2] << "\n";
    }
    else
    {
        std::cout << "WARNING: Control points already normalized for Straight Line. Skipping...\n";
    }
}

GLfloat* StraightLine::getRenderPoints()
{
    renderPoints[0] = pt1[0];
    renderPoints[1] = pt1[1];
    renderPoints[2] = pt1[2];
    renderPoints[3] = pt2[0];
    renderPoints[4] = pt2[1];
    renderPoints[5] = pt2[2];

    //std::cout << "Render Points for Straight Line = " << renderPoints[0] << " " << renderPoints[1] << " " << renderPoints[2] << " " << renderPoints[3] << " " << renderPoints[4] << " " << renderPoints[5] << "\n";

    return renderPoints;
}

int StraightLine::getNumRenderPoints()
{
    return 6;
}

void StraightLine::Delete()
{
    delete[] renderPoints;
}
