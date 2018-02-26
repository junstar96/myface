// 프로젝트 실행.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include"reference_folder\glew.h"
#include"reference_folder\freeglut.h"

int move_to_left;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);


	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f * (0.01)*(move_to_left), -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
	case 'A':
		move_to_left += 1;
		break;
	}
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		move_to_left += 1;
		break;
	case GLUT_KEY_RIGHT:
		if (move_to_left > 1)
		{
			move_to_left -= 1;
		}
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_UP:
		break;
	}
	RenderScene();
}

int main(int argc, char*  argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	glutInitWindowSize(500, 500); //optional
	glutCreateWindow("Game Software Engineering KPU");

	srand(time(NULL));
	init_maze();
	make_maze();
	move_to_left = 1;
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	
	

	
	
    return 0;
}

