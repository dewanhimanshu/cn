#include<iostream>
#include<limits.h>
using namespace std;
int get_distance(int r[] , int n ,int x);
int g = 0;
class rout
{
    public:
        int distances[10];
        int via[10];
        int neigh[10];
        int n;
        int id;
        int d;
        int table_length;
            rout()
            {
                for(int i=0;i<10;i++)
                {
                    distances[i] = INT_MAX;
                }
            }

        void routing_table()
        {
            cout<<"\nEnter the routing table of router "<<id;
            for(int i=0;i<table_length;i++)
            {
               cout<<"\nEnter the distance from router "<<i;
               cin>>distances[i];
            }
        }
        void test()
        {
            cout<<"\routing table of router "<<id;
            for(int i=0;i<table_length;i++)
            {
                cout<<"\nRouter Number\tDistance";
                cout<<i<<"\t"<<distances[i];

            }
        }
        void print()
        {

            for(int i=0;i<table_length;i++)
            {
                if(i==id)
                {
                    distances[i] = 0;
                }

                int d = get_distance(neigh,n,i) + distances[g];


                if(d<distances[i])
                {
                    distances[i] = d;
                    via[i] = g;
                }

            }

            for(int i=0;i<table_length;i++)
            {
                cout<<"\nRouter Number\tDistance\tvia\n";
                cout<<i<<"\t"<<distances[i]<<"\t"<<via[i];

            }
        }

};
rout router[10];

int get_distance(int r[] , int n ,int x)
{
    int min = INT_MAX;



    for(int i=0;i<n;i++)
    {

        int y = r[i];
       // cout<<endl<<y;
        if(min>router[y].distances[x])
        {
            min = router[y].distances[x];
            g = y;
        }
    }
    return min;
}

int main()
{

    int r;
    cout<<"\nEnter the number of routers in subnet::";
    cin>>r;
    for(int i=0;i<r;i++)
    {

        router[i].id = i;
        router[i].table_length = r;

    }
    cout<<"\nEnter the no of router whose routing table is to be found::";
    int t;
    cin>>t;

    cout<<"\nEnter number of the neighbouber of::"<<t ;
    int neigh;
    cin>>neigh;

    router[t].n = neigh;


    cout<<"\nEnter name of neigbours::";
    for(int i=0;i<neigh;i++)
    {
        int x;
        cin>>x;
        router[t].neigh[i] = x;
    }

    for(int i=0;i<neigh;i++)
    {
        int x = router[t].neigh[i];
        cout<<"\nEnter the distance of router to router"<<x;
        cin>>router[t].distances[x];
    }

    cout<<"\nEnter the routing table of neighbours::";
    for(int i=0;i<router[t].n;i++)
    {
        int x = router[t].neigh[i];
        router[x].routing_table();
    }

    cout<<"\nRouting table for neighbour::";
    for(int i=0;i<router[t].n;i++)
    {
        int x = router[t].neigh[i];
        router[x].test();
    }

    cout<<"\nRouting table of the node::"<<t;
    router[t].print();



}
