#include "stdafx.h"
#include "dice.h"


dice::dice()
{
}


dice::~dice()
{
}

int dice::dice_num()
{
	int temp = rand() % 6 + 1;

	return temp;
}