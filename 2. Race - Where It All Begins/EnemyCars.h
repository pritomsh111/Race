#include<stdio.h>
#include"graphics.h"

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

int getRandomPositionWithinRange(int,int);

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

//Enemy Car 2

int Enemy_car11_above_x1=Car_Rectangle_X1+1200; //Enemy Car
int Enemy_car11_above_y1=Car_Rectangle_Y1+160;
int Enemy_car11_above_x2=Car_Rectangle_X2+1200;
int Enemy_car11_above_y2=Car_Rectangle_Y2+160;
int Enemy_car11_above_color=RED;

int Enemy_car11_down_x1=D_Car_Rectangle_X1+1200;
int Enemy_car11_down_y1=D_Car_Rectangle_Y1+160;
int Enemy_car11_down_x2=D_Car_Rectangle_X2+1200;
int Enemy_car11_down_y2=D_Car_Rectangle_Y2+160;
int Enemy_car11_down_color=RED;

int Enemy_car11_leftwh_x=L_Car_Wheel_X+1200;
int Enemy_car11_leftwh_y=L_Car_Wheel_Y+160;
int Enemy_car11_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car11_leftwh_color1=WHITE;
int Enemy_car11_leftwh_color2=BLACK;

int Enemy_car11_rightwh_x=R_Car_Wheel_X+1200;
int Enemy_car11_rightwh_y=R_Car_Wheel_Y+160;
int Enemy_car11_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car11_rightwh_color1=WHITE;
int Enemy_car11_rightwh_color2=BLACK;

int Enemy_car11_left_inner_x=L_Inner_Car_Wheel_X+1200;
int Enemy_car11_left_inner_y=L_Inner_Car_Wheel_Y+160; 
int Enemy_car11_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car11_left_inner_color1=WHITE;
int Enemy_car11_left_inner_color2=WHITE;

//Enemy Car 3

int Enemy_car113_above_x1=Car_Rectangle_X1+1280; //Enemy Car
int Enemy_car113_above_y1=Car_Rectangle_Y1-40-50;
int Enemy_car113_above_x2=Car_Rectangle_X2+1280;
int Enemy_car113_above_y2=Car_Rectangle_Y2-40-50;
int Enemy_car113_above_color=RED;

int Enemy_car113_down_x1=D_Car_Rectangle_X1+1280;
int Enemy_car113_down_y1=D_Car_Rectangle_Y1-40-50;
int Enemy_car113_down_x2=D_Car_Rectangle_X2+1280;
int Enemy_car113_down_y2=D_Car_Rectangle_Y2-40-50;
int Enemy_car113_down_color=RED;

int Enemy_car113_leftwh_x=L_Car_Wheel_X+1280;
int Enemy_car113_leftwh_y=L_Car_Wheel_Y-40-50;
int Enemy_car113_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car113_leftwh_color1=WHITE;
int Enemy_car113_leftwh_color2=BLACK;

int Enemy_car113_rightwh_x=R_Car_Wheel_X+1280;
int Enemy_car113_rightwh_y=R_Car_Wheel_Y-40-50;
int Enemy_car113_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car113_rightwh_color1=WHITE;
int Enemy_car113_rightwh_color2=BLACK;

int Enemy_car113_left_inner_x=L_Inner_Car_Wheel_X+1280;
int Enemy_car113_left_inner_y=L_Inner_Car_Wheel_Y-40-50; 
int Enemy_car113_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car113_left_inner_color1=WHITE;
int Enemy_car113_left_inner_color2=WHITE;

//Enemy Car 4

int Enemy_car114_above_x1=Car_Rectangle_X1+1360; //Enemy Car
int Enemy_car114_above_y1=Car_Rectangle_Y1-40+100;
int Enemy_car114_above_x2=Car_Rectangle_X2+1360;
int Enemy_car114_above_y2=Car_Rectangle_Y2-40+100;
int Enemy_car114_above_color=RED;

