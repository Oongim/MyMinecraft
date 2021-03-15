#pragma once
#include "Global.h"

class Object_BackGround :	public Object
{
private:
	TextureInfo BGTextureID{};

public:
	Object_BackGround();
	virtual ~Object_BackGround();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

};

class Object_Sun : public Object
{
private:
	glm::vec3 transform;
	TextureInfo testTextureID{};

public:
	Object_Sun();
	virtual ~Object_Sun();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

};

class Object_Cloud : public Object
{
private:
	glm::vec3 transform;
	TextureInfo testTextureID{};

public:
	Object_Cloud();
	virtual ~Object_Cloud();

public:
	virtual void Draw();
	virtual void Update(float ElapsedTime);

};

