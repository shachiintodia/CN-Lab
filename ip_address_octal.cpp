#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert_decimal(long a);
int convert_octal(int a);

main()
{
int i,j,choice;	
long ip[4];	
int output[4]; 
int temp;
char *piece;
char input[100];


printf("\t\tIP ADDRESS");
printf("\n1. Decimal to Octal");
printf("\n2. Octal to Decimal");
printf("\n\nEnter choice (1/2) : ");
scanf("%d",&choice);

if (choice==1)
{
	printf("\nEnter ip address : ");
	scanf("%s",input);             
	
	piece = strtok(input,".");   
	i=0;

	do {
		ip[i++]=atoi(piece);		
		piece=strtok(NULL,".");		
	} while(piece && i<4);
	
	for(j=0;j<4;j++)  
	{
		temp = convert_octal( ip[j] );	
		output[j]=temp;   
	}
	
	printf("\nOctal Equivalent : ");
	for(i=0;i<4;i++)
	{
		if(i>0 ) 
		printf(".");   
	
		printf("0%d",output[i]);		
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
	temp = convert_decimal( ip[j] );	
	output[j]=temp;   
	}
	
	printf("\nDecimal Equivalent : ");
	for(i=0;i<4;i++)
	{
	if(i>0 ) printf(".");   
	printf("%d",output[i]);		
	}
	printf("\n");
}

else
printf("Wrong Choice");

}

int convert_octal(int a)
{
	int octalNum = 0, countval = 1;
 
    while (a != 0) {
        int remainder = a % 8;
        octalNum += remainder * countval;
        countval = countval * 10;
        a /= 8;
    }
    return octalNum;
}

int convert_decimal(long n)
{
	int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
 
        int last_digit = temp % 10;
        temp = temp / 10;
 
       dec_value += last_digit * base;
 
        base = base * 8;
        }
 
    return dec_value;
}
