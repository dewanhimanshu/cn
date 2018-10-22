#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main() 
{



   cout<<"1. USE CRC-12 AS GENERATOR POLYNOMIAL"<<endl;
   cout<<"2. USE CRC-16 AS GENERATOR POLYNOMIAL"<<endl;
   cout<<"3. USE CRC-32 AS GENERATOR POLYNOMIAL"<<endl;
   cout<<"\n\nSELECT ONE OPTION FROM ABOVE  "<<endl;

int ch;
cin>>ch;


	
	int *g;
	
	int gs;

int arr1[] ={1,1,0,0,0,0,0,0,0,1,1,1,1};
int  arr2[]={1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,};

int arr3[]={1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};

do{

switch(ch)
{


case 1 :   gs=12+1;
    
           g = arr1;
           
           break;

case 2  :  gs =16+1;
          
            g = arr2;
          
           break;

case 3  :  gs =32+1;
          
            g = arr3;
          
           break;


default :  cout<<"\n\nWRONG CHOICE!!!! "<<endl;

}

}while(ch>3);




	int i, j, k=0;

	int rs=gs-1;
	
	int n;	//No. of user entered bits

	
	
	
	/////////////////////////////////   Sender Side    //////////////////////////////////////

	cout<<"\n\n<<<------------------ Sender Side ------------------------->>>\n\n";

	cout<<"\nEnter no. of bits in your data: ";
	cin>>n;
	
	int t=n+rs;
	
	int a[t];
	int aTemp[t];
	int R[rs];
	
	int acopy[n+rs];
	
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

	cout<<"Entered Data: ";
	for(int i=0; i<n;++i) {
		cout<<a[i];
	}
	
	cout<<"\nDivisor: ";
	for(int i=0; i<gs;++i) {
		cout<<g[i];
	}
	
	for(int i=n; i<n+rs;++i) {
		a[i]=0;
	}
	
		
	for(int i=0; i<n+rs;++i) {

			acopy[i]=0;
			aTemp[i]=0;
		}
	
	
	
	
	//Dividing
	for(i=0;i<n;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (aTemp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
            	//xor
                if((aTemp[k]==1 && g[j]==1) || (aTemp[k]==0 && g[j]==0))
                {
                    aTemp[k]=0;
                }
                else
                {
                    aTemp[k]=1;
                }
            }
        }
    }
    
    
	//Extracting Remainder
    for(i=0,j=n;i<rs;i++,j++)
    {
        R[i]=aTemp[j];
    }
 
/*cout<<endl;
    for(i=0;i<rs;i++)
    {
        cout<<R[i];
    }*/
    
    
    k=0;
    //addding remainder
    for(int i = n; i < n+rs; ++i) {
    	a[i] = a[i]+R[k++];

	}
	
		
	cout<<"\nSent Data: ";
	for(i=0;i<n+rs;i++) {
        cout<<a[i];
    }
    
    
    //////////////////////////////////  Reciever Side   /////////////////////////////////
    
    

    
    cout<<"\n\n<<<------------------ Reciever Side ------------------------->>>\n\n";
    int sum=n+rs;

    //Generating error

    int r = rand()%sum;
    if(a[r]==0){
        a[r]=1;

    }
    else{
        a[r]=0;
    }
  
   
    
    cout<<"\nReceived Data: ";
	for(i=0;i<n+rs;i++) {
        cout<<a[i];
    }
    
	
	
    cout<<"\n\tChecking Recieved Data......"<<endl;
    
    //Dividing
    for(i=0;i<n;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (a[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((a[k]==1 && g[j]==1) || (a[k]==0 && g[j]==0))
                {
                    a[k]=0;
                }
                else
                {
                    a[k]=1;
                }
            }
        }
    }
    
    
    for(i=0,j=n;i<rs;i++,j++)
    {
        R[i]=a[j];
    }
    
    int f=0;
    for(i=0;i<rs;i++)
    {
        if(R[i] != 0) {
        	f=1;
        	break;
		}
    }
    
    if(f) {
    	cout<<"Recieved Data is Corrupted!!!!!!"<<endl;
	}
	else {
		cout<<"Recieved Data is Correct"<<endl;
	}
}


