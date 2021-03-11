#pragma once
#include "Global.h"

class Object_Character : public Object
{
private:
	glm::vec3 transform;
	TextureInfo testTextureID{};

public:
	Object_Character();
	virtual ~Object_Character();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

public:
	void SetPos(const glm::vec3& pos);
	glm::vec3 GetPos() const;
};

