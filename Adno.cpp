#include<fstream.h>
#include<stdio.h>
class student
{
	int adno;
   char name[20];
   double fees;
   public:
   	void inputdata(int an)
      {
      	adno=an;
         cout<<"Input Name? "; cin>>name;
         cout<<"Input Fees? "; cin>>fees;
      }
      void showdata() { cout<<adno<<" , "<<name<<" , "<<fees<<endl; }
      int retadno() { return adno; }
};
int getlastadno()
{
   student a;
   int an, len=sizeof(student);
   ifstream fin("student.dat", ios::binary);
   if (fin==NULL)
   	an=0;
   else
   {
      fin.seekg(0, ios::end);
      int n=fin.tellg()/len;
      if (n==0)
         an=0;
      else
      {
         fin.seekg(len*(n-1), ios::beg);
         fin.read((char*)&a, sizeof(a));
         an=a.retadno();
      }
   }
   fin.close();
   return an;
}
void addrecord()
{
	student a;
   int lastadno=getlastadno();
   ofstream fout("student.dat", ios::binary|ios::app);
   a.inputdata(lastadno+1);
   fout.write((char*)&a, sizeof(a));
   fout.close();
}
void displayrecord()
{
	student a;
   ifstream fin("student.dat", ios::binary);
   while (fin.read((char*)&a, sizeof(a)))
   	a.showdata();
   fin.close();
}
void deleterecord()
{
	student a;
   ifstream fin("student.dat", ios::binary);
   ofstream fout("temp.dat", ios::binary);
   int an, found=0;
   cout<<"Admission Number to Delete? "; cin>>an;
   while (fin.read((char*)&a, sizeof(a)))
   	if (an==a.retadno())
      	found=1;
      else
 			fout.write((char*)&a, sizeof(a));
   fin.close();
   fout.close();
   if (found==1)
   	cout<<an<<" deleted from the file\n";
   else
   	cout<<an<<" not found in the file\n";
	remove("student.dat");
   rename("temp.dat", "student.dat");
}
void main()
{
	int ch;
   do
   {
      cout<<"1. Add record\n";
      cout<<"2. Display record\n";
      cout<<"3. Delete record\n";
      cout<<"0. Quit\n";
      cout<<"Choice[0-3]? "; cin>>ch;
      switch (ch)
      {
      	case 1: addrecord(); break;
         case 2: displayrecord(); break;
         case 3: deleterecord(); break;
      }
   }
   while (ch);
}

