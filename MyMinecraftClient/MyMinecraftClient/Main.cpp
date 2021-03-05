#include "global.h"

#include <GL/glew.h>
#include <GL/freeglut.h>


void RenderScene(int temp)
{
}

void Display(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
}

void Idle(void)
{
}

void MouseInput(int button, int state, int x, int y)
{
}

void KeyDownInput(unsigned char key, int x, int y)
{
}

void KeyUpInput(unsigned char key, int x, int y)
{
}

void SpecialKeyDownInput(int key, int x, int y)
{
}

void SpecialKeyUpInput(int key, int x, int y)
{
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(800, 600);		// ���α׷� �ܺ� ������ ����
	glutCreateWindow("Game Software Engineering KPU");

	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))	std::cout << " GLEW Version is 3.0\n ";
	else									std::cout << "GLEW 3.0 not supported\n ";

	// �����ڴ� �̰���

	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);	// keydown event callback
	glutKeyboardUpFunc(KeyUpInput);	// keyup event callback
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	glutMainLoop();

	return 0;
}