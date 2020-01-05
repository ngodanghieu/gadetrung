#include "Point.h"

Point::Point(void)
{
}

void Point::setPos(int x,int y){
	this->x = x;
	this->y = y;
}
void Point::setPosX(int x){
	this->x = x;
}
void Point::setPosY(int y){
	this->y = y;
}
void Point::clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;
 
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
 
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void Point::textColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Point::gotoXY(int x,int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
int Point::getPosX(){
	return this->x;
}
int Point::getPosY(){
	return this->y;
}
Point::~Point(void)
{
}
