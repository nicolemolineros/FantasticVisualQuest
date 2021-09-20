#include "Obj3D.h"

Obj3D::Obj3D() {
    objmodel_ptr = NULL;
}

void Obj3D::AbrirMalla(char *malla) {
    

    if (!objmodel_ptr)
    {
        objmodel_ptr = glmReadOBJ(malla);
        if (!objmodel_ptr)
            exit(0);

        glmUnitize(objmodel_ptr);
        glmFacetNormals(objmodel_ptr);
        glmVertexNormals(objmodel_ptr, 90.0);
    }
}
void Obj3D::DibujarMalla(float x, float y, float z) {
    glPushMatrix();
        glTranslatef(x, y, z);
        glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}