#include "Map.h"
Map::Map(void)
{
}
void Map::drawFrame(){
	textColor(244);
	for(int i = X0; i <= XMAX; i++){
		gotoXY(i, Y0);
		cout << char(4);
		gotoXY(i, YMAX);
		cout << char(5);
	}
	for(int j = Y0; j <= YMAX; j++){
		gotoXY(X0, j);
		cout << char(23);
		gotoXY(XMAX, j);
		cout << char (23);
	}
}
void Map::textPointAndLevel(int& pointHigh,int& point,int& level){
    gotoXY(XMAX / 2 - 8, VECTOR_Y+2);
	textColor(10);
	cout << "Point High: " << pointHigh;

	gotoXY(XMAX / 2 - 8, VECTOR_Y + 4);
	textColor(10);
	if(level==1) cout << "Mode: " << "Easy";
	if(level==2) cout << "Mode: " << "Normal";
	if(level==3) cout << "Mode: " << "High";
	if(level==4) cout << "Mode: " << "Very High";
    gotoXY(XMAX / 2 + 8, VECTOR_Y + 4);
	cout << "Point: " << "  ";
	gotoXY(XMAX / 2 + 8, VECTOR_Y + 4);
	textColor(10);
	cout << "Point: " << point;
 
}
Map::~Map(void)
{
}
