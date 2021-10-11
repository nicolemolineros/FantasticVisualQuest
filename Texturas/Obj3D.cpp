#include "Obj3D.h"
#include <FreeImage.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
GLuint texid;

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

void Obj3D::initialize_textures(char *src) {
    int w, h;
    GLubyte* data = 0;
    //data = glmReadPPM("soccer_ball_diffuse.ppm", &w, &h);
    //std::cout << "Read soccer_ball_diffuse.ppm, width = " << w << ", height = " << h << std::endl;

    //dib1 = loadImage("soccer_ball_diffuse.jpg"); //FreeImage

    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Loading JPG file
    //./Mallas/luna301.jpg
    FIBITMAP* bitmap = FreeImage_Load(
        FreeImage_GetFileType(src, 0),
        src);  //*** Para Textura: esta es la ruta en donde se encuentra la textura

    FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
    int nWidth = FreeImage_GetWidth(pImage);
    int nHeight = FreeImage_GetHeight(pImage);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
        0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

    FreeImage_Unload(pImage);
    //
    glEnable(GL_TEXTURE_2D);
}