#pragma once
#include "Global.h"
#include "Scene_GamePlay.h"

class SceneManager
{
private:
	Renderer* m_Renderer;
	Scene* m_CurrentScene;

public:
	SceneManager(unsigned int screenWidth,unsigned int screenHeight);
	~SceneManager();

public:
	void Update(float ElapsedTime);
	void DrawScene();

public:     /*    키 입력 함수    */
	void KeyDownInput(unsigned char key, int x, int y);
	void KeyUpInput(unsigned char key, int x, int y);
	void SpecialKeyDownInput(int key, int x, int y);
	void SpecialKeyUpInput(int key, int x, int y);
	void MouseInput(int button, int state, int x, int y);
	void PassiveMotionInput(int x, int y);

};

