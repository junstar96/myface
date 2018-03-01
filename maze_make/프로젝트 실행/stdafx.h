// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include"reference_folder\glew.h"
#include"reference_folder\freeglut.h"
#include<Windows.h>
#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include<cmath>
#include<ctime>
#include"Make_Maze.h"


//define area
#define round 3.141592/180


using std::cout;
using std::endl;

extern float eye[3], at[3], up[3];
extern int rad;
extern int move_to_left, move_to_right;

extern GLfloat AmbientLightValue[4];
extern GLfloat DiffuseLightValue[4];
extern GLfloat SpecularLightValue[4];
extern GLfloat PositionLightValue[4];
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
