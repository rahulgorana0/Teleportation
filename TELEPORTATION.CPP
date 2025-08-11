#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void border();
void portal();
void player(int c1,int c2);
void control(int &c1,int &c2);
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 int c1=0,c2=0;
 int i=0;
 setbkcolor(1);
 do
 {
  control(c1,c2);
  cleardevice();
  border();
  player(c1,c2);
  portal();
 }while(i!=1);
 getch();
 closegraph();
}

void border()
{
 setfillstyle(SOLID_FILL,15);
 bar(0,0,10,480);
 bar(0,0,640,10);
 bar(0,470,640,480);
 bar(630,0,640,480);
 bar(0,230,640,250);
 setfillstyle(SOLID_FILL,7);
 bar(11,11,629,229);
 setfillstyle(SOLID_FILL,1);
 bar(11,251,629,629);
 setfillstyle(SOLID_FILL,15);
 bar(0,470,640,480);
}

void portal()
{
 setfillstyle(SOLID_FILL,2);
 bar(580,30,630,70);
 bar(560,20,580,80);
 bar(30,180,70,230);
 bar(20,160,80,180);
 bar(570,250,610,300);
 bar(560,300,620,320);
 bar(10,410,60,450);
 bar(60,400,80,460);
}

void control(int &c1,int &c2)
{
 char ch;
 ch=getch();
 if(c1>10)
    c1=10;
 if(c1<-390)
    c1=-390;
 if(c2<-10)
    c2=-10;
 if(c2>550)
    c2=550;
 if(c1==0&&c2==550)
 {
  c1=-380;
  c2=0;
 }
 if(c1==-380&&c2==-10)
 {
  c1=0;
  c2=540;
 }
 if(c1==-150&&c2==0)
 {
  c1=-240;
  c2=540;
 }
 if(c1==-230&&c2==540)
 {
  c1=-140;
  c2=0;
 }
 switch(ch)
 {
  case 'w': c1=c1+10;
	    break;
  case 's': c1=c1-10;
	    break;
  case 'd': c2=c2+10;
	    break;
  case 'a': c2=c2-10;
	    break;
  case 'e': exit(0);
 }
}

void player(int c1, int c2)
{
 setfillstyle(SOLID_FILL,4);
 circle(50+c2,50-c1,20);
 floodfill(50+c2,50-c1,15);
}
