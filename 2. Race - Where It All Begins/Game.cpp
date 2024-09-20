#include"graphics.h"
#include<time.h>
#include<stdlib.h>
#include "Car_My.h"
#include"EnemyCars.h"
#include<vector>
#include<algorithm>
using namespace std;

#define Window_X 1016
#define Window_Y 730

#define U_Grass_X1 0
#define U_Grass_Y1 0
#define U_Grass_X2 1016
#define U_Grass_Y2 740/3 - 55 - 25 // = 191

#define D_Grass_X1 0
#define D_Grass_Y1 740 - (740/3 - 55) + 25 // = 549 
#define D_Grass_X2 1016
#define D_Grass_Y2 740

#define Road_X1 0
#define Road_Y1 740/3 - 55
#define Road_X2 1016
#define Road_Y2 740 - (740/3 - 55)

#define Road_Moving_X1 100
#define Road_Moving_Y1 360
#define Road_Moving_X2 400
#define Road_Moving_Y2 380

int road_moving_X1=Road_Moving_X1;
int road_moving_Y1=Road_Moving_Y1;
int road_moving_X2=Road_Moving_X2;
int road_moving_Y2=Road_Moving_Y2;

int road2_moving_X1=Road_Moving_X1+500;
int road2_moving_Y1=Road_Moving_Y1;
int road2_moving_X2=Road_Moving_X2+500;
int road2_moving_Y2=Road_Moving_Y2;

#define Sun_X 1000
#define Sun_Y 0
#define Sun_Rad 50

int Enemy_car_right_inner_x=R_Inner_Car_Wheel_X+1000; //Enemy Car Vaiables End
int Enemy_car_right_inner_y=R_Inner_Car_Wheel_Y-50;
int Enemy_car_right_inner_rad=R_Inner_Car_Wheel_Rad;
int Enemy_car_right_inner_color1=WHITE;
int Enemy_car_right_inner_color2=WHITE;

#define MAX_COLLISION_ALLOWED 8

//for Level(s)
int levelChange=0;

//for Score
int s11=0;
char scc[50];

//for Life
int life = MAX_COLLISION_ALLOWED;
char lif[50];

// car Struct
myCar car;

// for menu
int choice;
char userName[100];

//for game ove and then menu
int aks=0;

// level changing scores
#define FIRST_LEVEL_SCORE 60
#define SECOND_LEVEL_SCORE 120
#define THIRD_LEVEL_SCORE 180
#define FOURTH_LEVEL_SCORE 240
#define FIFTH_LEVEL_SCORE 300
#define SIXTH_LEVEL_SCORE 360
#define SEVENTH_LEVEL_SCORE 430

// for highscores

FILE *fout = fopen("highScores.txt","a");
struct MyStruct
{
    int key;
    char stringValue[100];

    bool operator < (const MyStruct& str) const
    {
        return (str.key < key);
    }
};
vector<MyStruct> sortCeleb;

//Declaration
void test();
void showHighScores();
void choice1();
void choice2();
void createMenu();
void sortIfHighest();
void gameOver();
void Credits();
void isBetween();
void INITIALIZE();
void ReinAllEnemy();


//Celebration
int max=-1;


void Upper(int a,int b,int c,int d)
{
	readimagefile("palm.jpg",a,b,c,d); //Upper (U_Grass)
}

void Lower(int a,int b,int c,int d)
{
	readimagefile("palmNight.jpg",a,b,c,d);
}

void MovingRoad(int a,int b,int c,int d,int e)
{
	setcolor(e);
	rectangle(a,b,c,d);
	setfillstyle(SOLID_FILL,e);
	bar(a,b,c,d);
}

void MovingRoad2(int a,int b,int c,int d,int e)
{
	setcolor(e);
	rectangle(a,b,c,d);
	setfillstyle(SOLID_FILL,e);
	bar(a,b,c,d);
}

void Road()
{
	readimagefile("image004.jpg",U_Grass_X1,U_Grass_Y2-5,U_Grass_X2,U_Grass_Y2); //Pavement 1
	readimagefile("image004.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y1+5); //Pavement 2
}

void RoadReincarnated1()
{
	road_moving_X1=Road_Moving_X1+950;
	road_moving_Y1=Road_Moving_Y1;
	road_moving_X2=Road_Moving_X2+950;
	road_moving_Y2=Road_Moving_Y2;
}

void RoadReincarnated2()
{
	road2_moving_X1=Road_Moving_X1+950;
	road2_moving_Y1=Road_Moving_Y1;
	road2_moving_X2=Road_Moving_X2+950;
	road2_moving_Y2=Road_Moving_Y2;
}

void MoveTheRoad(int speed,int color)
{
	MovingRoad(road_moving_X1-=speed,road_moving_Y1,road_moving_X2-=speed,road_moving_Y2,color);
	MovingRoad2(road2_moving_X1-=speed,road2_moving_Y1,road2_moving_X2-=speed,road2_moving_Y2,color);
}

void Enemy_Above_Part_Car(int a,int b,int c,int d,int color)
{
	setcolor( color); //(Enemy Above Car)
	rectangle(a,b,c,d);
	setfillstyle(SOLID_FILL,color);
	bar(a,b,c,d);
}

void Enemy_Down_Part_Car(int a,int b,int c,int d,int color)
{
	setcolor(color); //(Down Car)
	rectangle(a,b,c,d);
	setfillstyle(SOLID_FILL,color);
	bar(a,b,c,d);
}

void Enemy_Left_Wheel_Car(int a,int b,int c,int color)
{
	setcolor(color); //Left Wheel
	circle(a,b,c);
	setfillstyle(SOLID_FILL,color);
	fillellipse(a,b,c,c);
}

void Enemy_Right_Wheel_Car(int a,int b,int c,int color)
{	
	setcolor(color);
	circle(a,b,c); //Right Wheel
	setfillstyle(SOLID_FILL,color);
	fillellipse(a,b,c,c);
}

void Enemy_Left_Inner_Wheel_Car(int a,int b,int c,int color)
{
	setcolor(color); //Left Inner Wheel
	circle(a,b,c);
	setfillstyle(SOLID_FILL,color);
	fillellipse(a,b,c,c);
}

void Enemy_Right_Inner_Wheel_Car(int a,int b,int c,int color)
{
	setcolor(color);
	circle(a,b,c);  //Right Inner Wheel
	setfillstyle(SOLID_FILL,color);
	fillellipse(a,b,c,c);
}

bool isBetween(int a,int b,int c)
{
	return a <= b && b<= c;
}

void EnemyCar(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car_above_x1-=Speed,Enemy_car_above_y1,Enemy_car_above_x2-=Speed,Enemy_car_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car_down_x1-=Speed,Enemy_car_down_y1,Enemy_car_down_x2-=Speed,Enemy_car_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car_leftwh_x-=Speed,Enemy_car_leftwh_y,Enemy_car_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car_rightwh_x-=Speed,Enemy_car_rightwh_y,Enemy_car_rightwh_rad,EnemyColors[3]);
	Enemy_Left_Inner_Wheel_Car(Enemy_car_left_inner_x-=Speed,Enemy_car_left_inner_y,Enemy_car_left_inner_rad,EnemyColors[4]);
	Enemy_Right_Inner_Wheel_Car(Enemy_car_right_inner_x-=Speed,Enemy_car_right_inner_y,Enemy_car_right_inner_rad,EnemyColors[5]);
}

