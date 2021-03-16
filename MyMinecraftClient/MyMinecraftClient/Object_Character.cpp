#include "Object_Character.h"

using namespace glm;

Object_Character::Object_Character()
{
	textureMode = GL_RGBA;
	CreateIdleTextureMesh();
	CreateMoveTextureMesh();

	m_pos =  vec3(0.1, -0.4f, 0);
	m_rot = rotate(m_rot, radians(0.f), vec3(1.f, 0.f, 0.f));
	m_scale = vec3(1.f, 1.f, 1.f);

	mat4 posMat4 = glm::mat4(1.0f);
	posMat4 = translate(posMat4, m_pos);
	transform = posMat4;

	m_isMoving = false;
	m_speed = 0.4f;
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

		frame = (frame > 10.f) ? 0.f : frame = frame + 0.2f;

		m_pos += m_velocity * m_speed* ElapsedTime;

		mat4 posMat4 = glm::mat4(1.0f);
		posMat4 = translate(posMat4, m_pos);
		transform = posMat4 * m_rot;
		transform = scale(transform, m_scale);

		m_isMoving = true;
	}
	else
		m_isMoving = false;
}
void Object_Character::AddOffset(const glm::vec3& pos)
{
	m_pos += pos;
}

void Object_Character::SetPosition(const glm::vec3& pos)
{
	m_pos = pos;
}

glm::vec3 Object_Character::GetPosition() const
{
	return m_pos;
}

void Object_Character::SetTransform(const glm::mat4& pos)
{
	transform = pos;
}
glm::mat4 Object_Character::GetTransform() const
{
	return transform;
}
void Object_Character::Rotate(const float& degrees, const glm::vec3& axis)
{
	m_rot = rotate(m_rot, radians(degrees), axis);
}
glm::mat4 Object_Character::GetRotation() const
{
	return m_rot;
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
	float wScale = static_cast<double>(MoveTextureID.width) / static_cast<double>(s_width) * 0.28;
	float hScale = static_cast<double>(MoveTextureID.height) / static_cast<double>(s_height) * 0.19;

	Mesh mesh;

	mesh.addVertex({ -wScale, -hScale, -1.f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale, hScale, -1.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale, hScale, -1.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale, -hScale, -1.f });
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

	mesh.addVertex({ -wScale, -hScale, -1.f });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -wScale , hScale , -1.f });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ wScale, hScale, -1.f });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ wScale, -hScale, -1.f });
	mesh.addTexCoord({ 1.f,0.f });

	idleVertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);
}
