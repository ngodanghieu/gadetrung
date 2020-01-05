#pragma once
#include "Point.h"
class Knife : public Point
{
public:
	Knife(void);
	Knife(int x,int y);
	void drawKnife(int x,int y);
	void removeKnife(int x,int y);
	~Knife(void);
};