void EnemyCar11(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car11_above_x1-=Speed,Enemy_car11_above_y1,Enemy_car11_above_x2-=Speed,Enemy_car11_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car11_down_x1-=Speed,Enemy_car11_down_y1,Enemy_car11_down_x2-=Speed,Enemy_car11_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car11_leftwh_x-=Speed,Enemy_car11_leftwh_y,Enemy_car11_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car11_rightwh_x-=Speed,Enemy_car11_rightwh_y,Enemy_car11_rightwh_rad,EnemyColors[3]);
}

void EnemyCar113(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car113_above_x1-=Speed,Enemy_car113_above_y1,Enemy_car113_above_x2-=Speed,Enemy_car113_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car113_down_x1-=Speed,Enemy_car113_down_y1,Enemy_car113_down_x2-=Speed,Enemy_car113_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car113_leftwh_x-=Speed,Enemy_car113_leftwh_y,Enemy_car113_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car113_rightwh_x-=Speed,Enemy_car113_rightwh_y,Enemy_car113_rightwh_rad,EnemyColors[3]);
}

void EnemyCar114(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car114_above_x1-=Speed,Enemy_car114_above_y1,Enemy_car114_above_x2-=Speed,Enemy_car114_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car114_down_x1-=Speed,Enemy_car114_down_y1,Enemy_car114_down_x2-=Speed,Enemy_car114_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car114_leftwh_x-=Speed,Enemy_car114_leftwh_y,Enemy_car114_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car114_rightwh_x-=Speed,Enemy_car114_rightwh_y,Enemy_car114_rightwh_rad,EnemyColors[3]);
}

void EnemyCar115(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car115_above_x1-=Speed,Enemy_car115_above_y1,Enemy_car115_above_x2-=Speed,Enemy_car115_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car115_down_x1-=Speed,Enemy_car115_down_y1,Enemy_car115_down_x2-=Speed,Enemy_car115_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car115_leftwh_x-=Speed,Enemy_car115_leftwh_y,Enemy_car115_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car115_rightwh_x-=Speed,Enemy_car115_rightwh_y,Enemy_car115_rightwh_rad,EnemyColors[3]);
}

void EnemyCar116(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car116_above_x1-=Speed,Enemy_car116_above_y1,Enemy_car116_above_x2-=Speed,Enemy_car116_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car116_down_x1-=Speed,Enemy_car116_down_y1,Enemy_car116_down_x2-=Speed,Enemy_car116_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car116_leftwh_x-=Speed,Enemy_car116_leftwh_y,Enemy_car116_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car116_rightwh_x-=Speed,Enemy_car116_rightwh_y,Enemy_car116_rightwh_rad,EnemyColors[3]);
}

void EnemyCar117(int EnemyColors[],int Speed)
{
	Enemy_Above_Part_Car(Enemy_car117_above_x1-=Speed,Enemy_car117_above_y1,Enemy_car117_above_x2-=Speed,Enemy_car117_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car117_down_x1-=Speed,Enemy_car117_down_y1,Enemy_car117_down_x2-=Speed,Enemy_car117_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car117_leftwh_x-=Speed,Enemy_car117_leftwh_y,Enemy_car117_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car117_rightwh_x-=Speed,Enemy_car117_rightwh_y,Enemy_car117_rightwh_rad,EnemyColors[3]);
}

void EnemyCar118(int EnemyColors[],int Speed)
{	
	Enemy_Above_Part_Car(Enemy_car118_above_x1-=Speed,Enemy_car118_above_y1,Enemy_car118_above_x2-=Speed,Enemy_car118_above_y2,EnemyColors[0]);
	Enemy_Down_Part_Car(Enemy_car118_down_x1-=Speed,Enemy_car118_down_y1,Enemy_car118_down_x2-=Speed,Enemy_car118_down_y2,EnemyColors[1]);
	Enemy_Left_Wheel_Car(Enemy_car118_leftwh_x-=Speed,Enemy_car118_leftwh_y,Enemy_car118_leftwh_rad,EnemyColors[2]);
	Enemy_Right_Wheel_Car(Enemy_car118_rightwh_x-=Speed,Enemy_car118_rightwh_y,Enemy_car118_rightwh_rad,EnemyColors[3]);
}

