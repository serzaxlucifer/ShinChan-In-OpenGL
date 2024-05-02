#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "VBO.h"
#include "VAO.h"
#include <glad/glad.h>
#include "Polygon.h"
#include "Shader.h"

class Renderer		// Renders a Polygon. When you instantiate a polygon rendered object, your polygon's vertices are stored to the GPU in constructor call.
{
public:
	Polygon* polygon;
	Shader& fillShader;
	Shader& borderShader;
	static bool enableDebug;

	VBO vbo;
	VAO vao;
	GLfloat* renderPoints;

	Renderer(Polygon* polygon, Shader& fillShader, Shader& borderShader);

	void renderPolygon();

	void renderBorder();

	void Delete();

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
#endif
