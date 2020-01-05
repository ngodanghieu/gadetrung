#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include "Point.h"
#include "Knife.h"
#include "Basket.h"
#pragma comment(lib, "Winmm.lib")
using namespace std;
class Chicken : public Point
{
public:
	int arr[SIZE][SIZE];
	Chicken(void);
	Chicken(int x,int y);
	void init();
	void drawChicken(int x,int y);
	void removeChicken(int x,int y);
	void drawEggs();
	
	void move(bool& gameOver,int& point);
	
	void checkEggToBasket(Basket& b,int& point);
	void checkGameOver(Knife& k,bool& gameOver);
	~Chicken(void);
};

