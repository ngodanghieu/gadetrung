#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <mciapi.h>
#include <fstream>
#include <MMsystem.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define SIZE 100
#define BLACK			0
#define DARK_BLUE		1
#define DARK_GREEN		2
#define DARK_CYAN		3
#define DARK_RED		4
#define DARK_PINK		5
#define DARK_YELLOW  	6
#define DARK_WHITE		7
#define GREY			8
#define BLUE			9
#define GREEN			10
#define CYAN			11
#define RED 			12
#define PINK			13
#define YELLOW  		14
#define WHITE			15
#define CHR 219
#define X0 3
#define Y0 7
#define XMAX 75
#define YMAX 40
#define VECTOR_X 1
#define VECTOR_Y 1

using namespace std;

class Point
{
	int x, y;
public:
	Point(void);
	void setPos(int x,int y);
	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
	void gotoXY(int x,int y);
	void textColor(int color);
	void clrscr();
	~Point(void);
};

