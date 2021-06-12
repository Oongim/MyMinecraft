//
//  Interface.h
//  MacOpenGLMinecraft
//
//  Created by 강동균 on 2021/06/12.
//
#pragma once
#include "Global.h"
#include "Renderer.h"

class Scene {
public:
    Renderer* m_Renderer = 0;

public:
    Scene() { m_Renderer = Renderer::instance(); };
    virtual ~Scene(){};

public:
    virtual void DrawScene() = 0;
    virtual void Update(float ElapsedTime) = 0;

public:     /*    ≈∞ ¿‘∑¬ «‘ºˆ    */
    virtual void KeyDownInput(unsigned char key, int x, int y) {};
    virtual void KeyUpInput(unsigned char key, int x, int y) {};
    virtual void SpecialKeyDownInput(int key, int x, int y) {};
    virtual void SpecialKeyUpInput(int key, int x, int y) {};
    virtual void MouseInput(int button, int state, int x, int y) {};
    virtual void PassiveMotionInput(int x, int y){};

};

class Object {
public:
    Renderer* m_Renderer = 0;
    float* vertexArray = nullptr;
    unsigned int size = 0;

    unsigned long textureMode = 0;

    glm::mat4 transform= glm::mat4(1.0f);

public:
    Object(){ m_Renderer = Renderer::instance(); };
    virtual ~Object() { delete vertexArray; };

public:
    virtual void Draw() = 0;
    virtual void Update(float ElapsedTime) = 0;

public:
    void SetTransform(const glm::mat4& trans) {transform = trans;};
    glm::mat4 GetTransform() const {return transform;};

};

