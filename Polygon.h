
#ifndef POLYGON_H
#define POLYGON_H
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include "PolygonElement.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846     // For use in Regular Polygon Drawing using GL_TRIANGLE_FAN primitive.
#endif

class Polygon
{
public:
	PolygonElement** elements;
	static bool enableDebug;

	GLfloat* renderPoints;
	int numElements;
	int numRenderPoints = -1;

	virtual void normalizeControlPoints(float maxX, float maxY, float minX, float minY) = 0;

	virtual GLfloat* getRenderVertices() = 0;

	virtual int getNumRenderPoints() = 0;

	virtual void Delete() = 0;

	static void enableDebugMode()
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

class IrregularPolygon : public Polygon		// Stores Irregular Polygons
{
public:

	void normalizeControlPoints(float maxX, float maxY, float minX, float minY);

	IrregularPolygon(PolygonElement** elements, int numElements);

	GLfloat* getRenderVertices();

	int getNumRenderPoints();

	void Delete();
};

class RegularPolygon : public Polygon		// Stores Regular Polygons + Circle
{
public:
	float centerVertex[3];
	float radius = -1;
	bool normalized = false;


	void normalizeControlPoints(float maxX, float maxY, float minX, float minY);
	RegularPolygon(float* centerVertex, float radius, int numSides);
	GLfloat* getRenderVertices();
	int getNumRenderPoints();
	void Delete();
};
#endif
