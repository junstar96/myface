#include "stdafx.h"

float eye[3]; //ī�޶��� ��ġ
float at[3]; //ī�޶� ���� �ִ� ���

// at[0] = x�� : s * cos@, s�� r^2������ z���� �� �� 
// at[1] = y�� : s * sin@
// at[2] = z��, +- 1�� �����δ�.
float up[3];//ī�޶��� ���� 
int rad;//����


int move_to_left, move_to_right;//�̵� ����


GLfloat AmbientLightValue[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat DiffuseLightValue[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat SpecularLightValue[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat PositionLightValue[4] = { 0.0f, 0.0f, 1.0f, 0.0f };