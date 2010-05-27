#ifndef WIN32
#include <GL/glut.h>
#define GAMBI_INIT() glutInit(&argc, argv)
#else
#define GAMBI_INIT() ;;
#include <gl/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "joy.h"

Joystick global_joy;

void SetupRC(void)
{
		if (global_joy.isConfigured())
		{
			global_joy.loadConfig();
		}
		
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void RenderScene(void)
{
     glutSwapBuffers();
}

void JoystickFunc(unsigned int mask, int x, int y, int z)
{
	
		global_joy.receiveInput(mask,x,y,z);
		
		vector<int> vectorzenyo = global_joy.getAll();
		for(int i = 0; i < vectorzenyo.size(); ++i)
			cout << vectorzenyo[i] << " - ";
		cout << endl;
		global_joy.printStatus();
}

int main(int argc, char **argv)
{

	//incializa a glut para funcionar no windows e no linux
    GAMBI_INIT();

	//so para mostrar na tela
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //tela
    glutCreateWindow("JOY OH JOY");
    //registra na glut os callbacks
    glutDisplayFunc(RenderScene);
    //chama de 100 em 100 ms
    glutJoystickFunc(JoystickFunc,100);
    SetupRC();
    glutMainLoop();
		
    return 0;
}

