#pragma once
#include "Global.h"
#include "Object_Character.h"
#include "Objects.h"

class Scene_GamePlay:public Scene
{
	
private:
	Object_Character* m_Player = nullptr;
	std::vector<std::vector<Object*>> m_objects;  //알파 블랜딩 되는 오브젝트와의 레이어 구분
	float elapsedTime;

public:
	enum Layer {
		RGB = 0, RGBA, ADD_RGBA,
		SIZE
	};
	Scene_GamePlay();
	virtual ~Scene_GamePlay();

public:
	void InitialObejct();

	virtual void DrawScene();
	virtual void Update(float elapsedTime);

	

public:     /*    키 입력 함수    */
	virtual void KeyDownInput(unsigned char key, int x, int y);
	virtual void KeyUpInput(unsigned char key, int x, int y) ;
	virtual void SpecialKeyDownInput(int key, int x, int y) {};
	virtual void SpecialKeyUpInput(int key, int x, int y) {};
	virtual void MouseInput(int button, int state, int x, int y) {};
	virtual void PassiveMotionInput(int x, int y) {};
};

