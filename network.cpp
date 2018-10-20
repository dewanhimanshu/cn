#include<iostream>
#include <stdlib.h>
using namespace std;
#define MAX 100

class network
{
    char a[MAX];
    char code[MAX+1];

    public:
        void set()
        {
            cout<<"\n enter the message:";
            cin>>a;
            for(int i=0;a[i]!='\0';i++)
            {
                if(!(a[i]=='0'||a[i]=='1'))
                {
                    cout<<"invalid input";
                    exit(0);
                }
            }
        }
        void generate_code(int c)
        {
            int no_of_ones = 0 ;
            for(int i=0;a[i]!='\0';i++)
            {
                if(a[i]=='1')
                {
                   no_of_ones++;
                }
            }
            int i = 0;
                    for( i =0;a[i]!='\0';i++)
                    {
                        code[i] = a[i];
                    }
            if(c==0)
            {
                if(no_of_ones%2==0)
                {

                    code[i] = '0';
                }
                else
                {
                    code[i] = '1';
                }
            }
            else
            {
                if(no_of_ones%2==0)
                {
                    code[i]='1';
                }
                else
                {
                    code[i] = '0';
                }
            }
            code[i+1] = '\0';

        }
        void error()
        {
            int x = 1;
            for(int i=0;i<x;i++)
            {
                if(a[i]=='0')
                    a[i]='1';
                else
                    a[i]='0';
            }

        }
        void show()
        {
            cout<<"\nMessage is:"<<a;
            cout<<"\nCodeWord id:"<<code;
        }

};
int main()
{
 network n;
   cout<<"\n1,CHECK BY EVEN PRIARITY";
   cout<<"\n2,CHECK BY ODD PRIARITY";
   cout<<"\nANY OTHER KEY TO EXIT";
   int ch;
   cout<<"\n ENTER YOUR CHOICE:";
   cin>>ch;
   n.set();

   if(ch==1)
   {
        n.generate_code(0);
        n.error();
        n.show();
//        n.check(0);


   }
   else if(ch==2)
   {
        n.generate_code(1);
        n.error();
        n.show();
     //   n.check(1);
   }
   else
   {
    cout<<"\nEXITIING...........";
   }
}
