#include<fstream.h>
#include<stdio.h>
#include<conio.h>
typedef char string[128];
int countline()
{
	ifstream f("Yahoo.txt");
   string line;
   int c=0;
   while (f.getline(line, 128))
   	c++;
   f.close();
   return c;
}
void initarray(string* &arr, int& n)
{
	n=countline();
   arr=new string[n];
   int i=-1;
   ifstream f("Yahoo.txt");
   while (f.getline(arr[++i], 128));
   f.close();
}
void main()
{
	string* arr;
   int n;
   initarray(arr, n);
   int bot=-1, done=0, top=0;
   while (bot<23)
   	puts(arr[++bot]);
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
               		gotoxy(1,24);
                  	delline();
                  	gotoxy(1,1);
                     insline();
                  	puts(arr[top]);
                  }
               	break;
               case 80:
               	if (bot<n-1)
                  {
                  	bot++;
                     top++;
               		gotoxy(1,1);
                  	delline();
                  	gotoxy(1,24);
                  	puts(arr[bot]);
                  }
               	break;
            }
            break;
         case 27:
            done=1;
      }
   }
   while (!done);
   delete []arr;
   _setcursortype(_NORMALCURSOR);
}

