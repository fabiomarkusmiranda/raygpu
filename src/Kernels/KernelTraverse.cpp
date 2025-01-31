#include "KernelTraverse.h"


KernelTraverse::KernelTraverse(){


}

KernelTraverse::KernelTraverse(int width, int height, Vector3 voxelSize, Vector3 bbMin, Vector3 bbMax, GLuint texIdGrid, int gridArraySize, Vector3 gridSize, GLuint texIdRayPos, GLuint texIdRayDir, GLuint texIdGridIntersectionMax)
: KernelBase("./resources/vertice.vert", "./resources/traverse.frag", width, height){

	//Output
	addOutput(0, texIdRayPos);
	addOutput(1, texIdRayDir);
	addOutput(2, texIdGridIntersectionMax);
	GLuint aux = addOutput(3);

  GLint max_tex_size = 0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);

	//Input
	m_shader->setActive(true);
		addInputTexture(GL_TEXTURE_2D, "samplerRayPos", texIdRayPos);
		addInputTexture(GL_TEXTURE_2D, "samplerRayDir", texIdRayDir);
		addInputTexture(GL_TEXTURE_2D, "samplerGridIntersectionMax", texIdGridIntersectionMax);
		addInputTexture(GL_TEXTURE_2D, "samplerGrid", texIdGrid);
		
    addInputFloat("maxTextureSize", max_tex_size);

    addInputVec3("bbMin", bbMin);
		addInputVec3("bbMax", bbMax);
		addInputVec3("gridVoxelSize", voxelSize);
		addInputVec3("gridSize", gridSize);
		addInputFloat("gridArraySize", (float)gridArraySize);
	m_shader->setActive(false);

}

KernelTraverse::~KernelTraverse(){

}

