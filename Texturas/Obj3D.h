#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glsl.h"
#include "glm/glm.h"

#pragma once
class Obj3D
{
	GLMmodel* objmodel_ptr;

	public:
		Obj3D();
		void AbrirMalla(char *malla);
		void DibujarMalla(float x, float y, float z);
		void initialize_textures(char *src);

};

