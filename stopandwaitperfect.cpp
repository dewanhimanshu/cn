#include<iostream>
#include<stdlib.h>
using namespace std;
void simulate(int ch,int ch1,int i)
{
    switch(ch)
    {
        case 1: //Ack Lost or not
                cout<<endl<<"SENDER:"<<endl<<endl;
                cout<<"Frame "<<i<<" sent"<<endl;
                cout<<"Waitng for acknowledgement"<<endl;
                cout<<endl<<"RECEIVER:"<<endl<<endl;
                cout<<"Frame "<<i<<" receieved"<<endl;
                cout<<"Ack"<<i+1<<" sent"<<endl;
                switch(ch1)
                {
                case 1://Perfect Case
                        cout<<endl<<"SENDER:"<<endl<<endl;;
                        cout<<"Ack"<<i+1<<" received"<<endl;
                        cout<<"Preparing to send another frame"<<endl;
                        break;
                case 0://Ack lost
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"(Ack lost)"<<endl;
                        cout<<"Still Waiting For Acknowledgement"<<endl;
                        cout<<"....."<<endl;
                        cout<<"......."<<endl;
                        cout<<"Timer expires!"<<endl;
                        cout<<"Resending the Frame"<<endl;
                        cout<<"Frame "<<i<<" sent";
                        cout<<"Waitng for acknowledgement"<<endl;
                        cout<<endl<<"RECEIVER:"<<endl<<endl;
                        cout<<"Frame "<<i<<" received"<<endl;
                        cout<<"Ack"<<i+1<<" sent"<<endl;
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"Ack"<<i+1<<" received"<<endl;
                        cout<<"Preparing to send another frame"<<endl;
                        break;
                default: return;
                         break;
                }
                break;
        case 0://Frame  lost/discarded
                cout<<endl<<"SENDER:"<<endl<<endl;
                cout<<"Frame "<<i<<" sent"<<endl;
                cout<<"Waitng for acknowledgement"<<endl;
                switch(ch1)
                {
                case 1://frame corrupted
                        cout<<endl<<"RECEIVER:"<<endl<<endl;
                        cout<<"Frame "<<i<<" received"<<endl;
                        cout<<"Frame is corrupted"<<endl;
                        cout<<"Frame "<<i<<" discarded"<<endl;
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"Still Waiting For Acknowledgement"<<endl;
                        cout<<"....."<<endl;
                        cout<<"......."<<endl;
                        cout<<"Timer expires!"<<endl;
                        cout<<"Resending the Frame"<<endl;
                        cout<<"Frame "<<i<<" sent"<<endl;
                        cout<<"Waitng for acknowledgement"<<endl;
                        cout<<endl<<"RECEIVER:"<<endl<<endl;
                        cout<<"Frame "<<i<<" receieved"<<endl;
                        cout<<"Ack"<<i+1<<" sent"<<endl;
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"Ack"<<i+1<<" received"<<endl;
                        cout<<"Preparing to send another frame"<<endl;
                        break;
                case 0://frame lost
                        cout<<endl<<"RECEIVER:"<<endl<<endl;
                        cout<<"(Frame is lost)"<<endl;
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"Still Waiting For Acknowledgement"<<endl;
                        cout<<"....."<<endl;
                        cout<<"......."<<endl;
                        cout<<"Timer expires!"<<endl;
                        cout<<"Resending the Frame"<<endl;
                        cout<<"Frame "<<i<<" sent"<<endl;
                        cout<<"Waitng for acknowledgement"<<endl;
                        cout<<endl<<"RECEIVER:"<<endl<<endl;
                        cout<<"Frame "<<i<<" received"<<endl;
                        cout<<"Ack"<<i+1<<" sent"<<endl;
                        cout<<endl<<"SENDER:"<<endl<<endl;
                        cout<<"Ack"<<i+1<<" received"<<endl;
                        cout<<"Preparing to send another frame"<<endl;
                        break;
                default: return;
                         break;
                }
                break;
        default:return;
                break;
}}
int main()
{
    cout<<"SIMULATION OF STOP AND WAIT ARQ"<<endl;
    int i=1;
    int x,y;
    char c;
    while(true)
    {
        x=rand()%2;
        y=rand()%2;
        simulate(x,y,i);
        i++;
        cout<<endl<<"Enter Y to continue : ";
        cin>>c;
        cout<<endl;
        if(c!='Y'&&c!='y')
            break;
    }
}