int Enemy_car114_down_x1=D_Car_Rectangle_X1+1360;
int Enemy_car114_down_y1=D_Car_Rectangle_Y1-40+100;
int Enemy_car114_down_x2=D_Car_Rectangle_X2+1360;
int Enemy_car114_down_y2=D_Car_Rectangle_Y2-40+100;
int Enemy_car114_down_color=RED;

int Enemy_car114_leftwh_x=L_Car_Wheel_X+1360;
int Enemy_car114_leftwh_y=L_Car_Wheel_Y-40+100;
int Enemy_car114_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car114_leftwh_color1=WHITE;
int Enemy_car114_leftwh_color2=BLACK;

int Enemy_car114_rightwh_x=R_Car_Wheel_X+1360;
int Enemy_car114_rightwh_y=R_Car_Wheel_Y-40+100;
int Enemy_car114_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car114_rightwh_color1=WHITE;
int Enemy_car114_rightwh_color2=BLACK;

int Enemy_car114_left_inner_x=L_Inner_Car_Wheel_X+1360;
int Enemy_car114_left_inner_y=L_Inner_Car_Wheel_Y-40+100; 
int Enemy_car114_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car114_left_inner_color1=WHITE;
int Enemy_car114_left_inner_color2=WHITE;


//Enemy Car 5

int Enemy_car115_above_x1=Car_Rectangle_X1+1430; //Enemy Car
int Enemy_car115_above_y1=Car_Rectangle_Y1-40-50+330;
int Enemy_car115_above_x2=Car_Rectangle_X2+1430;
int Enemy_car115_above_y2=Car_Rectangle_Y2-40-50+330;
int Enemy_car115_above_color=RED;

int Enemy_car115_down_x1=D_Car_Rectangle_X1+1430;
int Enemy_car115_down_y1=D_Car_Rectangle_Y1-40-50+330;
int Enemy_car115_down_x2=D_Car_Rectangle_X2+1430;
int Enemy_car115_down_y2=D_Car_Rectangle_Y2-40-50+330;
int Enemy_car115_down_color=RED;

int Enemy_car115_leftwh_x=L_Car_Wheel_X+1430;
int Enemy_car115_leftwh_y=L_Car_Wheel_Y-40-50+330;
int Enemy_car115_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car115_leftwh_color1=WHITE;
int Enemy_car115_leftwh_color2=BLACK;

int Enemy_car115_rightwh_x=R_Car_Wheel_X+1430;
int Enemy_car115_rightwh_y=R_Car_Wheel_Y-40-50+330;
int Enemy_car115_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car115_rightwh_color1=WHITE;
int Enemy_car115_rightwh_color2=BLACK;

int Enemy_car115_left_inner_x=L_Inner_Car_Wheel_X+1430;
int Enemy_car115_left_inner_y=L_Inner_Car_Wheel_Y-40-50+330; 
int Enemy_car115_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car115_left_inner_color1=WHITE;
int Enemy_car115_left_inner_color2=WHITE;

//Enemy Car 6

int Enemy_car116_above_x1=Car_Rectangle_X1+1390; //Enemy Car
int Enemy_car116_above_y1=Car_Rectangle_Y1+160-140;
int Enemy_car116_above_x2=Car_Rectangle_X2+1390;
int Enemy_car116_above_y2=Car_Rectangle_Y2+160-140;
int Enemy_car116_above_color=RED;

int Enemy_car116_down_x1=D_Car_Rectangle_X1+1390;
int Enemy_car116_down_y1=D_Car_Rectangle_Y1+160-140;
int Enemy_car116_down_x2=D_Car_Rectangle_X2+1390;
int Enemy_car116_down_y2=D_Car_Rectangle_Y2+160-140;
int Enemy_car116_down_color=RED;

int Enemy_car116_leftwh_x=L_Car_Wheel_X+1390;
int Enemy_car116_leftwh_y=L_Car_Wheel_Y+160-140;
int Enemy_car116_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car116_leftwh_color1=WHITE;
int Enemy_car116_leftwh_color2=BLACK;

