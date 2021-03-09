#pragma once
#include "Global.h"

class Scene_GamePlay:public Scene
{
private:
	float* vertexArray;
	unsigned int size;
	glm::vec3 transform;
	GLuint testTextureID = 0;
	GLuint test2TextureID = 0;

public:
	Scene_GamePlay();
	virtual ~Scene_GamePlay();

public:
	virtual void DrawScene();
	virtual void Update();

public:     /*    키 입력 함수    */
	virtual void KeyDownInput(unsigned char key, int x, int y);
	virtual void KeyUpInput(unsigned char key, int x, int y) {};
	virtual void SpecialKeyDownInput(int key, int x, int y) {};
	virtual void SpecialKeyUpInput(int key, int x, int y) {};
	virtual void MouseInput(int button, int state, int x, int y) {};
	virtual void PassiveMotionInput(int x, int y) {};
};

