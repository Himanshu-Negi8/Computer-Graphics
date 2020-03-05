#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm,a[3][3],i,j,k,t;
	float p,b[3][3]={0},r[3][3];

	printf("\nEnter first vertex: ");
	scanf("%d%d",&a[0][0],&a[1][0]);
	printf("\nEnter second vertex: ");
	scanf("%d%d",&a[0][1],&a[1][1]);
	printf("\nEnter third vertex: ");
	scanf("%d%d",&a[0][2],&a[1][2]);
	a[2][0]=a[2][1]=a[2][2]=1;

	printf("\nEnter angle of rotation: ");
	scanf("%d",&t);

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	line(a[0][0],a[1][0],a[0][1],a[1][1]);
	line(a[0][1],a[1][1],a[0][2],a[1][2]);
	line(a[0][2],a[1][2],a[0][0],a[1][0]);
	getch();
	p=(3.14/180)*t;
	b[0][0]=cos(p);
	b[0][1]=-sin(p);
	b[1][0]=sin(p);
	b[1][1]=cos(p);
	b[2][2]=1.0;

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			r[i][j]=0.0;
			for(k=0;k<3;k++)
				r[i][j]+=b[i][k]*a[k][j];
		}

	printf("\nResultant matrix is: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf(" %.2f ",r[i][j]);
		printf("\n");
	}
	getch();
	line(floor(r[0][0]+0.5),floor(r[1][0]+0.5),floor(r[0][1]+0.5),floor(r[1][1]+0.5));
	line(floor(r[0][1]+0.5),floor(r[1][1]+0.5),floor(r[0][2]+0.5),floor(r[1][2]+0.5));
	line(floor(r[0][2]+0.5),floor(r[1][2]+0.5),floor(r[0][0]+0.5),floor(r[1][0]+0.5));
	getch();
	closegraph();
	return 0;
	}