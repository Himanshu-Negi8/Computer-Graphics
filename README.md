

# Mid point circle generating algorithm.


```c
#include <stdio.h>


#include<conio.h>
#include<graphics.h>

int main(){

    int gd=DETECT,gm;
    int xc,yc,x,p,y,r;
    initgraph(&gd,&gm,"C:\\TC\\BGI");


    printf("Enter the coordinates \n");
    scanf("%d%d",&xc,&yc);

    printf("Enter the radius of the cricle\n");
    scanf("%d",&r);


//    intial  decision paramter p

    p=(5/4)-r;   // incase of Breshnam's  p=3-2*r
    x=0;
    y=r;

    while (x<=y){
        if(p<0){
            x+=1;
            p=p+2*x+3;       //p+4*x+6;
        }
        else{
          x+=1;
          y-=1;
          p=p+2*(x-y)+5;   // p+4*(x-y)+10
        }

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
return 0;

}
```


---

# DDA 

```c
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
```


---




---

# Bresenhams

```c

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
```

---

# Rotation of a triangle

```c
#include <graphics.h>
#include <stdio.h>
#include <math.h>
int main(){
    int i,j,k,a[3][3],t;
    float p,r[3][3],b[3][3];
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C://TC//BGI");

    printf("Enter the first point A (x1,y1) \n");
    scanf("%d%d",&a[0][0],&a[1][0]);

    printf("Enter the first point B (x2,y2) \n");
    scanf("%d%d",&a[0][1],&a[1][1]);

    printf("Enter the first point C (x3,y3) \n");
    scanf("%d%d",&a[0][2],&a[1][2]);
    a[2][0]=a[2][1]=a[2][2]=1;

    printf("Enter the angle of rotation\n");
    scanf("%d",&t);

    line(a[0][0],a[1][0],a[0][1],a[1][1]);
    line(a[0][0],a[1][0],a[0][2],a[1][2]);
    line(a[0][1],a[1][1],a[0][2],a[1][2]);

    p=(float)((3.14/180)*t);
    b[0][0]=cos(p);
    b[0][1]=-sin(p);
    b[1][0]=sin(p);
    b[1][1]=cos(p);

    b[0][2]=b[1][2]=b[2][0]=b[2][1]=0.0;
    b[2][2]=1;

    for(i=0;i<3;i++){
    for(k=0;k<3;k++){
        r[i][k]=0.0;
        for(j=0;j<3;j++){
        r[i][k]=r[i][k]+(b[i][j]*a[j][k]);
        }
    }
    }



    for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%f  ",r[i][j]);
    }
    printf("\n");
    }



    line(r[0][0],r[1][0],r[0][1],r[1][1]);
    line(r[0][0],r[1][0],r[0][2],r[1][2]);
    line(r[0][1],r[1][1],r[0][2],r[1][2]);




    return 0;



}
```

---



#Program for Rotation of 2-D Object

```c
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>


void main()
{
	int gd = DETECT,gm;

	int i,j,k,a[3][3],t;
	float p,b[3][3],r[3][3];
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the first vertex : ");
	scanf("%d%d",&a[0][0],&a[1][0]);
	printf("Enter the second vertex : ");
	scanf("%d%d",&a[0][1],&a[1][1]);
	printf("Enter the third vertex : ");
	scanf("%d%d",&a[0][2],&a[1][2]);
	a[2][0]=a[2][1]=a[2][2]=1;
	printf("enter the angle:");
	scanf("%d",&t);
	line(a[0][0],a[1][0],a[0][1],a[1][1]);
	line(a[0][0],a[1][0],a[0][2],a[1][2]);
	line(a[0][1],a[1][1],a[0][2],a[1][2]);
	p=(float)((3.14/180)*t);

	b[0][0]=cos(p);
	b[0][1]=-sin(p);
	b[1][0]=sin(p);
	b[1][1]=cos(p);
	b[0][2]=b[1][2]=b[2][0]=b[2][1]=0.0;
	b[2][2]=1;

	for(i=0;i<3;i++)
	{
		for(k=0;k<3;k++)
		{
			r[i][k]=0.0;
			for(j=0;j<3;j++)
			{
				r[i][k]=r[i][k]+(b[i][j]*a[j][k]);
			}
		}
	}

	printf("the matrix formed is : \n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%f ",r[i][j]);
		}
		printf("\n");
	}

	line(r[0][0],r[1][0],r[0][1],r[1][1]);
	line(r[0][0],r[1][0],r[0][2],r[1][2]);
	line(r[0][1],r[1][1],r[0][2],r[1][2]);
	getch();
}
```


