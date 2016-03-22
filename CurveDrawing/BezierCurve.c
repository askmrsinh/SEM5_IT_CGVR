#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int gd,gm,maxx,maxy;
float xxx[1][2]={0.0,0.0,};

void line1(float x2,float y2)
{
 int d1,d2,d3,d4;
 d1=maxx*xxx[0][0];
 d2=maxy*xxx[0][1];
 d3=maxx*x2;
 d4=maxy*y2;
 line(d1,d2,d3,d4);
 xxx[0][0]=x2;
 xxx[0][1]=y2;
}

bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
 float xab,yab,xbc,ybc,xcd,ycd;
 float xabc,yabc,xbcd,ybcd;
 float xabcd,yabcd;
 if (n==0)
 {
  line1(xb,yb);
  line1(xc,yc);
  line1(xd,yd);
 }
 else
 {
  xab = (xxx[0][0]+xb)/2;
  yab = (xxx[0][1]+yb)/2;
  xbc = (xb+xc)/2;
  ybc = (yb+yc)/2;
  xcd = (xc+xd)/2;
  ycd = (yc+yd)/2;
  xabc = (xab+xbc)/2;
  yabc = (yab+ybc)/2;
  xbcd = (xbc+xcd)/2;
  ybcd = (ybc+ycd)/2;
  xabcd = (xabc+xbcd)/2;
  yabcd = (yabc+ybcd)/2;
  n=n-1;
  bezier(xab,yab,xabc,yabc,xabcd,yabcd,n);
  bezier(xbcd,ybcd,xcd,ycd,xd,yd,n);
 }
 return (0);
}
void igraph()
{
 detectgraph(&gd,&gm);
 if(gd<0)
 {
  puts("CANNOT DETECT A GRAPHICS CARD");
  exit(1);
 }
 initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
}
main()
{
 igraph();
 maxx = getmaxx();
 maxy = getmaxy();
 setcolor(2);
 bezier(0.85,0.75,0.57,0.78,0.534,0.9,4);
 setfillstyle(2,2);
 getch();
 closegraph();
 return(0);
}
 