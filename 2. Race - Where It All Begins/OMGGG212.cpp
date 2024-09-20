#include"graphics.h"
#include<time.h>
#include<stdlib.h>
#include "Car_My.h"
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

#define Road_X1 0  //Not So Importnat
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

#define Car_Rectangle_X1 85 //Above Car
#define Car_Rectangle_Y1 262
#define Car_Rectangle_X2 150-17-7
#define Car_Rectangle_Y2 295-10-4

int car_above_x1=Car_Rectangle_X1; //Variable For The Car
int car_above_y1=Car_Rectangle_Y1;
int car_above_x2=Car_Rectangle_X2;
int car_above_y2=Car_Rectangle_Y2;
int car_above_color=RED;

#define D_Car_Rectangle_X1 61 //Down Car
#define D_Car_Rectangle_Y1 305-20-5
#define D_Car_Rectangle_X2 235-55-20-12
#define D_Car_Rectangle_Y2 345-25-10-7

int car_down_x1=D_Car_Rectangle_X1;  //Variable For The Car
int car_down_y1=D_Car_Rectangle_Y1;
int car_down_x2=D_Car_Rectangle_X2;
int car_down_y2=D_Car_Rectangle_Y2;
int car_down_color=RED;

#define L_Car_Wheel_X 78 //Left Wheel
#define L_Car_Wheel_Y 352-36-12
#define L_Car_Wheel_Rad 9

int car_leftwh_x=L_Car_Wheel_X; //Variable For The Car
int car_leftwh_y=L_Car_Wheel_Y;
int car_leftwh_rad=L_Car_Wheel_Rad;
int car_leftwh_color1=WHITE;
int car_leftwh_color2=BLACK;

#define R_Car_Wheel_X 155-16-8 //Right Wheel
#define R_Car_Wheel_Y 352-36-12
#define R_Car_Wheel_Rad 9

int car_rightwh_x=R_Car_Wheel_X; //Variable For The Car
int car_rightwh_y=R_Car_Wheel_Y;
int car_rightwh_rad=R_Car_Wheel_Rad;
int car_rightwh_color1=WHITE;
int car_rightwh_color2=BLACK;

#define L_Inner_Car_Wheel_X 78
#define L_Inner_Car_Wheel_Y 352-36-12
#define L_Inner_Car_Wheel_Rad 6

int car_left_inner_x=L_Inner_Car_Wheel_X; //Variable For The Car
int car_left_inner_y=L_Inner_Car_Wheel_Y; 
int car_left_inner_rad=L_Inner_Car_Wheel_Rad;
int car_left_inner_color1=WHITE;
int car_left_inner_color2=WHITE;

#define R_Inner_Car_Wheel_X 155-16-8
#define R_Inner_Car_Wheel_Y 352-36-12
#define R_Inner_Car_Wheel_Rad 6

int car_right_inner_x=R_Inner_Car_Wheel_X; //Variable For The Car
int car_right_inner_y=R_Inner_Car_Wheel_Y;
int car_right_inner_rad=R_Inner_Car_Wheel_Rad;
int car_right_inner_color1=WHITE;
int car_right_inner_color2=WHITE;

// Enemy Car(s)
int Enemy_car_above_x1=Car_Rectangle_X1+1000; //Enemy Car
int Enemy_car_above_y1=Car_Rectangle_Y1-50;
int Enemy_car_above_x2=Car_Rectangle_X2+1000;
int Enemy_car_above_y2=Car_Rectangle_Y2-50;
int Enemy_car_above_color=RED;

int Enemy_car_down_x1=D_Car_Rectangle_X1+1000;
int Enemy_car_down_y1=D_Car_Rectangle_Y1-50;
int Enemy_car_down_x2=D_Car_Rectangle_X2+1000;
int Enemy_car_down_y2=D_Car_Rectangle_Y2-50;
int Enemy_car_down_color=RED;

int Enemy_car_leftwh_x=L_Car_Wheel_X+1000;
int Enemy_car_leftwh_y=L_Car_Wheel_Y-50;
int Enemy_car_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car_leftwh_color1=WHITE;
int Enemy_car_leftwh_color2=BLACK;

int Enemy_car_rightwh_x=R_Car_Wheel_X+1000;
int Enemy_car_rightwh_y=R_Car_Wheel_Y-50;
int Enemy_car_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car_rightwh_color1=WHITE;
int Enemy_car_rightwh_color2=BLACK;

int Enemy_car_left_inner_x=L_Inner_Car_Wheel_X+1000;
int Enemy_car_left_inner_y=L_Inner_Car_Wheel_Y-50; 
int Enemy_car_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car_left_inner_color1=WHITE;
int Enemy_car_left_inner_color2=WHITE;

