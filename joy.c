#ifndef WIN32
#include <GL/glut.h>
#define GAMBI_INIT() glutInit(&argc, argv)
#elif
#define GAMBI_INIT() ;;
#include <gl/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SQRT3 sqrt(3);

void SetupRC(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void RenderScene(void)
{
	 	
     glutSwapBuffers();

}

void JoystickFunc(unsigned int mask, int x, int y, int z)
{
		
		printf("recebi %5d,%5d,%5d\nmask: %i\n",x,y,z,mask );
}

int main(int argc, char **argv)
{
    GAMBI_INIT();

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("JOY OH JOY");
    glutDisplayFunc(RenderScene);
    glutJoystickFunc(JoystickFunc,100);
    SetupRC();
    glutMainLoop();
		
		
    return 0;
}

