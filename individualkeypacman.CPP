#include<iostream.h>
#include<conio.h>

void keyw(int &ay,int &ax,int &bx,int &by,int &cx,int &cy,int &dx,int &dy,char fkey)
{
	if(fkey=='w')
   {
      gotoxy(ax,--ay);
      cout<<"*";
      gotoxy(bx,by--);
      cout<<" ";
      gotoxy(cx,cy--);
      cout<<" ";
      gotoxy(dx,--dy);
      cout<<"*";
   }
}

void keyd(int &ay,int &ax,int &bx,int &by,int &cx,int &cy,int &dx,int &dy,char fkey)
{
	if(fkey=='d')
   {
      gotoxy(++dx,dy);
      cout<<"*";
      gotoxy(++cx,cy);
      cout<<"*";
      gotoxy(ax++,ay);
      cout<<" ";
      gotoxy(bx++,by);
      cout<<" ";
   }
}

void keya(int &ay,int &ax,int &bx,int &by,int &cx,int &cy,int &dx,int &dy,char fkey)
{
	if(fkey=='a')
   {
      gotoxy(--ax,ay);
      cout<<"*";
      gotoxy(--bx,by);
      cout<<"*";
      gotoxy(cx--,cy);
      cout<<" ";
      gotoxy(dx--,dy);
      cout<<" ";
   }
}

void keys(int &ay,int &ax,int &bx,int &by,int &cx,int &cy,int &dx,int &dy,char fkey)
{
	if(fkey=='s')
   {
      gotoxy(bx,++by);
      cout<<"*";
      gotoxy(cx,++cy);
      cout<<"*";
      gotoxy(ax,ay++);
      cout<<" ";
      gotoxy(dx,dy++);
      cout<<" ";
   }
}



void main()
{
   int a,b;
	for(a=5;a<20;a++)
   {
   	gotoxy(5,a);
      cout<<"|";
      gotoxy(70,a);
      cout<<"|";
   }
   for(b=5;b<70;b++)
   {
   	gotoxy(b,5);
      cout<<"-";
      gotoxy(b,20);
      cout<<"-";
   }



   int pay=13,pax=40,pbx=40,pby=14,pcx=41,pcy=14,pdx=41,pdy=13;
   gotoxy(40,13);
   cout<<"*";
   gotoxy(40,14);
   cout<<"*";
   gotoxy(41,14);
   cout<<"*";
   gotoxy(41,13);
   cout<<"*";
   gotoxy(40,10);
   cout<<".";
   gotoxy(40,9);
   cout<<".";
   gotoxy(20,5);
   cout<<".";
   gotoxy(70,18);
   cout<<".";
   gotoxy(50,24);
   cout<<".";

   char key=getch();
   while(key!='p')
   {
      if(pax==6&&pay==6)
      {
        keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
        keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
   	if(pax==6&&pay<=17)
      {
          keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
          keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
          keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pay==6&&pax<=67)
      {
      	keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pbx==6&&pby==19)
      {
         keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pby==19&&pbx<=67)
      {
         keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pdx==69&&pdy==6)
      {
        keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
        keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pdx==69&&pdy<=17)
      {
        keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
        keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
        keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      if(pcx==69&&pcy==19)
      {
         keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
      }
      else
      {
         keyw(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keyd(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keys(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
         keya(pay,pax,pbx,pby,pcx,pcy,pdx,pdy,key);
		}
      key=getch();
   }
}
