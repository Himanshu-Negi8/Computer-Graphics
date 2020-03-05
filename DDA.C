#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int main()
{
	int gd=DETECT,gm,x1,y1,x2,y2,dx,dy,step,h=250,k=250;
	float x,y,xin,yin;

	printf("\nEnter 1st point: ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter 2nd point: ");
	scanf("%d%d",&x2,&y2);

	dx=x2-x1;
	dy=y2-y1;

	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);

	xin=(float)dx/step;
	yin=(float)dy/step;

	x=x1,y=y1;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	putpixel(x,y,4);
	putpixel(h+x,k-y,4);

	line(h,k,640,k);
	line(h,k,h,10);

	while(step--)
	{
		x+=xin;
		y+=yin;
		putpixel(h+floor(x+0.5),k-floor(y+0.5),3);
	}
	getch();
	closegraph();
	return 0;
}