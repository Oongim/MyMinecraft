#include "Objects.h"

Object_BackGround::Object_BackGround()
{
	testTextureID.id = m_Renderer->GenPngTexture("./Resource/forest.png", testTextureID.width, testTextureID.height,GL_RGB);
	Mesh mesh;

	mesh.addVertex({ -1.f, -1.f , 0.5f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -1.f  , 1.f , 0.5f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ 1.f, 1.f , 0.5f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ 1.f , -1.f , 0.5f });
	mesh.addTexCoord({ 1.f,0.f });

	vertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);
}

Object_BackGround::~Object_BackGround()
{
}

void Object_BackGround::Draw()
{
	m_Renderer->drawTexture(vertexArray, size, testTextureID.id, {0,0,0}, { 0,0,0,1 });
}

void Object_BackGround::Update(float ElapsedTime)
{
}

/**********************************************************************************************************************************/

Object_Cloud::Object_Cloud()
{
	unsigned int s_width;
	unsigned int s_height;

	m_Renderer->getScreenSize(s_width, s_height);

	testTextureID.id = m_Renderer->GenPngTexture("./Resource/cloud.png", testTextureID.width, testTextureID.height);
	float wScale = static_cast<float>(testTextureID.width) / static_cast<float>(s_width);
	float hScale = static_cast<float>(testTextureID.height) / static_cast<float>(s_height);

	Mesh mesh;
	transform = { -0.55f, 0.f, 0.5f };
	mesh.addVertex({ -wScale + transform.x, -hScale + transform.y, transform.z });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale + transform.x , hScale + transform.y , transform.z });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale + transform.x, hScale + transform.y, transform.z });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale + transform.x, -hScale + transform.y, transform.z });
	mesh.addTexCoord({ 1.f,0.f });

	vertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);
}

Object_Cloud::~Object_Cloud()
{
}

void Object_Cloud::Draw()
{
	m_Renderer->drawTexture(vertexArray, size, testTextureID.id, { 0,0,0 }, { 0,0,0,0.8f });
}

void Object_Cloud::Update(float ElapsedTime)
{
}