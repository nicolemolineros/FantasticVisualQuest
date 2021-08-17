#include "Arbol.h"

Arbol::Arbol(){}

void Arbol::DibujarArbol(float x, float y, float z, float angle, int ex, int ey, int ez){

	glPushMatrix();

	glTranslatef(x, y, z);
	glRotatef(angle, ex, ey, ez);
	
		glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(0.5, 20, 20);
				glutSolidCylinder(0.2, 1.0, 20, 20);
		glPopMatrix();
	glPopMatrix();
}