int Enemy_car_right_inner_x=R_Inner_Car_Wheel_X+1000; //Enemy Car Vaiables End
int Enemy_car_right_inner_y=R_Inner_Car_Wheel_Y-50;
int Enemy_car_right_inner_rad=R_Inner_Car_Wheel_Rad;
int Enemy_car_right_inner_color1=WHITE;
int Enemy_car_right_inner_color2=WHITE;

//For Bhoot 1
#define bhootX1 990+110
#define bhootY1 170
#define bhootX2 1046+110
#define bhootY2 240

int bhootx1=bhootX1;
int bhooty1=bhootY1;
int bhootx2=bhootX2;
int bhooty2=bhootY2;

//For Bhoot 2
#define bhoot2X1 990+40
#define bhoot2Y1 485
#define bhoot2X2 1046+40
#define bhoot2Y2 555

int bhoot2x1=bhoot2X1;
int bhoot2y1=bhoot2Y1;
int bhoot2x2=bhoot2X2;
int bhoot2y2=bhoot2Y2;

//for Level(s)
int levelChange=0;
int levelChange1=2;
int levelChange2=4;
int levelChange3=6;
int levelChange4=8;

//for Score
int s11=0;
char scc[10];

// car Struct
myCar car;

// for menu
int choice;
char userName[100];

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

//Celebration
int max=-1;

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

