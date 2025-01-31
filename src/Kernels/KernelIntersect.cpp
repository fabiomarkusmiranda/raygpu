#include "KernelIntersect.h"

KernelIntersect::KernelIntersect()
{

}

KernelIntersect::KernelIntersect(int width, int height, GLuint texIdRayPos, GLuint texIdRayDir,
                                 GLuint texIdShadowInfo, GLuint texIdGrid,
                                 GLuint texIdTriangleList, GLuint texIdvertexes, GLfloat gridTexSize, 
                                 GLfloat triangleListTexSize, GLfloat vertexesTexSize)
: KernelBase("./resources/vertice.vert", "./resources/intersector.frag", width, height){


	//Output
	addOutput(0, texIdRayDir);
  addOutput(1, texIdRayPos);
	m_texIdTriangleHitInfo = addOutput(2);
  GLuint aux = addOutput(3);

  GLint max_tex_size = 0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);

	//Input
	m_shader->setActive(true);
    addInputTexture(GL_TEXTURE_2D, "rayPos", texIdRayPos);
    addInputTexture(GL_TEXTURE_2D, "rayDir", texIdRayDir);
    addInputTexture(GL_TEXTURE_2D, "triangleInfoTex", m_texIdTriangleHitInfo);
    addInputTexture(GL_TEXTURE_2D, "shadowInfoTex", texIdShadowInfo);
    addInputTexture(GL_TEXTURE_2D, "grid", texIdGrid);
    addInputTexture(GL_TEXTURE_2D, "vertexes", texIdvertexes);
    //addInputTexture(GL_TEXTURE_1D, "vertexes", texIdvertexes);
    addInputTexture(GL_TEXTURE_2D, "triangleList", texIdTriangleList);

    addInputFloat("maxTextureSize", max_tex_size);
    addInputFloat("gridSize", gridTexSize);
    addInputFloat("triangleListSize", triangleListTexSize);
    addInputFloat("vertexesSize", vertexesTexSize);
	m_shader->setActive(false);
}

KernelIntersect::~KernelIntersect(){

}

GLuint KernelIntersect::getTexIdTriangleHitInfo() const 
{
	return m_texIdTriangleHitInfo; 
}