#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{   srand(time(NULL));
    int frames,total =0,ws,current=0,outsanding=0;
    cout<<"\nEnter the number of frames ";
    cin>>frames;
    cout<<"\nEnter the number of window size";
    cin>>ws;

    for(int i=0;i<ws;i++)
    {
        cout<<"\nSending Frames"<<outsanding++;
    }
    while(current<frames)
    {

        int r = rand()%10;
        if(r%2)
        {
            cout<<"\nAck for"<<current++<<"Received";

            if(outsanding<frames)
            {
                 cout<<"\nSending Frames"<<outsanding++;
            }
        }
        else
        {
            cout<<"\nTimer for packet "<<current<<" Time Out";
            outsanding = current;
            for(int i=0;i<ws&&outsanding<frames;i++)
            {
                  cout<<"\nSending Frames"<<outsanding++;
            }
        }
    }


}
