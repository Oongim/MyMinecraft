#include "Global.h"
#include "SceneManager.h"

SceneManager* g_ScnMgr = NULL;


void Update(int temp)
{
	static int s_prevTime = glutGet(GLUT_ELAPSED_TIME);

	/*---------------ElapsedTime ���-------------------*/
	int currTime = glutGet(GLUT_ELAPSED_TIME);
	float ElapsedTime = (currTime - s_prevTime)/1000.f;
	s_prevTime = currTime;
	//std::cout << ElapsedTime << std::endl;

	/*-----------------Update ����----------------------*/
	g_ScnMgr->Update(ElapsedTime);

	/*-----------ȭ�� ����� �� Update�ݺ�---------------*/
	glutPostRedisplay();                  // ȭ�� �����
	glutTimerFunc(10, Update, 0);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1.0f);

	g_ScnMgr->DrawScene();

	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}

void Idle(void)
{
}

void MouseInput(int button, int state, int x, int y)
{
	g_ScnMgr->MouseInput(button, state, x, y);
}

void PassiveMotionInput(int x, int y)
{
	g_ScnMgr->PassiveMotionInput(x, y);
}

void KeyDownInput(unsigned char key, int x, int y)
{
	g_ScnMgr->KeyDownInput(key, x, y);
}

void KeyUpInput(unsigned char key, int x, int y)
{
	g_ScnMgr->KeyUpInput(key, x, y);
}

void SpecialKeyDownInput(int key, int x, int y)
{
	g_ScnMgr->SpecialKeyDownInput(key, x, y);
}

void SpecialKeyUpInput(int key, int x, int y)
{
	g_ScnMgr->SpecialKeyUpInput(key, x, y);
}

void Reshape(int w, int h)
{
}

int main(int argc, char** argv)
{
	// openGL ����
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(800, 600);		// ���α׷� �ܺ� ������ ����
	glutCreateWindow("My Minecraft Client");
	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))	std::cout << " GLEW Version is 3.0\n ";
	else									std::cout << "GLEW 3.0 not supported\n ";

	// �ʱ�ȭ
	g_ScnMgr = new SceneManager;

	// �Լ�����
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);	// keydown event callback
	glutKeyboardUpFunc(KeyUpInput);	// keyup event callback
	glutMouseFunc(MouseInput);
	glutPassiveMotionFunc(PassiveMotionInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);
	glutReshapeFunc(Reshape);

	// ����
	glutTimerFunc(10, Update, 0);	// 10milliseconds�� Update ȣ��  �Լ��� value����
	glutMainLoop();

	// �Ҹ�
	delete g_ScnMgr;

	return 0;
}