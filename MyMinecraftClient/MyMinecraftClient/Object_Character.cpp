#include "Object_Character.h"

Object_Character::Object_Character()
{
	textureMode = GL_RGBA;
	CreateIdleTextureMesh();
	CreateMoveTextureMesh();

	transform = { 0.1,0,0 };

	m_isMoving = false;
	m_speed = 0.4;
	m_velocity = { 0,0,0 };
}

Object_Character::~Object_Character()
{
}

void Object_Character::Draw()
{
	if(m_isMoving)
		m_Renderer->drawTexture(moveVertexArray, size, MoveTextureID.id, transform, { 0,0,0,1 }, { 0.28,0.19 }, { (int)frame % 3,(int)frame / 3 }, m_velocity.x<0.f);
	else
		m_Renderer->drawTexture(idleVertexArray, size, IdleTextureID.id, transform, { 0,0,0,1 }, { 1.f,1.f }, { 0,0 });
}

void Object_Character::Update(float ElapsedTime)
{
	m_velocity = { 0,0,0 };
	if (m_key.W == true) {
		m_velocity.y = 1.f;
	}
	if (m_key.S == true) {
		m_velocity.y = -1.f;
	}
	if (m_key.A == true) {
		m_velocity.x = -1.f;
	}
	if (m_key.D == true) {
		m_velocity.x = +1.f;
	}
	float velocity_Length = m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y + m_velocity.z * m_velocity.z;
	
	if (velocity_Length != 0.f) {
		m_velocity = m_velocity / sqrt(velocity_Length);

		Debug::DebugPrint(velocity_Length);
		std::cout << m_velocity.x << ", " << m_velocity.y << ", " << m_velocity.z << std::endl;
		frame = (frame > 10.f) ? 0.f : frame = frame + 0.2f;
		transform += m_velocity * m_speed * ElapsedTime;

		m_isMoving = true;
	}
	else
		m_isMoving = false;
}

void Object_Character::SetPos(const glm::vec3& pos)
{
	transform = pos;
}
glm::vec3 Object_Character::GetPos() const
{
	return transform;
}
void Object_Character::SetVelocity(const glm::vec3& vel)
{
	m_velocity = vel;
}
glm::vec3 Object_Character::GetVelocity() const
{
	return m_velocity;
}

void Object_Character::SetKeyInput(const KeyInput& key)
{
	m_key = key;
}

KeyInput Object_Character::GetKeyInput() const
{
	return m_key;
}

void Object_Character::CreateMoveTextureMesh()
{
	unsigned int s_width;
	unsigned int s_height;

	m_Renderer->getScreenSize(s_width, s_height);

	MoveTextureID.id = m_Renderer->GenPngTexture("./Resource/walk_sheet.png", MoveTextureID.width, MoveTextureID.height);
	float wScale = static_cast<float>(MoveTextureID.width) / static_cast<float>(s_width) * 0.28;
	float hScale = static_cast<float>(MoveTextureID.height) / static_cast<float>(s_height) * 0.19;

	Mesh mesh;

	mesh.addVertex({ -wScale + transform.x, -hScale + transform.y, -1.f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale + transform.x , hScale + transform.y , -1.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale + transform.x, hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale + transform.x, -hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,0.f });

	moveVertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);
}

void Object_Character::CreateIdleTextureMesh()
{
	unsigned int s_width;
	unsigned int s_height;

	m_Renderer->getScreenSize(s_width, s_height);

	IdleTextureID.id = m_Renderer->GenPngTexture("./Resource/alien.png", IdleTextureID.width, IdleTextureID.height);
	float wScale = static_cast<float>(IdleTextureID.width) / static_cast<float>(s_width);
	float hScale = static_cast<float>(IdleTextureID.height) / static_cast<float>(s_height);

	Mesh mesh;

	mesh.addVertex({ -wScale + transform.x, -hScale + transform.y, -1.f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale + transform.x , hScale + transform.y , -1.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale + transform.x, hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale + transform.x, -hScale + transform.y, -1.f });
	mesh.addTexCoord({ 1.f,0.f });

	idleVertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);
}
