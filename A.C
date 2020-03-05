#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	putpixel(200,300,4);
	circle(200,100,50);
	line(50,150,300,220);
	getch();
	closegraph();
	return 0;
}