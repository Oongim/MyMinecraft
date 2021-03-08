#pragma once
#include <GL/glm/glm.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <string>

class Renderer
{
public: // �̱��� �ν��Ͻ�
	static Renderer* instance() {
		static Renderer* instance = new Renderer();
		return instance;
	};

private:
	unsigned int m_windowWidth = 0;
	unsigned int m_windowHeight = 0;
	
	GLuint m_testShader = 0;
	GLuint m_VBORect = 0;

	Renderer();
	~Renderer();

public:
	void drawTriangle(float* vertexBuffer, int v_size);

public:	//���� �ε�
	bool ReadFile(const char* filename, std::string* target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(const char* filenameVS, const char* filenameFS);

};

