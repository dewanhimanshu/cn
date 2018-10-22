#include<iostream>

using namespace std;

int main() 
{

	int n;
		int i, j, k=0;

	cout<<"Enter no. of bits in your data: ";
	cin>>n;
	
	int a[n];
	
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



	
	int g[] = {1, 0, 0, 1};
	
	int gs=4, rs=gs-1;

	
	int t[n+rs];

	
	
	for(i=0;i<n;i++)
    	{
		j=0;
		k=i;
		
        //check whether it is divisible or not
        if (t[k]>=g[j])
        {
            for(j=0, k=i; j<rs; j++, k++)
            {
                if((t[k]==1 && g[j]==1) || (t[k]==0 && g[j]==0))
                {
                    t[k]=0;
                }
                else
                {
                    t[k]=1;
                }
            }
        }
    }
    

    int R[rs];
    for(i=0,j=n;i<rs;i++,j++)
    {
        R[i]=t[j];
    }
 
    
    cout<<"Remainder: ";
    for(int i=0; i < rs; ++i)
    {
        cout<<R[i];
    }
    
}


