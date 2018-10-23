#include<iostream>
#include<limits.h>
using namespace std;
int v;
int e;
int findminvertex(int distance[] , bool visited[] ,int n)
{
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(minVertex==-1||distance[i]<distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void dijstra(int a[100][100],int n)
{
    int distance[n];
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for(int i=1;i<n;i++)
    {
        int minVertex = findminvertex(distance,visited,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++)
        {
            if(a[minVertex][j]!=0 && !visited[j] && distance[minVertex]!=INT_MAX)
            {
                    int dis = distance[minVertex] + a[minVertex][j] ;
                    if( dis < distance[j])
                    {
                        distance[j] = dis;
                    }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"\nMin distance to::"<<i<<" is "<<distance[i];

    }
}


int main()
{

    cout<<"\nEnter the number of vertices";
    cin>>v;
    cout<<"\nEnter the number of edges";
    cin>>e;
    int a[100][100];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            a[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter the vertices and with weight";
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y] = z;
        a[y][x] = z;
    }

    cout<<"\n***adjancey matrix entered is*******\n";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<"\t"<<a[i][j];
        }
        cout<<endl;
    }


    dijstra(a,v);
}
