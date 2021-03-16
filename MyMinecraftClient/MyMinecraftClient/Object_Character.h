#pragma once
#include "Global.h"

class Object_Character : public Object
{
private:
	TextureInfo IdleTextureID{};
	TextureInfo MoveTextureID{};
	float* idleVertexArray = nullptr;
	float* moveVertexArray = nullptr;

	float frame = 0;

	bool m_isMoving;
	float m_speed;
	glm::vec3 m_velocity;
	KeyInput m_key;

	glm::vec3 m_pos = glm::vec3(0.0f);
	glm::mat4 m_rot = glm::mat4(1.0f);
	glm::vec3 m_scale = glm::vec3(1.f);

public:
	Object_Character();
	virtual ~Object_Character();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

public:
	void AddOffset(const glm::vec3& pos);

	void SetPosition(const glm::vec3& pos);
	glm::vec3 GetPosition() const;
	void SetTransform(const glm::mat4& trans);
	glm::mat4 GetTransform() const;
	void Rotate(const float& degrees,const glm::vec3& axis);
	glm::mat4 GetRotation() const;

	void SetVelocity(const glm::vec3& pos);
	glm::vec3 GetVelocity() const;

	void SetKeyInput(const KeyInput& key);
	KeyInput GetKeyInput() const;

	void CreateIdleTextureMesh();
	void CreateMoveTextureMesh();
};

