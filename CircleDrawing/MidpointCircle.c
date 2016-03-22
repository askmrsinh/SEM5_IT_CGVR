#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
 float  p;
 int i,gd,gm,x,y;
 int r;

 /* initialise graphics
 ------------------------ */
 detectgraph(&gd,&gm);
 //Replace NULL with "c:\\tc\\bgi" on Windows OS
 initgraph(&gd,&gm,NULL);
 
 /* Read the radius
 ----------------------- */
 printf("Enter the radius of the circle :");
 scanf("%d",&r);
 
 x=0;
 y=r;
 p = 1.25 - r;
 do
 {
  putpixel(200+x,200+y,15);
  putpixel(200+y,200+x,15);
  putpixel(200+x,200-y,15);
  putpixel(200+y,200-x,15);
  putpixel(200-x,200-y,15);
  putpixel(200-x,200+y,15);
  putpixel(200-y,200+x,15);
  putpixel(200-y,200-x,15);
  
  if (p < 0)
  {
   x = x+1;
   y = y;
   p = p + 2*x + 1;
  }
  else
  {
   x= x+1;
   y= y-1;
   p = p + 2*(x-y) + 1;
  }
  delay(100);
 }
 while(x < y);
 sleep(200);
 getch();
 closegraph();
}
