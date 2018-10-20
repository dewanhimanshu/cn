#include<iostream>
using namespace std;
class frame
{
    public:
        int n;
};
void  receiver(frame f)
{
        cout<<"\nReceived frame is :"<<f.n;
}
void sender(frame f)
{
    receiver(f);
}



int main()
{
    cout<<"enter the number of frames you want to sent";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        frame f ;
        f.n = i;
        sender(f);
    }
}
