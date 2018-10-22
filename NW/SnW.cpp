#include<iostream>
using namespace std;


class Receiver
{
	int ack;
	
	public:
		void receive(int x)
		{
			cout<<"\n\t\t\t\t\t\tReceived "<<x;
			ack=x;
		}
		
		int feedback()
		{
			cout<<"\n\t\t\t\t\t\tSending Ack"<<1-ack;
			return (1-ack);
		}
};


class Sender
{
	int c;
	Receiver r;
	
	public:
		Sender()
		{
			c=0;
		}
		void send()
		{
			cout<<"\nSending "<<c;

			r.receive(c);
		}
		
		void getAck()
		{
			c=r.feedback();
			cout<<"\nReceived Ack "<<c;
		}
};


int main()
{
	int num;
	Sender s;
	cout<<"\t\tSTOP AND WAIT NOISELESS";
	cout<<"\n\nEnter number of packets to be sent :\t";
	cin>>num;
	cout<<"\n\nSENDER\t\t\t\t\t\tRECEIVER";
	
	for(int i=0;i<num;i++){
	//	cout<<"\n==>>PACKET "<<(i+1);
		s.send();
		s.getAck();
	}

	cout<<"\n\n-----TRANSMISSION COMPLETE------\n";
	return 0;
}
