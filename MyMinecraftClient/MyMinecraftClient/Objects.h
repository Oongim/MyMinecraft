#pragma once
#include "Global.h"

class Object_Basic :	public Object
{
private:
	TextureInfo TextureID{};

	glm::vec4 m_color;

	glm::vec3 m_pos = glm::vec3(1.0f);
	glm::mat4 m_rot = glm::mat4(1.0f);
	glm::vec3 m_scale = glm::vec3(1.f);

public:
	Object_Basic(const char* path, GLint mode, float depth, glm::vec4 color);
	virtual ~Object_Basic();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

public:
	void AddOffset(const glm::vec3& pos);

	void SetPosition(const glm::vec3& pos);
	glm::vec3 GetPosition() const;
	void Rotate(const float& degrees, const glm::vec3& axis);
	glm::mat4 GetRotation() const;
	void SetScale(const glm::vec3& scale);
	glm::vec3 GetScale() const;

};