int Enemy_car116_rightwh_x=R_Car_Wheel_X+1390;
int Enemy_car116_rightwh_y=R_Car_Wheel_Y+160-140;
int Enemy_car116_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car116_rightwh_color1=WHITE;
int Enemy_car116_rightwh_color2=BLACK;

int Enemy_car116_left_inner_x=L_Inner_Car_Wheel_X+1390;
int Enemy_car116_left_inner_y=L_Inner_Car_Wheel_Y+160-140; 
int Enemy_car116_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car116_left_inner_color1=WHITE;
int Enemy_car116_left_inner_color2=WHITE;

// Constant Enemy Cars 1

int Enemy_car117_above_x1=Car_Rectangle_X1+1220; //Enemy Car
int Enemy_car117_above_y1=Car_Rectangle_Y1+160-105;
int Enemy_car117_above_x2=Car_Rectangle_X2+1220;
int Enemy_car117_above_y2=Car_Rectangle_Y2+160-105;
int Enemy_car117_above_color=RED;

int Enemy_car117_down_x1=D_Car_Rectangle_X1+1220;
int Enemy_car117_down_y1=D_Car_Rectangle_Y1+160-105;
int Enemy_car117_down_x2=D_Car_Rectangle_X2+1220;
int Enemy_car117_down_y2=D_Car_Rectangle_Y2+160-105;
int Enemy_car117_down_color=RED;

int Enemy_car117_leftwh_x=L_Car_Wheel_X+1220;
int Enemy_car117_leftwh_y=L_Car_Wheel_Y+160-105;
int Enemy_car117_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car117_leftwh_color1=WHITE;
int Enemy_car117_leftwh_color2=BLACK;

int Enemy_car117_rightwh_x=R_Car_Wheel_X+1220;
int Enemy_car117_rightwh_y=R_Car_Wheel_Y+160-105;
int Enemy_car117_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car117_rightwh_color1=WHITE;
int Enemy_car117_rightwh_color2=BLACK;

int Enemy_car117_left_inner_x=L_Inner_Car_Wheel_X+1220;
int Enemy_car117_left_inner_y=L_Inner_Car_Wheel_Y+160-105; 
int Enemy_car117_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car117_left_inner_color1=WHITE;
int Enemy_car117_left_inner_color2=WHITE;

// Constant Enemy Cars 2

int Enemy_car118_above_x1=Car_Rectangle_X1+1540; //Enemy Car
int Enemy_car118_above_y1=Car_Rectangle_Y1+160-56;
int Enemy_car118_above_x2=Car_Rectangle_X2+1540;
int Enemy_car118_above_y2=Car_Rectangle_Y2+160-56;
int Enemy_car118_above_color=RED;

int Enemy_car118_down_x1=D_Car_Rectangle_X1+1540;
int Enemy_car118_down_y1=D_Car_Rectangle_Y1+160-56;
int Enemy_car118_down_x2=D_Car_Rectangle_X2+1540;
int Enemy_car118_down_y2=D_Car_Rectangle_Y2+160-56;
int Enemy_car118_down_color=RED;

int Enemy_car118_leftwh_x=L_Car_Wheel_X+1540;
int Enemy_car118_leftwh_y=L_Car_Wheel_Y+160-56;
int Enemy_car118_leftwh_rad=L_Car_Wheel_Rad;
int Enemy_car118_leftwh_color1=WHITE;
int Enemy_car118_leftwh_color2=BLACK;

int Enemy_car118_rightwh_x=R_Car_Wheel_X+1540;
int Enemy_car118_rightwh_y=R_Car_Wheel_Y+160-56;
int Enemy_car118_rightwh_rad=R_Car_Wheel_Rad;
int Enemy_car118_rightwh_color1=WHITE;
int Enemy_car118_rightwh_color2=BLACK;

