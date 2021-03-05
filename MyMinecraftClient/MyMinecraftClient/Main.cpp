#include "global.h"

#include <GL/glew.h>
#include <GL/freeglut.h>


void RenderScene(int temp)
{
}

void Display(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
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
	glutInitWindowSize(800, 600);		// 프로그램 외부 사이즈 결정
	glutCreateWindow("Game Software Engineering KPU");

	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))	std::cout << " GLEW Version is 3.0\n ";
	else									std::cout << "GLEW 3.0 not supported\n ";

	// 생성자는 이곳에

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