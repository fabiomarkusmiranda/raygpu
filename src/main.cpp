#include "application.h"
#include "Manager/Manager.h"
#include <iostream>


int main(int argc,char *argv[])
{
//   Manager appManager(argc,argv,1280,800,"GPURayTracer",Color(.8 ,.8,.8),true); //FullScreen
//   Manager appManager(argc,argv,1680,1050,"GPURayTracer",Color(.8 ,.8,.8)); //NormalScreen 16x10
//   Manager appManager(argc,argv,1280,800,"GPURayTracer",Color(.8 ,.8,.8)); //NormalScreen 16x10
//   Manager appManager(argc,argv,1200,675,"GPURayTracer",Color(.8 ,.8,.8)); //NormalScreen 16x9
   Manager appManager(argc, argv, 800, 800, "GPURayTracer", Color(.8, .8, .8)); //NormalScreen 4x3
//   Manager appManager(argc,argv,WIDTH,HEIGHT,"GPURayTracer",Color(.8 ,.8,.8)); //NormalScreen Other NOT
//   Manager appManager(argc,argv,"GPURayTracer",Color(.8 ,.8,.8)); //FullScreen


   printf("============Controles============\n");
   printf("  Up e Down: Contrast Factor \n");
   printf("\n");
   printf("=================================\n");


   appManager.applicationLoop();
   return 42;
}

