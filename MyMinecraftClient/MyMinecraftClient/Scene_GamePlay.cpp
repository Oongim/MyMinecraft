#include "Scene_GamePlay.h"

Scene_GamePlay::Scene_GamePlay()
{
	//Enable/Disable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	//Rendering
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glFrontFace(GL_CCW);
	glColor3f(0.0f, 0.5f, 1.0f);

	//Light
	GLfloat lightPos[] = { 0.f, 0.f, 10.f, 0.f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_COLOR_MATERIAL);

	//Modelview and projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.f, 1.f, -1.f, 1.f, -1.f, 1.f);
	glMatrixMode(GL_MODELVIEW);

	//initialize
	transform = { 0,0,0 };

	float scale = 1.f;
	Mesh mesh;
	
	mesh.addVertex({ -1.f * scale, -1.f * scale, 0.f });
	mesh.addTexCoord({ 0.f,0.f});

	mesh.addVertex({ -1.f * scale , 1.f * scale , 0.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ 1.f * scale, 1.f * scale, 0.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ 1.f * scale, -1.f * scale, 0.f });
	mesh.addTexCoord({ 1.f,0.f });

	vertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD,size);

	testTextureID = m_Renderer->GenPngTexture("./Resource/parrot.png");
}

Scene_GamePlay::~Scene_GamePlay()
{
}

void Scene_GamePlay::DrawScene()
{
	m_Renderer->drawTexture(vertexArray, size, testTextureID,transform);
}

void Scene_GamePlay::Update()
{
}

void Scene_GamePlay::KeyDownInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		transform.x -= 0.1f;
		break;
	}
}
