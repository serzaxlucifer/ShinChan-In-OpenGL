#include "Renderer.h"

bool Renderer::

Renderer::Renderer(Polygon* polygon, Shader& fillShader, Shader& borderShader) : fillShader(fillShader), borderShader(borderShader)
{
	renderPoints = NULL;
	this->polygon = polygon;
	this->fillShader = fillShader;
	this->borderShader = borderShader;

	// Now, generate some VAO and VBO.

	GLfloat* vertices = polygon->getRenderVertices();
	int numVertices = polygon->getNumRenderPoints();

	if (enableDebug)
		std::cout << "Number of Render Points for Polygon received by Renderer = " << numVertices << "\n";

	if (enableDebug)
	{
		for (int i = 0; i < numVertices; i++)
		{
			std::cout << vertices[i] << " | ";
		}


		std::cout << "Beginning VBO and VAO Generation...\n";
	}
	VBO vb(vertices, (int)(numVertices * 4));
	vbo = vb;
	vao.Bind();
	vao.LinkVBO(vbo, 0);			// 0 is the layout to be used in Vertex Shader. For our purpose, we're using layout = 0. See our documentation for more details.
	vao.Unbind();

	// Now, we have the VAO and VBO ready.
}

void Renderer::renderPolygon()
{
	fillShader.Activate();
	vao.Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, polygon->getNumRenderPoints() / 3);
	vao.Unbind();
}

void Renderer::renderBorder()
{
	borderShader.Activate();
	vao.Bind();
	glDrawArrays(GL_LINE_STRIP, 0, polygon->getNumRenderPoints() / 3);
	vao.Unbind();
}

void Renderer::Delete()
{
	vbo.Delete();
	vao.Delete();
	fillShader.Delete();
	borderShader.Delete();

	polygon->Delete();

	delete polygon;
}