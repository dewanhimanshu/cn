#include<iostream>
using namespace std;

class Receiever
{
    int ack;

    public:
        void receive(int x)
        {
            cout<<"\nReceived::"<<x;
            ack = x;
        }
        int feedback()
        {
            cout<<"\nSending ack:"<<1-ack;
            return (1-ack);
        }
};

class Sender
{
    int c=0;
    Receiever r;
    public:
        void send()
        {
            cout<<"\nSending::"<<c;
            r.receive(c);
        }
        void getAck()
        {
            c = r.feedback();
            cout<<"\nReceived ack::"<<c;
        }

};

int main()
{
    int num;
    Sender s;
    cout<<"\nEnter the number of packets to be send";
    cin>>num;
    for(int i=0;i<num;i++)
    {

        s.send();
        s.getAck();
    }
}
