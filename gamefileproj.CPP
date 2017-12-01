//DXBALL Game
//Submitted By sumit sardana <sardana.sumit08@gmail.com> 
//Downloaded From c4cpp.co.nr

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

 void main()
 {clrscr();
 int n,h,dir,chnc,scr=0,batc,c,i,r,d;
 char ch=' ';


 //loop for horizontal lines
 for(c=1;c<=80;c++)
 {gotoxy(c,1);
  cout<<'#';
  gotoxy(c,24);
  cout<<'#';
  textbackground(BROWN);textcolor(WHITE);
  }

 //loop for vertical lines
 for(r=1;r<=24;r++)
 {gotoxy(1,r);
  cout<<'#';
  gotoxy(80,r);
  cout<<'#';
  }


  c=62;r=22;
  dir=1;d=55;
  batc=58;
  chnc=4;

  gotoxy(60,1);
  cout<<"            ";

 // DISPLAY JUST NIL SCORE IN THE START OF THE GAME
    gotoxy(59,1);
    cout<<"                 ";
    gotoxy(60,1);
    cout<<"SCORE :";
    gotoxy(68,1);
    cout<<"000000";


 //CHANCE LEFT
    gotoxy(5,1);
    cout<<"                 ";
    gotoxy(6,1);
    cout<<"CHANCE LEFT : "<<chnc;

 //DISPLAY JUST BAT AND BALL IN STARTING OF THE GAME
    gotoxy(c,r);
    cout<<'*';
    gotoxy(batc,23);
    cout<<"<========>";
    ch=getch();
  if(ch=='a')
    dir=2;

  if(ch=='d')
    dir=1;



 //COLUMN OF SCORE
    h=74;


while((ch!='q')&&(ch!='Q'))
 {while((c<=79)&&(c>=2)&&(r<=22)&&(r>=2))

 //make ball
  {gotoxy(c,r);
   cout<<'*';

 // SCORE
   gotoxy(h,1);
   cout<<scr;
   scr++;

 //make bat
   gotoxy(batc,23);
   cout<<"<========>";
   for(int o=0;o<50000000;o++)
   {
   }

 //erase ball
   gotoxy(c,r);
   cout<<' ';

 //erase bat
   gotoxy(batc,23);
   cout<<"          ";

 if(kbhit())
   ch=getch();

 //DIRECTIO TO BAT with keys
 if(ch=='a')
  if(batc>2)  batc-=2;

 if(ch=='d')
  if(batc<70) batc+=2;

 if(ch=='~')
    batc=c-4;

 //CRITERIA FOR SCORE
 if(scr==10)
    h=h--;

 if(scr==100)
    h=h--;

 if(scr==1000)
    h=h--;

 if(scr==10000)
    h=h--;

 // DIRECTIONS

 if(dir==1)
   {c++;r--;}

 if(dir==2)
   {c--;r--;}

 if(dir==3)
   {c--;r++;}

 if(dir==4)
   {c++;r++;}
   }

 // change in direction of ball
 if(c==1)
    {c=2;
 if(dir==2)
    dir=1;
 if(dir==3)
    dir=4;
    }

 if(c==80)
  {if(dir==1)
     dir=2;
   if(dir==4)
     dir=3;
     c=79;
    }

 if(r==1)
  {r=2;
   if(dir==2)
     dir=3;
   if(dir==1)
     dir=4;
    }

 //CONDITION IF BALL HITS THE BAT
 if((r==23)&&(c>=batc)&&(c<=batc+9))
  {r=22;
   if(dir==3)
     dir=2;
   if(dir==4)
     dir=1;
    }


 //CONDITION IF BALL DOESN'T HITS THE BAT
 if((r==23)&&((c<batc)||(c>batc+9)))

 //DEDUCTION OF CHANCES

  { //CONDITION IF CHANCE LEFT = 0
   if(chnc==0)
  {gotoxy(33,15);
     cout<<"GAME OVER!";
     gotoxy(28,18);
     cout<<"YOUR TOTAL SCORE : "<<scr-1;
     ch=getch();
     exit(0);
     }

    chnc--;

     gotoxy(20,1);
      cout<<chnc;



 //LOOP FOR ANOTHER CHANCE OR QUIT
    gotoxy(16,15);
    cout<<"FOR ANOTHER CHANCE PRESS 'R'  OR TO QUIT PRESS'Q'";


    ch=getch();

 // IF THE USER TYPE 'Q'AT TIME OF CHOICE
 if((ch=='q')||(ch=='Q'))
 //ERASING THE PREVIOUS INPUT
    {gotoxy(16,15);
    cout<<"                                                 ";
    gotoxy(33,11);
    cout<<"               ";

     gotoxy(33,15);
     cout<<"GAME OVER!";
     gotoxy(28,18);
     cout<<"YOUR TOTAL SCORE : "<<scr-1;
     ch=getch();
     exit(0);
     }

 //IF THE USER TYPE 'R' AT TIME OF CHOICE
 if((ch=='r')||(ch=='R'))
 // restart th game
    {gotoxy(16,15);
     cout<<"                                                 ";
     gotoxy(33,11);
     cout<<"               ";




 //RE-ASSIGN ALL THE VALUES
     c=62;r=22;
     batc=58;

 //WHEN ANOTHER CHANCE STARTS DISPLAY BAT AND BALL
     gotoxy(c,r);
     cout<<'*';
     gotoxy(batc,23);
     cout<<"<========>";
     ch=getch();
     if(ch=='a')
     dir=2;

     if(ch=='d')
     dir=1;

 // end of gotoxy loop
    }
 //end of if loop
    }
 //end of while loop
    }

    }


