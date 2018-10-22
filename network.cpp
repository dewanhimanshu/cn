#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 100
int pararity(int a[] , int n)
{
    int count = 0;
    for(int i=0; i<n ;i++)
    {
        if(a[i]==1)
        {
            count++;
        }
    }
    if(count%2==0)
    {
        return 0;
    }
    return 1;



}
class network
{
  int a[MAX];
  int size;
  int code[MAX+1];
  int code_size;
  public:
    network()
    {
        size = 0;
        code_size = 0;
    }
    bool valid()
    {
        for(int i=0;i<size; )
        {
            if(a[i]==0||a[i]==1)
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    void set()
    {

        cout<<"\nenter the number of bits of info";
        cin>>size;
        if(cin.fail())
        {
            size = 0;
            cout<<"wrong input";
            cin.clear();
            return;
        }
        while(size<=0)
        {
            cout<<"size cant be negative and zero";
            cout<<"\nenter the number of bits of info";
            cin>>size;

        }
        cout<<"\nenter "<<size<<" bits";
        code_size = size + 1;
        for(int i=0;i<size; )
        {

            cin>>a[i];
            code[i] = a[i];
            i++;


         }
         if(!valid())
         {
            cout<<"\nthe input you entered is invalid";
            set();
         }

        cout<<"\n***info code**";
        for(int i=0;i<size;i++)
        {
            cout<<a[i];
        }


    }
    void generate_code(int flag)
    {
        int check = pararity(a,size);
       if(!flag)
       {
            if(!check)
            {
                code[size] = 0;
            }
            else
            {
                code[size] = 1;
            }
        }
        else
        {
          if(check)
            {
                code[size] = 0;
            }
            else
            {
                code[size] = 1;
            }

        }

    cout<<"\n**CODE WORD****";
    for(int i=0;i<code_size;i++)
        {
            cout<<code[i];
        }
    }
    void error()
    {
        srand( time( NULL ));
        float error_time =  (random() % size);
        for(int i=0;i<error_time;i++)
        {
            int r =(int)(random() % size);

            code[r] = !code[r];
        }


    cout<<"\n**CODE SEND****";
    for(int i=0;i<code_size;i++)
        {
            cout<<code[i];
        }

    }
    void check(int flag)
    {
       int check = pararity(code,size+1);
       if(check==flag)
       {
            cout<<"\nPASSED";
       }
       else
       {
        cout<<"\nerror caught";
       }




    }




};


int main()
{
   network n;


   cout<<"\n1,CHECK BY EVEN PRIARITY";
   cout<<"\n2,CHECK BY ODD PRIARITY";
   cout<<"\nANY OTHER KEY TO EXIT";
   int ch;
   cout<<"\n ENTER YOUR CHOICE";
   cin>>ch;
   n.set();

   if(ch==1)
   {
        n.generate_code(0);
        n.error();
        n.check(0);
        

   }
   else if(ch==2)
   {
        n.generate_code(1);
        n.error();
        n.check(1);
   }
   else
   {
    cout<<"\nEXITIING...........";
   }






}
