#include "Global.h"
#include "SceneManager.h"

SceneManager* g_ScnMgr = NULL;


void Update(int temp)
{
	static int s_prevTime = glutGet(GLUT_ELAPSED_TIME);

	/*---------------ElapsedTime 계산-------------------*/
	int currTime = glutGet(GLUT_ELAPSED_TIME);
	float ElapsedTime = (currTime - s_prevTime)/1000.f;
	s_prevTime = currTime;
	//std::cout << ElapsedTime << std::endl;

	/*-----------------Update 내용----------------------*/
	g_ScnMgr->Update(ElapsedTime);

	/*-----------화면 재출력 및 Update반복---------------*/
	glutPostRedisplay();                  // 화면 재출력
	glutTimerFunc(10, Update, 0);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1.0f);

	g_ScnMgr->DrawScene();

	glutSwapBuffers(); // 화면에 출력하기
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
	// openGL 설정
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(800, 600);		// 프로그램 외부 사이즈 결정
	glutCreateWindow("My Minecraft Client");
	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))	std::cout << " GLEW Version is 3.0\n ";
	else									std::cout << "GLEW 3.0 not supported\n ";

	// 초기화
	g_ScnMgr = new SceneManager;

	// 함수연결
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);	// keydown event callback
	glutKeyboardUpFunc(KeyUpInput);	// keyup event callback
	glutMouseFunc(MouseInput);
	glutPassiveMotionFunc(PassiveMotionInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);
	glutReshapeFunc(Reshape);

	// 루프
	glutTimerFunc(10, Update, 0);	// 10milliseconds에 Update 호출  함수에 value전달
	glutMainLoop();

	// 소멸
	delete g_ScnMgr;

	return 0;
}