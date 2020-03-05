#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int main()
{
	int gd=DETECT,gm,xc,yc,x,y,r;
	int p;

	printf("\nEnter centre of circle: ");
	scanf("%d%d",&xc,&yc);
	printf("\nEnter radius: ");
	scanf("%d",&r);

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	p=3-2*r;
	x=0;
	y=r;
	line(xc,yc,640,yc);
	line(xc,yc,xc,10);
	while(x<=y)
	{
		if(p<0)
			p=p+4*x+6;
		else
		{
			p=p+4*(x-y)+10;
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