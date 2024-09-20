#include"graphics.h"
typedef struct myCar
{
	int car_above_x1;
	int car_above_y1;
	int car_above_x2;
	int car_above_y2;
	int car_above_color;

	int car_down_x1;
	int car_down_y1;
	int car_down_x2;
	int car_down_y2;
	int car_down_color;

	int car_leftwh_x;
	int car_leftwh_y;
	int car_leftwh_rad;
	int car_leftwh_color1;
	int car_leftwh_color2;

	int car_rightwh_x;
	int car_rightwh_y;
	int car_rightwh_rad;
	int car_rightwh_color1;
	int car_rightwh_color2;

	int car_left_inner_x;
	int car_left_inner_y;
	int car_left_inner_rad;
	int car_left_inner_color1;
	int car_left_inner_color2;

	int car_right_inner_x;
	int car_right_inner_y;
	int car_right_inner_rad;
	int car_right_inner_color1;
	int car_right_inner_color2;
	
	myCar()
	{
		car_above_x1 = 85;
		car_above_y1 = 262;
		car_above_x2 = 150-17-7;
		car_above_y2 = 295-10-4;
		car_above_color = 1;

		car_down_x1 = 61;
		car_down_y1 = 305-20-5;
		car_down_x2 = 235-55-20-10;
		car_down_y2 = 345-25-10-7;
		car_down_color = 1;

		car_leftwh_x = 78;
		car_leftwh_y = 352-36-12;
		car_leftwh_rad = 9;
		car_leftwh_color1 = 0;
		car_leftwh_color2 = 15;

		car_rightwh_x = 155-16-8;
		car_rightwh_y = 352-36-12;
		car_rightwh_rad = 9;
		car_rightwh_color1 = 12;
		car_rightwh_color2 = 12;

		car_left_inner_x = 78;
		car_left_inner_y = 352-36-12;
		car_left_inner_rad = 6;
		car_left_inner_color1 = 12 ;
		car_left_inner_color2 = 12 ;

		car_right_inner_x = 155-16-8;
		car_right_inner_y = 352-36-12;
		car_right_inner_rad = 6;
		car_right_inner_color1 = 12 ;
		car_right_inner_color2 = 12 ;
	}
	
	void CarrReinCarnation1()
	{
		car_above_x1 = 85+240;
		car_above_y1 = 262-40;
		car_above_x2 = 150-17-7+240;
		car_above_y2 = 295-10-4-40;
		car_above_color = 1;

		car_down_x1 = 61+240;
		car_down_y1 = 305-20-5-40;
		car_down_x2 = 235-55-20-10+240;
		car_down_y2 = 345-25-10-7-40;
		car_down_color = 1;

		car_leftwh_x = 78+240;
		car_leftwh_y = 352-36-12-40;
		car_leftwh_rad = 9;
		car_leftwh_color1 = 0;
		car_leftwh_color2 = 15;

		car_rightwh_x = 155-16-8+240;
		car_rightwh_y = 352-36-12-40;
		car_rightwh_rad = 9;
		car_rightwh_color1 = 12;
		car_rightwh_color2 = 12;

		car_left_inner_x = 78+240;
		car_left_inner_y = 352-36-12-40;
		car_left_inner_rad = 6;
		car_left_inner_color1 = 12 ;
		car_left_inner_color2 = 12 ;

		car_right_inner_x = 155-16-8+240;
		car_right_inner_y = 352-36-12-40;
		car_right_inner_rad = 6;
		car_right_inner_color1 = 12 ;
		car_right_inner_color2 = 12 ;
	}

	void CarrReinCarnation2()
	{
		car_above_x1 = 85+130;
		car_above_y1 = 262+145+40;
		car_above_x2 = 150-17-7+130;
		car_above_y2 = 295-10-4+145+40;
		car_above_color = 1;

		car_down_x1 = 61+130;
		car_down_y1 = 305-20-5+145+40;
		car_down_x2 = 235-55-20-10+130;
		car_down_y2 = 345-25-10-7+145+40;
		car_down_color = 1;

		car_leftwh_x = 78+130;
		car_leftwh_y = 352-36-12+145+40;
		car_leftwh_rad = 9;
		car_leftwh_color1 = 0;
		car_leftwh_color2 = 15;

		car_rightwh_x = 155-16-8+130;
		car_rightwh_y = 352-36-12+145+40;
		car_rightwh_rad = 9;
		car_rightwh_color1 = 12;
		car_rightwh_color2 = 12;

		car_left_inner_x = 78+130;
		car_left_inner_y = 352-36-12+145+40;
		car_left_inner_rad = 6;
		car_left_inner_color1 = 12 ;
		car_left_inner_color2 = 12 ;

		car_right_inner_x = 155-16-8+130;
		car_right_inner_y = 352-36-12+145+40;
		car_right_inner_rad = 6;
		car_right_inner_color1 = 12 ;
		car_right_inner_color2 = 12 ;
	}

	void Carr(int color)
	{
		Above_Part_Car(car_above_x1,car_above_y1,car_above_x2,car_above_y2,color);
		Down_Part_Car(car_down_x1,car_down_y1,car_down_x2,car_down_y2,color);
		Left_Wheel_Car(car_leftwh_x,car_leftwh_y,car_leftwh_rad,color);
		Right_Wheel_Car(car_rightwh_x,car_rightwh_y,car_rightwh_rad,color);
		Left_Inner_Wheel_Car(car_left_inner_x,car_left_inner_y,car_left_inner_rad,color);
		Right_Inner_Wheel_Car(car_right_inner_x,car_right_inner_y,car_right_inner_rad,color);
	}

	void Above_Part_Car(int a,int b,int c,int d,int color)
	{
		setcolor( color); //(Above Car)
		rectangle(a,b,c,d);
		setfillstyle(SOLID_FILL,color);
		bar(a,b,c,d);
	}

	void Down_Part_Car(int a,int b,int c,int d,int color)
	{
		setcolor(color); //(Down Car)
		rectangle(a,b,c,d);
		setfillstyle(SOLID_FILL,color);
		bar(a,b,c,d);
	}

	void Left_Wheel_Car(int a,int b,int c,int color)
	{
		setcolor(color); //Left Wheel
		circle(a,b,c);
		setfillstyle(SOLID_FILL,color);
		fillellipse(a,b,c,c);
	}

	void Right_Wheel_Car(int a,int b,int c,int color)
	{	
		setcolor(color);
		circle(a,b,c); //Right Wheel
		setfillstyle(SOLID_FILL,color);
		fillellipse(a,b,c,c);
	}

	void Left_Inner_Wheel_Car(int a,int b,int c,int color)
	{
		setcolor(color); //Left Inner Wheel
		circle(a,b,c);
		setfillstyle(SOLID_FILL,color);
		fillellipse(a,b,c,c);
	}

	void Right_Inner_Wheel_Car(int a,int b,int c,int color)
	{
		setcolor(color);
		circle(a,b,c);  //Right Inner Wheel
		setfillstyle(SOLID_FILL,color);
		fillellipse(a,b,c,c);
	}

	void MovingCar(int colors[],int Speed,int count)
	{
		if(count==1)
		{
			Above_Part_Car(car_above_x1,car_above_y1-=Speed,car_above_x2,car_above_y2-=Speed,colors[0]);
			Down_Part_Car(car_down_x1,car_down_y1-=Speed,car_down_x2,car_down_y2-=Speed,colors[1]);
			Left_Wheel_Car(car_leftwh_x,car_leftwh_y-=Speed,car_leftwh_rad,colors[2]);
			Right_Wheel_Car(car_rightwh_x,car_rightwh_y-=Speed,car_rightwh_rad,colors[3]);
			Left_Inner_Wheel_Car(car_left_inner_x,car_left_inner_y-=Speed,car_left_inner_rad,colors[4]);
			Right_Inner_Wheel_Car(car_right_inner_x,car_right_inner_y-=Speed,car_right_inner_rad,colors[5]);
		}
		if(count==2)
		{
			Above_Part_Car(car_above_x1-=Speed,car_above_y1,car_above_x2-=Speed,car_above_y2,colors[0]);
			Down_Part_Car(car_down_x1-=Speed,car_down_y1,car_down_x2-=Speed,car_down_y2,colors[1]);
			Left_Wheel_Car(car_leftwh_x-=Speed,car_leftwh_y,car_leftwh_rad,colors[2]);
			Right_Wheel_Car(car_rightwh_x-=Speed,car_rightwh_y,car_rightwh_rad,colors[3]);
			Left_Inner_Wheel_Car(car_left_inner_x-=Speed,car_left_inner_y,car_left_inner_rad,colors[4]);
			Right_Inner_Wheel_Car(car_right_inner_x-=Speed,car_right_inner_y,car_right_inner_rad,colors[5]);
		}
		if(count==3)
		{
			Above_Part_Car(car_above_x1+=Speed,car_above_y1,car_above_x2+=Speed,car_above_y2,colors[0]);
			Down_Part_Car(car_down_x1+=Speed,car_down_y1,car_down_x2+=Speed,car_down_y2,colors[1]);
			Left_Wheel_Car(car_leftwh_x+=Speed,car_leftwh_y,car_leftwh_rad,colors[2]);
			Right_Wheel_Car(car_rightwh_x+=Speed,car_rightwh_y,car_rightwh_rad,colors[3]);
			Left_Inner_Wheel_Car(car_left_inner_x+=Speed,car_left_inner_y,car_left_inner_rad,colors[4]);
			Right_Inner_Wheel_Car(car_right_inner_x+=Speed,car_right_inner_y,car_right_inner_rad,colors[5]);
		}
		if(count==4)
		{
			Above_Part_Car(car_above_x1,car_above_y1+=Speed,car_above_x2,car_above_y2+=Speed,colors[0]);
			Down_Part_Car(car_down_x1,car_down_y1+=Speed,car_down_x2,car_down_y2+=Speed,colors[1]);
			Left_Wheel_Car(car_leftwh_x,car_leftwh_y+=Speed,car_leftwh_rad,colors[2]);
			Right_Wheel_Car(car_rightwh_x,car_rightwh_y+=Speed,car_rightwh_rad,colors[3]);
			Left_Inner_Wheel_Car(car_left_inner_x,car_left_inner_y+=Speed,car_left_inner_rad,colors[4]);
			Right_Inner_Wheel_Car(car_right_inner_x,car_right_inner_y+=Speed,car_right_inner_rad,colors[5]);
		}
		delay(0);
	}
};