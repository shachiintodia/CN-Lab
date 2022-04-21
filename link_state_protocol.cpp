#include<iostream> 
#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back 
#define ff first
#define ss second 
#define mod 1000000007 
using namespace std;
int main()
{
	int count,src_router,i,j,k,w,v,min;
	int cost_matrix[100][100],dist[100],last[100]; 
	int flag[100];
	
	cout<<"\nEnter the no of routers : "; 
	cin>>count;
	cout<<"\nEnter the cost matrix values :\n"; 
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
		cin>>cost_matrix[i][j]; 
		if(cost_matrix[i][j]<0)
			cost_matrix[i][j]=1000;
		}
	}
	
	cout<<"\nEnter the source router : "; 
	cin>>src_router; 
	
	for(v=0;v<count;v++)
	{
		flag[v]=0; 
		last[v]=src_router;
		dist[v]=cost_matrix[src_router][v];
	}
	
	flag[src_router]=1; 
	for(i=0;i<count;i++)
	{
		min=1000; 
		for(w=0;w<count;w++)
		{
			if(!flag[w] && dist[w]<min)
			{
				v=w; 
				min=dist[w];
			}
		}
		flag[v]=1; 
		
		for(w=0;w<count;w++)
		{
			if(!flag[w])
			{
				if(min+cost_matrix[v][w]<dist[w])
				{
					dist[w]=min+cost_matrix[v][w]; 
					last[w]=v;
				}
			}
		}
	}
	
	for(i=0;i<count;i++)
	{
		cout<<"\n"<<src_router<<"==> "<<i<<" :\nPath taken : "<<i; 
		w=i;
		while(w!=src_router)
		{
			cout<<"<--"<<last[w]; 
			w=last[w];
		}
		cout<<"\nShortest path cost : "<<dist[i];
	}
	return 0;
}
