#include "Knife.h"


Knife::Knife(void)
{
}
Knife::Knife(int x,int y){
	this->setPos(x,y);
}
void Knife::drawKnife(int x,int y){
	textColor(12);
	gotoXY(x, y);
	cout << char(4);
 
	gotoXY(x+1, y);
	cout << char(4);
	gotoXY(x+2, y);
	cout << char(4);
}
void Knife::removeKnife(int x,int y){
	textColor(12);
	gotoXY(x, y);
	cout << " ";
	gotoXY(x+1, y);
	cout << " ";
	gotoXY(x+2, y);
	cout << " ";
}
Knife::~Knife(void)
{
}
