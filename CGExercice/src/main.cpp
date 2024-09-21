#include "GpuLayer/GpuLayer.h"
#include <GLFW/glfw3.h>
#include <algorithm>
#include <iostream>


#define RGBA_COLOR(r, g, b, a) ((r) | (g << 8) | (b << 16) | (a << 24))


int WindowWidth = 800;
int WindowHeight = 600;

FrameBuffer* framebuffer = nullptr;
uint32_t* pixels = nullptr;

void OnResize(GLFWwindow* window, int width, int height);

void DrawCircle(uint32_t* pixels, int &cx, int &cy, int &r, uint32_t &color)
{
	float half_raduis = 0.5f * r;
	float topleft_x = cx - half_raduis;
	float topleft_y = cy - half_raduis;

	float bottomright_x = cx + half_raduis;
	float bottomright_y = cy + half_raduis;

	for (int py = topleft_y; py < bottomright_y; py++)
	{
		for (int px = topleft_x; px < bottomright_x; px++)
		{
			float x = px - cx;
			float y = py - cy;
			float dist = sqrtf(x * x + y * y);

			if (dist <= half_raduis)
				if (px > 0 && py > 0 && px < WindowWidth && py < WindowHeight)
					pixels[py * WindowWidth + px] = color;
		}
	}
}
// struct Vertex
// {
// 	Vertex() = default;
// 	Vertex(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
// 	float x, y, z, w = 0.0f;
// };

// // Function to compute barycentric coordinates
// void BarycentricCoordinates(Vertex v0, Vertex v1, Vertex v2, float x, float y, float& alpha, float& beta, float& gamma)
// {
// 	float detT = (v1.y - v2.y) * (v0.x - v2.x) + (v2.x - v1.x) * (v0.y - v2.y);
// 	alpha = ((v1.y - v2.y) * (x - v2.x) + (v2.x - v1.x) * (y - v2.y)) / detT;
// 	beta = ((v2.y - v0.y) * (x - v2.x) + (v0.x - v2.x) * (y - v2.y)) / detT;
// 	gamma = 1.0f - alpha - beta;
// }

// Function to rasterize a filled triangle using barycentric coordinates
// void DrawTriangle(uint32_t* pixels, Vertex v0, Vertex v1, Vertex v2, uint32_t color)
// {
// 	// Bounding box of the triangle
// 	int minX = std::max(0, (int)ceil(std::min(v0.x, std::min(v1.x, v2.x))));
// 	int maxX = std::min(WindowWidth - 1, (int)floor(std::max(v0.x, std::max(v1.x, v2.x))));
// 	int minY = std::max(0, (int)ceil(std::min(v0.y, std::min(v1.y, v2.y))));
// 	int maxY = std::min(WindowHeight - 1, (int)floor(std::max(v0.y, std::max(v1.y, v2.y))));

// 	for (int y = minY; y <= maxY; ++y)
// 	{
// 		for (int x = minX; x <= maxX; ++x)
// 		{
// 			float alpha, beta, gamma;
// 			BarycentricCoordinates(v0, v1, v2, x + 0.5f, y + 0.5f, alpha, beta, gamma);

// 			if (alpha >= 0.0f && beta >= 0.0f && gamma >= 0.0f)
// 			{
// 				/*
// 				// Check depth to perform depth test
// 				// Interpolate depth
// 				float depth = alpha * v0.z + beta * v1.z + gamma * v2.z;
// 				if (depth < framebuffer.depthBuffer[y * framebuffer.width + x]) {
// 					// Interpolate color
// 					Color color;
// 					color.r = (int)(alpha * v0.color.r + beta * v1.color.r + gamma * v2.color.r);
// 					color.g = (int)(alpha * v0.color.g + beta * v1.color.g + gamma * v2.color.g);
// 					color.b = (int)(alpha * v0.color.b + beta * v1.color.b + gamma * v2.color.b);

// 					// Write to framebuffer
// 					framebuffer.SetPixel(x, y, depth, color);
// 				}
// 				*/

// 				// Write to framebuffer
// 				pixels[y * WindowWidth + x] = color;
// 			}
// 		}
// 	}
// }

void drawRectangle(uint32_t* pixels, float &ox, float &oy, float &length, float &height, int &color){
	for(int i=ox; i < ox+length; i++){
		for(int j = oy; j < oy+height; j++){
			pixels[j*WindowWidth + i] = color;
		}
	}
}

bool mouseOnRectangle(double mx, double &my, float &ox, float &oy, float &length, float &height){
	bool result= false;
	if (mx <= ox+length && mx >= ox && my <= oy+height && my >= oy){
		result = true;
	}else{
		result = false;
	}

	return result;
}


int main()
{
	if (!glfwInit())
	{
		std::cout << "failed to init glfw\n";
		return 0;
	}

	GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, "CG", nullptr, nullptr);

	glfwSetWindowSizeCallback(window, OnResize);
	GpuLayer::Init(window);

	framebuffer = new FrameBuffer(WindowWidth, WindowHeight);
	pixels = new uint32_t[WindowWidth * WindowHeight];


	// rectangle attributes
	float x=0;
	float y=0;
	float length=100;
	float height=100;
	float speedx=0.5;
	float speedy=0.5;
	int color =  RGBA_COLOR(255,0,0,0);

	// mouse attributes
	double mx{} , my{};

	while (!glfwWindowShouldClose(window))
	{
		// events
		glfwPollEvents();
		// clear screen
		std::fill(pixels, pixels + WindowWidth * WindowHeight, RGBA_COLOR(0, 0, 0, 0));

		drawRectangle(pixels, x,y,length,height,color);
	
		glfwGetCursorPos(window, &mx, &my);

		if(mouseOnRectangle(mx,my,x,y,length,height)){
			
			// if left mouse click is pressed when cursor is on the rectangle, close the app
			if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
				glfwSetWindowShouldClose(window,true);
			}
			color = RGBA_COLOR(0,255,0,0);
		}else{
			color = RGBA_COLOR(255,0,0,0);
		}

		if(y == 0){
			speedy=0.5;

		}else if (y+height > WindowHeight-1){
			speedy=-0.5;
		}

		if(x == 0){
			speedx=0.5;

		}else if (x+length > WindowWidth-1){
			speedx=-0.5;
		}
		x+= speedx;
		y+= speedy;


		framebuffer->Present(pixels);
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}


void OnResize(GLFWwindow* window, int width, int height)
{
	WindowWidth = width;
	WindowHeight = height;

	framebuffer->Resize(width, height);
	delete[] pixels;
	pixels = new uint32_t[WindowWidth * WindowHeight];
}
