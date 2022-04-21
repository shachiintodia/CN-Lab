#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
 
int checkip (char s[])
{
	int ip[4];
	char str[100];
	char *piece;
	int i=0, dotcount=0;
			
	for (i=0;s[i]!='\0';i++)
	{
		str[i]=s[i];
		if(s[i]=='.')
		dotcount++;
	}
	str[i]='\0';
	
	if(dotcount!=3)
	{
		cout<<"\nINVALID IP ADDRESS";
		return 0;
	}
	
	i=0;
	piece = strtok(str,".");   
	do {
		ip[i++]=atoi(piece);		
		piece=strtok(NULL,".");		
	} while(piece);
	
	for (i=0;i<4;i++)
	{
		if(ip[i]>255)
		{
			cout<<"\nINVALID IP ADDRESS";
			return 0;
		}
	}
	return 1;
}

char findClass(char str[])
{
    char arr[4];
    int i = 0;
    while (str[i] != '.')
    {
        arr[i] = str[i];
        i++;
    }
    i--;
 
    int ip = 0, j = 1;
    while (i >= 0)
    {
        ip = ip + (str[i] - '0') * j;
        j = j * 10;
        i--;
    }
 
    // Class A
    if (ip >=1 && ip <= 126)
        return 'A';
 
    // Class B
    else if (ip >= 128 && ip <= 191)
        return 'B';
 
    // Class C
    else if (ip >= 192 && ip <= 223)
        return 'C';
 
    // Class D
    else if (ip >= 224 && ip <= 239)
        return 'D';
 
    // Class E
    else
        return 'E';
}
 
void separate(char str[], char ipClass)
{
    char network[12], host[12];
    for (int k = 0; k < 12; k++)
        network[k] = host[k] = '\0';
 
    if (ipClass == 'A')
    {
        int i = 0, j = 0;
        while (str[j] != '.')
            network[i++] = str[j++];
        i = 0;
        j++;
        while (str[j] != '\0')
            host[i++] = str[j++];
        cout<<"\nNetwork ID is "<<network;
        cout<<"\nHost ID is "<<host;
    }
 
    else if (ipClass == 'B')
    {
        int i = 0, j = 0, dotCount = 0;
 
        while (dotCount < 2)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;
 
        while (str[j] != '\0')
            host[i++] = str[j++];
 
        cout<<"\nNetwork ID is "<<network;
        cout<<"\nHost ID is "<<host;
    }
 
    else if (ipClass == 'C')
    {
        int i = 0, j = 0, dotCount = 0;
 
        while (dotCount < 3)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
 
        i = 0;
        j++;
 
        while (str[j] != '\0')
            host[i++] = str[j++];
 
        cout<<"\nNetwork ID is "<<network;
        cout<<"\nHost ID is "<<host;
    }
 
    else
        cout<<"\nIn this Class, IP address is not divided into Network and Host ID";
}
 
int main()
{
	char str[100];
	cout<<"Enter IP Address : ";
	cin>>str;
	if (checkip(str)==1)
	{
    char ipClass = findClass(str);
    cout<<"\nGiven IP address belongs to Class "<<ipClass;
    separate(str, ipClass);
	}
    return 0;
}
