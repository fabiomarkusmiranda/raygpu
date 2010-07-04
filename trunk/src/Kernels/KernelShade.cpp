#include "KernelShade.h"

KernelShade::KernelShade()
{

}

KernelShade::KernelShade(int width, int height, GLuint texIdRayDir, GLuint texIdTriangleHitInfo, GLuint texIdvertexes, GLuint texIdNormals, 
                          GLuint texIdDiffuseTex, GLuint texIdSpecularTex, GLuint texIdLights, 
                          GLfloat normalsTexSize, GLfloat vertexesTexSize, GLfloat diffuseTexSize, GLfloat specularTexSize,
                          GLfloat lightsTexSize)
: KernelBase("./resources/vertice.vert", "./resources/shade.frag", width, height){
      //Output
      addOutput(0, texIdRayDir);    
      m_texIdColor = addOutput(1);
      GLuint aux = addOutput(2);
      GLuint aux2 = addOutput(3);

      GLint max_tex_size = 0;
      glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);

      //Input
      m_shader->setActive(true);
        addInputTexture(GL_TEXTURE_2D, "rayDir", texIdRayDir);  
        addInputTexture(GL_TEXTURE_2D, "triangleInfo", texIdTriangleHitInfo);
        addInputTexture(GL_TEXTURE_2D, "vertexes", texIdvertexes);
        addInputTexture(GL_TEXTURE_2D, "normals", texIdNormals);
        addInputTexture(GL_TEXTURE_2D, "diffuseTex", texIdDiffuseTex);
        addInputTexture(GL_TEXTURE_2D, "especularTex", texIdSpecularTex);
        addInputTexture(GL_TEXTURE_1D, "lights", texIdLights);

        addInputFloat("vertexesSize", vertexesTexSize);
        addInputFloat("maxTextureSize", max_tex_size);
        addInputFloat("normalsSize", normalsTexSize);
        addInputFloat("diffuseSize", diffuseTexSize);
        addInputFloat("especularSize", specularTexSize);
        addInputFloat("lightsSize", lightsTexSize);
        m_locEyePos = addInputVec3("eyePos", Vector3(0, 0, 0));
      m_shader->setActive(false);
}

KernelShade::~KernelShade(){

}

void KernelShade::step(Vector3 eyePos){

  m_fbo->setActive(true);
  m_shader->setActive(true);
  activateTextures();
    glUniform3f(m_locEyePos, eyePos.x, eyePos.y, eyePos.z);
    renderQuad();
  m_shader->setActive(false);
  m_fbo->setActive(false);
}

GLuint KernelShade::getTextureColorId(){
	return m_texIdColor;
}