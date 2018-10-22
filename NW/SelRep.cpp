#include<iostream>
#include<cstdlib>
#include<cmath>

const int TOT_FRAMES=500;
const int FRAMES_SEND=16;

using namespace std;
class selRpeat{
	private:
		int fr_send_at_instance;
		int arr[TOT_FRAMES];
		int send[FRAMES_SEND];
		int rcvd[FRAMES_SEND];
		char rcvd_ack[FRAMES_SEND];
		int sw;
		int rw;       
	public:
		void input();
		void sender(int);
		void receiver(int);
};

void selRpeat::input(){
	int n;     
	int m;    


		cout <<"\n\nEnter the number of bits for the Sequence Number:\t";
		cin >> n;
		

	m=pow(2,n-1);
	int t=0;
	fr_send_at_instance=m;
	
	cout<<"\nNumber of frames sent in one go: "<<fr_send_at_instance<<"\n\n";


	for(int i=0;i<TOT_FRAMES;i++){
		
		arr[i]=t;
		t=(t+1)%m;
		
	}
	for(int i=0;i<fr_send_at_instance;i++){
		
		send[i]=arr[i];
		rcvd[i]=arr[i];
		rcvd_ack[i]='n';
	}
	
	rw=sw=fr_send_at_instance;
	sender(m);
}


void selRpeat::sender(int m){
	
	cout<<"\n<<-------- SENDER --------->>\n";

	for(int i=0;i<fr_send_at_instance;i++){
		if(rcvd_ack[i]=='n')
			cout<<"SENDER : Frame "<<send[i]<<" is sent\n";
	}
	receiver(m);
}


void selRpeat::receiver(int m) {
	
	cout<<"\n\t\t\t\t<<--------- RECIEVER --------->>\n";
	
	time_t t;
	int f,j,f1,a1;
	char ch;


	for(int i=0;i<fr_send_at_instance;i++){
		
		if(rcvd_ack[i]=='n'){
			f=rand()%10;
		
		
			if(f!=5){
				for(j=0;j<fr_send_at_instance;j++){
					if(rcvd[j]==send[i]) {
						
						cout<<"\t\tReciever : Frame "<<rcvd[j]<<" recieved correctly!!!\n";
						rcvd[j]=arr[rw];
						rw=(rw+1)%m;
						break;
					}
				}
				
				if(j==fr_send_at_instance)
					cout<<"\t\tReciever : Duplicate Frame "<<send[i]<<" discarded!!!\n";
					
				a1=rand()%5;
				
				
				if(a1==3) {
					cout<<"\t\t(Acknowledgement "<<send[i]<<" lost)\n";
					cout<<"\t\t(Sender timeouts-->Resend the frame)\n";
					rcvd_ack[i]='n';
				}
				
				else {
					cout<<"\t\t(Acknowledgement "<<send[i]<<" recieved)\n";
					rcvd_ack[i]='p';
				}
				
			}
			
			else{
				int ld=rand()%2;
				
				
				if(ld==0){
					cout<<"\t\tReceiver : Frame "<<send[i]<<" is damaged\n";
					cout<<"\t\tReceiver : Negative Acknowledgement "<<send[i]<<" sent\n";
				}else{
					cout<<"\t\t  (Frame : "<<send[i]<<" is lost)\n";
					cout<<"\t\t(Sender Timeout ----> please resend frame)\n";
				}
				rcvd_ack[i]='n';
			}
		}
	}
	for(j=0;j<fr_send_at_instance;j++) {
		
		if(rcvd_ack[j]=='n')
			break;
	}
	int i=0;
	for(int k=j;k<fr_send_at_instance;k++) {
		send[i]=send[k];
		if(rcvd_ack[k]=='n')
			rcvd_ack[i]='n';
		else
			rcvd_ack[i]='p';
			i++;
	}
	
	if(i!=fr_send_at_instance ){
		
		for(int k=i;k<fr_send_at_instance;k++){
			send[k]=arr[sw];
			sw=(sw+1)%m;
			rcvd_ack[k]='n';
		}
	}
	cout<<"\nDo you want to continue ::\t";
	cin>>ch;
	cout<<"\n";
	if(ch=='y')
		sender(m);
	else
		exit(0);
}


int main(){
	selRpeat sr;
	sr.input();
}
