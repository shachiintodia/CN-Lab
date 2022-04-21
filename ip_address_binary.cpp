#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert_decimal(long a);
int *  convert_binary(int a);

main()
{
int i,j,choice;	
long ip[4];	
int binary[32], decimal[4]; 
int dec;
int *bin;
char *piece;
char input[100];


printf("\t\tIP ADDRESS");
printf("\n1. Decimal to Binary");
printf("\n2. Binary to Decimal");
printf("\n\nEnter choice (1/2) : ");
scanf("%d",&choice);

if (choice==1)
{
	printf("\nEnter ip address:");
	scanf("%s",input);             
	
	piece = strtok(input,".");   
	i=0;

	do {
		ip[i++]=atoi(piece);		
		piece=strtok(NULL,".");		
	} while(piece && i<4);
	
	for(j=0;j<4;j++)  
	{
		bin = convert_binary( ip[j] );	
		for(i=0;i<8;i++)
		{
		binary[j*8+i]=bin[i];   
		}
	}
	
	printf("\nBinary Equivalent : ");
	for(i=0;i<32;i++)
	{
		if(i>0 && (i)%8==0) 
		printf(".");   
		
		printf("%d",binary[i]);		
	}
	
	printf("\n");
	
}

else if (choice==2)
{
printf("\nEnter ip address:");
scanf("%s",input);             

piece = strtok(input,".");   
i=0;
do {
ip[i++]=atoi(piece);		
piece=strtok(NULL,".");		
} while(piece && i<4);

for(j=0;j<4;j++)  
{
dec = convert_decimal( ip[j] );	
decimal[j]=dec;   
}

printf("\nDecimal Equivalent : ");
for(i=0;i<4;i++)
{
if(i>0 ) printf(".");   
printf("%d",decimal[i]);		
}
printf("\n");
}

else
printf("\nWrong choice");
}


int * convert_binary(int a)
{
int *num=(int *)malloc(sizeof(int)*8);  
for(int i=0;i<=7;i++)
{
num[7-i]=a%2;
a=a/2;
}
return num;
}

int convert_decimal(long a)
{
	int dec = 0, i = 0, rem;

  while (a!=0) {
    rem = a % 10;
    a /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
