#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    int frames;
    cout<<"\nEnter the Frames";
    cin>>frames;

    cout<<"\nEnter the ws";
    int ws;
    cin>>ws;
    int start = 0;
    int out = 0;
    int in = 0;
    for(int i=0; i<ws; i++)
    {
        cout<<"\nSending Frames "<<start++;
    }
    srand(time(NULL));
    int total = 0;
    while(total<frames)
    {
        start = ws;
        out = 0;
        in = 0;


        while(in<start)
        {
            int r = rand()%10;
            if(r)
            {
                if(out<start)
                {
                    cout<<"\nRecieved Frame "<<(out++)%ws;
                    cout<<"\nack Send for Frame"<<out;
                }
                int c = rand()%10;
                if(c/2)
                {
                    cout<<"\nRecieved Ack"<<out;
                    in++;
                    total++;

                }
                else
                {
                    cout<<"\nDoes Not Recieved Ack Timer Out"<<out;
                    for(int i=out; i<start; i++)
                    {
                        cout<<"\nFrames Discarded"<<i;
                    }
                    cout<<"\nResending";

                    for(int i=out; i<start; i++)
                    {
                        cout<<"\nSending Frames "<<i;
                    }
                }
            }
        }
    }




}
