#include "Object_Character.h"

Object_Character::Object_Character()
{
	unsigned int s_width;
	unsigned int s_height;

	m_Renderer->getScreenSize(s_width, s_height);

	transform = { 0.1,0,0 };

	testTextureID.id = m_Renderer->GenPngTexture("./Resource/alien.png", testTextureID.width, testTextureID.height);
	float wScale = static_cast<float>(testTextureID.width) / static_cast<float>(s_width);
	float hScale = static_cast<float>(testTextureID.height)/ static_cast<float>(s_height);

	Mesh mesh;

	mesh.addVertex({ -wScale+ transform.x, -hScale+ transform.y, -1.f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale+transform.x , hScale + transform.y , -1.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale+transform.x, hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale+transform.x, -hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,0.f });

	vertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);

	
}

Object_Character::~Object_Character()
{
}

void Object_Character::Draw()
{
	m_Renderer->drawTexture(vertexArray, size, testTextureID.id, transform, {0,0,0,1});
}

void Object_Character::Update(float ElapsedTime)
{
}

void Object_Character::SetPos(const glm::vec3& pos)
{
	transform = pos;
}

glm::vec3 Object_Character::GetPos() const
{
	return transform;
}