void EnemyCarReIncarnated_1(int y_speed)
{
	Enemy_car_above_x1=Car_Rectangle_X1+1000; //Enemy Car
	Enemy_car_above_y1=Car_Rectangle_Y1-50+y_speed;
	Enemy_car_above_x2=Car_Rectangle_X2+1000;
	Enemy_car_above_y2=Car_Rectangle_Y2-50+y_speed;
	Enemy_car_above_color=RED;

	Enemy_car_down_x1=D_Car_Rectangle_X1+1000;
	Enemy_car_down_y1=D_Car_Rectangle_Y1-50+y_speed;
	Enemy_car_down_x2=D_Car_Rectangle_X2+1000;
	Enemy_car_down_y2=D_Car_Rectangle_Y2-50+y_speed;
	Enemy_car_down_color=RED;

	Enemy_car_leftwh_x=L_Car_Wheel_X+1000;
	Enemy_car_leftwh_y=L_Car_Wheel_Y-50+y_speed;
	Enemy_car_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car_leftwh_color1=WHITE;
	Enemy_car_leftwh_color2=BLACK;

	Enemy_car_rightwh_x=R_Car_Wheel_X+1000;
	Enemy_car_rightwh_y=R_Car_Wheel_Y-50+y_speed;
	Enemy_car_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car_rightwh_color1=WHITE;
	Enemy_car_rightwh_color2=BLACK;

	Enemy_car_left_inner_x=L_Inner_Car_Wheel_X+1000;
	Enemy_car_left_inner_y=L_Inner_Car_Wheel_Y-50+y_speed; 
	Enemy_car_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car_left_inner_color1=WHITE;
	Enemy_car_left_inner_color2=WHITE;

	Enemy_car_right_inner_x=R_Inner_Car_Wheel_X+1000; //Enemy Car Vaiables End
	Enemy_car_right_inner_y=R_Inner_Car_Wheel_Y-50+y_speed;
	Enemy_car_right_inner_rad=R_Inner_Car_Wheel_Rad;
	Enemy_car_right_inner_color1=WHITE;
	Enemy_car_right_inner_color2=WHITE;
}

void EnemyCarReIncarnated_2(int y_speed)
{
	Enemy_car_above_x1=Car_Rectangle_X1+1000; //Enemy Car
	Enemy_car_above_y1=Car_Rectangle_Y1+100+y_speed;
	Enemy_car_above_x2=Car_Rectangle_X2+1000;
	Enemy_car_above_y2=Car_Rectangle_Y2+100+y_speed;
	Enemy_car_above_color=RED;

	Enemy_car_down_x1=D_Car_Rectangle_X1+1000;
	Enemy_car_down_y1=D_Car_Rectangle_Y1+100+y_speed;
	Enemy_car_down_x2=D_Car_Rectangle_X2+1000;
	Enemy_car_down_y2=D_Car_Rectangle_Y2+100+y_speed;
	Enemy_car_down_color=RED;

	Enemy_car_leftwh_x=L_Car_Wheel_X+1000;
	Enemy_car_leftwh_y=L_Car_Wheel_Y+100+y_speed;
	Enemy_car_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car_leftwh_color1=WHITE;
	Enemy_car_leftwh_color2=BLACK;

	Enemy_car_rightwh_x=R_Car_Wheel_X+1000;
	Enemy_car_rightwh_y=R_Car_Wheel_Y+100+y_speed;
	Enemy_car_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car_rightwh_color1=WHITE;
	Enemy_car_rightwh_color2=BLACK;

	Enemy_car_left_inner_x=L_Inner_Car_Wheel_X+1000;
	Enemy_car_left_inner_y=L_Inner_Car_Wheel_Y+100+y_speed; 
	Enemy_car_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car_left_inner_color1=WHITE;
	Enemy_car_left_inner_color2=WHITE;

	Enemy_car_right_inner_x=R_Inner_Car_Wheel_X+1000; //Enemy Car Vaiables End
	Enemy_car_right_inner_y=R_Inner_Car_Wheel_Y+100+y_speed;
	Enemy_car_right_inner_rad=R_Inner_Car_Wheel_Rad;
	Enemy_car_right_inner_color1=WHITE;
	Enemy_car_right_inner_color2=WHITE;
}

void sortIfHighest()
{
	FILE *fifH = fopen("highScores.txt","r");
	char user[101];
	int score,max=-1;
	while(fscanf(fifH,"%s %d",user,&score) !=-1)
	{
		MyStruct myStruct;
		myStruct.key = score;
		sortCeleb.push_back(myStruct);
		if(max<score)
			max=score;
	}
	sort(sortCeleb.begin(),sortCeleb.end());
	printf("max = %d\n\n\n\n",max);
	printf("s11 = %d\n\n\n",s11);
	if(s11>=max)
	{
		cleardevice();
		readimagefile("new-record-top.jpg",0,0,1016,300);
			
		setcolor(WHITE);
		settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(508,193+120,"ConGratulations!");
			
		settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(508,193+180,userName);
			
		settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(508,193+240,"You Are Now The Highest Scorer!");
		getch();
		delay(3000);
	}
}

void Score()
{
	setcolor(BLACK);
	rectangle(770,0,822,31);
	setfillstyle(SOLID_FILL,BLACK);
	bar(770,0,822,31);
	readimagefile("coins.jpg",770,0,802,31);

	setcolor(BLACK);
	rectangle(910,0,1016,32);
	setfillstyle(SOLID_FILL,BLACK);
	bar(910,0,1016,32);
	
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
	settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
	outtextxy(930,32,"SCORE:");
	
	setcolor(BLACK);
	rectangle(0,0,300,31);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,300,31);

	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
	settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
	outtextxy(300,32,"Life Remaining:");

}

