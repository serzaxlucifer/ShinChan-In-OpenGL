

#include <iostream>
#include <glad/glad.h>		// find my OpenGL definitions and fetch their functional pointers to let me use OpenGL.
#include <GLFW/glfw3.h>		// setting OpenGL context and Window Rendering for my device and OS. Alternate: GLUT
#include <vector>			// STL Vector for storing vertices and edges of a polygon.
#include "Shader.h"         // Our shader functions are in this! Modularized for ease of use.
#include "VAO.h"            // VAO Management implemented here to keep main code clean.
#include "VBO.h"            // VBO Management implemented here to keep main code clean.
#include "Polygon.h"		// Helpful for defining a polygon with vertices and edges by using PolygonElements.
#include "PolygonElement.h" // Helpful for defining parts that make up an entire polygon... using curves, lines.
#include "Renderer.h"		// Rendering functions are implemented here to keep main code clean.

// MUKUL MALIK (Author)

// Function Declaration can be found below code...
Renderer** loadShinChanMesh(Shader** shaderArray, int size);

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	PolygonElement::initialize();
	Polygon::initialize();
	Renderer::initialize();
	Polygon::disableDebug();
	Renderer::disableDebug();
	PolygonElement::disableDebug();


	GLFWwindow* window = glfwCreateWindow(800, 800, "ShinChan", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Enable anti-aliasing
	glfwWindowHint(GLFW_SAMPLES, 16); // Adjust the number for higher quality

	gladLoadGL();

	std::cout << "Window Initialized!\n";

	// GLAD OVER WORK

	glViewport(0, 0, 1000, 1000);

	Shader* s1 = new Shader("vertexShader.vert", "fragmentSkin.frag");
	Shader* s2 = new Shader("vertexShader.vert", "fragmentBlack.frag");
	Shader* s3 = new Shader("vertexShader.vert", "fragmentRed.frag");
	Shader* s4 = new Shader("vertexShader.vert", "fragmentYellow.frag");
	Shader* s5 = new Shader("vertexShader.vert", "fragmentDarkYellow.frag");
	Shader* s6 = new Shader("vertexShader.vert", "fragmentWhite.frag");
	Shader* s7 = new Shader("vertexShader.vert", "fragmentMouth.frag");
	Shader* shaderArray[7] = { s1, s2, s3, s4, s5, s6, s7};

	std::cout << "Shaders Compiled and Linked!\n";
	glEnable(GL_LINE_SMOOTH);

	Renderer** bodyPartRenderers = loadShinChanMesh(shaderArray, 7);
	int numRenderers = 33;

	std::cout << "Renderer Created!\n";

	while (!glfwWindowShouldClose(window))
	{

		glClearColor(1.00f, 1.00f, 1.00f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glLineWidth(2.0f);




		// Render in correct order!

		bodyPartRenderers[1]->renderPolygon();
		bodyPartRenderers[1]->renderBorder();
		//bodyPartRenderers[2]->renderPolygon();
		bodyPartRenderers[2]->renderBorder();
		//bodyPartRenderers[3]->renderPolygon();
		bodyPartRenderers[3]->renderBorder();
		bodyPartRenderers[4]->renderPolygon();
		bodyPartRenderers[4]->renderBorder();
		//bodyPartRenderers[6]->renderPolygon();
		bodyPartRenderers[6]->renderBorder();
		bodyPartRenderers[7]->renderPolygon();
		bodyPartRenderers[7]->renderBorder();
		bodyPartRenderers[8]->renderPolygon();
		bodyPartRenderers[8]->renderBorder();
		bodyPartRenderers[9]->renderPolygon();
		bodyPartRenderers[9]->renderBorder();
		bodyPartRenderers[10]->renderPolygon();
		bodyPartRenderers[10]->renderBorder();
		bodyPartRenderers[11]->renderPolygon();
		bodyPartRenderers[11]->renderBorder();
		bodyPartRenderers[12]->renderPolygon();
		bodyPartRenderers[12]->renderBorder();
		bodyPartRenderers[13]->renderPolygon();
		bodyPartRenderers[13]->renderBorder();
		bodyPartRenderers[14]->renderPolygon();
		bodyPartRenderers[14]->renderBorder();
		//bodyPartRenderers[15]->renderPolygon();
		bodyPartRenderers[15]->renderBorder();
		bodyPartRenderers[16]->renderPolygon();
		bodyPartRenderers[16]->renderBorder();
		//bodyPartRenderers[17]->renderPolygon();
		bodyPartRenderers[17]->renderBorder();
		bodyPartRenderers[18]->renderPolygon();
		bodyPartRenderers[18]->renderBorder();
		bodyPartRenderers[19]->renderPolygon();
		bodyPartRenderers[19]->renderBorder();
		bodyPartRenderers[20]->renderPolygon();
		bodyPartRenderers[20]->renderBorder();

		bodyPartRenderers[33]->renderPolygon();
		bodyPartRenderers[33]->renderBorder();
		bodyPartRenderers[21]->renderPolygon();
		bodyPartRenderers[21]->renderBorder();

		bodyPartRenderers[23]->renderPolygon();
		bodyPartRenderers[23]->renderBorder();
		//bodyPartRenderers[24]->renderPolygon();
		bodyPartRenderers[24]->renderBorder();

		bodyPartRenderers[22]->renderPolygon();
		bodyPartRenderers[22]->renderBorder();
		bodyPartRenderers[25]->renderPolygon();
		bodyPartRenderers[25]->renderBorder();
		bodyPartRenderers[26]->renderPolygon();
		bodyPartRenderers[26]->renderBorder();
		bodyPartRenderers[27]->renderPolygon();
		bodyPartRenderers[27]->renderBorder();
		bodyPartRenderers[28]->renderPolygon();
		bodyPartRenderers[28]->renderBorder();
		//bodyPartRenderers[29]->renderPolygon();
		bodyPartRenderers[29]->renderBorder();
		//bodyPartRenderers[30]->renderPolygon();
		bodyPartRenderers[30]->renderBorder();
		bodyPartRenderers[31]->renderPolygon();
		bodyPartRenderers[31]->renderBorder();
		bodyPartRenderers[32]->renderPolygon();
		bodyPartRenderers[32]->renderBorder();

		bodyPartRenderers[37]->renderPolygon();

		bodyPartRenderers[38]->renderPolygon();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	for (int i = 0; i < numRenderers; i++)
	{
		bodyPartRenderers[i]->Delete();
	}


	for (int i = 0; i < 7; i++)
	{
		shaderArray[i]->Delete();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}


// Hardcoded from Desmos Modelling.
Renderer** loadShinChanMesh(Shader** shaderArray, int size)
{
	// Render Up Hand Part 1:

	Renderer** bodyPartRenderers = new Renderer * [40];
	Polygon** POLYGONS = new Polygon * [50];
	float maxX = 200.0, maxY = 200.0, minX = -200.0, minY = -200.0;

	std::vector<std::vector<float>> ST1A = { { -35.1f, 40.9f, 0 }, { -38.6f, 48.0f , 0} };
	float CTRL1A[4][2] = { { -38.6f, 48.0f }, { -40.36f, 47.74f }, { -46.94f, 46.7f }, { -49.41f, 43.6f } };
	std::vector<std::vector<float>> ST1C = { { -47.2f, 32.7f, 0 }, { -35.1f, 40.9f , 0} };
	PolygonElement* p1[3] = { new StraightLine(ST1A[0], ST1A[1]), new CubicBezierCurve(CTRL1A), new StraightLine(ST1C[0], ST1C[1]) };
	POLYGONS[1] = new IrregularPolygon(p1, 3);
	POLYGONS[1]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[7] = new Renderer(POLYGONS[1], *shaderArray[2], *shaderArray[1]);

	// SHIRT:               18


	float CTRL2A[4][2] = { { -35.64f, -2.56f }, { -34.6f, -16.2f }, { -38.5f, -35.6f }, { -35.8f, -42.5f } };
	float CTRL2B[4][2] = { { -35.8f, -42.5f }, { -35.4f, -45.5f }, { -36.4f, -48.2f }, { -32.7f, -47.4f } };
	std::vector<std::vector<float>> ST2A = { { -32.7f, -47.4f, 0 }, { 45.0f, -54.6f , 0} };
	std::vector<std::vector<float>> ST2B = { { 45.0f, -54.6f, 0 }, { 40.3, -25.5 , 0} };
	std::vector<std::vector<float>> ST2C = { { 40.3, -25.5, 0 }, { 45.3, -8.5 , 0} };
	std::vector<std::vector<float>> ST2D = { { 45.3, -8.5 , 0 }, { -35.64f, -2.56f , 0} };
	PolygonElement* p2[6] = { new CubicBezierCurve(CTRL2A), new CubicBezierCurve(CTRL2B), new StraightLine(ST2A[0], ST2A[1]), new StraightLine(ST2B[0], ST2B[1]), new StraightLine(ST2C[0], ST2C[1]), new StraightLine(ST2D[0], ST2D[1]) };
	POLYGONS[2] = new IrregularPolygon(p2, 6);
	POLYGONS[2]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[18] = new Renderer(POLYGONS[2], *shaderArray[2], *shaderArray[1]);

	// Render Down Hand Part 1:

	std::vector<std::vector<float>> ST3A = { { 51.7, -5.0, 0 }, { 64.63, -41.5 , 0} };
	std::vector<std::vector<float>> ST3B = { { 64.63, -41.5, 0 }, { 57.7, -44.22 , 0} };
	float CTRL3A[4][2] = { { 57.7, -44.22 }, { 46.4, -32.7 }, { 43.1, -27.1 }, { 34.2, -20.7 } };
	std::vector<std::vector<float>> ST3C = { { 34.2, -20.7, 0 }, { 51.7, -5.0 , 0} };
	PolygonElement* p3[4] = { new StraightLine(ST3A[0], ST3A[1]), new StraightLine(ST3B[0], ST3B[1]), new CubicBezierCurve(CTRL3A), new StraightLine(ST3C[0], ST3C[1]) };

	PolygonElement* p3a[1] = { new StraightLine(ST3C[0], ST3C[1]) };//RED

	POLYGONS[3] = new IrregularPolygon(p3, 4);
	POLYGONS[3]->normalizeControlPoints(maxX, maxY, minX, minY);
	POLYGONS[4] = new IrregularPolygon(p3a, 1);
	POLYGONS[4]->normalizeControlPoints(maxX, maxY, minX, minY);

	bodyPartRenderers[19] = new Renderer(POLYGONS[3], *shaderArray[2], *shaderArray[1]);
	bodyPartRenderers[20] = new Renderer(POLYGONS[4], *shaderArray[2], *shaderArray[2]);

	// Render Face:

	float CTRL4A[4][2] = { { 45.3, -8.5 }, { -84.189, -31.4 }, { -56.6, 53.6 }, { -24.8, 39.9 } };
	float CTRL4B[4][2] = { { -24.8, 39.9 }, { -23.14, 48.3 }, { -18.4, 50.9 }, { -13.7, 54} };
	float CTRL4C[4][2] = { { -13.7, 54}, { 0.3, 56.2 }, { 18.6, 55.6 }, { 36.7, 39.5 } };
	float CTRL4D[4][2] = { { 36.7, 39.5}, { 47.76, 37.23 }, { 40.1, 8.0 }, {45.3, -8.5} };
	//float CTRL4C[4][2] = { { -13.7, 54 }, { 0.6, 68 }, { 59.7, 60 }, { 45.3, -8.5 } };

	PolygonElement* p4[4] = { new CubicBezierCurve(CTRL4A), new CubicBezierCurve(CTRL4B), new CubicBezierCurve(CTRL4C), new CubicBezierCurve(CTRL4D) };
	POLYGONS[5] = new IrregularPolygon(p4, 4);
	POLYGONS[5]->normalizeControlPoints(maxX, maxY, minX, minY);

	bodyPartRenderers[21] = new Renderer(POLYGONS[5], *shaderArray[0], *shaderArray[1]);

	// Render Hair:


	float CTRL5A[4][2] = { { -13.7, 54.0}, { 0.3, 56.2 }, { 18.6, 55.6 }, { 36.7, 39.5 } };
	float CTRL5BA[4][2] = { { 36.7, 39.5}, { 47.76, 37.23 }, { 40.1, 8.0 }, {45.3, -8.5} };
	float CTRL5B[4][2] = { { 45.3, -8.5}, { 59.7, 60.0 }, { 0.6, 68 }, {-13.7, 54.0} };

	PolygonElement* p5[3] = { new CubicBezierCurve(CTRL5A), new CubicBezierCurve(CTRL5BA), new CubicBezierCurve(CTRL5B) };

	POLYGONS[6] = new IrregularPolygon(p5, 3);
	POLYGONS[6]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[33] = new Renderer(POLYGONS[6], *shaderArray[1], *shaderArray[1]);


	std::vector<std::vector<float>> ST6A = { { -46.5, 45.55, 0 }, { -47.8, 50.0 , 0} };
	float CTRL6A[4][2] = { { -47.8, 50.0 }, { -48.5, 53.3 }, { -53.9, 44.1 }, { -57.44, 50.5 } };
	float CTRL6B[4][2] = { { -57.44, 50.5 }, { -59.9, 51.6 }, { -60.3, 59.6 }, { -57.2, 59.3} };
	float CTRL6C[4][2] = { { -57.2, 59.3 }, { -47.6, 58.95 }, { -45.73, 70.02 }, { -41.6, 62.16 } };
	float CTRL6D[4][2] = { { -41.6, 62.16 }, { -39.86, 60.27 }, { -38.46, 56.37 }, { -39.33, 54.63 } };
	float CTRL6E[4][2] = { { -39.33, 54.63 }, { -42.42, 52.62 }, { -42.6, 51.25 }, { -41.16, 50.26} };
	std::vector<std::vector<float>> ST6B = { { -41.16, 50.26, 0 }, { -40.36, 47.74 , 0} };

	PolygonElement* p6[7] = { new StraightLine(ST6A[0], ST6A[1]), new CubicBezierCurve(CTRL6A), new CubicBezierCurve(CTRL6B), new CubicBezierCurve(CTRL6C), new CubicBezierCurve(CTRL6D), new CubicBezierCurve(CTRL6E), new StraightLine(ST6B[0], ST6B[1]) };
	POLYGONS[7] = new IrregularPolygon(p6, 7);
	POLYGONS[7]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[1] = new Renderer(POLYGONS[7], *shaderArray[0], *shaderArray[1]);

	// HAND BROW 1:

	float CTRL7[4][2] = { { -55.85, 54.33 }, { -52.7, 50.97 }, { -48.24, 53.66 }, { -44.2, 56.4} };
	PolygonElement* p7[1] = { new CubicBezierCurve(CTRL7) };
	POLYGONS[8] = new IrregularPolygon(p7, 1);
	POLYGONS[8]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[2] = new Renderer(POLYGONS[8], *shaderArray[1], *shaderArray[1]);

	// HAND BROW 2:


	float CTRL8[4][2] = { { -44.2, 56.4 }, {  -55.5, 55.2 }, { -44.54, 66.23 }, { -42.4, 62.4} };
	PolygonElement* p8[1] = { new CubicBezierCurve(CTRL8) };
	POLYGONS[9] = new IrregularPolygon(p8, 1);
	POLYGONS[9]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[3] = new Renderer(POLYGONS[9], *shaderArray[1], *shaderArray[1]);

	// Right Hand Below: 


	std::vector<std::vector<float>> ST9A = { { 58.64, -43.77, 0 }, { 59.1, -44.5 , 0} };
	float CTRL9A[4][2] = { { 59.1, -44.5 }, { 59.34, -46.4 }, { 56.95, -47.07 }, { 55.45, -48.14 } };
	float CTRL9B[4][2] = { { 55.45, -48.14 }, { 53.8, -50.37 }, { 55, -51.46 }, { 56.45, -52.66} };
	float CTRL9C[4][2] = { { 56.45, -52.66 }, { 58.46, -55.43 }, { 62.5, -55.86 }, { 64.46, -54.54 } };
	float CTRL9D[4][2] = { { 64.46, -54.54 }, { 71.4, -50.08 }, { 72.36, -50.17 }, { 70.92, -49.8 } };
	float CTRL9E[4][2] = { { 70.92, -49.8 }, { 68.1, -41.2 }, { 66.4, -45.15 }, { 63.18, -41.62} };
	std::vector<std::vector<float>> ST9B = { { 63.18, -41.62, 0 }, {  58.64, -43.77 , 0} };
	PolygonElement* p9[7] = { new StraightLine(ST9A[0], ST9A[1]), new CubicBezierCurve(CTRL9A), new CubicBezierCurve(CTRL9B), new CubicBezierCurve(CTRL9C), new CubicBezierCurve(CTRL9D), new CubicBezierCurve(CTRL9E), new StraightLine(ST9B[0], ST9B[1]) };
	POLYGONS[10] = new IrregularPolygon(p9, 7);
	POLYGONS[10]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[4] = new Renderer(POLYGONS[10], *shaderArray[0], *shaderArray[1]);

	// HAND BROW 1:


	float CTRL10[4][2] = { { 59.47, -54.87 }, { 57.13, -50.7 }, { 57.8, -49.78 }, { 60.31, -50.74} };
	PolygonElement* p10[1] = { new CubicBezierCurve(CTRL10) };
	POLYGONS[11] = new IrregularPolygon(p10, 1);
	POLYGONS[11]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[5] = new Renderer(POLYGONS[11], *shaderArray[1], *shaderArray[1]);

	// HAND BROW 2:
	float CTRL11[4][2] = { { 59.535, -54.85 }, { 58.5, -54.85 }, { 57.98, -50.2 }, { 60.43, -50.9} };
	PolygonElement* p11[1] = { new CubicBezierCurve(CTRL11) };
	POLYGONS[12] = new IrregularPolygon(p11, 1);
	POLYGONS[12]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[6] = new Renderer(POLYGONS[12], *shaderArray[1], *shaderArray[1]);



	// FIX TILL HERE! 11 FIXED   8->17
	// PANTS 1: 8-17   


	std::vector<std::vector<float>> ST12A = { { -32.7, -47.4, 0 }, { -34.3, -72.51 , 0} };
	float CTRL12A[4][2] = { { -34.3, -72.51 }, { -37.0, -79.7 }, { -11, -79.5 }, { 2.7, -81.8 } };
	float CTRL12B[4][2] = { { 2.7, -81.8 }, { 6.27, -82.66 }, { 6.78, -80.535 }, { 6.82, -79.66 } };
	std::vector<std::vector<float>> ST12B = { { 6.82, -79.66, 0 }, { 45.0, -54.6 , 0} };
	std::vector<std::vector<float>> ST12C = { { 45.0, -54.6, 0 }, {  -32.7, -47.4 , 0} };

	PolygonElement* p12[5] = { new StraightLine(ST12A[0], ST12A[1]), new CubicBezierCurve(CTRL12A), new CubicBezierCurve(CTRL12B),  new StraightLine(ST12B[0], ST12B[1]), new StraightLine(ST12C[0], ST12C[1]) };
	POLYGONS[13] = new IrregularPolygon(p12, 5);
	POLYGONS[13]->normalizeControlPoints(maxX, maxY, minX, minY);

	bodyPartRenderers[14] = new Renderer(POLYGONS[13], *shaderArray[3], *shaderArray[1]);

	// RE-BORDER WITH YELLOW!:
	// 

	std::vector<std::vector<float>> ST13A = { { 6.82, -79.66, 0 }, { 45.0, -54.6 , 0} };
	PolygonElement* p13[1] = { new StraightLine(ST13A[0], ST13A[1]) };
	POLYGONS[14] = new IrregularPolygon(p13, 1);
	POLYGONS[14]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[15] = new Renderer(POLYGONS[14], *shaderArray[3], *shaderArray[3]);

	// PANTS 2: 


	float CTRL14A[4][2] = { { 1.4, -64.1 }, { 3.8, -71.7 }, { 6.1, -83.9  }, { 12.4, -83.6 } };
	std::vector<std::vector<float>> ST14A = { { 12.4, -83.6, 0 }, { 52.5, -88.0 , 0} };
	float CTRL14B[4][2] = { { 52.5, -88.0 }, { 46.3, -78.1 }, { 48.7, -66.7 }, { 45.0, -54.6} };
	std::vector<std::vector<float>> ST14B = { { 45.0, -54.6, 0 }, {  1.4, -64.1 , 0} };

	PolygonElement* p14[4] = { new CubicBezierCurve(CTRL14A),  new StraightLine(ST14A[0], ST14A[1]),  new CubicBezierCurve(CTRL14B),  new StraightLine(ST14B[0], ST14B[1]) };
	POLYGONS[15] = new IrregularPolygon(p14, 4);
	POLYGONS[15]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[16] = new Renderer(POLYGONS[15], *shaderArray[3], *shaderArray[1]);


	// RE-BORDER WITH YELLOW!: 
	std::vector<std::vector<float>> ST15AB = { { 45.0, -54.6, 0 }, {  1.4, -64.1 , 0} };

	PolygonElement* p15[1] = { new StraightLine(ST15AB[0], ST15AB[1]) };
	POLYGONS[16] = new IrregularPolygon(p15, 1);
	POLYGONS[16]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[17] = new Renderer(POLYGONS[16], *shaderArray[3], *shaderArray[3]);


	// LEFT LEG: render before pant (START 11) 8->17

	std::vector<std::vector<float>> ST15A = { { -0.78, -80.46, 0 }, { -6, -106.9 , 0} };
	float CTRL15A[4][2] = { { -6, -106.9  }, { -8.6, -111.4 }, {  -17.6, -109.8 }, { -18.3, -106.64 } };
	float CTRL15B[4][2] = { { -18.3, -106.64 }, { -18.93, -101.87 }, { -19.35, -99.2 }, { -19.9, -95.0} };
	float CTRL15C[4][2] = { { -19.9, -95.0 }, { -20.92, -91.0 }, { -21.27, -85.33 }, { -24.2, -77.58} };
	std::vector<std::vector<float>> ST15B = { { -24.2, -77.58, 0 }, {  -0.78, -80.46 , 0} };

	PolygonElement* p16[5] = { new StraightLine(ST15A[0], ST15A[1]),  new CubicBezierCurve(CTRL15A),  new CubicBezierCurve(CTRL15B),  new CubicBezierCurve(CTRL15C),new StraightLine(ST15B[0], ST15B[1]) };
	POLYGONS[17] = new IrregularPolygon(p16, 5);
	POLYGONS[17]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[8] = new Renderer(POLYGONS[17], *shaderArray[0], *shaderArray[1]);


	// border (black only) white color

	std::vector<std::vector<float>> ST15C = { { -19.9, -95.0, 0 }, { -3.6, -94.7 , 0} };
	std::vector<std::vector<float>> ST15C1 = { { -3.6, -94.7 , 0 }, { -6, -106.9 , 0} };
	float CTRL15A1[4][2] = { { -6, -106.9  }, { -8.6, -111.4 }, {  -17.6, -109.8 }, { -18.3, -106.64 } };
	float CTRL15B1[4][2] = { { -18.3, -106.64 }, { -18.93, -101.87 }, { -19.35, -99.2 }, { -19.9, -95.0} };
	PolygonElement* p16B[4] = { new StraightLine(ST15C[0], ST15C[1]), new StraightLine(ST15C1[0], ST15C1[1]), new CubicBezierCurve(CTRL15A1), new CubicBezierCurve(CTRL15B1) };
	POLYGONS[18] = new IrregularPolygon(p16B, 4);
	POLYGONS[18]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[12] = new Renderer(POLYGONS[18], *shaderArray[5], *shaderArray[1]);


	// RIGHT LEG: render before pant

	std::vector<std::vector<float>> ST17A = { { 23.5, -83.7, 0 }, { 42.95, -85.4 , 0} };
	std::vector<std::vector<float>> ST17B = { { 42.95, -85.4, 0 }, { 43.7, -99.3 , 0} };
	float CTRL17A[4][2] = { { 43.7, -99.3 }, { 43.16, -100.7 }, { 44.55, -104.1  }, { 44.56, -105.8 } };
	std::vector<std::vector<float>> ST17C = { { 44.56, -105.8, 0 }, { 41.2, -113.8 , 0} };
	float CTRL17B[4][2] = { { 41.2, -113.8 }, { 38.5, -112.35 }, { 35.04, -111.1 }, { 31.9, -110.0} };
	float CTRL17C[4][2] = { { 31.9, -110.0 }, { 32.0, -107.1 }, { 30.6, -104.4 }, { 28.4, -98.4 } };
	float CTRL17D[4][2] = { { 28.4, -98.4 }, { 27.3, -97.0 }, { 25.3, -91.1 }, { 23.5, -83.7} };

	PolygonElement* p17[7] = { new StraightLine(ST17A[0], ST17A[1]), new StraightLine(ST17B[0], ST17B[1]),  new CubicBezierCurve(CTRL17A),  new StraightLine(ST17C[0], ST17C[1]),  new CubicBezierCurve(CTRL17B),  new CubicBezierCurve(CTRL17C),  new CubicBezierCurve(CTRL17D) };
	POLYGONS[19] = new IrregularPolygon(p17, 7);
	POLYGONS[19]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[9] = new Renderer(POLYGONS[19], *shaderArray[0], *shaderArray[1]);


	// border (black only)


	std::vector<std::vector<float>> ST17_ = { { 28.4, -98.4, 0 }, { 43.7, -99.3, 0} };
	float CTRL17A_[4][2] = { { 43.7, -99.3 }, { 43.16, -100.7 }, { 44.55, -104.1  }, { 44.56, -105.8 } };
	std::vector<std::vector<float>> ST17C_ = { { 44.56, -105.8, 0 }, { 41.2, -113.8 , 0} };
	float CTRL17B_[4][2] = { { 41.2, -113.8 }, { 38.5, -112.35 }, { 35.04, -111.1 }, { 31.9, -110.0} };
	float CTRL17D_[4][2] = { { 31.9, -110.0 }, { 32.0, -107.1 }, { 30.6, -104.4 }, { 28.4, -98.4 } };

	PolygonElement* p17E[5] = { new StraightLine(ST17_[0], ST17_[1]),  new CubicBezierCurve(CTRL17A_) , new StraightLine(ST17C_[0], ST17C_[1]) , new CubicBezierCurve(CTRL17B_) , new CubicBezierCurve(CTRL17D_) };
	POLYGONS[20] = new IrregularPolygon(p17E, 5);
	POLYGONS[20]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[13] = new Renderer(POLYGONS[20], *shaderArray[5], *shaderArray[1]);


	// LEFT SHOE: RENDER B4 LEG

	std::vector<std::vector<float>> ST18A = { { -18.3, -106.64, 0 }, { -6.0, -106.9 , 0} };
	std::vector<std::vector<float>> ST18B = { { -6.0, -106.9, 0 }, {  -1.64, -118.06 , 0} };
	float CTRL18A[4][2] = { {  -1.64, -118.06 }, { -7.77, -119.57 }, { -23.85, -120.2  }, { -26.16, -120.46 } };
	float CTRL18B[4][2] = { { -26.16, -120.46 }, { -29.4, -120.7 }, { -36.3, -121.5 }, { -29.2, -116.6} };
	float CTRL18C[4][2] = { { -29.2, -116.6 }, { -25.0, -112.6 }, { -19.0, -115.0 }, { -18.3, -106.64 } };

	PolygonElement* p18[5] = { new StraightLine(ST18A[0], ST18A[1]),  new StraightLine(ST18B[0], ST18B[1]), new CubicBezierCurve(CTRL18A), new CubicBezierCurve(CTRL18B), new CubicBezierCurve(CTRL18C) };
	POLYGONS[21] = new IrregularPolygon(p18, 5);
	POLYGONS[21]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[10] = new Renderer(POLYGONS[21], *shaderArray[4], *shaderArray[1]);


	// RIGHT SHOE: RENDER B4 LEG


	std::vector<std::vector<float>> ST19A = { { 44.56, -105.8,  0 }, {  31.76, -110.0 , 0} };
	float CTRL19A[4][2] = { {  31.76, -110.0 }, { 28.6, -111.05 }, { 24.14, -116.6  }, { 31.0, -118.0 } };
	float CTRL19B[4][2] = { { 31.0, -118.0 }, { 42.7, -119.9 }, { 50.0, -119.0 }, { 58.3, -119.2} };
	float CTRL19C[4][2] = { { 58.3, -119.2 }, { 50.3, -108.3 }, { 44.4, -112.4 }, { 44.56, -105.8 } };

	PolygonElement* p19[4] = { new StraightLine(ST19A[0], ST19A[1]), new CubicBezierCurve(CTRL19A), new CubicBezierCurve(CTRL19B), new CubicBezierCurve(CTRL19C) };
	POLYGONS[22] = new IrregularPolygon(p19, 4);
	POLYGONS[22]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[11] = new Renderer(POLYGONS[22], *shaderArray[4], *shaderArray[1]);

	// MOUTH:  22 start!

	float CTRL20A[4][2] = { {  -34.2, -0.9 }, { -34.1, -18.1 }, { -5.8, -16.5 }, { -4.3, 0.7 } };
	float CTRL20B[4][2] = { { -4.3, 0.7 }, { -5.9, 11.7 }, { -15.2, 20.0 }, { -23.9, 14.1} };
	float CTRL20C[4][2] = { { -23.9, 14.1 }, { -27.6, 12.6 }, { -35.6, 6.7 }, { -34.2, -0.9 } };

	PolygonElement* p20[3] = { new CubicBezierCurve(CTRL20A), new CubicBezierCurve(CTRL20B), new CubicBezierCurve(CTRL20C) };
	POLYGONS[23] = new IrregularPolygon(p20, 3);
	POLYGONS[23]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[22] = new Renderer(POLYGONS[23], *shaderArray[6], *shaderArray[1]);


	// EAR: 

	float CTRL21[4][2] = { { 39.3, 9.3 }, { 70.9, 32.75 }, { 70.2, -34.3 }, { 38.7, -3.6 } };

	PolygonElement* p21[1] = { new CubicBezierCurve(CTRL21) };
	POLYGONS[24] = new IrregularPolygon(p21, 1);
	POLYGONS[24]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[23] = new Renderer(POLYGONS[24], *shaderArray[0], *shaderArray[1]);


	// SKIN STRIP: RENDER AT LAST

	std::vector<std::vector<float>> ST22 = { { 39.3, 9.3,  0 }, {  38.7, -3.6 , 0} };

	PolygonElement* p22[1] = { new StraightLine(ST22[0], ST22[1]) };
	POLYGONS[25] = new IrregularPolygon(p22, 1);
	POLYGONS[25]->normalizeControlPoints(maxX, maxY, minX, minY);

	bodyPartRenderers[24] = new Renderer(POLYGONS[25], *shaderArray[0], *shaderArray[0]);


	// EYE1:

	float ST23[3] = { -6.0, 33.0,  0 };
	//float ST23[3] = { 0.0, 0.0,  0 };
	POLYGONS[30] = new RegularPolygon(ST23, 10.0, 500);
	POLYGONS[30]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[25] = new Renderer(POLYGONS[30], *shaderArray[1], *shaderArray[1]);


	// EYE1B:


	float ST24[3] = { -5.8, 33.0,  0 };
	POLYGONS[31] = new RegularPolygon(ST24, 4.3, 500);
	POLYGONS[31]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[26] = new Renderer(POLYGONS[31], *shaderArray[5], *shaderArray[5]);


	// EYE2:


	float ST25[3] = { 19.0, 23.0,  0 };
	POLYGONS[32] = new RegularPolygon(ST25, 10.0, 500);
	POLYGONS[32]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[27] = new Renderer(POLYGONS[32], *shaderArray[1], *shaderArray[1]);


	// EYE2B:


	float ST26[3] = { 19.0, 23.0,  0 };
	POLYGONS[33] = new RegularPolygon(ST26, 4.0, 500);
	POLYGONS[33]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[28] = new Renderer(POLYGONS[33], *shaderArray[5], *shaderArray[5]);


	// BROW1:

	float CTRL27[4][2] = { { 32.2, 27.6 }, { 30.1, 39.9 }, { 17.3, 40.2 }, { 12.06, 32.2 } };

	PolygonElement* p27[1] = { new CubicBezierCurve(CTRL27) };
	POLYGONS[26] = new IrregularPolygon(p27, 1);
	POLYGONS[26]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[29] = new Renderer(POLYGONS[26], *shaderArray[1], *shaderArray[1]);


	// BROW2:


	float CTRL28[4][2] = { { 5.9, 36.86 }, { 4.6, 46.55 }, { -8.1, 51.87 }, { -16.7, 41.75 } };

	PolygonElement* p28[1] = { new CubicBezierCurve(CTRL28) };
	POLYGONS[27] = new IrregularPolygon(p28, 1);
	POLYGONS[27]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[30] = new Renderer(POLYGONS[27], *shaderArray[1], *shaderArray[1]);


	// THICK  BROW 1:


	float CTRL29[4][2] = { { -15.9, 54.66 }, { -18.4, 51.14 }, { -14.9, 49.8 }, { -13.1, 50.3 } };
	float CTRL30[4][2] = { { -13.1, 50.3 },  { -2.55, 52.2 }, { -1.55, 60.3 }, { 8.05, 47.4 } };
	float CTRL31[4][2] = { { 8.05, 47.4 }, { 9.77, 43.38 }, { 14.45, 45.66 }, { 12.94, 49.34 } };
	float CTRL32[4][2] = { { 12.94, 49.34 }, { 3.56, 63.14 }, { 6.05, 64.7 }, { -15.9, 54.66 } };

	PolygonElement* p29[4] = { new CubicBezierCurve(CTRL29), new CubicBezierCurve(CTRL30), new CubicBezierCurve(CTRL31), new CubicBezierCurve(CTRL32) };
	POLYGONS[28] = new IrregularPolygon(p29, 4);
	POLYGONS[28]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[31] = new Renderer(POLYGONS[28], *shaderArray[1], *shaderArray[1]);


	// THICK BROW 2:

	float CTRL33[4][2] = { { 18.36, 46.2 }, { 15.67, 44.26 }, { 16.8, 42.0 }, { 20.05, 42.2 } };
	float CTRL34[4][2] = { { 20.05, 42.2 }, { 34.2, 48.2 }, { 30.82, 42.67 }, { 35.8, 33.9 } };
	float CTRL35[4][2] = { { 35.8, 33.9 }, { 36.57, 30.66 }, { 41.5, 30.1 }, { 41.2, 35.0 } };
	float CTRL36[4][2] = { { 41.2, 35.0 }, { 37.1, 54.6 }, { 39.8, 57.9 }, { 18.36, 46.2 } };

	PolygonElement* p30[4] = { new CubicBezierCurve(CTRL33), new CubicBezierCurve(CTRL34), new CubicBezierCurve(CTRL35), new CubicBezierCurve(CTRL36) };
	POLYGONS[29] = new IrregularPolygon(p30, 4);
	POLYGONS[29]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[32] = new Renderer(POLYGONS[29], *shaderArray[1], *shaderArray[1]);

	float CTRL100[4][2] = { { -13.1, 50.3 },  { -2.55, 52.2 }, { -1.55, 60.3 }, { 8.05, 47.4 } };
	std::vector<std::vector<float>> ST100 = { {8.05, 47.4, 0},  { -13.1, 50.3,  0 } };

	PolygonElement* p100[2] = { new CubicBezierCurve(CTRL100), new StraightLine(ST100[0], ST100[1])};
	POLYGONS[100] = new IrregularPolygon(p100, 2);
	POLYGONS[100]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[37] = new Renderer(POLYGONS[100], *shaderArray[0], *shaderArray[1]);


	float CTRL101[4][2] = { { 20.05, 42.2 }, { 34.2, 48.2 }, { 30.82, 42.67 }, { 35.8, 33.9 } };
	std::vector<std::vector<float>> ST101 = { {35.8, 33.9, 0},  { 20.05, 42.2,  0 } };

	PolygonElement* p101[2] = { new CubicBezierCurve(CTRL101), new StraightLine(ST101[0], ST101[1]) };
	POLYGONS[101] = new IrregularPolygon(p101, 2);
	POLYGONS[101]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[38] = new Renderer(POLYGONS[101], *shaderArray[0], *shaderArray[1]);


	return bodyPartRenderers;
}
