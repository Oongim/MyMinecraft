#pragma once
#include "Global.h"

class Object_Character : public Object
{
private:
	glm::vec3 transform;
	TextureInfo IdleTextureID{};
	TextureInfo MoveTextureID{};
	float* idleVertexArray = nullptr;
	float* moveVertexArray = nullptr;

	float frame = 0;

	bool m_isMoving;
	float m_speed;
	glm::vec3 m_velocity;
	KeyInput m_key;

public:
	Object_Character();
	virtual ~Object_Character();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

public:
	void SetPos(const glm::vec3& pos);
	glm::vec3 GetPos() const;
	void SetVelocity(const glm::vec3& pos);
	glm::vec3 GetVelocity() const;
	void SetKeyInput(const KeyInput& key);
	KeyInput GetKeyInput() const;

	void CreateIdleTextureMesh();
	void CreateMoveTextureMesh();
};