int Enemy_car118_left_inner_x=L_Inner_Car_Wheel_X+1540;
int Enemy_car118_left_inner_y=L_Inner_Car_Wheel_Y+160-56; 
int Enemy_car118_left_inner_rad=L_Inner_Car_Wheel_Rad;
int Enemy_car118_left_inner_color1=WHITE;
int Enemy_car118_left_inner_color2=WHITE;

int getRandomPositionWithinRange(int a,int b){
	srand(time(NULL));
	return a + rand()% (b-a);
}

int getRandomSign(){
	srand(time(NULL));
	if(rand()%2 == 0)
		return 1;
	return -1;
}

void con1EnemyCarReIncarnated_2()
{
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
}

void con2EnemyCarReIncarnated_2()
{
	int inc1 = getRandomSign() * getRandomPositionWithinRange(1,45);
	Enemy_car118_above_x1=Car_Rectangle_X1+1600; //Enemy Car
	Enemy_car118_above_y1=Car_Rectangle_Y1+160+inc1;
	Enemy_car118_above_x2=Car_Rectangle_X2+1600;
	Enemy_car118_above_y2=Car_Rectangle_Y2+160+inc1;
	Enemy_car118_above_color=RED;

	Enemy_car118_down_x1=D_Car_Rectangle_X1+1600;
	Enemy_car118_down_y1=D_Car_Rectangle_Y1+160+inc1;
	Enemy_car118_down_x2=D_Car_Rectangle_X2+1600;
	Enemy_car118_down_y2=D_Car_Rectangle_Y2+160+inc1;
	Enemy_car118_down_color=RED;

	Enemy_car118_leftwh_x=L_Car_Wheel_X+1600;
	Enemy_car118_leftwh_y=L_Car_Wheel_Y+160+inc1;
	Enemy_car118_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car118_leftwh_color1=WHITE;
	Enemy_car118_leftwh_color2=BLACK;

	Enemy_car118_rightwh_x=R_Car_Wheel_X+1600;
	Enemy_car118_rightwh_y=R_Car_Wheel_Y+160+inc1;
	Enemy_car118_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car118_rightwh_color1=WHITE;
	Enemy_car118_rightwh_color2=BLACK;

	Enemy_car118_left_inner_x=L_Inner_Car_Wheel_X+1600;
	Enemy_car118_left_inner_y=L_Inner_Car_Wheel_Y+160+inc1; 
	Enemy_car118_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car118_left_inner_color1=WHITE;
	Enemy_car118_left_inner_color2=WHITE;
}

void EnemyCar115ReIncarnated_2()
{
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
}

void EnemyCar113ReIncarnated_2()
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
}

void EnemyCar11ReIncarnated_2()
{
	Enemy_car11_above_x1=Car_Rectangle_X1+1200; //Enemy Car
	Enemy_car11_above_y1=Car_Rectangle_Y1+160;
	Enemy_car11_above_x2=Car_Rectangle_X2+1200;
	Enemy_car11_above_y2=Car_Rectangle_Y2+160;
	Enemy_car11_above_color=RED;

	Enemy_car11_down_x1=D_Car_Rectangle_X1+1200;
	Enemy_car11_down_y1=D_Car_Rectangle_Y1+160;
	Enemy_car11_down_x2=D_Car_Rectangle_X2+1200;
	Enemy_car11_down_y2=D_Car_Rectangle_Y2+160;
	Enemy_car11_down_color=RED;

	Enemy_car11_leftwh_x=L_Car_Wheel_X+1200;
	Enemy_car11_leftwh_y=L_Car_Wheel_Y+160;
	Enemy_car11_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car11_leftwh_color1=WHITE;
	Enemy_car11_leftwh_color2=BLACK;

	Enemy_car11_rightwh_x=R_Car_Wheel_X+1200;
	Enemy_car11_rightwh_y=R_Car_Wheel_Y+160;
	Enemy_car11_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car11_rightwh_color1=WHITE;
	Enemy_car11_rightwh_color2=BLACK;

	Enemy_car11_left_inner_x=L_Inner_Car_Wheel_X+1200;
	Enemy_car11_left_inner_y=L_Inner_Car_Wheel_Y+160; 
	Enemy_car11_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car11_left_inner_color1=WHITE;
	Enemy_car11_left_inner_color2=WHITE;
}

