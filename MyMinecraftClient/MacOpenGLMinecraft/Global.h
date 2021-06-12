#pragma once
#pragma warning(disable:6386)
#define GL_SILENCE_DEPRECATION

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLUT/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Mesh.h"

struct TextureInfo {
	GLuint id;
	int width;
	int height;
};

struct KeyInput {
	bool W;
	bool S;
	bool A;
	bool D;
};

namespace Debug {
	template<typename T>
	void DebugPrint(T a) {
		std::cout << a << std::endl;
	}

	template<typename T>
	void DebugPrint(T a, T b) {
		std::cout << a << ", " << b << std::endl;
	}

}
