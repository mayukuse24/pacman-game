struct date
{
	int dd, mm, yy;
};
int checkdate(date dt)
{
  	int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  	if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   	maxdays[1]=29;
  	if (dt.mm>=1 && dt.mm<=12)
  	{
    	if (dt.dd>=1 && dt.dd<=maxdays[dt.mm-1])
      	return 1;
    	else
      	return 0;
  	}
  	else
    	return 0;
}
void inputdate(date& dt)
{
   int valid;
   do
   {
      cout<<"Enter Day [1-31]  ? "; cin>>dt.dd;
      cout<<"Enter Month [1-12]? "; cin>>dt.mm;
      cout<<"Enter Year [YYYY] ? "; cin>>dt.yy;
      valid=checkdate(dt);
      if (valid==0)
      	cout<<"Invalid date. Input again.\n";
   }
   while(valid==0);
}
date nextdate(date dt, int days)
{
   int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   	maxdays[1]=29;
   dt.dd+=days;
   while (dt.dd>maxdays[dt.mm-1])
   {
      dt.dd-=maxdays[dt.mm-1];
      dt.mm++;
      if (dt.mm==13)
      {
         dt.mm=1;
         dt.yy++;
      }
   }
   return dt;
}
int nodays(date dt)
{
   int month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   	month[1]=29;
   int leap=(dt.yy-1)/4-400;
   int nonleap=dt.yy-1901-leap;
   int days=366*leap+365*nonleap+dt.dd;
   for (int i=1; i<dt.mm; i++)
   	days+=month[i-1];
	return days;
}
void date2str(date dt, char* datestr)
{
   sprintf(datestr, "%04i/%02i/%02i", dt.yy, dt.mm, dt.dd);
}
void displaydate(date dt)
{
   printf("%02i-%02i-%04i\n", dt.dd, dt.mm, dt.yy);
}

