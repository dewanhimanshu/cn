#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;



int main() {

	int n;

	cout<<"\n\n<<<------------------ Sender Side ------------------------->>>\n\n";

	cout<<"Enter no. of bits in your data: ";
	cin>>n;

	int r=1;

	while(true){
		if(n+r+1<=(int)pow(2,r)){
			break;
			
		}
		else {
			r++;
		}
	}

	int m=n+r;

	int a[n],data[m], k=0;
 
	for (int i=0;i<r;++i){
		check[i]=0;
	}

	for (int i=0;i<m;++i){
		data[i]=0;
	}

	char temp;
	cout<<"Enter your data bit by bit: \n";
	cin>>temp;



	do{
		if(temp=='0'|| temp=='1') {
			a[k++] = (int) (temp-'0');
		}
		else {
			cout<<"Invalid Data!!!\nTry Again...\n";
		}

		if(k>=n){
			break;
		}

		cin>>temp;

	}while(true);

	k=0;
	int p=0;
	for(int i=0;i<m;i++) {
		if ((i+1)==(int)pow(2,p)) {
			p++;
			continue;
		}
		else
		data[i]=a[k++];
	} 


int ctr;
for(int i=0;i<m;i++) {

	if(data[i]==1) {

	ctr=i+1;

		for (int mask = 1; mask != 0; mask <<= 1) {
		 if ((mask & ctr) != 0) {

			if (mask==1)
			   check[0]++;
			else if(mask==2)
			   check[1]++;
			else if(mask==4)
			   check[2]++;
			else if(mask==8)
			   check[3]++;
		  }
		}
	}
}


p=0;
k=0;

for(int i=0; i<r; ++i) {

	while(k<m) {

		if(k+1==(int)pow(2,p)){ 

			if(check[i]%2==0)
				data[k]=1;
			else
				data[k]=0;

			k++;
			p++;
			break;
		}

		else {
			k++;
		}

	}

}



cout<<"Codeword Using Odd parity: ";
for (int i=0;i<m;++i){
		cout<<data[i];
}

int copy[m];
for (int i=0;i<m;++i) {

	copy[i]=data[i];
}

cout<<"\nData Sent: ";
for (int i=0;i<m;++i){
	cout<<copy[i];
}

int ran = (rand()%m);
    if(copy[ran]==0){
        copy[ran]=1;

    }
    else{
        copy[ran]=0;
    }
    

    cout<<"\n\n<<<------------------ Reciever Side ------------------------->>>\n\n";

 cout<<"\nData Received: ";
 for (int i=0;i<m;++i){ 
	cout<<copy[i];	
 }

cout<<"\n\tChecking............. ";

int errBit=-1;

for(int i = 0; i < m; ++i) {
	if(data[i] != copy[i]) {
		errBit = i+1;
	}
}

if(errBit != -1) {

cout<<"\nError bit: "<<errBit<<endl;

if(copy[errBit-1]==1) {
		copy[errBit-1]=0;
	}
	else {
		copy[errBit-1]=1;
	} 
	
	
	cout<<"\nData after correction: ";
	for (int i=0;i<m;++i){ 
	cout<<copy[i];
	cout<<endl;	
 	}
}

else {
	cout<<"Received Data is correct";
	cout<<endl;
}

 
}
