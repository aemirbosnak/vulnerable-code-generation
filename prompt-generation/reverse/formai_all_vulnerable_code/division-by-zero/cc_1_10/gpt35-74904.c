//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define MAX 100 

// function to generate prime number
int isPrime(int n)
{
    int i;
    for(i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

// function to find the GCD of two numbers
int gcd(int a,int b)
{
    int i,j;
    for(i=2;i<=a;i++)
    {
        if(a%i==0 && b%i==0)
        {
            j=i;
        }
    }
    return j;
}

// function to generate the public and private keys
void generateKeys(int p,int q,int *n,int *e,int *d)
{
    int phi,dummy;
    *n=p*q;
    phi=(p-1)*(q-1);
    do
    {
        *e=rand()%phi+2;     
    }while(gcd(phi,*e)!=1);
    do
    {
        dummy=(*e*(*d)-1)%phi;
        *d=*d+1;
    }while(dummy!=0);
}

// function to encrypt the data
void encrypt(char *text,int *cipher,int len,int e,int n)
{
    int i,num;
    for(i=0;i<len;i++)
    {
        num=text[i];
        cipher[i]=pow(num,e);
        cipher[i]%=n;
    }
}

// function to decrypt the data
void decrypt(int *cipher,char *text,int len,int d,int n)
{
    int i,num;
    for(i=0;i<len;i++)
    {
        num=cipher[i];
        text[i]=pow(num,d);
        text[i]%=n;
    }
}

// function to display the cipher text
void displayCipher(int *cipher,int len)
{
    int i;
    printf("\n\n");
    printf("The cipher text is : \n");
    for(i=0;i<len;i++)
    {
        printf("%d ",cipher[i]);
    }
}

// function to display the plain text
void displayPlain(char *text,int len)
{
    int i;
    printf("\n\n");
    printf("The plain text is : \n");
    for(i=0;i<len;i++)
    {
        printf("%c",text[i]);
    }
}

int main()
{
//taking input from the user
    int p,q,n=0,e=0,d=1;
    char text[MAX];
    int cipher[MAX];
    int len;

    printf("Enter the two prime numbers p and q : \n");
    scanf("%d%d",&p,&q);

    printf("Enter the plain text : \n");
    scanf("%s",text);

    len=strlen(text);

    srand(time(0));  // seed for random number generator

    if(!isPrime(p) || !isPrime(q))
    {
        printf("The numbers are not prime.\n");
        return 0;
    }

    generateKeys(p,q,&n,&e,&d);

    encrypt(text,cipher,len,e,n);

    displayCipher(cipher,len);

    decrypt(cipher,text,len,d,n);

    displayPlain(text,len);

    return 0;
}