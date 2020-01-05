#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "Point.h"
using namespace std;
class Map : public Point
{
public:
	Map(void);
	void drawFrame();
	void textPointAndLevel(int& pointHigh,int& point,int& level);
	~Map(void);
};

