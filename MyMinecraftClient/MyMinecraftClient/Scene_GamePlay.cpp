#include "Scene_GamePlay.h"


Scene_GamePlay::Scene_GamePlay()
{
	//Enable/Disable
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);

	//Rendering
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glFrontFace(GL_CCW);

	//Light
	//GLfloat lightPos[] = { 0.f, 0.f, 10.f, 0.f };
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	//glEnable(GL_COLOR_MATERIAL);

	//Modelview and projection
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.f, 1.f, -1.f, 1.f, -1.f, 1.f);
	glMatrixMode(GL_MODELVIEW);*/

	//initialize
	elapsedTime = 0;

	InitialObejct();
}

Scene_GamePlay::~Scene_GamePlay()
{
}

void Scene_GamePlay::InitialObejct()
{
	m_objects.reserve(2);
	m_Player = new Object_Character();
	m_objects.emplace_back(std::vector<Object*>{});
	m_objects.emplace_back(std::vector<Object*>{});
	m_objects.emplace_back(std::vector<Object*>{});

	m_objects[Layer::RGB].emplace_back(new Object_BackGround());
	m_objects[Layer::RGBA].emplace_back(new Object_Cloud());
	m_objects[Layer::ADD_RGBA].emplace_back(new Object_Sun());
}

void Scene_GamePlay::DrawScene()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	m_Player->Draw();

	for (int i = 0; i < Layer::SIZE; ++i) {
		for (auto object : m_objects[i]) {
			object->Draw();
		}
		if (i == RGB) {
			glDisable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}
		else if (i == RGBA)
			glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
	}
	glDisable(GL_BLEND);
}

void Scene_GamePlay::Update(float elapsedTime)
{
	m_Player->Update(elapsedTime);
	for (auto objectLayer : m_objects) {
		for (auto object : objectLayer) {
			object->Update(elapsedTime);
		}
	}
}

void Scene_GamePlay::KeyDownInput(unsigned char key, int x, int y)
{
	KeyInput temp = m_Player->GetKeyInput();
	if (key == 'w') {
		temp.W = true;
	}
	if (key == 's') {
		temp.S = true;
	}
	if (key == 'a') {
		temp.A = true;
	}
	if (key == 'd') {
		temp.D = true;
	}
	m_Player->SetKeyInput(temp);
}

void Scene_GamePlay::KeyUpInput(unsigned char key, int x, int y)
{
	KeyInput temp = m_Player->GetKeyInput();
	if (key == 'w') {
		temp.W = false;
	}
	if (key == 's') {
		temp.S = false;
	}
	if (key == 'a') {
		temp.A = false;
	}
	if (key == 'd') {
		temp.D = false;
	}
	m_Player->SetKeyInput(temp);
}