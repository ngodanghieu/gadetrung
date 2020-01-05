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
#include "Point.h"
#include "Map.h"
#include "Chicken.h"
#include "Knife.h"

#pragma comment(lib, "Winmm.lib")

using namespace std;

bool mContinue = true;
bool gameOver = false;
int Width = 45;
int	Height = 8;
int len = 2;
int level = 1;
int pointHigh =0;
int point = 0;
void playMp3(){

	mciSendString("open \"MusicBackgroud.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
	while (true) {
		if (_kbhit()) {
			char temp = _getch();
			if (temp == 13) {
				if (mContinue) {
					mciSendString("pause mp3", NULL, 0, NULL);
					mContinue = false;
				} else {
					mciSendString("resume mp3", NULL, 0, NULL);
					mContinue = true;
				}
			}
		}
		if(gameOver==true){
			mciSendString("pause mp3", NULL, 0, NULL);
			break;
		}
	}
}
void playVictory(){
	Sleep(1000);
	mciSendString("open \"Victory.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
}
void playGameOver(){
	Sleep(1000);
	mciSendString("open \"Defeat.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
}

void playDeTrung(){
	mciSendString("open \"DeTrung.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
}

int Menu(int& choose, int option) {
	Point p;
	int key = 0;
	int leng = len + 5;
	while (key != 13) {
		for (int i = 0; i < option * 2; i += 2) {
			p.gotoXY(Width - 4, Height + i);
			cout << ' ';
		}
		if ((key == 'w' || key == 'W' || key == 72) && choose > 1)
			--choose;
		else if ((key == 's' || key == 'S' || key == 80) && choose < option)
			++choose;
 
		for (int i = 0; i <= option * 2; i += 2) {
			if (choose == i / 2 + 1) {
				p.gotoXY(Width - 4, Height + i);
				putchar(175);
			}
		}
		key = _getch();
		if(key ==27){
			return 27;
		}
	}
	return choose;
}

void readFile(char *file,char *data) {
	Point p;
	ifstream ifs;
	ifs.open(file);
	p.textColor(GREEN);
	while (!ifs.eof()) {
		ifs.getline(data, 100);
		cout <<"\t" << data<<endl;
	}
	ifs.close();
}

void readScore()
{
	Point p;
	ifstream ifs;
	ifs.open("score.txt",ios::app);
	char *data = new char[100];
	p.textColor(CYAN);
	ifs.getline(data, 100);
	pointHigh = atoi(data);
	ifs.close();
	if(pointHigh < point){
		ofstream of;
		of.open("score.txt",ios::trunc);
		of << point << endl;
		of.close();
	}
}
void showVictory(){
	Point p;
	p.gotoXY(0,0);
	char showVictory[SIZE];
	readFile("victory.txt",showVictory);
	cout << "\t\tYOUR POINT: " << point;
	thread musicVictory = thread (playVictory);
	musicVictory.join();
	Sleep(2000);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void showGameOver(){
	Point p;
	p.gotoXY(0,0);
	char showOver[SIZE];
	readFile("gameover2.txt",showOver);
	cout<<endl;
	cout << "\t\t YOUR POINT:" << point;
	thread musicgameOVer = thread (playGameOver);
	musicgameOVer.join();
	Sleep(2000);
	resizeConsole(800,720);
}
void game(){
	resizeConsole(650,720);
	Point p;
	Chicken chicken(XMAX/2,12);
	chicken.init();
	Map m;
	m.drawFrame();

	chicken.drawChicken(chicken.getPosX(),chicken.getPosY());

	Basket basket(XMAX / 2,39);
	basket.drawBasket(basket.getPosX(),basket.getPosY());

	int knife1Rand =rand() % 10;
	knife1Rand <5?6:knife1Rand;
	Knife knife(5,15);
	knife.drawKnife(knife.getPosX(),knife.getPosY());

	Knife knife2(rand() % 60,21);

	knife2.drawKnife(knife2.getPosX(), knife2.getPosY());
 
	int knife3Rand =rand() % 10;
	knife3Rand <5?5:knife3Rand;
	Knife knife3(knife3Rand,27);
	knife3.drawKnife(knife3.getPosX(), knife3.getPosY());
 
	Knife knife4(rand() % 60,33);
	knife4.drawKnife(knife4.getPosX(), knife4.getPosY());

	bool direction = true;
	bool direction1 = true;
	bool direction2 = true;
	bool direction3 = true;
	bool direction4 = true;
	bool directionBasket = true;
 
	int randomNumber = 1;
	point = 0;

	

	while(1){
        
		m.textPointAndLevel(pointHigh,point,level);
		readScore();
		if(point > 10 && point < 20) level = 2;
		else if(point >= 20 && point < 30) level = 3;
		else if(point >= 30 && point < 40) level = 4;
		else if(point >= 40) level = 5;
 
		srand(time(NULL));
		if(level == 2) randomNumber = rand() % 5 + 1;
		if(level == 3) randomNumber = level - 2;
		if(level == 4) randomNumber = rand() % 5 + 1;

		if (basket.getPosX() <= 20) directionBasket = true;
		if (basket.getPosX() + randomNumber >= XMAX - 20) directionBasket = false;
 
		if(level > 2){
			if (directionBasket == true)
			{
				basket.removeBasket(basket.getPosX(), basket.getPosY());
				basket.setPosX(basket.getPosX() + randomNumber);
				basket.drawBasket(basket.getPosX(),basket.getPosY());
			}else if (directionBasket == false)
			{
				basket.removeBasket(basket.getPosX(), basket.getPosY());
				basket.setPosX(basket.getPosX() - randomNumber);
				basket.drawBasket(basket.getPosX(),basket.getPosY());
			}
			
		}else{
			basket.drawBasket(basket.getPosX(), basket.getPosY());
		}
 
		if (GetAsyncKeyState(VK_SPACE) && direction == true) {
			thread playDeTrung (playDeTrung);
			playDeTrung.join();
			chicken.arr[chicken.getPosX()+4][chicken.getPosY() + 1] = 1;
		}else if(GetAsyncKeyState(VK_SPACE) && direction == false){
			thread playDeTrung (playDeTrung);
			playDeTrung.join();
			chicken.arr[chicken.getPosX()+3][chicken.getPosY() + 1] = 1;
		}
 
		if (chicken.getPosX() == 5) direction = true;
		if (chicken.getPosX() == XMAX - 8) direction = false;
 
		if (direction == true){
			chicken.removeChicken(chicken.getPosX(), chicken.getPosY());
			chicken.setPosX(chicken.getPosX()+1);
			chicken.drawChicken(chicken.getPosX(),chicken.getPosY());
		}
 
		if (direction == false){
			chicken.removeChicken(chicken.getPosX(), chicken.getPosY());
			chicken.setPosX(chicken.getPosX()-1);
			chicken.drawChicken(chicken.getPosX(), chicken.getPosY());
		}
 
		if (knife.getPosX() <= 5) direction1 = true;
		if (knife.getPosX() + randomNumber >= XMAX - 6) direction1 = false;
 
		if (knife2.getPosX() + randomNumber >= XMAX - 6) direction2 = false;
		if (knife2.getPosX() <= 5) direction2 = true;
 
		if (knife3.getPosX() + randomNumber >= XMAX - 6) direction3 = false;
		if (knife3.getPosX() <= 5) direction3 = true;
 
		if (knife4.getPosX() + randomNumber >= XMAX - 6) direction4 = false;
		if (knife4.getPosX() <= 5) direction4 = true;
 
		if (direction1 == true){
			knife.removeKnife(knife.getPosX(), knife.getPosY());
			knife.setPosX(knife.getPosX() + randomNumber);
			knife.drawKnife(knife.getPosX(), knife.getPosY());
		}
 
		if (direction1 == false){
			knife.removeKnife(knife.getPosX(), knife.getPosY());
			knife.setPosX(knife.getPosX()-1);
			knife.drawKnife(knife.getPosX(), knife.getPosY());
		}
 
		if (direction2 == true){
			knife2.removeKnife(knife2.getPosX(), knife2.getPosY());
			knife2.setPosX(knife2.getPosX() + randomNumber);
			knife2.drawKnife(knife2.getPosX(), knife2.getPosY());
		}
 
		if (direction2 == false){
			knife2.removeKnife(knife2.getPosX(), knife2.getPosY());
			knife2.setPosX(knife2.getPosX()-1);
			knife2.drawKnife(knife2.getPosX(), knife2.getPosY());
		}
 
		if (direction3 == true){
			knife3.removeKnife(knife3.getPosX(), knife3.getPosY());
			knife3.setPosX(knife3.getPosX() + randomNumber);
			knife3.drawKnife(knife3.getPosX(), knife3.getPosY());
		}
 
		if (direction3 == false){
			knife3.removeKnife(knife3.getPosX(), knife3.getPosY());
			knife3.setPosX(knife3.getPosX()-1);
			knife3.drawKnife(knife3.getPosX(), knife3.getPosY());
		}
 
		if (direction4 == true){
			knife4.removeKnife(knife4.getPosX(), knife4.getPosY());
			knife4.setPosX(knife4.getPosX() + randomNumber);
			knife4.drawKnife(knife4.getPosX(), knife4.getPosY());
		}
 
		if (direction4 == false){
			knife.removeKnife(knife4.getPosX(), knife4.getPosY());
			knife4.setPosX(knife4.getPosX()-1);
			knife4.drawKnife(knife4.getPosX(), knife4.getPosY());
		}
 
		chicken.drawEggs();
		chicken.checkEggToBasket(basket,point);
		chicken.checkGameOver(knife,gameOver);
		chicken.checkGameOver(knife2,gameOver);
		chicken.checkGameOver(knife3,gameOver);
		chicken.checkGameOver(knife4,gameOver);
		Sleep(50);
		chicken.move(gameOver,point);
		
		if (point >= 40 && level >= 5)
		{
			system("cls");
			ofstream of;
			of.open("score.txt",ios::trunc);
			of << point << endl;
			of.close();
			level=1;
			if(point < 0){
				point=0;
			}
			showVictory();
			break;
		}

		if(gameOver ==  true ){
			system("cls");
			if(pointHigh < point){
				ofstream of;
				of.open("score.txt",ios::trunc);
				of << point << endl;
				of.close();
			}
			level=1;
			if(point <0){
				point=0;
			}
			showGameOver();
			break;
		}
	}
}
void run(){
	thread playSoundThread = thread (playMp3);
	thread gameplay = thread (game);
	playSoundThread.join();
	gameplay.join();
	if(gameOver==true){
		gameplay.~thread();
		
		gameOver=false;
	}
}
void hidePointer(){
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
int main(){
	hidePointer();
	resizeConsole(800,720);
	Point p;
	char nameGame[SIZE] = "name.txt";
	char chicken[SIZE] = "chicken.txt";
	char data[SIZE];
	int choose = 1;
	int lv = 1;
	cout << endl;
	cout << endl;
	readScore();
	while (choose != 0) {
		choose = 1;
		p.clrscr();
		readFile(nameGame, data);
		p.textColor(YELLOW);
		p.gotoXY(Width, Height);
		puts("NEW GAME");
		p.gotoXY(Width, Height + 2 );
		puts("MODE");
		p.gotoXY(Width, Height + 4);
		puts("EXIT");
		choose = Menu(choose, 3);
		switch (choose) {
		case 1:
			choose = 1;
			p.clrscr();
			run();
			break;
		case 2:
			p.clrscr();
			readFile(nameGame, data);
			p.textColor(YELLOW);
			p.gotoXY(Width, Height);
			puts("EASY");
			p.gotoXY(Width, Height + 2 );
			puts("NORMAL");
			p.gotoXY(Width, Height + 4 );
			puts("HIGH");
			p.gotoXY(Width, Height + 6 );
			puts("VERY HIGH");
			p.gotoXY(Width, Height + 8 );
			puts("EXIT");
			lv = Menu(lv, 5);
			switch (lv)
			{
			    case 1:
					level = 1;
					break;
				case 2:
					level = 2;
					break;
				case 3:
					level = 3;
					break;
				case 4:
					level = 4;
					break;
				case 5:
					continue;	
			}
			continue;
		case 3: 
			choose = 0;
			return 0;
		}
	}
	getchar();
	return 0;
}