void EnemyCar114ReIncarnated_2()
{
	Enemy_car114_above_x1=Car_Rectangle_X1+1360; //Enemy Car
	Enemy_car114_above_y1=Car_Rectangle_Y1-40+100;
	Enemy_car114_above_x2=Car_Rectangle_X2+1360;
	Enemy_car114_above_y2=Car_Rectangle_Y2-40+100;
	Enemy_car114_above_color=RED;

	Enemy_car114_down_x1=D_Car_Rectangle_X1+1360;
	Enemy_car114_down_y1=D_Car_Rectangle_Y1-40+100;
	Enemy_car114_down_x2=D_Car_Rectangle_X2+1360;
	Enemy_car114_down_y2=D_Car_Rectangle_Y2-40+100;
	Enemy_car114_down_color=RED;

	Enemy_car114_leftwh_x=L_Car_Wheel_X+1360;
	Enemy_car114_leftwh_y=L_Car_Wheel_Y-40+100;
	Enemy_car114_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car114_leftwh_color1=WHITE;
	Enemy_car114_leftwh_color2=BLACK;

	Enemy_car114_rightwh_x=R_Car_Wheel_X+1360;
	Enemy_car114_rightwh_y=R_Car_Wheel_Y-40+100;
	Enemy_car114_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car114_rightwh_color1=WHITE;
	Enemy_car114_rightwh_color2=BLACK;

	Enemy_car114_left_inner_x=L_Inner_Car_Wheel_X+1360;
	Enemy_car114_left_inner_y=L_Inner_Car_Wheel_Y-40+100; 
	Enemy_car114_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car114_left_inner_color1=WHITE;
	Enemy_car114_left_inner_color2=WHITE;
}

void EnemyCar116ReIncarnated_2()
{
	Enemy_car116_above_x1=Car_Rectangle_X1+1390; //Enemy Car
	Enemy_car116_above_y1=Car_Rectangle_Y1+160-140;
	Enemy_car116_above_x2=Car_Rectangle_X2+1390;
	Enemy_car116_above_y2=Car_Rectangle_Y2+160-140;
	Enemy_car116_above_color=RED;

	Enemy_car116_down_x1=D_Car_Rectangle_X1+1390;
	Enemy_car116_down_y1=D_Car_Rectangle_Y1+160-140;
	Enemy_car116_down_x2=D_Car_Rectangle_X2+1390;
	Enemy_car116_down_y2=D_Car_Rectangle_Y2+160-140;
	Enemy_car116_down_color=RED;

	Enemy_car116_leftwh_x=L_Car_Wheel_X+1390;
	Enemy_car116_leftwh_y=L_Car_Wheel_Y+160-140;
	Enemy_car116_leftwh_rad=L_Car_Wheel_Rad;
	Enemy_car116_leftwh_color1=WHITE;
	Enemy_car116_leftwh_color2=BLACK;

	Enemy_car116_rightwh_x=R_Car_Wheel_X+1390;
	Enemy_car116_rightwh_y=R_Car_Wheel_Y+160-140;
	Enemy_car116_rightwh_rad=R_Car_Wheel_Rad;
	Enemy_car116_rightwh_color1=WHITE;
	Enemy_car116_rightwh_color2=BLACK;

	Enemy_car116_left_inner_x=L_Inner_Car_Wheel_X+1390;
	Enemy_car116_left_inner_y=L_Inner_Car_Wheel_Y+160-140; 
	Enemy_car116_left_inner_rad=L_Inner_Car_Wheel_Rad;
	Enemy_car116_left_inner_color1=WHITE;
	Enemy_car116_left_inner_color2=WHITE;
}