#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int main()
{
	int gd=DETECT,gm,xc,yc,x,y,r;
	float p;

	printf("\nEnter centre of circle: ");
	scanf("%d%d",&xc,&yc);
	printf("\nEnter radius: ");
	scanf("%d",&r);

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	p=5/4-r;
	x=0;
	y=r;
	line(0,yc,640,yc);
	line(xc,0,xc,400);
	while(x<=y)
	{
		if(p<0)
			p=p+2*x+3;
		else
		{
			p=p+2*(x-y)+5;
			y=y-1;
		}
		x=x+1;
		putpixel(xc+x,yc-y,3);
		putpixel(xc+y,yc-x,3);
		putpixel(xc+y,yc+x,3);
		putpixel(xc+x,yc+y,3);
		putpixel(xc-x,yc+y,3);
		putpixel(xc-y,yc+x,3);
		putpixel(xc-y,yc-x,3);
		putpixel(xc-x,yc-y,3);
	}
	getch();
	closegraph();
	return 0;
}