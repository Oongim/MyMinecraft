#include "Renderer.h"
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION    
#include "stb_image.h"

Renderer::Renderer()
{
	//Load shaders
	m_testShader = CompileShaders("./Shaders/vertex_color.vs", "./Shaders/vertex_color.fs");

	//stbi_set_flip_vertically_on_load(true);//ó���� �ؽ��� ����� �����µ� ����������
}

Renderer::~Renderer()
{
	glDeleteShader(m_testShader);

	delete this->instance();
}

void Renderer::drawTriangle(float* vertexArray, int v_size, glm::vec3 trans = { 0,0,0 })
{
	glGenBuffers(1, &m_VBORect);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray)* v_size, vertexArray, GL_STATIC_DRAW);
	
	glUseProgram(m_testShader);

	GLuint uTrans = glGetUniformLocation(m_testShader, "u_Trans");

	glUniform3f(uTrans, trans.x,trans.y,trans.z);

	int attribPosition = glGetAttribLocation(m_testShader, "pos");
	glEnableVertexAttribArray(attribPosition);
	int attribColor = glGetAttribLocation(m_testShader, "color");
	glEnableVertexAttribArray(attribColor);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glVertexAttribPointer(attribColor, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid*)(sizeof(float)*3));

	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	glDisableVertexAttribArray(0);
}
void Renderer::drawRectangle(float* vertexArray, int v_size, glm::vec3 trans = { 0,0,0 })
{
	glGenBuffers(1, &m_VBORect);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray) * v_size, vertexArray, GL_STATIC_DRAW);

	glUseProgram(m_testShader);

	GLuint uTrans = glGetUniformLocation(m_testShader, "u_Trans");

	glUniform3f(uTrans, trans.x, trans.y, trans.z);

	int attribPosition = glGetAttribLocation(m_testShader, "pos");
	glEnableVertexAttribArray(attribPosition);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	//glVertexAttribPointer(attribColor, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid*)(sizeof(float)*3));

	glDrawArrays(GL_QUADS, 0, 4);

	glDisableVertexAttribArray(0);
}

void Renderer::drawTexture(float* vertexArray, int v_size, GLuint textureID,glm::mat4 trans, glm::vec4 col,glm::vec2 size,glm::vec2 frame,bool isLeft)
{
	glGenBuffers(1, &m_VBORect);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray) * v_size, vertexArray, GL_STATIC_DRAW);

	glUseProgram(m_testShader);


	GLuint uTrans = glGetUniformLocation(m_testShader, "u_Transfrom");
	GLuint uCol = glGetUniformLocation(m_testShader, "u_Col");
	GLuint uTexture = glGetUniformLocation(m_testShader, "u_Texture");
	GLuint uSpriteSize = glGetUniformLocation(m_testShader, "u_SpriteSize");
	GLuint uSpriteOffset = glGetUniformLocation(m_testShader, "u_SpriteOffset");
	GLuint uIsLeft = glGetUniformLocation(m_testShader, "u_isLeft");
	

	glUniform2f(uSpriteSize, size.x, size.y);
	glUniform2f(uSpriteOffset, frame.x, frame.y);
	glUniformMatrix4fv(uTrans, 1,GL_FALSE,value_ptr(trans));
	glUniform4f(uCol, col.r, col.g, col.b, col.a);
	glUniform1i(uTexture, 0);
	glUniform1i(uIsLeft, isLeft);
	

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Textures[textureID]);

	int attribPosition = glGetAttribLocation(m_testShader, "pos");
	glEnableVertexAttribArray(attribPosition);
	int attribUV = glGetAttribLocation(m_testShader, "uv");
	glEnableVertexAttribArray(attribUV);

	unsigned attribSize = 3 + 2;

	glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * attribSize, 0);
	glVertexAttribPointer(attribUV, 2, GL_FLOAT, GL_FALSE, sizeof(float) * attribSize, (GLvoid*)(sizeof(float) * 3));

	glDrawArrays(GL_QUADS, 0, 4);

	glDisableVertexAttribArray(0);


}

