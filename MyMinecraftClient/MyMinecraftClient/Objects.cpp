#include "Objects.h"

Object_BackGround::Object_BackGround()
{
	textureMode = GL_RGB;
	BGTextureID.id = m_Renderer->GenPngTexture("./Resource/forest.png", BGTextureID.width, BGTextureID.height, textureMode);
	
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
	m_Renderer->drawTexture(vertexArray, size, BGTextureID.id, { 0,0,0 }, { 0,0,0,1 }, { 1.f,1.f }, { 0,0 });
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
	textureMode = GL_RGBA;
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
	m_Renderer->drawTexture(vertexArray, size, testTextureID.id, { 0,0,0 }, { 0,0,0,0.8f }, { 1.f,1.f }, { 0,0 });
}

void Object_Cloud::Update(float ElapsedTime)
{
}

/**********************************************************************************************************************************/

Object_Sun::Object_Sun()
{
	textureMode = GL_RGBA;
	testTextureID.id = m_Renderer->GenPngTexture("./Resource/sun.png", testTextureID.width, testTextureID.height, textureMode);

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

Object_Sun::~Object_Sun()
{
}

void Object_Sun::Draw()
{
	m_Renderer->drawTexture(vertexArray, size, testTextureID.id, { 0,0,0 }, { 0,0,0,0.8f }, { 1.f,1.f }, {0,0});
}

void Object_Sun::Update(float ElapsedTime)
{
}