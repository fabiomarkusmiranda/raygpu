/**********************************************************\
            Nome:Eduardo Ceretta Dalla Favera
\**********************************************************/

#include <iostream>
#include <cmath>


#include "RayTracerObjects/RTLight.h"

using namespace std;

int RTLight :: lightNum = 0;
///////////////////
//~ RTLight
//////////////////
RTLight :: RTLight()
:mCalculed(false)
,mLightStruct(NULL)
{
   myRTLightNum = lightNum++;

   if(myRTLightNum >= Max_Lights)
      myRTLightNum = myRTLightNum%Max_Lights;
}

RTLight :: ~RTLight()
{
  if(mLightStruct)
    delete mLightStruct;
}

int RTLight :: getMyRTLightNumber() const
{
   return myRTLightNum;
}


void RTLight :: readFromStr(char buffer[])
{
  float type = (float)Point; 
  mSpotExponent = 0.0f;
  mSpotAngle = 180.0f;
  mSpotDir = Vector3(0,0,0);
  int r = sscanf( buffer, 
    "%f %f %f \
    %f %f %f \
    %f %f %f \
    %f \
    %f \
    %f \
    %f %f %f \n", 
      &mPos.x, &mPos.y, &mPos.z,

      &mDiffuse.r, &mDiffuse.g, &mDiffuse.b, 
      &mSpecular.r, &mSpecular.g, &mSpecular.b,
      &type,
      &mSpotExponent,
      &mSpotAngle,
      &mSpotDir.x, &mSpotDir.y, &mSpotDir.z);
   
  mDiffuse *= 1.0/255;
  mSpecular *= 1.0/255;
  mType = (LightType)(int) floor(type + .5);
  assert(r >= 9);
  //cout << "Light num, pos, Diffuse, Specular, Type, SpotExponent, SpotAngle, SpotDir:\n"<< myLightNum << endl << mPos  << mDiffuse << mSpecular <<endl << mType << endl << mSpotExponent << endl << mSpotAngle << endl << mSpotDir<<endl;
}

void RTLight :: configure()
{
   if(!mCalculed)
   {
      mPLight.setAmbientColor(mDiffuse*.2);
      mPLight.setDiffuseColor(mDiffuse);
      mPLight.setSpecularColor(mSpecular);
      mPLight.setPosition(mPos);

      

      mCalculed = true;
   }
   mPLight.configure();
}

void RTLight :: render()
{
   mPLight.render();
}

struct lightStruct * RTLight::getLightStruct()
{
  if(mLightStruct)
    return mLightStruct;

  mLightStruct = new lightStruct;
  mLightStruct->diffuse[0] = mDiffuse.r;
  mLightStruct->diffuse[1] = mDiffuse.g;
  mLightStruct->diffuse[2] = mDiffuse.b;
  mLightStruct->spotExponent = mSpotExponent;
  mLightStruct->specular[0] = mSpecular.r;
  mLightStruct->specular[1] = mSpecular.g;
  mLightStruct->specular[2] = mSpecular.b;
  mLightStruct->enabled = 1.0;
  mLightStruct->pos[0] = mPos.x;
  mLightStruct->pos[1] = mPos.y;
  mLightStruct->pos[2] = mPos.z;
  mLightStruct->type = (float)(int)mType;
  mLightStruct->spotDir[0] = mSpotDir.x;
  mLightStruct->spotDir[1] = mSpotDir.y;
  mLightStruct->spotDir[2] = mSpotDir.z;
  mLightStruct->spotAngle = DEG_TO_RAD(mSpotAngle);
  return mLightStruct;
}