---



---

#  Program for scaling a two-dimensional object using our coordinate system.


```c
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>


void main()
{
	int gd = DETECT,gm;

	int i,j,k1,a[3][3];
	float b[3][3],r[3][3];
	float sx,sy;
	int h=350,k=300;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the first vertex : ");
	scanf("%d%d",&a[0][0],&a[1][0]);
	printf("Enter the second vertex : ");
	scanf("%d%d",&a[0][1],&a[1][1]);
	printf("Enter the third vertex : ");
	scanf("%d%d",&a[0][2],&a[1][2]);
	a[2][0]=a[2][1]=a[2][2]=1;
	printf("enter sx and sy:");
	scanf("%f%f",&sx,&sy);
	line(h,k,640,k);
	line(h,k,h,10);
	line(h+a[0][0],k-a[1][0],h+a[0][1],k-a[1][1]);
	line(h+a[0][0],k-a[1][0],h+a[0][2],k-a[1][2]);
	line(h+a[0][1],k-a[1][1],h+a[0][2],k-a[1][2]);


	b[0][0]=sx;

	b[1][1]=sy;

	b[0][1]=b[1][0]=b[0][2]=b[1][2]=b[2][0]=b[2][1]=0.0;
	b[2][2]=1;

	for(i=0;i<3;i++)
	{
		for(k1=0;k1<3;k1++)
		{
			r[i][k1]=0.0;
			for(j=0;j<3;j++)
			{

				r[i][k1]=r[i][k1]+(b[i][j]*a[j][k1]);
			}
		}
	}

	printf("the matrix formed is : \n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%f ",r[i][j]);
		}
		printf("\n");
	}

	line(floor(h+r[0][0]),floor(k-r[1][0]),floor(h+r[0][1]),floor(k-r[1][1]));
	line(floor(h+r[0][0]),floor(k-r[1][0]),floor(h+r[0][2]),floor(k-r[1][2]));
	line(floor(h+r[0][1]),floor(k-r[1][1]),floor(h+r[0][2]),floor(k-r[1][2]));
	getch();
}
```

---


# Program for Boundary Fill
```c
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor){
    if(getpixel(x,y) != boundaryColor && getpixel(x,y) != fillColor){
	putpixel(x,y,fillColor);
	boundaryFill(x+1, y, fillColor, boundaryColor);
	boundaryFill(x-1, y, fillColor, boundaryColor);
	boundaryFill(x, y+1, fillColor, boundaryColor);
	boundaryFill(x, y-1, fillColor, boundaryColor);
    }
}

void main(){
    int x1,y1,x2,y2,x3,y3,x,y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter coordinates of A: ");
    scanf("%d%d",&x1, &y1);
    printf("Enter coordinates of B: ");
    scanf("%d%d",&x2, &y2);
    printf("Enter coordinates of c: ");
    scanf("%d%d",&x3, &y3);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
    x = (int) (x1+x2+x3)/3;
    y = (int) (y1+y2+y3)/3;
    delay(500);
    boundaryFill(x,y,5, WHITE);
    getch();
}
```
---

