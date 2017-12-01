#include<fstream.h>
#include<conio.h>
class student
{
	int roll;
   char name[25], lang[3];
   struct
   {
   	int ma;
      char gr[3];
   } sub[5];
   double avg;
   public:
      void display();
};
void student::display()
{
   cprintf("%i %-24s %3i %s  %s", roll, name, sub[0].ma, sub[0].gr, lang);
   cprintf("%4i %2s %4i %2s", sub[1].ma, sub[1].gr,sub[2].ma, sub[2].gr);
	cprintf("%4i %2s %4i %2s", sub[3].ma, sub[3].gr,sub[4].ma, sub[4].gr);
   cprintf("%6.1lf", avg);
}
void main()
{
   student obj;
   int size=sizeof(obj);
	ifstream fin("Marks.dat", ios::binary);
   fin.seekg(0, ios::end);
   int n=fin.tellg()/size;
   window(1, 1, 80, 1);
   textcolor(BLACK);
   textbackground(LIGHTGRAY);
   clrscr();
   cprintf("Roll    Name                      Eng    Fre/Hin     Math   ");
   cprintf("Sc      SSt    Agg%");
	window(1, 25, 80, 25);
   textcolor(BLACK);
   textbackground(LIGHTGRAY);
   clrscr();
   gotoxy(1, 1);
   cprintf(" UP = %c    DOWN = %c", char(24), char(25));
   gotoxy(70, 1);
   cprintf("EXIT = ESC");
   window(1, 2, 80, 24);
   textcolor(YELLOW);
   textbackground(BLUE);
   clrscr();
   fin.seekg(0);
   for (int k=0; k<23; k++)
   {
   	fin.read((char*)&obj, size);
      gotoxy(1, k+1);
   	obj.display();
   }
   int top=0, bot=22, done=0;
   _setcursortype(_NOCURSOR);
   do
   {
   	int ch=getch();
      switch (ch)
      {
         case 0:
            ch=getch();
            switch (ch)
            {
               case 72:
               	if (top>0)
                  {
                  	bot--;
                     top--;
               		gotoxy(1,23);
                  	delline();
                  	gotoxy(1,1);
                     insline();
                  	fin.seekg(size*top);
   						fin.read((char*)&obj, size);
   						obj.display();
                  }
               	break;
               case 80:
               	if (bot<n-1)
                  {
                  	bot++;
                     top++;
               		gotoxy(1,1);
                  	delline();
                  	gotoxy(1,23);
                  	fin.seekg(size*bot);
   						fin.read((char*)&obj, size);
   						obj.display();
                  }
               	break;
            }
            break;
         case 27:
            done=1;
      }
   }
   while (!done);
   fin.close();
	_setcursortype(_NORMALCURSOR);
   window(1, 1, 80, 25);
   textcolor(LIGHTGRAY);
   textbackground(BLACK);
}

