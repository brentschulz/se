#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;
void menu()
{
cout<<"\n1.Translation\n";
cout<<"2.Rotation\n";
cout<<"3.Scaling\n";
cout<<"4.Shear\n";
}
class Line{
public:
int gm,gd=DETECT;
int x1=15,x2=75,x3=105,x4=45,y1=15,y2=45,y3=105,y4=75,tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4,shx,shy;
float sx,sy,r,t;
int xt,yt;
int ch;
int rh[10]={150,60, 280,60, 280,150, 150,150, 150,60};
int rh1[10]={20,150, 60,70, 110,150, 20,150};
int tr[10];
int tr1[8];
void display()
{
setcolor(12);
drawpoly(5,rh);
delay(500);
setcolor(WHITE);
drawpoly(5,tr);
delay(500);
}
void displaytri()
{
setcolor(12);
drawpoly(4,rh1);
delay(500);
setcolor(WHITE);
drawpoly(4,tr1);
delay(500);
}
void Rhombus(int ch)
{
switch(ch)
{
case 1:
cout<<"Enter the Translation Factor x: ";
cin>>xt;
cout<<"Enter the Translation Factor y: ";
cin>>yt;
tr[0]=rh[0]+xt; tr[1]=rh[1]+yt;
tr[2]=rh[2]+xt; tr[3]=rh[3]+yt;
tr[4]=rh[4]+xt; tr[5]=rh[5]+yt;
tr[6]=rh[6]+xt; tr[7]=rh[7]+yt;
tr[8]=rh[8]+xt; tr[9]=rh[9]+yt;
initgraph(&gd,&gm,NULL);
display();
closegraph();
break;
case 2:
cout<<"\nEnter the Angle of Translation: ";
cin>>r;
t=3.14*r/180;
tr[0]=abs(rh[0]*cos(t)-rh[1]*sin(t));
tr[1]=abs(rh[0]*sin(t)+rh[1]*cos(t));
tr[2]=abs(rh[2]*cos(t)-rh[3]*sin(t));
tr[3]=abs(rh[2]*sin(t)+rh[3]*cos(t));
tr[4]=abs(rh[4]*cos(t)-rh[5]*sin(t));
tr[5]=abs(rh[4]*sin(t)+rh[5]*cos(t));
tr[6]=abs(rh[6]*cos(t)-rh[7]*sin(t));
tr[7]=abs(rh[6]*sin(t)+rh[7]*cos(t));
tr[8]=abs(rh[8]*cos(t)-rh[9]*sin(t));
tr[9]=abs(rh[8]*sin(t)+rh[9]*cos(t));
initgraph(&gd,&gm,NULL);
display();
closegraph();
break;
case 3:
cout<<"Enter the Scaling Factor x: ";
cin>>sx;
cout<<"Enter the Scaling Factor y: ";
cin>>sy;
tr[0]=rh[0]*sx; tr[1]=rh[1]*sy;
tr[2]=rh[2]*sx; tr[3]=rh[3]*sy;
tr[4]=rh[4]*sx; tr[5]=rh[5]*sy;
tr[6]=rh[6]*sx; tr[7]=rh[7]*sy;
tr[8]=rh[8]*sx; tr[9]=rh[9]*sy;
initgraph(&gd,&gm,NULL);
display();
closegraph();
break;
case 4:
cout<<"Enter the Shear Factor x: ";
cin>>shx;
cout<<"Enter the Shear Factor y: ";
cin>>shy;
tr[0]=abs(rh[0]+shx*rh[1]);
tr[1]=abs(rh[2]+shx*rh[3]);
tr[2]=abs(rh[4]+shx*rh[5]);
tr[3]=abs(rh[6]+shx*rh[7]);
tr[4]=abs(rh[1]+shy*rh[0]);
tr[5]=abs(rh[3]+shy*rh[2]);
tr[6]=abs(rh[5]+shy*rh[4]);
tr[7]=abs(rh[7]+shy*rh[6]);
tr[8]=abs(rh[0]+shx*rh[1]);
tr[9]=abs(rh[2]+shx*rh[3]);
initgraph(&gd,&gm,NULL);
display();
closegraph();
break;
}
}
void Triangle(int ch)
{
switch(ch)
{
case 1:
cout<<"Enter the Translation Factor x: ";
cin>>xt;
cout<<"Enter the Translation Factor y: ";
cin>>yt;
tr1[0]=rh1[0]+xt; tr1[1]=rh1[1]+yt;
tr1[2]=rh1[2]+xt; tr1[3]=rh1[3]+yt;
tr1[4]=rh1[4]+xt; tr1[5]=rh1[5]+yt;
tr1[6]=rh1[6]+xt; tr1[7]=rh1[7]+yt;
initgraph(&gd,&gm,NULL);
displaytri();
closegraph();
break;
case 2:
cout<<"\nEnter the Angle of Translation: ";
cin>>r;
t=3.14*r/180;
tr1[0]=abs(rh1[0]*cos(t)-rh1[1]*sin(t));
tr1[1]=abs(rh1[0]*sin(t)+rh1[1]*cos(t));
tr1[2]=abs(rh1[2]*cos(t)-rh1[3]*sin(t));
tr1[3]=abs(rh1[2]*sin(t)+rh1[3]*cos(t));
tr1[4]=abs(rh1[4]*cos(t)-rh1[5]*sin(t));
tr1[5]=abs(rh1[4]*sin(t)+rh1[5]*cos(t));
tr1[6]=abs(rh1[6]*cos(t)-rh1[7]*sin(t));
tr1[7]=abs(rh1[6]*sin(t)+rh1[7]*cos(t));
initgraph(&gd,&gm,NULL);
displaytri();
closegraph();
break;
case 3:
cout<<"Enter the Scaling Factor x: ";
cin>>sx;
cout<<"Enter the Scaling Factor y: ";
cin>>sy;
tr1[0]=rh1[0]*sx; tr1[1]=rh1[1]*sy;
tr1[2]=rh1[2]*sx; tr1[3]=rh1[3]*sy;
tr1[4]=rh1[4]*sx; tr1[5]=rh1[5]*sy;
tr1[6]=rh1[6]*sx; tr1[7]=rh1[7]*sy;
initgraph(&gd,&gm,NULL);
displaytri();
closegraph();
break;
case 4:
cout<<"Enter the Shear Factor x: ";
cin>>shx;
cout<<"Enter the Shear Factor y: ";
cin>>shy;
tr1[0]=abs(rh1[0]+shx*rh1[1]);
tr1[1]=abs(rh1[2]+shx*rh1[3]);
tr1[2]=abs(rh1[4]+shx*rh1[5]);
tr1[3]=abs(rh1[1]+shy*rh1[0]);
tr1[4]=abs(rh1[3]+shy*rh1[2]);
tr1[5]=abs(rh1[5]+shy*rh1[4]);
tr1[6]=abs(rh1[0]+shx*rh1[1]);
tr1[7]=abs(rh1[2]+shx*rh1[3]);
initgraph(&gd,&gm,NULL);
displaytri();
closegraph();
break;
}
}
};
int main()
{
Line obj;
while(1)
{
cout<<"\n1.Rhombus\n";
cout<<"2.Equilateral Triangle\n";
cout<<"3.Exit\n";
cout<<"Enter Your Choice\n";
cin>>obj.ch;
switch(obj.ch)
{
case 1:
menu();
cout<<"\nEnter Your Choice\n";
cin>>obj.ch;
obj.Rhombus(obj.ch);
break;
case 2:
menu();
cout<<"\nEnter Your Choice\n";
cin>>obj.ch;
obj.Triangle(obj.ch);
break;
case 3:
cout<<"Exiting...";
exit(1);
break;
}
}
return 0;
}