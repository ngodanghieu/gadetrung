#pragma once
#include "Point.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class Basket : public Point
{
public:
	Basket(void);
	Basket(int x,int y);
	void drawBasket(int x,int y);
	void removeBasket(int x,int y);
	~Basket(void);
};

