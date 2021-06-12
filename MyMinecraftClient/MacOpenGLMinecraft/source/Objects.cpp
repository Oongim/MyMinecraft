#include "Objects.h"

using namespace glm;

Object_Basic::Object_Basic(const char* path, GLint mode,float depth,glm::vec4 color) :m_color(color)
{
	unsigned int s_width;
	unsigned int s_height;
	m_Renderer->getScreenSize(s_width, s_height);

	textureMode = mode;

	TextureID.id = m_Renderer->GenPngTexture(path, TextureID.width, TextureID.height, textureMode);
	float wScale = static_cast<float>(TextureID.width) / static_cast<float>(s_width);
	float hScale = static_cast<float>(TextureID.height) / static_cast<float>(s_height);
	
	Mesh mesh;

	mesh.addVertex({ -1.f* wScale, -1.f* hScale , depth });
	mesh.addTexCoord({ 0.f,0.f });

	mesh.addVertex({ -1.f * wScale , 1.f* hScale , depth });
	mesh.addTexCoord({ 0.f,1.f });

	mesh.addVertex({ 1.f * wScale, 1.f* hScale , depth });
	mesh.addTexCoord({ 1.f,1.f });

	mesh.addVertex({ 1.f * wScale , -1.f* hScale , depth });
	mesh.addTexCoord({ 1.f,0.f });

	vertexArray = mesh.getVerticeArray(MESH_VERTICE | MESH_TEXCOORD, size);

	m_pos = glm::vec3(0.1, 0, 0);
	m_rot = glm::rotate(m_rot, glm::radians(0.f), glm::vec3(1.f, 0.f, 0.f));
	m_scale = glm::vec3(1.f, 1.f, 1.f);
}

Object_Basic::~Object_Basic()
{
}

void Object_Basic::Draw()
{
	m_Renderer->drawTexture(vertexArray, size, TextureID.id, transform, m_color, { 1.f,1.f }, { 0,0 });
}

void Object_Basic::Update(float ElapsedTime)
{
	mat4 posMat4 = glm::mat4(1.0f);
	posMat4 = translate(posMat4, m_pos);
	transform = posMat4 * m_rot;
	transform = scale(transform, m_scale);
}

void Object_Basic::AddOffset(const glm::vec3& pos)
{
	m_pos += pos;
}

void Object_Basic::SetPosition(const glm::vec3& pos)
{
	m_pos = pos;
}

glm::vec3 Object_Basic::GetPosition() const
{
	return m_pos;
}

void Object_Basic::Rotate(const float& degrees, const glm::vec3& axis)
{
	m_rot = glm::rotate(m_rot, radians(degrees), axis);
}
glm::mat4 Object_Basic::GetRotation() const
{
	return m_rot;
}

void Object_Basic::SetScale(const glm::vec3& scale)
{
	m_scale = scale;
}

glm::vec3 Object_Basic::GetScale() const
{
	return m_scale;
}
