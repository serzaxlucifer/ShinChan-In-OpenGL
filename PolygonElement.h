#ifndef POLYGONELEMENT_H
#define POLYGONELEMENT_H

#include <glad/glad.h>
#include <iostream>
#include <vector>

float scaleValue(float value, float minVal, float maxVal);

void scaleArray(float** arr, float size, int dim2, float minX, float minY, float maxX, float maxY);

class PolygonElement
{
public:
    GLfloat* renderPoints = NULL;
    bool normalized = false;
    static bool enableDebug;

    virtual void Delete() = 0;

    virtual void normalizeControlPoints(float maxX, float maxY, float minX, float minY) = 0;

    virtual int getNumRenderPoints() = 0;

    virtual GLfloat* getRenderPoints() = 0;

    static void disableDebugMode()
    {
		enableDebug = true;
	}

    static void disableDebug()
    {
        enableDebug = false;
    }

    static void initialize()
    {
		enableDebug = false;
	}
};



class CubicBezierCurve : public PolygonElement
{
public:
    float** controlPoints;
    int dim1, dim2;
    int numControlPoints = 4;
    int bezierDegree = 3;
    int bezierSmoothness = 100;

    CubicBezierCurve(float** CtrlPoints);

    CubicBezierCurve(float CtrlPoints[4][2]);

    void normalizeControlPoints(float maxX, float maxY, float minX, float minY) override;

    GLfloat* getRenderPoints() override;

    void Delete() override;

    int getNumRenderPoints() override;

    void cubicBezierGenerator();

};

class StraightLine : public PolygonElement
{
public:
    float pt1[3];
    float pt2[3];


    StraightLine(std::vector<float> p1, std::vector<float> p2);

    void normalizeControlPoints(float maxX, float maxY, float minX, float minY) override;

    GLfloat* getRenderPoints() override;

    int getNumRenderPoints() override;

    void Delete() override;

};

#endif