void Restart()
{
	myCar();
	Enemy_car_above_x1=Car_Rectangle_X1+1000; //Enemy Car
	Enemy_car_above_y1=Car_Rectangle_Y1-50;
	Enemy_car_above_x2=Car_Rectangle_X2+1000;
	Enemy_car_above_y2=Car_Rectangle_Y2-50;
	Enemy_car_above_color=RED;

	Enemy_car_down_x1=D_Car_Rectangle_X1+1000;
	Enemy_car_down_y1=D_Car_Rectangle_Y1-50;
	Enemy_car_down_x2=D_Car_Rectangle_X2+1000;
	Enemy_car_down_y2=D_Car_Rectangle_Y2-50;
	Enemy_car_down_color=RED;

	Enemy_car_leftwh_x=L_Car_Wheel_X+1000;
	Enemy_car_leftwh_y=L_Car_Wheel_Y-50;
	Enemy_car_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car_leftwh_color1=WHITE;
	Enemy_car_leftwh_color2=BLACK;

	Enemy_car_rightwh_x=R_Car_Wheel_X+1000;
	Enemy_car_rightwh_y=R_Car_Wheel_Y-50;
	Enemy_car_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car_rightwh_color1=WHITE;
	Enemy_car_rightwh_color2=BLACK;

	Enemy_car_left_inner_x=L_Inner_Car_Wheel_X+1000;
	Enemy_car_left_inner_y=L_Inner_Car_Wheel_Y-50; 
	Enemy_car_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car_left_inner_color1=WHITE;
	Enemy_car_left_inner_color2=WHITE;

	Enemy_car_right_inner_x=R_Inner_Car_Wheel_X+1000; //Enemy Car Vaiables End
	Enemy_car_right_inner_y=R_Inner_Car_Wheel_Y-50;
	Enemy_car_right_inner_rad=R_Inner_Car_Wheel_Rad;
	Enemy_car_right_inner_color1=WHITE;
	Enemy_car_right_inner_color2=WHITE;
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

void BhootReincarnated()
{
	bhootx1=bhootX1;
	bhooty1=bhootY1;
	bhootx2=bhootX2;
	bhooty2=bhootY2;

	bhoot2x1=bhoot2X1;
	bhoot2y1=bhoot2Y1;
	bhoot2x2=bhoot2X2;
	bhoot2y2=bhoot2Y2;
}

void Bhoot1()
{
	readimagefile("Bhootd.jpg",--bhootx1,bhooty1,--bhootx2,bhooty2);
	readimagefile("Bhootded.jpg",--bhootx1+56,bhooty1,--bhootx2+56,bhooty2);
	if(bhootx1==car.car_above_x2 || bhootx1==car.car_down_x2)
	{
		if((bhooty1<=car.car_above_y1 && bhooty2>=car.car_above_y1)
			||(bhooty1<=car.car_down_y1 && bhooty2>=car.car_down_y1))
		{
			setcolor(WHITE);
			settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
			settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
			sprintf(scc,"%d",s11-=10);
			outtextxy(1016,32,scc);
		}
	}
}

void Bhoot2()
{
	readimagefile("Bhootd.jpg",--bhoot2x1,bhoot2y1,--bhoot2x2,bhoot2y2);
	readimagefile("Bhootded.jpg",--bhoot2x1+56,bhoot2y1,--bhoot2x2+56,bhoot2y2);
	if(bhoot2x1==car.car_above_x2 || bhoot2x1==car.car_down_x2)
	{
		if(bhoot2y1<=car.car_down_y1 && bhoot2y2>=car.car_down_y1)
		{
			setcolor(WHITE);
			settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
			settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
			sprintf(scc,"%d",s11-=10);
			outtextxy(1016,32,scc);
		}
	}
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
}

void MovingScore()
{
	if(Enemy_car_down_x2<=0 && Enemy_car_down_x2>=-5)
	{
		s11+=10;
	}
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,15);
	settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
	sprintf(scc,"%d",s11);
	outtextxy(1016,32,scc);
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

void gameOver()
{
	levelChange=0;
	sortIfHighest();
	readimagefile("Game over.jpg",0,0,1016,730);
	delay(1000);
	cleardevice();
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
	for(i=0;i<=15;i++)
	{
		car.Carr(i%16);
		delay(10);
	}
	car.Carr(0);
	if(car.car_above_y2>=382)
	{
		car.CarrReinCarnation1();
	}
	else
	{
		car.CarrReinCarnation2();
	}
	if(count==8)
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
		if(s11>=50)
		{
			cleardevice();
			readimagefile("Checkered20flag.jpg",0,0,1016,730);
			getch();
			delay(1000);
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
		if(s11>=100)
		{
			cleardevice();
			readimagefile("l3.jpg",0,0,1016,730);
			getch();
			delay(1000);
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
		if(s11>=150)
		{
			cleardevice();
			readimagefile("asdd.jpg",0,0,1016,730);
			getch();
			delay(1000);
			cleardevice();
			readimagefile("gga2.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
			readimagefile("gga3.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2);
			Score();
			Road();
			levelChange++;
		}
	}
	if(levelChange==3)
	{
		if(s11>=200)
		{
			cleardevice();
			readimagefile("5hhj.jpg",0,0,1016,730);
			getch();
			delay(1000);
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
		if(s11>=250)
		{
			cleardevice();
			readimagefile("65gf.jpg",0,0,1016,730);
			getch();
			delay(1000);
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
		if(s11>=300)
		{
			cleardevice();
			readimagefile("7ghg.jpg",0,0,1016,730);
			getch();
			delay(1000);
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
		if(s11>=350)
		{
			cleardevice();
			readimagefile("8.jpg",0,0,1016,730);
			getch();
			delay(1000);
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

void choice1()
{
	int count=0,i=0,a=2,b=2,co=0;
	if(choice==1)
	{
		test();
		readimagefile("checkered-flag-vector.jpg",0,0,1016,730);
		readimagefile("ready.jpg",420,2,590,80);
		delay(1000);
		readimagefile("1.jpg",487,80,520,150);
		delay(1000);
		readimagefile("2.jpg",487,160,520,230);
		delay(1000);
		readimagefile("3.jpg",487,240,520,340);
		delay(1000);
		readimagefile("4.jpg",0,0,1016,730);
		delay(1000);
		getch();
		cleardevice();

		Score();
		readimagefile("1st level.jpg",U_Grass_X1,U_Grass_Y1,U_Grass_X2,U_Grass_Y2); //Upper (U_Grass)
		readimagefile("1st level2.jpg",D_Grass_X1,D_Grass_Y1,D_Grass_X2,D_Grass_Y2); //Upper (U_Grass)
		Road();
		int colors[]={RED,RED,WHITE,WHITE,BLACK,BLACK};
		int clearColors[]={BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};
		int testColors[]={RED,GREEN,BLUE,YELLOW,WHITE,GREEN};
		s11=0;
		Score();
		BhootReincarnated();
		while(true)
		{
			MovingScore();
			if(levelChange==0 || levelChange==4 || levelChange==6 || levelChange==7 || levelChange==8 )
			{
				if(s11==250 || s11==350|| s11==400|| s11==450)
				{
					BhootReincarnated();
				}
			}
			
			Bhoot1();
			Bhoot2();

			MoveTheRoad(0,0);
			MoveTheRoad(5,15);
		
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
			if(Enemy_car_down_x2 > -1)
			{
				EnemyCar(clearColors,0);
				EnemyCar(EnemyColors,8);
			}
			else
			{
				srand(time(NULL));
				(a+=rand())%14;
				(b+=rand())%14;
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
					if(Enemy_car_leftwh_y>=310)
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
			if(flag == true)
			{
				co++;
				CollisionResponse(co);
				if(co==8)
				{
					co=0;
					Restart();
					return;
				}
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
	delay(50);
}

void Credits()
{
	readimagefile("Untidqtled.jpg",0,0,1016,730);
	getch();
}

int main( )
{
    initwindow(Window_X,Window_Y,"Game");
	while(true)
	{
		createMenu();
		cleardevice();
	}
	system("pause");
	return 0;
}