# Program For Flood Fill
```c
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void floodFill(int x, int y, int fillColor, int oldColor){
    if(getpixel(x,y) == oldColor){
	putpixel(x,y,fillColor);
	floodFill(x+1, y, fillColor, oldColor);
	floodFill(x-1, y, fillColor, oldColor);
	floodFill(x, y+1, fillColor, oldColor);
	floodFill(x, y-1, fillColor, oldColor);
    }
}

void main(){
    int x1,y1,x2,y2,x3,y3,x4,y4,x,y;
    int oldColor = BLACK;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter coordinates of A: ");
    scanf("%d%d",&x1, &y1);
    printf("Enter coordinates of B: ");
    scanf("%d%d",&x2, &y2);
    printf("Enter coordinates of C: ");
    scanf("%d%d",&x3, &y3);
    printf("Enter coordinates of D: ");
    scanf("%d%d",&x4, &y4);
    setcolor(YELLOW);
    line(x1,y1,x2,y2);
    setcolor(GREEN);
    line(x2,y2,x3,y3);
    setcolor(MAGENTA);
    line(x3,y3,x4,y4);
    setcolor(BLUE);
    line(x4,y4,x1,y1);
    x = (int) (x1+x2+x3+x4)/4;
    y = (int) (y1+y2+y3+y4)/4;
    floodFill(x,y,RED,oldColor);
    getch();
}
```
---

# Program for Scan Line Filling
```c

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int n,i,j,k,dy,dx;
	int gd = DETECT,gm;
	int x,y,temp;
	int a[10][2],xi[10];
	float slope[20];

	printf("enter the no of edegs of polygon:");
	scanf("%d",&n);

	printf("Enter the cords of polygon:");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    for(i=0;i<n;i++)
    {
	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
	getch();
	for(i=0;i<n;i++)
	{
		dy=a[i+1][1]-a[i][1];
		dx = a[i+1][0]-a[i][0];

		if(dy==0)
		{
			slope[i]=1.0;
		}
		if(dx==0)
		{
			slope[i]=0.0;
		}
		if((dy!=0)&&(dx!=0))
		{
			slope[i]= (float)(dx/dy);
		}
	}

	for(y=0;y<480;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if((a[i][1]<=y)&&(a[i+1][1]>y)||((a[i][1]>y)&&(a[i+1][1]<=y)))
			{
				xi[k]=(int)a[i][0]+slope[i]*(y-a[i][1]);
				k++;
			}
		}

		for(j=0;j<k-1;j++)
		for(i=0;i<k-1;i++)
		{
			if(xi[i]>xi[i+1])
			{
				temp=xi;
				xi[i]=xi[i+1];
				xi[i+1]=temp;
			}
		}
		setcolor(4);
		for(i=0;i<k;i+=2)
		{
			line(xi[i],y,xi[i+1],y);
			getch();
		}
	}
	getch();

	getch();
}
```
---

# Program for Liang barsky clipping algorithm

```c

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm,k,h=50,c=400;
	float x1,y1,x2,y2,xmin,xmax,ymin,ymax,dx,dy,p[4],q[4],r[4],u1=0.0,u2=1.0;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printf("Enter the boundaries of clip window\n");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
	printf("Enter the end point of the line\n");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	line(h,c,640,c);
	line(h,c,h,10);
	rectangle(h+xmin,c-ymin,h+xmax,c-ymax);
	line(h+x1,c-y1,h+x2,c-y2);
	getch();
	dx=x2-x1;
	dy=y2-y1;
	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;
	for(k=0;k<=3;k++)
	{
		if((p[k]==0)&&(q[k]<0))
		{
			printf("Line is outside of clip window\n");
			getch();
		}
	}
	for(k=0;k<=3;k++)
	{
		if(p[k]<0)
		{
			r[k]=q[k]/p[k];
			if(r[k]>u1)
				u1=r[k];
		}
		if(p[k]>0)
		{
			r[k]=q[k]/p[k];
			if(r[k]<u2)
				u2=r[k];
		}
	}
	if(u1>u2)
	{
		printf("line is completely out of clip window");
		getch();
	}
	if(u1==0.0&&u2==1.0)
	{
		printf("The line is inside the clip window");
		getch();
	}
	if(u1<u2)
	{
		x2=x1+(u2*dx);
		y2=y1+(u2*dy);
		x1=x1+(u1*dx);
		y1=y1+(u1*dy);
		clrscr();
		printf("u1=%f\tu2=%f\nx1=%f\ty1=%f\nx2=%f\ty2=%f\n",u1,u2,x1,y1,x2,y2);
		printf("The required clipped line is:\n");
		line(h,c,640,c);
		line(h,c,h,10);
		rectangle(h+xmin,c-ymin,h+xmax,c-ymax);
		line(h+x1,c-y1,h+x2,c-y2);
		getch();
	}
}
```
---
