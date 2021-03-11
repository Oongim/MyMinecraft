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
	m_Player = new Object_Character();

	m_objects.emplace_back(new Object_BackGround());
	m_objects.emplace_back(new Object_Cloud());
}

void Scene_GamePlay::DrawScene()
{
	m_Player->Draw();
	for (auto object : m_objects) {
		object->Draw();
	}
}

void Scene_GamePlay::Update(float elapsedTime)
{
	m_Player->Update(elapsedTime);
	for (auto object : m_objects) {
		object->Update(elapsedTime);
	}
}

void Scene_GamePlay::KeyDownInput(unsigned char key, int x, int y)
{
	glm::vec3 temp = m_Player->GetPos();
	switch (key)
	{	
	case 'a':
		temp.x -= 0.1f;
		break;
	case 'd':
		temp.x += 0.1f;
		break;
	case 'w':
		temp.y += 0.1f;
		break;
	case 's':
		temp.y -= 0.1f;
		break;
	}
	m_Player->SetPos(temp);
}
