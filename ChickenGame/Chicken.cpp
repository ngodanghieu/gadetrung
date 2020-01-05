#include "Chicken.h"
#include "Knife.h"

Chicken::Chicken(void)
{
}
Chicken::Chicken(int x,int y){
	this->setPos(x,y);
}
void Chicken::init(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			arr[i][j] = 0;
		}
	}
}
void playVoTrung(){
	mciSendString("open \"VoTrung.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
}
void playTangDiem(){
	mciSendString("open \"yeah.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
}

void Chicken::drawChicken(int x,int y){
	textColor(14);
	gotoXY(x+2, y);
	putchar(223);
	gotoXY(x+3, y);
	putchar(223);
	gotoXY(x+4, y);
	putchar(223);
	gotoXY(x+5, y);
	putchar(223);
	gotoXY(x+6, y);
	cout << " ";
	gotoXY(x+7, y);
	cout << " ";
 
	textColor(14);
	gotoXY(x, y-1);
	putchar(223);
	textColor(235);
	gotoXY(x+1, y-1);
	cout << " ";
	gotoXY(x+2, y-1);
	cout << " ";
 
	textColor(236);
	gotoXY(x+3, y-1);
	putchar(92);
	gotoXY(x+4, y-1);
	putchar(47);
	textColor(235);
	gotoXY(x+5, y-1);
	cout << " ";
	gotoXY(x+6, y-1);
	cout << " ";
 
	textColor(14);
	gotoXY(x+7, y-1);
	putchar(223);
	textColor(235);
	gotoXY(x, y-2);
	cout << " ";
	gotoXY(x+1, y-2);
	cout << " ";
	gotoXY(x+3, y-2);
	cout << " ";
	gotoXY(x+4, y-2);
	cout << " ";
	gotoXY(x+6, y-2);
	cout << " ";
	gotoXY(x+7, y-2);
	cout << " ";
	gotoXY(x+2,y-3);
	cout<< " ";
	gotoXY(x+3,y-3);
	cout<< " ";
	gotoXY(x+4,y-3);
	cout<< " ";
	gotoXY(x+5,y-3);
	cout<< " ";
 
	textColor(224);
	gotoXY(x+2, y-2);
	putchar(4);
	gotoXY(x+5, y-2);
	putchar(4);
 
	textColor(14);
	gotoXY(x+1, y-3);
	putchar(220);
	gotoXY(x+6, y-3);
	putchar(220);
 
	textColor(12);
	gotoXY(x+3, y-4);
	putchar(220);
	gotoXY(x+4, y-4);
	putchar(220);
}
void Chicken::removeChicken(int x,int y){
	gotoXY(x, y - 1);
	puts(" ");
	gotoXY(x+1, y);
	puts(" ");
	gotoXY(x+2, y);
	puts(" ");
	gotoXY(x+4, y);
	puts(" ");
	gotoXY(x+5, y-1);
	puts(" ");
	gotoXY(x+7, y-1);
	puts(" ");
	gotoXY(x, y - 2);
	puts(" ");
	gotoXY(x+7, y-2);
	puts(" ");
	gotoXY(x+1, y-3);
	puts(" ");
	gotoXY(x+6, y-3);
	puts(" ");
	gotoXY(x+3, y-4);
	puts(" ");
	gotoXY(x+4, y-4);
	puts(" ");
}
void Chicken::drawEggs(){
	textColor(YELLOW);
	for(int i = XMAX - 1; i > X0; i--){
		for(int j = YMAX-1; j > Y0; j--){
			if(arr[i][j] == 1){
				gotoXY(i, j);
				cout << "O";
			}
		}
	}
}
void Chicken::checkGameOver(Knife& k,bool& gameOver){
	for (int i = k.getPosX()-1; i <= k.getPosX() + 2; i++) if (arr[i][k.getPosY()]==1) gameOver=true;
}

void Chicken::checkEggToBasket(Basket& basket,int& point){
	for(int i = basket.getPosX(); i <= basket.getPosX()+ 5; i++){
		if(arr[i][basket.getPosY()-1] == 1){
			arr[i][basket.getPosY()-1] = 0;
			point+=1;
			thread tangDiem (playTangDiem);
			tangDiem.join();
		}
	}
}

void Chicken::move(bool& gameOver,int& point){
	for(int i = XMAX - 1; i >= X0; i--){ 
		for(int j = YMAX-1; j >= Y0; j--){
			if(arr[i][j] == 1){
				arr[i][j] = 0;
				gotoXY(i, j);
				cout << " ";
				arr[i][j+1] = 1;
			}
			if(j+1== 40 && arr[i][j+1]==1){
				arr[i][j+1]=0;
				point=point-1;
				thread voTrung (playVoTrung);
				voTrung.join();
				if(point <0){
					gameOver =true;
				}
			}
		}
	}
}
Chicken::~Chicken(void)
{
}
