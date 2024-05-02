#include "Polygon.h"
#include <iostream>

IrregularPolygon::IrregularPolygon(PolygonElement** elements, int numElements)
{
	if (elements == NULL)
	{
		return;
	}

	if (enableDebug)
		std::cout << "Constructing your polygon~\n";

	this->elements = elements;
	this->numElements = numElements;
	renderPoints = NULL;
}

void IrregularPolygon::normalizeControlPoints(float maxX, float maxY, float minX, float minY)
{
	if(enableDebug)
		std::cout << "Normalizing Control Points for Polygon... POLYGON NORMALIZER!\n";
	for (int i = 0; i < numElements; i++)
	{
		elements[i]->normalizeControlPoints(maxX, maxY, minX, minY);
	}
}

GLfloat* IrregularPolygon::getRenderVertices()
{
	if (enableDebug)
		std::cout << "Generating Render Points for Polygon...\n";
	std::vector<float> auxiliary;
	int offset = 0;
	float lastX = -20;
	float lastY = -20;
	float lastZ = -20;

	for (int i = 0; i < numElements; i++)
	{
		if (enableDebug)
			std::cout << "Generating Render Points for Polygon Element " << i + 1 << "...\n";
		GLfloat* temp = elements[i]->getRenderPoints();
		int numPoints = elements[i]->getNumRenderPoints();

		if (enableDebug)
		{
			std::cout << "RENDER START : " << temp[0] << "  " << temp[1] << "  " << temp[2] << "\n";
			std::cout << "RENDER END : " << temp[numPoints - 3] << "  " << temp[numPoints - 2] << "  " << temp[numPoints - 1] << "\n";
		}

		// Adjust next element's first point to last point of current element.
		offset = 0;
		if (temp != NULL && lastX == temp[0] && lastY == temp[1] && lastZ == temp[2])
		{

			offset = 0;
		}
	
		for (int j = 0 + offset; j < numPoints; j++)
		{
			if (temp[j] > 1 || temp[j] < -1)
			{
				std::cout << "FATAL: Render point not normalized between -1 to 1! POLYGON NUMBER: " << i + 1 << "Exiting...\n";
				exit(1);
			}

			// Otherwise Proceed...

			auxiliary.push_back(temp[j]);
		}

		offset = 0;
	}

	for (int i = 0; i < numElements; i++)
	{
		elements[i]->Delete();
	}

	renderPoints = new GLfloat[auxiliary.size()];
	numRenderPoints = auxiliary.size();
	if (renderPoints != NULL)
	{
		delete[] renderPoints;
	}

	renderPoints = new GLfloat[numRenderPoints];

	for (int i = 0; i < numRenderPoints; i++)
	{
		renderPoints[i] = auxiliary[i];
	}

	return renderPoints;

}

int IrregularPolygon::getNumRenderPoints()
{
	return numRenderPoints;

}

void IrregularPolygon::Delete()
{
	delete[] renderPoints;
}

RegularPolygon::RegularPolygon(float* centerVertex, float radius, int numSides)
{
	this->centerVertex[0] = centerVertex[0];
	this->centerVertex[1] = centerVertex[1];
	this->centerVertex[2] = centerVertex[2];
	this->radius = radius;
	this->numElements = numSides * 3;
	this->normalized = false;
}

int RegularPolygon::getNumRenderPoints()
{
	return numElements;
}

void RegularPolygon::Delete()
{
	delete[] renderPoints;
}

void RegularPolygon::normalizeControlPoints(float maxX, float maxY, float minX, float minY)
{
	if (!normalized)
	{
		normalized = true;
		centerVertex[0] = scaleValue(centerVertex[0], minX, maxX);
		centerVertex[1] = scaleValue(centerVertex[1], minY, maxY);
		radius = scaleValue(radius, minX, maxX);
		if (enableDebug)
			std::cout << "Circle Normalized! " << centerVertex[0] << "   " << centerVertex[1] <<"\n";
	}
	else
	{
		std::cout << "WARNING: Control points already normalized for Regular/Circular Polygon. Skipping...\n";
	}
}

GLfloat* RegularPolygon::getRenderVertices()
{
	if (renderPoints != NULL)
	{
		delete[] renderPoints;
	}

	renderPoints = new GLfloat[numElements];

	for (int i = 0; i < numElements / 3; ++i)
	{
		float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numElements/3);
		float dx = radius * std::cos(angle);
		float dy = radius * std::sin(angle);
		renderPoints[i * 3 + 0] = (centerVertex[0] + dx);
		renderPoints[i * 3 + 1] = (centerVertex[1] + dy);
		renderPoints[i * 3 + 2] = (centerVertex[2]);
	}

	return renderPoints;

}