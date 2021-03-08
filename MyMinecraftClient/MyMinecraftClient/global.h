#pragma once

#include <GL/glm/glm.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <assert.h> 

#include "Renderer.h"

class vector3f {
public:
	float m_x;
	float m_y;
	float m_z;

public:
	vector3f():m_x(0),m_y(0),m_z(0){}
	vector3f(float x,float y,float z): m_x(x),m_y(y),m_z(z){}
	~vector3f(){}

	void SetVector3(const float x,const float y,const float z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	vector3f operator+(const vector3f& other)
	{
		return vector3f(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
	}

	template<typename T>
	vector3f operator+(const T num)
	{
		return vector3f(m_x + num, m_y + num, m_z + num);
	}

	vector3f operator-(const vector3f& other)
	{
		return vector3f(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
	}

	template<typename T>
	vector3f operator-(const T num)
	{
		return vector3f(m_x - num, m_y - num, m_z - num);
	}

	vector3f operator*(const vector3f& other)
	{
		return vector3f(m_x * other.m_x, m_y * other.m_y, m_z * other.m_z);
	}

	template<typename T>
	vector3f operator*(const T num)
	{
		return vector3f(m_x * num, m_y * num, m_z * num);
	}

	vector3f operator/(const vector3f& other)
	{
		return vector3f(m_x / other.m_x, m_y / other.m_y, m_z / other.m_z);
	}

	template<typename T>
	vector3f operator/(const T num)
	{
		return vector3f(m_x / num, m_y / num, m_z / num);
	}
};

class Mesh {
private:
	std::vector<glm::vec3> m_vVertices;

public:
	Mesh() {};
	~Mesh() {};

public:
	void addVertex(const glm::vec3& vertex) { m_vVertices.emplace_back(vertex); }
	GLfloat* getVerticeArray() const
	{
		GLfloat* Vertices = new GLfloat[getVerticeSize()];
		int index = 0;

		for (const auto& vertex : m_vVertices)
		{
			Vertices[index++] = vertex.x;
			Vertices[index++] = vertex.y;
			Vertices[index++] = vertex.z;
		}

		return Vertices;
	}

	const GLint getVerticeSize() const
	{
		return m_vVertices.size() * 3;
	}
};

class Scene {
public:
	Renderer* m_Renderer = 0;

public:
	Scene() { m_Renderer = Renderer::instance(); };
	virtual ~Scene(){};

public:
	virtual void DrawScene() = 0;
	virtual void Update() = 0;

public:     /*    키 입력 함수    */
	virtual void KeyDownInput(unsigned char key, int x, int y) {};
	virtual void KeyUpInput(unsigned char key, int x, int y) {};
	virtual void SpecialKeyDownInput(int key, int x, int y) {};
	virtual void SpecialKeyUpInput(int key, int x, int y) {};
	virtual void MouseInput(int button, int state, int x, int y) {};
	virtual void PassiveMotionInput(int x, int y){};

};