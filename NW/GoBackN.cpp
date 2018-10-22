#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

const int TOT_FRAMES=500;
const int FRAMES_SEND=16;

class GoBackN{
	private:
		int fr_send_at_instance;
		int arr[TOT_FRAMES];
  		int arr1[FRAMES_SEND];
  		int sw;	
  		int rw; 
	public:
  		GoBackN() {
  			
  			sw = 0;
			rw = 0;
		  };
  		void input();
  		void sender(int m);
		void reciever(int m);
};


void GoBackN :: input(){
	
 	int n; 
 	int m;  
	
		cout <<"\nEnter the number of bits for the Sequence Number :";
 		cin >> n;
 		
	m = pow (2 , n);
	int t = 0;
	fr_send_at_instance=m-1; 
	
	cout<<"\nNumber of frames sent in one go: "<<fr_send_at_instance<<"\n\n";
	for (int i = 0 ; i < TOT_FRAMES ; i++){
		arr[i] = t;
		t = (t + 1) % m; 
	}
	sender(m);
}

void GoBackN :: sender(int m) {
	cout<<"\n<<-------- SENDER --------->>\n";
	int j = 0;
	
	for (int i = sw ; i < sw + fr_send_at_instance ; i++) {
		arr1[j++] = arr[i];
	}
	
	for (int i = 0 ; i < j ; i++){
		cout << "SENDER : Frame " <<arr1[i]<<" SENT!!!\n";		
	}
	
	reciever (m);
}

void GoBackN :: reciever(int m){
	cout<<"\n\t\t\t\t<<--------- RECIEVER --------->>\n";

	srand(rw); 

	int f = rand() % fr_send_at_instance;


	if (f != 3 ){

		int i=0;

		for (i = 0; i < fr_send_at_instance; i++){
			if (rw == arr1[i]){
				cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " recieved correctly\n";
				rw = (rw + 1) % m;
			}else{
				cout << "\t\t\t\tRECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
			}
		}

		f = rand() % fr_send_at_instance;

   
		if (f>fr_send_at_instance/2){

			cout << "\t\t\t\t(Acknowledgement " << arr1[f] << " & all after this lost)\n";
			cout << "\t\t\t\t (SENDER TIMEOUTS --> RESEND THE FRAME)\n";
			sw = arr1[f];
		}

		else{
			sw = (sw + fr_send_at_instance) % m;
			cout << "\t\t\t\t(Acknowledgement " << arr[rw] << " is Sent!!!)\n";
		}
	}
	
	else {
		
		int f1 = rand() % fr_send_at_instance;

   		
		for (int i = 0 ; i < f1 ; i++) {
			if (rw == arr1[i]){
				cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " recieved correctly\n";
				rw = (rw + 1) % m;
			}
			
			else {
				cout << "\t\t\t\tRECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
			}
  		}

		f = rand() % 2;
		

		if (f == 0){
			cout<<"\t\t\t\tRECIEVER : Frame " << arr1[f1] << " damaged\n";
			cout<<"\n\t\t\t\tRECIEVER : Damaged frame " << arr1[f1] << " discarded\n\n";
		}
		
		else
			cout << "\t\t\t\t            (Frame " << arr1[f1] << " lost)\n";
			
			//N frame discarded
		for (int i = f1 + 1 ; i < fr_send_at_instance ; i++)
			cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " discarded\n";
			
			
		cout << "\t\t\t\t (SENDER TIMEOUTS --> RESEND THE FRAME)\n";
		sw = arr1[f1];
	}
	
	char ch;
	cout<<"\nDo you want to continue(y/n) ::\t";
	cin>>ch;
	if(ch=='y')
		sender(m);
	else
		exit(0);
}
int main(){
	
	GoBackN g;
	g.input();
	return 0;
}