void Renderer::setScreenSize(const unsigned int& width, const unsigned int& height)
{
	m_windowWidth = width;
	m_windowHeight = height;
}

void Renderer::getScreenSize(unsigned int& width, unsigned int& height)
{
	width = m_windowWidth;
	height = m_windowHeight;
}

int Renderer::GenPngTexture(const char* filePath, int& fileWidth, int& fileHeight,GLint loadFormat)
{
	int idx = m_Textures.size();

	GLuint temp;
	glGenTextures(1, &temp);
	glBindTexture(GL_TEXTURE_2D, temp);
	// �ؽ�ó wrapping/filtering �ɼ� ����(���� ���ε��� �ؽ�ó ��ü�� ����)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// �ؽ�ó �ε� �� ����
	int nrChannels;
	unsigned char* data = stbi_load(filePath, &fileWidth, &fileHeight, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, loadFormat, fileWidth, fileHeight, 0, loadFormat, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	m_Textures.emplace_back(temp);
	return idx;
}

bool Renderer::ReadFile(const char* filename, std::string* target)
{
	std::ifstream file(filename);
	if (file.fail())
	{
		std::cout << filename << " file loading failed.. \n";
		file.close();
		return false;
	}
	std::string line;
	while (getline(file, line)) {
		target->append(line.c_str());
		target->append("\n");
	}
	return true;
}
void Renderer::AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
	//���̴� ������Ʈ ����
	GLuint ShaderObj = glCreateShader(ShaderType);

	if (ShaderObj == 0) {
		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
	}

	const GLchar* p[1];
	p[0] = pShaderText;
	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);
	//���̴� �ڵ带 ���̴� ������Ʈ�� �Ҵ�
	glShaderSource(ShaderObj, 1, p, Lengths);

	//�Ҵ�� ���̴� �ڵ带 ������
	glCompileShader(ShaderObj);

	GLint success;
	// ShaderObj �� ���������� ������ �Ǿ����� Ȯ��
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];

		//OpenGL �� shader log �����͸� ������
		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
		printf("%s \n", pShaderText);
	}

	// ShaderProgram �� attach!!
	glAttachShader(ShaderProgram, ShaderObj);
}
GLuint Renderer::CompileShaders(const char* filenameVS,const char* filenameFS)
{
	GLuint ShaderProgram = glCreateProgram(); //�� ���̴� ���α׷� ����

	if (ShaderProgram == 0) { //���̴� ���α׷��� ����������� Ȯ��
		fprintf(stderr, "Error creating shader program\n");
		assert(0);
	}

	std::string vs, fs;

	//shader.vs �� vs ������ �ε���
	if (!ReadFile(filenameVS, &vs)) {
		printf("Error compiling vertex shader\n");
		assert(0);
		return -1;
	};

	//shader.fs �� fs ������ �ε���
	if (!ReadFile(filenameFS, &fs)) {
		printf("Error compiling fragment shader\n");
		assert(0);
		return -1;
	};

	// ShaderProgram �� vs.c_str() ���ؽ� ���̴��� �������� ����� attach��
	AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);

	// ShaderProgram �� fs.c_str() �����׸�Ʈ ���̴��� �������� ����� attach��
	AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	//Attach �Ϸ�� shaderProgram �� ��ŷ��
	glLinkProgram(ShaderProgram);

	//��ũ�� �����ߴ��� Ȯ��
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0) {
		// shader program �α׸� �޾ƿ�
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		std::cout << filenameVS << ", " << filenameFS << " Error linking shader program\n" << ErrorLog;
		assert(0);
		return -1;
	}

	glValidateProgram(ShaderProgram);
	glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
	if (!Success) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		std::cout << filenameVS << ", " << filenameFS << " Error validating shader program\n" << ErrorLog;
		assert(0);
		return -1;
	}

	glUseProgram(ShaderProgram);
	std::cout << filenameVS << ", " << filenameFS << " Shader compiling is done.\n";

	return ShaderProgram;
}
