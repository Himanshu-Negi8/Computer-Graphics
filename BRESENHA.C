#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int main()
{
	int gd=DETECT,gm,x1,y1,x2,y2,dx,dy,p,xstart,ystart,end,h=250,k=250;

	printf("\nEnter 1st point: ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter 2nd point: ");
	scanf("%d%d",&x2,&y2);

	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(x1<x2)
	{
		xstart=x1;
		ystart=y1;
		end=x2;
	}
	else
	{
		xstart=x2;
		ystart=y2;
		end=x1;
	}
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	line(h,k,600,k);
	line(h,k,h,15);
	p=2*dy-dx;

	while(xstart<end)
	{
		int x=1;
		putpixel(h+xstart,k-ystart,++x%5);
		if(p<0)
			p=p+2*dy;
		else
		{
			p=p+2*dy-2*dx;
			ystart++;
		}
		xstart++;
	}

	getch();
	closegraph();
	return 0;
}