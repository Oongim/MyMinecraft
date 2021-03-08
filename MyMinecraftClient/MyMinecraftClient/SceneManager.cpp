#include "SceneManager.h"

SceneManager::SceneManager()
{
	// Initialize
	m_Renderer = Renderer::instance();

	m_CurrentScene = new Scene_GamePlay();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update(float ElapsedTime)
{
	m_CurrentScene->Update();
}

void SceneManager::DrawScene()
{
	m_CurrentScene->DrawScene();
}

void SceneManager::KeyDownInput(unsigned char key, int x, int y)
{
	m_CurrentScene->KeyDownInput(key, x, y);
}

void SceneManager::KeyUpInput(unsigned char key, int x, int y)
{
	m_CurrentScene->KeyUpInput(key, x, y);
}

void SceneManager::SpecialKeyDownInput(int key, int x, int y)
{
	m_CurrentScene->SpecialKeyDownInput(key, x, y);
}

void SceneManager::SpecialKeyUpInput(int key, int x, int y)
{
	m_CurrentScene->SpecialKeyUpInput(key, x, y);
}

void SceneManager::MouseInput(int button, int state, int x, int y)
{
	m_CurrentScene->MouseInput(button, state, x, y);
}

void SceneManager::PassiveMotionInput(int x, int y)
{
	m_CurrentScene->PassiveMotionInput(x, y);
}
