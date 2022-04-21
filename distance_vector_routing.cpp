#include <bits/stdc++.h> 
using namespace std; 

struct node
{
    unsigned dist[20]; 
    unsigned from[20];
}rt[10];

int main()
{
    int costmat[20][20]; 
    int nodes,i,j,k,count=0;
   
    cout<<"\n Enter the number of nodes : "; 
    cin>>nodes;
    
    cout<<"\n Enter the cost matrix : \n"; 
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            cin>>costmat[i][j]; 
            costmat[i][i]=0; 
            rt[i].dist[j]=costmat[i][j]; 
            rt[i].from[j]=j;
        }
    }
    
    do
    {
        count=0; 
        for(i=0;i<nodes;i++)
        {
            for(j=0;j<nodes;j++)
            {
                for(k=0;k<nodes;k++)
                {
                    if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j]; 
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0); 
    
    for(i=0;i<nodes;i++)
    {
        cout<<"\n\n For router"<<i+1<<" "; 
        for(j=0;j<nodes;j++)
        cout<<"\n Node "<<j+1<<" via "<<rt[i].from[j]+1<<" Distance "<<rt[i].dist[j];
    }
    cout<<("\n\n"); 
    return 0;
}

