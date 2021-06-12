//
//  Mesh.h
//  MacOpenGLMinecraft
//
//  Created by 강동균 on 2021/06/12.
//

#ifndef Mesh_h
#define Mesh_h
#include "Global.h"

#define MESH_VERTICE 0b001
#define MESH_COLOR 0b010
#define MESH_TEXCOORD 0b100

class Mesh {
private:
    std::vector<glm::vec3> m_vVertices;
    std::vector<glm::vec4> m_vColors;
    std::vector<glm::vec2> m_vTexCoord;

public:
    Mesh() {};
    ~Mesh() {};

public:
    void addVertex(const glm::vec3& vertex) { m_vVertices.emplace_back(vertex); }
    void addColor(const glm::vec4& color) { m_vColors.emplace_back(color); }
    void addTexCoord(const glm::vec2& texcoord) { m_vTexCoord.emplace_back(texcoord); }

    GLfloat* getVerticeArray(const unsigned int attribute,unsigned& _size) const
    {
        bool isAddVertice = false;
        bool isAddColor = false;
        bool isAddTexCoord = false;
        unsigned int size = 0;

        if (attribute & MESH_VERTICE) {
            size += getVerticeSize();
            isAddVertice = true;
        }
        if (attribute & MESH_COLOR) {
            size += getColorSize();
            isAddColor = true;
        }
        if (attribute & MESH_TEXCOORD) {
            size += getTexCoordSize();
            isAddTexCoord = true;
        }

        GLfloat* Vertices = new GLfloat[size];

        int index = 0;
        for (unsigned int i = 0; i < m_vVertices.size(); ++i)
        {
            if (isAddVertice) {
                Vertices[index++] = m_vVertices[i].x;
                Vertices[index++] = m_vVertices[i].y;
                Vertices[index++] = m_vVertices[i].z;
            }
            if (isAddColor) {
                Vertices[index++] = m_vColors[i].r;
                Vertices[index++] = m_vColors[i].g;
                Vertices[index++] = m_vColors[i].b;
                Vertices[index++] = m_vColors[i].a;
            }
            if (isAddTexCoord) {
                Vertices[index++] = m_vTexCoord[i].x;
                Vertices[index++] = m_vTexCoord[i].y;
                //std::cout << m_vTexCoord[i].x << ", " << m_vTexCoord[i].y << std::endl;
            }
        }

        _size = size;
        return Vertices;
    }

    const GLint getVerticeSize() const
    {
        return m_vVertices.size() * 3;
    }
    const GLint getColorSize() const
    {
        return  m_vColors.size() * 4;
    }
    const GLint getTexCoordSize() const
    {
        return m_vTexCoord.size() * 2;
    }

};


#endif /* Mesh_h */
