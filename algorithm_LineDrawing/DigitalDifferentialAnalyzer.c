#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
 float x,y,x1,y1,x2,y2,dx,dy,length;
 int i,gd,gm;

 /* Read two end points of line
 ---------------------------------- */
 printf("Enter the value of x1 :\t");
 scanf("%f",&x1);
 printf("Enter the value of y1 :\t");
 scanf("%f",&y1);
 printf("Enter the value of x2 :\t");
 scanf("%f",&x2);
 printf("Enter the value of y2 :\t");
 scanf("%f",&y2);

 /* Initialise graphics mode
 ---------------------------------- */
 detectgraph(&gd,&gm);
 //Replace NULL with "c:\\tc\\bgi" on Windows OS
 initgraph(&gd,&gm,NULL);
 
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 
 if (dx >= dy)
 {
  length = dx;
 }
 else
 {
  length = dy;
 }
 
 dx = (x2-x1)/length;
 dy = (y2-y1)/length;
 
 x = x1 + 0.5;  /* Factor 0.5 is added to round the values */
 y = y1 + 0.5;  /* Factor 0.5 is added to round the values */
 
 putpixel (x, y, 15);
 
 i = 1;         /* Initialise loop counter */
 
 while(i <= length)
 {
  x = x + dx;
  y = y + dy;
  putpixel (x, y, 15);
  i = i + 1;
  delay(100); /* Delay is purposely inserted to see
  observe the line drawing process */
 }
 sleep(200);
 getch();
 closegraph();
}