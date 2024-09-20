#include"graphics.h"
#include<time.h>
#include<stdlib.h>
#include "Car_My.h"
#include"EnemyCars.h"
#include<vector>
#include<algorithm>
#include "mmsystem.h"
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

//for Score
int s11=0;
char scc[10];

//for Life
int life=5;
char lif[10];

// car Struct
myCar car;

// for menu
int choice;
char userName[100];

// level changing scores
#define FIRST_LEVEL_SCORE 60
#define SECOND_LEVEL_SCORE 120
#define THIRD_LEVEL_SCORE 180
#define FOURTH_LEVEL_SCORE 240
#define FIFTH_LEVEL_SCORE 290
#define SIXTH_LEVEL_SCORE 350
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