//*************************** Other Useful function ***************************
void fillwindow(int x1, int y1, int x2, int y2, int color)
{
	window(x1, y1, x2, y2);
	textbackground(color);
	clrscr();
	window(1, 1, 80, 25);
	textbackground(BLACK);
}
void charat(int x, int y, char ch)
{
	gotoxy(x, y);
	cprintf("%c", ch);
}
void displayint(int x, int y, int ivar)
{
	gotoxy(x, y);
	cprintf("%i", ivar);
}
void displaydouble(int x, int y, double dvar)
{
	gotoxy(x, y);
	cprintf("%f", dvar);
}
void normalvideo(int x, int y, char *str)
{
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	gotoxy(x, y);
	cprintf("%s", str);
}
void reversevideo(int x, int y, int tcol, int bcol, char *str)
{
	textcolor(tcol);
	textbackground(bcol);
	gotoxy(x, y);
	cprintf("%s", str);
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}
void box1(int x1, int y1, int x2, int y2)
{
   // **************************************************************************
	// Draws a single line box on the screen 												 *
   // **************************************************************************

	textcolor(LIGHTGRAY);
	textbackground(MAGENTA);
	for(int col=x1;col<x2;col++)
	{
		charat(col, y1, 196);
		charat(col, y2, 196);
	}
	for(int row=y1;row<y2;row++)
	{
		charat(x1, row, 179);
		charat(x2, row, 179);
	}
	charat(x1, y1, 218);
	charat(x1, y2, 192);
	charat(x2, y1, 191);
	charat(x2, y2, 217);
}
void box2(int x1, int y1, int x2, int y2)
{
   // **************************************************************************
	// Draws a double line box on the screen 												 *
   // **************************************************************************

	textcolor(LIGHTGRAY);
	textbackground(MAGENTA);
	for(int col=x1;col<x2;col++)
	{
		charat(col, y1, 205);
		charat(col, y2, 205);
	}
	for(int row=y1;row<y2;row++)
	{
		charat(x1, row, 186);
		charat(x2, row, 186);
	}
	charat(x1, y1, 201);
	charat(x1, y2, 200);
	charat(x2, y1, 187);
	charat(x2, y2, 188);
}
int menu(char *a[], int n, char *heading)
{
   // **************************************************************************
	// Displays menu on the centre of the screen depending on number of options *
   // assuming that there are 80 cols and 25 rows.                             *
   // Parameters from left to right are:                                       *
   // 1.	name of the 2D character array containing option                      *
   // 2.	number of options                                                     *
   // 3.	heading to appear with menu                                           *
   // **************************************************************************

   int i;
	clrscr();
	int h=(25-n)/2;
	int l=strlen(a[0]);
	int w=(80-l)/2;
	fillwindow(w-1, h, w+l+2, h+n+1, MAGENTA);
	box1(w-1, h, w+l+2, h+n+1);
	int x=(80-strlen(heading))/2;
	gotoxy(x+1, h);
	cprintf(heading);
	for(i=0;i<n;i++)
		normalvideo(w+1, h+i+1, a[i]);
	reversevideo(w+1, h+1, LIGHTGRAY, BLACK, a[0]);
	int done=i=0;
	_setcursortype(_NOCURSOR);
	do
	{
		int key=getch();
		switch(key)
		{
			case 00:
				key=getch();
				switch(key)
				{
					case 72:
						normalvideo(w+1, h+i+1, a[i]);
						i--;
						if(i==-1) i=n-1;
						reversevideo(w+1, h+i+1, LIGHTGRAY, BLACK, a[i]);
						break;
					case 80:
						normalvideo(w+1, h+i+1, a[i]);
						i++;
						if (i==n) i=0;
						reversevideo(w+1, h+i+1, LIGHTGRAY, BLACK, a[i]);
						break;
				}
				break;
			case 13:
				done=1;
				break;
			case 27:
				done=1;
				i=-1;
		}
	}
	while(done==0);
	_setcursortype(_NORMALCURSOR);
	return char(i+1);
}
void mygets(char *s, int limit)
{
   // **************************************************************************
	// A very user freindly function to input a string from keyboard            *
   // You only can input exactly number of characaters or less                 *
   // If you press escape in between, it return a null string                  *
   // **************************************************************************

	void delchar(char*, int, int, int&);

   int i, curx, done;

   int col=wherex();
   for(i=0; i<limit; i++)
      cout<<'.';
   gotoxy(col, wherey());

   done=curx=i=0;
   do
   {
      char ch=char(getch());
      switch(ch)
      {
         case 0:
            ch=char(getch());
            switch (ch)
            {
               case 75:
                  if (curx>0)
                  {
                     curx--;
                     gotoxy(wherex()-1, wherey());
                  }
                  break;
               case 77:
                  if (curx<i)
                  {
                     curx++;
                     gotoxy(wherex()+1, wherey());
                  }
                  break;
               case 83:
                  if (i>0)
                  {
                     if (curx<i)
                     {
                        delchar(s, col, curx+1, i);
                        gotoxy(col+curx, wherey());
                        if (i==0)
                           s[i]=0;
                     }
                  }
            }
            break;
         case 8:
            if (curx>0)
            {
               delchar(s, col, curx, i);
               gotoxy(col+curx-1, wherey());
               curx--;
               if (i==0)
                  s[i]=0;
            }
            break;
         case 13:
            done=1;
            s[i]=0;
            break;
         case 27:
            done=1;
            s[0]=0;
            break;
         default:
            if (i<limit)
            {
               if (curx<i)
               {
                  s[curx]=ch;
                  cout<<ch;
                  curx++;
               }
               else
               {
                  s[i]=ch;
                  cout<<ch;
                  i++;
                  curx=i;
               }
            }
            else
               s[i]=0;
      }
   }
   while(!done);
   cout<<endl;
}
void delchar(char *s, int col, int p, int &len)
{
   // **************************************************************************
	// A function invoke from mygets() to delete a character                    *
   // **************************************************************************

   int i;
   for(i=p; i<len; i++)
      s[i-1]=s[i];
   gotoxy(col+p-1, wherey());
   len--;
   for(i=p-1; i<len; i++)
      cout<<s[i];
   cout<<'.';
}

