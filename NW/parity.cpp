#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


//Odd bit errors

int main() {


    int k=0, count=0,p;
    string par;
    char temp;

    int n;

    cout<<"Enter number of bits of data: ";
    cin>>n;

    int a[n];

    cout<<"Enter data (0/1):\n";
    cin>>temp;

    do{

        if(temp=='0'||temp=='1'){

            a[k++]=((int)temp-48);
        }
        else{

            cout<<"Invalid Input!!  Try Again..\n";
        }

        if(k>=n){

            break;
        }
            cin>>temp;


    }while(true);

    cout<<"Entered data: ";
    for(int i=0; i<n;++i){

        cout<<a[i];
    }
    cout<<endl;


    cout<<"Enter parity (even/odd):\n";
    cin>>par;



    for(int i=0; i<n;++i){
        if(a[i]==1){

            count++;
        }
    }

    if(par.compare("even")==0) {

        if(count%2==0){
            p=0;
        }
        else{
            p=1;
        }

    }

    else {

        if(count%2==0){
            p=1;
        }
        else{
            p=0;
        }

    }

    cout<<"Code Word: ";
    for(int i=0; i<n;++i){

        cout<<a[i];
    }
    cout<<p<<endl;


    int r = (rand()%n);
    if(a[r]==0) {
        a[r]=1;

    }
    else{
        a[r]=0;
    }

    cout<<"Recieved Data: ";
    for(int i=0; i<n;++i){

        cout<<a[i];
    }
    cout<<p<<endl;

    cout<<"Checking...\n";
    count=0;
    for(int i=0; i<n;++i){
        if(a[i]==1){

            count++;
        }
    }


    if(par.compare("even")==0) {

        if(count%2==0 && p==0){
            cout<<"Recieved Data is correct\n";
        }
        else if((count%2)!=0 && p==1){
            cout<<"Recieved Data is correct\n";
        }
        else {
            cout<<"Recieved Data is currupted!!!!\n";

        }

    }

    else {

        if(count%2==0 && p==1){
            cout<<"Recieved Data is correct\n";
        }
        else if((count%2)!=0 && p==0){
            cout<<"Recieved Data is correct\n";
        }
        else{
            cout<<"Recieved Data is currupted!!!!\n";

        }

    }

        return 0;
    }
