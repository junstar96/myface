#include "stdafx.h"

float eye[3]; //카메라의 위치
float at[3]; //카메라가 보고 있는 장소

// at[0] = x값 : s * cos@, s는 r^2값에서 z값을 뺀 값 
// at[1] = y값 : s * sin@
// at[2] = z값, +- 1로 움직인다.
float up[3];//카메라의 위쪽 
int rad;//각도


int move_to_left, move_to_right;//이동 변수


GLfloat AmbientLightValue[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat DiffuseLightValue[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat SpecularLightValue[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat PositionLightValue[4] = { 0.0f, 0.0f, 1.0f, 0.0f };