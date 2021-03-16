#pragma once
#include <GL/glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glm/gtc/type_ptr.hpp>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

class Renderer
{
public: // 싱글톤 인스턴스
	static Renderer* instance() {
		static Renderer* instance = new Renderer();
		return instance;
	};

private:
	unsigned int m_windowWidth = 0;
	unsigned int m_windowHeight = 0;

	std::vector<GLuint> m_Textures;
	
	GLuint m_testShader = 0;
	GLuint m_VBORect = 0;

	Renderer();
	~Renderer();

public:
	void drawTriangle(float* vertexArray, int v_size, glm::vec3 trans);
	void drawRectangle(float* vertexArray, int v_size, glm::vec3 trans);
	void drawTexture(float* vertexArray, int v_size, GLuint textureID, glm::mat4 trans, glm::vec4 col,
		glm::vec2 size , glm::vec2 frame, bool isLeft=false);

public:
	void setScreenSize(const unsigned int& width, const unsigned int& height);
	void getScreenSize(unsigned int& width, unsigned int& height);
	int GenPngTexture(const char* filePath, int& fileWidth, int& fileHeight, GLint loadFormat = GL_RGBA);

public:	//파일 로드
	bool ReadFile(const char* filename, std::string* target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(const char* filenameVS, const char* filenameFS);

};

