#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<stdio.h> 
#include<dos.h> 

#define Radius 100
#define CalLenMax 10
#define CalLenMin 5
#define Pi 3.141592654
#define HouL 40
#define MinL 55
#define SecL 70

double centerx, centery, hourhandx, hourhandy, minhandx, minhandy, sechandx, sechandy, oldsec = 0;
char time[32];
double anglehour, anglemin, anglesec;
struct time t; 

void initial();
void drawClockInterface();
void drawCalibration();
void drawHand();
void destruct();
void transformtime();
void timetostring();
void move();

void initial(){
	int gdriver = DETECT, gmode;
	initgraph( &gdriver, &gmode, "C:\\Program Files\\CLanguage" ); /*设置图形驱动及显示模式*/
	centerx = getmaxx() / 2;
	centery = getmaxy() / 2;
	hourhandx = hourhandy = 0;
	minhandx = minhandy = 0;
	sechandx = sechandy = 0;
	oldsec = 0;
	time[0] = '\0';
	anglehour = anglemin = anglesec = 0;
}

void drawClockInterface(){
	cleardevice();
	circle( centerx, centery, Radius );
	drawCalibration();
	drawHand();

}

void drawCalibration(){
	int i, j, x, y, l;
	double angle;
	for( i = 1; i < 61; i ++ ){
		angle = 6 * i * Pi / 180;
		x = centerx + Radius * sin( angle );
		y = centery - Radius * cos( angle );
		if( i % 5 == 0 )
			l = CalLenMax;
		else
			l = CalLenMin;
		line( x, y, x - l * sin( angle ), y + l * cos( angle ) );
	}
}

void drawHand(){
	line( centerx, centery, hourhandx, hourhandy );
	line( centerx, centery, minhandx, minhandy );
	line( centerx, centery, sechandx, sechandy );
}

void destruct(){
	closegraph();
}

void timetostring(){
	int s, i = 0;
	
	s = t.ti_hour / 10;
	time[i++] = 48 + s;
	s = t.ti_hour % 10;
	time[i++] = 48 + s;
	time[i++] = ':';
	
	s = t.ti_min / 10;
	time[i++] = 48 + s;
	s = t.ti_min % 10;
	time[i++] = 48 + s;
	time[i++] = ':';
	
	s = t.ti_sec / 10;
	time[i++] = 48 + s;
	s = t.ti_sec % 10;
	time[i++] = 48 + s;
	time[i++] = '\0';
}

void transformtime(){
	oldsec = t.ti_sec;
	anglesec = t.ti_sec * 6 * Pi / 180; 
	sechandx = centerx + SecL * sin( anglesec );
	sechandy = centery - SecL * cos( anglesec );
	anglemin = t.ti_min * 6 * Pi / 180 + anglesec / 60;
	minhandx = centerx + MinL * sin( anglemin );
	minhandy = centery - MinL * cos( anglemin );
	anglehour = t.ti_hour * 30 * Pi / 180 + anglemin / 60;
	hourhandx = centerx + HouL * sin( anglehour );
	hourhandy = centery - HouL * cos( anglehour );
}

void move(){
	while( 1 ){
		gettime(&t);
		if( abs( t.ti_sec - oldsec ) < 1 )
			continue;
			
		transformtime();
		drawClockInterface();
		timetostring( t.ti_hour, t.ti_min, t.ti_sec );
		outtextxy( centerx - 25, centery + Radius + 20, time );
    }
}

void main(){
    initial();
    move();
    getch();
    destruct();
}