void MovingScore()
{
	if(Enemy_car_down_x2<=0 )
	{
		s11+=(10-levelChange);
	}
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
	settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
	sprintf(scc,"%d",s11);
	outtextxy(1016,32,scc);
	sprintf(lif,"%d",life);
	outtextxy(340,32,lif);
	if(life<10)
	{
		setcolor(BLACK);
		rectangle(300,0,320,31);
		setfillstyle(SOLID_FILL,BLACK);
		bar(300,0,320,31);
	}
}

bool CollisionDetection()
{
	if(Enemy_car_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car_down_x1 <= car.car_above_x2) || (Enemy_car_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection1()
{
	if(Enemy_car11_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car11_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car11_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car11_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car11_down_x1 <= car.car_above_x2) || (Enemy_car11_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car11_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car11_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car11_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car11_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car11_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection2()
{
	if(Enemy_car113_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car113_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car113_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car113_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car113_down_x1 <= car.car_above_x2) || (Enemy_car113_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car113_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car113_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car113_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car113_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car113_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection3()
{
	if(Enemy_car114_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car114_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car114_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car114_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car114_down_x1 <= car.car_above_x2) || (Enemy_car114_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car114_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car114_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car114_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car114_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car114_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection4()
{
	if(Enemy_car115_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car115_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car115_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car115_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car115_down_x1 <= car.car_above_x2) || (Enemy_car115_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car115_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car115_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car115_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car115_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car115_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection5()
{
	if(Enemy_car116_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car116_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car116_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car116_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car116_down_x1 <= car.car_above_x2) || (Enemy_car116_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car116_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car116_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car116_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car116_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car116_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection6()
{
	if(Enemy_car117_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car117_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car117_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car117_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car117_down_x1 <= car.car_above_x2) || (Enemy_car117_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car117_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car117_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car117_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car117_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car117_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetection7()
{
	if(Enemy_car118_above_x1 <= car.car_down_x2)
	{
		if(isBetween(car.car_down_y1,Enemy_car118_above_y1,car.car_down_y2)==true  
			||isBetween(car.car_down_y1,Enemy_car118_above_y2,car.car_down_y2)==true)
		{
			if(car.car_down_x1 <= Enemy_car118_down_x2 )
			{
				return true;
			}
		}
	}
	if((Enemy_car118_down_x1 <= car.car_above_x2) || (Enemy_car118_down_x1 <= car.car_down_x2))
	{
		if((isBetween(car.car_above_y1,Enemy_car118_down_y1,car.car_above_y2)==true 
			|| isBetween(car.car_above_y1,Enemy_car118_down_y2,car.car_above_y2)==true)
			|| (isBetween(car.car_down_y1,Enemy_car118_down_y1,car.car_down_y2)==true 
			|| (isBetween(car.car_above_y1,Enemy_car118_down_y2,car.car_above_y2)==true) ))
		{
			if(car.car_down_x1 <= Enemy_car118_down_x2 )
			{
				return true;
			}
		}
	}
	return false;
}

void gameOver()
{
	aks++;
	levelChange=0;
	sortIfHighest();
	readimagefile("Game over.jpg",0,0,1016,730);
	delay(4000);
	createMenu();
}

void writeToFile()
{
	FILE *fout = fopen("highScores.txt","a");
	fprintf(fout,userName);
	fprintf(fout,"	");
	fprintf(fout,"%d\n",s11);
	fclose(fout);
}

void CollisionResponse(int count)
{
	int i;
	s11 -= (10-levelChange-1);
	for(i=0;i<=45;i++)
	{
		car.Carr(i%16);
		delay(10);
	}
	car.Carr(0);
	if(car.car_above_y2>=382)
	{
		life--;
		car.CarrReinCarnation1();
	}
	else
	{
		life--;
		car.CarrReinCarnation2();
	}
	if(count == MAX_COLLISION_ALLOWED)
	{
		char strScore[100];
		char userScore [100];
		writeToFile();
		gameOver();
	}
}

void LevelChange()
{
	if(levelChange==0)
	{
		if(s11>=FIRST_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("Checkered20flag.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("402313.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("402314.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==1)
	{
		if(s11>=SECOND_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("l3.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("canvas-particle-2.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("canvas-particle-3.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==2)
	{
		if(s11>=THIRD_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("asdd.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("1 layer.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("eletree-grass.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==3)
	{
		if(s11>=FOURTH_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("5hhj.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("cartoon-land-4.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("cartoon-land-5.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==4)
	{
		if(s11>=FIFTH_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("65gf.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("time-animated.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("time-animated2.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==5)
	{
		if(s11>=SIXTH_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("7ghg.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("grassLAnd.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("grassLAnd11.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==6)
	{
		if(s11>=SEVENTH_LEVEL_SCORE)
		{
			ReinAllEnemy();
			cleardevice();
			readimagefile("8.jpg",0,0,1016,730);
			getch();
			delay(2000);
			cleardevice();
			readimagefile("1last.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("last.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
}

void test()
{
	cleardevice();	
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(85,50,"Please Don't Use BackSpace or Escape Button While Writting Your Name...");

	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(250,320,"Please Enter Your Name : ");
	int i = 0;
	setcolor(WHITE);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	while(true)
	{
		char ch = getch();
		if(ch == 13) 
		{
			break;
		}
		if(ch == 8)
		{
			userName[--i] = '\0';
		}
		else
		{
			userName[i++] = ch;
			userName[i] = '\0';
			outtextxy(624,320,userName);
		}
	}
	userName[i++] = ' ';
	userName[i] = '\0';
}

char user[101];
int score;

void showHighScores()
{
	vector<MyStruct> vHighScores;
	FILE *fin = fopen("highScores.txt","r");
    int row = 193;
	char destBuf[100];
	while(fscanf(fin,"%s %d",user,&score) !=-1)
	{
		printf("%s\t%d\n",user,score);
		MyStruct myStruct;
		myStruct.key = score;
		strcpy(myStruct.stringValue,user);
		vHighScores.push_back(myStruct);	
	}
	if(choice==2)
	{
		sort(vHighScores.begin(), vHighScores.end());
		int i;
		cleardevice();
		readimagefile("highscore1.jpg",0,0,1016,192);
		for(i=0;i<vHighScores.size();i++)
		{
			MyStruct tempStruct = vHighScores[i];
			setcolor(WHITE);
			settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(385,row+12,tempStruct.stringValue);
			setcolor(WHITE);
			settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(620,row+12,itoa(tempStruct.key,destBuf,10));
			row += 40;
		}	
		getch();
		fclose(fin);
		cleardevice();
	}
	delay(100);
}

int getRandomColorCode()
{
	srand(time(NULL));
	return (1 + (rand() % 15));
}

void pushRandomColorsIntoArray(int *colorArray)
{
	int i;
	for(i=1;i<6;i++){
		colorArray[i] = getRandomColorCode();
	}
}

void ReinAllEnemy()
{
	Enemy_car113_above_x1=Car_Rectangle_X1+1280; //Enemy Car
	Enemy_car113_above_y1=Car_Rectangle_Y1 -40-50;
	Enemy_car113_above_x2=Car_Rectangle_X2+1280;
	Enemy_car113_above_y2=Car_Rectangle_Y2 -40-50;
	Enemy_car113_above_color=RED;

	Enemy_car113_down_x1=D_Car_Rectangle_X1+1280;
	Enemy_car113_down_y1=D_Car_Rectangle_Y1-40-50;
	Enemy_car113_down_x2=D_Car_Rectangle_X2+1280;
	Enemy_car113_down_y2=D_Car_Rectangle_Y2-40-50;
	Enemy_car113_down_color=RED;

	Enemy_car113_leftwh_x=L_Car_Wheel_X+1280;
	Enemy_car113_leftwh_y=L_Car_Wheel_Y-40-50;
	Enemy_car113_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car113_leftwh_color1=WHITE;
	Enemy_car113_leftwh_color2=BLACK;

	Enemy_car113_rightwh_x=R_Car_Wheel_X+1280;
	Enemy_car113_rightwh_y=R_Car_Wheel_Y-40-50;
	Enemy_car113_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car113_rightwh_color1=WHITE;
	Enemy_car113_rightwh_color2=BLACK;

	Enemy_car113_left_inner_x=L_Inner_Car_Wheel_X+1280;
	Enemy_car113_left_inner_y=L_Inner_Car_Wheel_Y-40-50; 
	Enemy_car113_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car113_left_inner_color1=WHITE;
	Enemy_car113_left_inner_color2=WHITE;

	Enemy_car115_above_x1=Car_Rectangle_X1+1400; //Enemy Car
	Enemy_car115_above_y1=Car_Rectangle_Y1-40-50+330;
	Enemy_car115_above_x2=Car_Rectangle_X2+1400;
	Enemy_car115_above_y2=Car_Rectangle_Y2-40-50+330;
	Enemy_car115_above_color=RED;

	Enemy_car115_down_x1=D_Car_Rectangle_X1+1400;
	Enemy_car115_down_y1=D_Car_Rectangle_Y1-40-50+330;
	Enemy_car115_down_x2=D_Car_Rectangle_X2+1400;
	Enemy_car115_down_y2=D_Car_Rectangle_Y2-40-50+330;
	Enemy_car115_down_color=RED;

	Enemy_car115_leftwh_x=L_Car_Wheel_X+1400;
	Enemy_car115_leftwh_y=L_Car_Wheel_Y-40-50+330;
	Enemy_car115_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car115_leftwh_color1=WHITE;
	Enemy_car115_leftwh_color2=BLACK;

	Enemy_car115_rightwh_x=R_Car_Wheel_X+1400;
	Enemy_car115_rightwh_y=R_Car_Wheel_Y-40-50+330;
	Enemy_car115_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car115_rightwh_color1=WHITE;
	Enemy_car115_rightwh_color2=BLACK;

	Enemy_car115_left_inner_x=L_Inner_Car_Wheel_X+1400;
	Enemy_car115_left_inner_y=L_Inner_Car_Wheel_Y-40-50+330; 
	Enemy_car115_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car115_left_inner_color1=WHITE;
	Enemy_car115_left_inner_color2=WHITE;

	int inc1 = getRandomSign() * getRandomPositionWithinRange(1,100);
	Enemy_car117_above_x1=Car_Rectangle_X1+1200; //Enemy Car
	Enemy_car117_above_y1=Car_Rectangle_Y1+160+inc1;
	Enemy_car117_above_x2=Car_Rectangle_X2+1200;
	Enemy_car117_above_y2=Car_Rectangle_Y2+160+inc1;
	Enemy_car117_above_color=RED;

	Enemy_car117_down_x1=D_Car_Rectangle_X1+1200;
	Enemy_car117_down_y1=D_Car_Rectangle_Y1+160+inc1;
	Enemy_car117_down_x2=D_Car_Rectangle_X2+1200;
	Enemy_car117_down_y2=D_Car_Rectangle_Y2+160+inc1;
	Enemy_car117_down_color=RED;

	Enemy_car117_leftwh_x=L_Car_Wheel_X+1200;
	Enemy_car117_leftwh_y=L_Car_Wheel_Y+160+inc1;
	Enemy_car117_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car117_leftwh_color1=WHITE;
	Enemy_car117_leftwh_color2=BLACK;

	Enemy_car117_rightwh_x=R_Car_Wheel_X+1200;
	Enemy_car117_rightwh_y=R_Car_Wheel_Y+160+inc1;
	Enemy_car117_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car117_rightwh_color1=WHITE;
	Enemy_car117_rightwh_color2=BLACK;

	Enemy_car117_left_inner_x=L_Inner_Car_Wheel_X+1200;
	Enemy_car117_left_inner_y=L_Inner_Car_Wheel_Y+160+inc1; 
	Enemy_car117_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car117_left_inner_color1=WHITE;
	Enemy_car117_left_inner_color2=WHITE;

	int inc2 = getRandomSign() * getRandomPositionWithinRange(1,45);
	Enemy_car118_above_x1=Car_Rectangle_X1+1600; //Enemy Car
	Enemy_car118_above_y1=Car_Rectangle_Y1+160+inc2;
	Enemy_car118_above_x2=Car_Rectangle_X2+1600;
	Enemy_car118_above_y2=Car_Rectangle_Y2+160+inc2;
	Enemy_car118_above_color=RED;

	Enemy_car118_down_x1=D_Car_Rectangle_X1+1600;
	Enemy_car118_down_y1=D_Car_Rectangle_Y1+160+inc2;
	Enemy_car118_down_x2=D_Car_Rectangle_X2+1600;
	Enemy_car118_down_y2=D_Car_Rectangle_Y2+160+inc2;
	Enemy_car118_down_color=RED;

	Enemy_car118_leftwh_x=L_Car_Wheel_X+1600;
	Enemy_car118_leftwh_y=L_Car_Wheel_Y+160+inc2;
	Enemy_car118_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car118_leftwh_color1=WHITE;
	Enemy_car118_leftwh_color2=BLACK;

	Enemy_car118_rightwh_x=R_Car_Wheel_X+1600;
	Enemy_car118_rightwh_y=R_Car_Wheel_Y+160+inc2;
	Enemy_car118_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car118_rightwh_color1=WHITE;
	Enemy_car118_rightwh_color2=BLACK;

	Enemy_car118_left_inner_x=L_Inner_Car_Wheel_X+1600;
	Enemy_car118_left_inner_y=L_Inner_Car_Wheel_Y+160+inc2; 
	Enemy_car118_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car118_left_inner_color1=WHITE;
	Enemy_car118_left_inner_color2=WHITE;

	Enemy_car116_above_x1=Car_Rectangle_X1+1300; //Enemy Car
	Enemy_car116_above_y1=Car_Rectangle_Y1+160-140;
	Enemy_car116_above_x2=Car_Rectangle_X2+1300;
	Enemy_car116_above_y2=Car_Rectangle_Y2+160-140;
	Enemy_car116_above_color=RED;

	Enemy_car116_down_x1=D_Car_Rectangle_X1+1300;
	Enemy_car116_down_y1=D_Car_Rectangle_Y1+160-140;
	Enemy_car116_down_x2=D_Car_Rectangle_X2+1300;
	Enemy_car116_down_y2=D_Car_Rectangle_Y2+160-140;
	Enemy_car116_down_color=RED;

	Enemy_car116_leftwh_x=L_Car_Wheel_X+1300;
	Enemy_car116_leftwh_y=L_Car_Wheel_Y+160-140;
	Enemy_car116_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car116_leftwh_color1=WHITE;
	Enemy_car116_leftwh_color2=BLACK;

	Enemy_car116_rightwh_x=R_Car_Wheel_X+1300;
	Enemy_car116_rightwh_y=R_Car_Wheel_Y+160-140;
	Enemy_car116_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car116_rightwh_color1=WHITE;
	Enemy_car116_rightwh_color2=BLACK;

	Enemy_car116_left_inner_x=L_Inner_Car_Wheel_X+1300;
	Enemy_car116_left_inner_y=L_Inner_Car_Wheel_Y+160-140; 
	Enemy_car116_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car116_left_inner_color1=WHITE;
	Enemy_car116_left_inner_color2=WHITE;

	Enemy_car114_above_x1=Car_Rectangle_X1+1340; //Enemy Car
	Enemy_car114_above_y1=Car_Rectangle_Y1-40+100;
	Enemy_car114_above_x2=Car_Rectangle_X2+1340;
	Enemy_car114_above_y2=Car_Rectangle_Y2-40+100;
	Enemy_car114_above_color=RED;

	Enemy_car114_down_x1=D_Car_Rectangle_X1+1340;
	Enemy_car114_down_y1=D_Car_Rectangle_Y1-40+100;
	Enemy_car114_down_x2=D_Car_Rectangle_X2+1340;
	Enemy_car114_down_y2=D_Car_Rectangle_Y2-40+100;
	Enemy_car114_down_color=RED;
	
	Enemy_car114_leftwh_x=L_Car_Wheel_X+1340;
	Enemy_car114_leftwh_y=L_Car_Wheel_Y-40+100;
	Enemy_car114_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car114_leftwh_color1=WHITE;
	Enemy_car114_leftwh_color2=BLACK;

	Enemy_car114_rightwh_x=R_Car_Wheel_X+1340;
	Enemy_car114_rightwh_y=R_Car_Wheel_Y-40+100;
	Enemy_car114_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car114_rightwh_color1=WHITE;
 	Enemy_car114_rightwh_color2=BLACK;

	Enemy_car114_left_inner_x=L_Inner_Car_Wheel_X+1340;
 	Enemy_car114_left_inner_y=L_Inner_Car_Wheel_Y-40+100; 
 	Enemy_car114_left_inner_rad=L_Inner_Car_Wheel_Rad;
 	Enemy_car114_left_inner_color1=WHITE;
 	Enemy_car114_left_inner_color2=WHITE;

	Enemy_car11_above_x1=Car_Rectangle_X1+1100; //Enemy Car
	Enemy_car11_above_y1=Car_Rectangle_Y1+160;
	Enemy_car11_above_x2=Car_Rectangle_X2+1100;
	Enemy_car11_above_y2=Car_Rectangle_Y2+160;
	Enemy_car11_above_color=RED;

	Enemy_car11_down_x1=D_Car_Rectangle_X1+1100;
	Enemy_car11_down_y1=D_Car_Rectangle_Y1+160;
	Enemy_car11_down_x2=D_Car_Rectangle_X2+1100;
	Enemy_car11_down_y2=D_Car_Rectangle_Y2+160;
	Enemy_car11_down_color=RED;

	Enemy_car11_leftwh_x=L_Car_Wheel_X+1100;
	Enemy_car11_leftwh_y=L_Car_Wheel_Y+160;
	Enemy_car11_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car11_leftwh_color1=WHITE;
	Enemy_car11_leftwh_color2=BLACK;

	Enemy_car11_rightwh_x=R_Car_Wheel_X+1100;
	Enemy_car11_rightwh_y=R_Car_Wheel_Y+160;
	Enemy_car11_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car11_rightwh_color1=WHITE;
	Enemy_car11_rightwh_color2=BLACK;

	Enemy_car11_left_inner_x=L_Inner_Car_Wheel_X+1100;
	Enemy_car11_left_inner_y=L_Inner_Car_Wheel_Y+160; 
	Enemy_car11_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car11_left_inner_color1=WHITE;
	Enemy_car11_left_inner_color2=WHITE;
}

void choice1()
{
	int count=0,i=0,a=2,b=2,co=0;
	if(choice==1 && aks==0)
	{
		aks++;
		test();
		readimagefile("checkered-flag-vector.jpg",0,0,1016,730);
		readimagefile("ready.jpg",425,2,590,80);
		delay(1000);
		readimagefile("1.jpg",490,80,520,150);
		delay(1000);
		readimagefile("2.jpg",490,160,520,230);
		delay(1000);
		readimagefile("3.jpg",490,240,520,340);
		delay(1000);
		readimagefile("4.jpg",0,0,1016,730);
		delay(1000);
		getch();
		cleardevice();
		Upper(U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2);
		Lower(D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
		Road();
		Score();
		int colors[]={RED,RED,WHITE,WHITE,BLACK,BLACK};
		int clearColors[]={BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};
		int testColors1[]={5,5,15,15,15,15};
		int testColors2[]={15,15,15,15,9,9};
		int testColors3[]={14,14,15,15,15,15};
		int testColors4[]={6,6,6,6,15,15};
		int testColors5[]={10,10,15,15,15,15};
		int testColors6[]={12,12,15,15,15,15};
		s11=0;
		Score();
		MovingRoad(road_moving_X1,road_moving_Y1,road_moving_X2,road_moving_Y2,15);
		MovingRoad2(road2_moving_X1,road2_moving_Y1,road2_moving_X2,road2_moving_Y2,15);
		int jkk=0;
		while(true)
		{
			jkk++;
			printf("J = %d\n",jkk);
			MovingScore();
			MoveTheRoad(0,0);
			MoveTheRoad(6,15);
			if(road_moving_X2 < 0)
			{
				RoadReincarnated1();
			}
			if(road2_moving_X2 < 0)
			{
				RoadReincarnated2();
			}
			car.MovingCar(colors,0,1);
			int EnemyColors[]={a,b,YELLOW,YELLOW,YELLOW,YELLOW};
			if(s11>=525)
			{
				writeToFile();
				gameOver();
				delay(4000);
				cleardevice();
				createMenu();
			}
			if(Enemy_car_down_x2 > -1)
			{
				EnemyCar(clearColors,0);
				EnemyCar(EnemyColors,8+(levelChange));
			}
			else
			{
				srand(time(NULL));
				(a+=rand())%16+1;
				(b+=rand())%16+1;
				srand(time(NULL));
				if( (count++ +rand()) % 2 == 0)
				{
					if(Enemy_car_leftwh_y>=540)
					{
						i=0;
					}
					srand(time(NULL));
					EnemyCarReIncarnated_2(i + rand()%140);
				}
				else
				{
					if(Enemy_car_leftwh_y>=320)
					{
						i=0;
					}
					srand(time(NULL));
					EnemyCarReIncarnated_1(i + rand()%56);
				}
			}
			delay(20);
			if(levelChange==0 || levelChange==1 || levelChange==2
				|| levelChange==3 || levelChange==4 || levelChange==5 
				|| levelChange==6)
			{
				LevelChange();
			}
			bool flag = CollisionDetection();
			bool flag1 = CollisionDetection1();
			bool flag2 = CollisionDetection2();
			bool flag3 = CollisionDetection3();
			bool flag4 = CollisionDetection4();
			bool flag5 = CollisionDetection5();
			bool conflag6 = CollisionDetection6();
			bool conflag7 = CollisionDetection7();
			if(flag == true || flag1 == true || flag2 == true 
				|| flag3 == true || flag4 == true || flag5 == true
				|| conflag6 == true || conflag7 == true)
			{
				co++;
				CollisionResponse(co);
				if(co==MAX_COLLISION_ALLOWED)
				{
					co=0;
					return;
				}
			}	
			if(Enemy_car118_down_x2<0)
			{
				pushRandomColorsIntoArray(testColors2);
				con2EnemyCarReIncarnated_2();
			}
			if(Enemy_car117_down_x2<0)
			{
				pushRandomColorsIntoArray(testColors1);
				con1EnemyCarReIncarnated_2();
			}
			if(Enemy_car116_down_x2<0)
			{
				pushRandomColorsIntoArray(testColors3);
				con1EnemyCarReIncarnated_2();
			}
			if(Enemy_car115_down_x2<0)
			{
				pushRandomColorsIntoArray(testColors4);
				EnemyCar115ReIncarnated_2();
			}		
			if(Enemy_car113_down_x2<0)
			{
				pushRandomColorsIntoArray(testColors5);
				EnemyCar113ReIncarnated_2();
			}
			if(levelChange==0 || levelChange==1)
			{	
				EnemyCar118(clearColors,0);
				EnemyCar118(testColors3,10+(levelChange));
				EnemyCar117(clearColors,0);
				EnemyCar117(testColors6,10+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors2,9+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors4,12+(levelChange));
			}
			if(levelChange==2)
			{
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors4,9+(levelChange));
				EnemyCar11(clearColors,0);
				EnemyCar11(testColors1,7+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors6,11+(levelChange));
				EnemyCar116(clearColors,0);
				EnemyCar116(testColors3,10+(levelChange));
			}
			if(levelChange==3)
			{
				EnemyCar118(clearColors,0);
				EnemyCar118(testColors3,10+(levelChange));
				EnemyCar117(clearColors,0);
				EnemyCar117(testColors6,9+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors2,9+(levelChange));
				EnemyCar11(clearColors,0);
				EnemyCar11(testColors1,7+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors4,8+(levelChange));
			}
			if(levelChange==4)
			{
				EnemyCar116(clearColors,0);
				EnemyCar116(testColors3,8+(levelChange));
				EnemyCar11(clearColors,0);
				EnemyCar11(testColors2,8+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors6,10+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors1,9+(levelChange));
			}
			if(levelChange==5)
			{
				EnemyCar117(clearColors,0);
				EnemyCar117(testColors6,11+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors2,12+(levelChange));
				EnemyCar114(clearColors,0);
				EnemyCar114(testColors3,6+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors1,8+(levelChange));
			}
			if(levelChange==6)
			{	
				EnemyCar11(clearColors,0);
				EnemyCar11(testColors1,6+(levelChange));
				EnemyCar118(clearColors,0);
				EnemyCar118(testColors3,13+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors2,9+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors1,16+(levelChange));
				EnemyCar117(clearColors,0);
				EnemyCar117(testColors6,7+(levelChange));
			}
			if(levelChange==7)
			{	
				EnemyCar116(clearColors,0);
				EnemyCar116(testColors6,12+(levelChange));
				EnemyCar118(clearColors,0);
				EnemyCar118(testColors3,13+(levelChange));
				EnemyCar117(clearColors,0);
				EnemyCar117(testColors6,15+(levelChange));
				EnemyCar11(clearColors,0);
				EnemyCar11(testColors1,18+(levelChange));
				EnemyCar115(clearColors,0);
				EnemyCar115(testColors4,11+(levelChange));
				EnemyCar113(clearColors,0);
				EnemyCar113(testColors2,17+(levelChange));
			}
			if(kbhit())
			{
				int input_key=getch();
				if(input_key == 27)
				{
					exit(0);
				}
				if(input_key==72&&car.car_above_y1>=180)
				{
					count=1;
					car.MovingCar(clearColors,0,count);
					car.MovingCar(colors,10,count);
				}
				if(input_key==75 && car.car_down_x1>=0)
				{
					count=2;
					car.MovingCar(clearColors,0,count);
					car.MovingCar(colors,10,count);
				}
				if(input_key==77&&car.car_down_x2<=1010)
				{
					count=3;
					car.MovingCar(clearColors,0,count);
					car.MovingCar(colors,10,count);	
				}
				if(input_key==80 && car.car_leftwh_y<=550)
				{
					count=4;
					car.MovingCar(clearColors,0,count);
					car.MovingCar(colors,10,count);
				}
			}
		}
	}
}

void choice2()
{
	cleardevice();
	showHighScores();
}

void createMenu()
{
	int x,y;
	readimagefile("COVVER.jpg",0,0,1016,730);
	clearmouseclick(WM_LBUTTONDOWN);
	while(!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(100);
	}
	getmouseclick(WM_LBUTTONDOWN,x,y);
	
	if((x>=432&&x<=577) && (y>=341 && y<=387))
	{
		choice=1;
		choice1();
		cleardevice();
	}
	else if((x>=428&&x<=582) && (y>=431 && y<=474))
	{
		choice=2;
		choice2();
		cleardevice();
	}
	else if((x>=431&&x<=581) && (y>=517 && y<=561))
	{
		choice=3;
		cleardevice();
		readimagefile("UntitledAQ.jpg",0,0,1016,730);
		getch();
		cleardevice();
	}
	else if((x>=431&&x<=582) && (y>=599 && y<=634))
	{
		choice=4;
		cleardevice();		
		Credits();
	}
	else
	{
		createMenu();  
	}
}

void Credits()
{
	readimagefile("Untidqtled.jpg",0,0,1016,730);
	getch();
	cleardevice();
}

void INITIALIZE()
{
	initwindow(Window_X,Window_Y,"Game");
	readimagefile("fooo.jpg",0,0,1016,730);
	getch();
	cleardevice();
}

int main( )
{
    INITIALIZE();
	while(true)
	{
		createMenu();
		cleardevice();
	}
	system("pause");
	return 0;
}