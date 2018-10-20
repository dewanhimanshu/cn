#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int r = 1;
int receiver(int s)
{
    srand(time(NULL));
    int c = rand()%10;
    if(c<4)
    {
        cout<<"\nFrame received successfully";
        r = 1-r;
        cout<<"\nSending ack";
    }
    else
    {

        cout<<"\nNot success";
    }
    return r;
}


void sender()
{
    cout<<"\nEnter the number of frames you want";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            a[i]=1;
        else
            a[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nSending the packet::"<<a[i];
        int ack = receiver(a[i]);
        while(ack==a[i])
        {
            cout<<"\n************Resending frame**************";
            ack = receiver(a[i]);
        }
        if(ack!=a[i])
        {
            cout<<"\nack received :: of"<<a[i];
        }
    }
}
int main()
{


   sender();

}
