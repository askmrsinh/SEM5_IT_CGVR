#include<stdio.h>
#include<graphics.h>

void flood(int, int, int, int);

void main()
{
 int gd,gm;

 /* Initialise graphics mode
	---------------------------------- */
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

 rectangle(50,50,100,100);
 flood(55,55,4,15);
 getch();
 closegraph();
}

void flood(seed_x,seed_y,foreground_col,background_col)
{
 int i;
 if(getpixel(seed_x,seed_y)!= background_col && getpixel(seed_x,seed_y)!= foreground_col)
 {
  putpixel(seed_x,seed_y,foreground_col);
  flood(seed_x+1,seed_y,foreground_col,background_col);
  flood(seed_x-1,seed_y,foreground_col,background_col);
  flood(seed_x,seed_y+1,foreground_col,background_col);
  flood(seed_x,seed_y-1,foreground_col,background_col);
  flood(seed_x+1,seed_y+1,foreground_col,background_col);
  flood(seed_x-1,seed_y-1,foreground_col,background_col);
  flood(seed_x+1,seed_y-1,foreground_col,background_col);
  flood(seed_x-1,seed_y+1,foreground_col,background_col);
 }
}
