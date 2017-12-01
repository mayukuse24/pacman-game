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



   int ay=13,ax=40,bx=40,by=14,cx=41,cy=14,dx=41,dy=13;
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
      if(ax==6)
      {
        ax++;bx++;cx++;dx++;
      }
      else
      if(ay==6)
      {
      	ay++;by++;cy++;dy++;
      }
      else
      if(cx==69)
      {
      	cx--;dx--;ax--;bx--;
      }
      else
      if(cy==19)
      {
         ay--;by--;cy--;dy--;
      }
      else
      {
         if(key=='w')
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
         if(key=='d')
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
         if(key=='a')
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
         if(key=='s')
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
         key=getch();
      }
   }

}




