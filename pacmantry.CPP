#include<iostream.h>
#include<conio.h>

void main()
{
   int a,b,c,d;
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

   getch();
}
