#pragma once
#include <GL/glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glm/gtc/type_ptr.hpp>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

struct CameraData {
	glm::vec3 position;
	float rotation;
};

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

	CameraData m_camera{};

private:
	Renderer();
	~Renderer();

public:	//쉐이더 사용한 그리기 함수
	void drawTriangle(float* vertexArray, int v_size, glm::vec3 trans);
	void drawRectangle(float* vertexArray, int v_size, glm::vec3 trans);
	void drawTexture(float* vertexArray, int v_size, GLuint textureID, glm::mat4 trans, glm::vec4 col,
		glm::vec2 size , glm::vec2 frame, bool isLeft=false);

public:	//카메라 설정 함수들
	glm::mat4 getViewMatrix() const;
	void setCameraPosition(const glm::vec3 pos);
	glm::vec3 getCameraPosition() const;
	void setCameraDegree(const float degree);
	float getCameraDegree() const;
	void addCameraOffset(const glm::vec3 pos);
	void addCameraDegree(const float degree);

public:	//스크린사이즈 구하기, 텍스쳐 인덱스 생성
	void setScreenSize(const unsigned int& width, const unsigned int& height);
	void getScreenSize(unsigned int& width, unsigned int& height);
	int GenPngTexture(const char* filePath, int& fileWidth, int& fileHeight, GLint loadFormat = GL_RGBA);

public:	//파일 로드
	bool ReadFile(const char* filename, std::string* target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(const char* filenameVS, const char* filenameFS);

};

