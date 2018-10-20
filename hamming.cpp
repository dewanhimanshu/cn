#include<iostream>
#include<math.h>
using namespace std;
#define MAX 100
class hamming
{
    char msg[MAX];
    char code[MAX];
    int m;
    int c;
    int bre[MAX];
public:
    hamming()
    {
        for(int i=0;i<MAX;i++)
        {
            bre[i] = 0;

        }
    }


    void input()
    {
        cout<<"\nEnter the Number of Message Bits";
        cin>>m;
        cout<<"Enter "<<m<<" Message Bits";
        cin>>msg;
        for(int i=0;msg[i]!='\0';i++)
        {
            if(msg[i]=='0'||msg[i]=='1')
            {
                continue;
            }
            else
            {
                cout<<"Invalid Input";
                exit(0);
            }
        }
    }
    void code_generater()
    {
        m = 0;
        int k =0;
        int pos = 1;
        for(int i=0;msg[i]!='\0';)
        {
           if(pos-1==m)
           {
                code[m++] = '*';
                k++;
                pos = pow(2,k);

           }
           else
           {
                code[m++] = msg[i++];
           }
        }
          code[m] = '\0';
    }

    void binary(int b[],int n,int &bs)
    {
        while(n>0)
        {
            b[bs++] = n % 2;
            n = n / 2;
        }
    }


    void code_fill()
    {
        int k = 0;
        int pos = 0;
        for(int i=0;code[i]!='\0';i++)
        {
            int k=0;
            if(code[i]=='1')
            {
                int b[MAX];
                int bs =0;
                int n = i-1;
                while(n>0)
                {
                      b[bs++] = n % 2;
                      n = n / 2;
                }

                for(int i=0;i<bs;i++)
                {
                    if(b[i]==1)
                    {
                        int x = pow(2,b[i]);
                        if(code[x-1]=='*'||code[x-1]=='1')
                            code[x-1]='0';
                        else
                            code[x-1]='1';
                    }
                }
            }

        }
        for(int i=0;code[i]!='\0';i++)
        {
            if(code[i]=='*')
            {
                code[i]='0';
            }
        }
    }

    void print()
    {
        cout<<"\nMessage is:"<<msg;
        cout<<"\nCode Word is:"<<code;
    }
};


int main()
{
    hamming h;
    h.input();
    h.code_generater();
    h.code_fill();
    h.print();
}
