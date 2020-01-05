#include "Basket.h"


Basket::Basket(void)
{
}

Basket::Basket(int x,int y){
	this->setPos(x,y);
}
void Basket::drawBasket(int x,int y){
	textColor(0);
	gotoXY(x, y);
	cout << char(220);
	gotoXY(x+5, y);
	cout << char(220);
 
	textColor(7);
	gotoXY(x+1, y);
	cout << char(223);
	gotoXY(x+4, y);
	cout << char(223);
	gotoXY(x+3, y);
	cout << char(223);
	gotoXY(x+2, y);
	cout << char(223);
 
	textColor(112);
	gotoXY(x, y-1);
	cout << " ";
	gotoXY(x+5, y-1);
	cout << " ";
 
	textColor(7);
	gotoXY(x+1, y-1);
	cout << char(220);
	gotoXY(x+4, y-1);
	cout << char(220);
}
void Basket::removeBasket(int x,int y){
	gotoXY(x, y);
	cout << " ";
	gotoXY(x+5, y);
	cout << " ";
	gotoXY(x+1, y);
	cout << " ";
	gotoXY(x+4, y);
	cout << " ";
	gotoXY(x+3, y);
	cout << " ";
	gotoXY(x+2, y);
	cout << " ";
	gotoXY(x, y-1);
	cout << " ";
	gotoXY(x+5, y-1);
	cout << " ";
	gotoXY(x+1, y-1);
	cout << " ";
	gotoXY(x+4, y-1);
	cout << " ";
}
Basket::~Basket(void)
{
}
