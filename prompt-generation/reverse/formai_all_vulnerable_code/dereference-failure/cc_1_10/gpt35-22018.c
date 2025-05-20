//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//function to generate random prime number
int isPrime(int num)
{
    int i;
    if(num==2)
        return 1;
    if(num==1 || num%2==0)
        return 0;
    for(i=3;i<=sqrt(num);i+=2)
        if(num%i==0)
            return 0;
    return 1;
}

//function to find the greatest common divisor
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

//function to generate public key
int* generatePublicKey(int p, int q, int *k)
{
    int n = p*q;
    *k = (p-1) * (q-1);
    int e = 2;
    while(e < *k)
    {
        if(gcd(e, *k) == 1)
            break;
        else
            e++;
    }
    int *publicKey = (int*)malloc(2*sizeof(int));
    publicKey[0] = e;
    publicKey[1] = n;
    return publicKey;
}

//function to generate private key
int* generatePrivateKey(int p, int q, int k)
{
    int n = p*q;
    int d;
    int *privateKey = (int*)malloc(2*sizeof(int));
    for(d=1;d<k;d++)
    {
        if((d*p)%k == 1)
            break;
    }
    privateKey[0] = d;
    privateKey[1] = n;
    return privateKey;
}

int main()
{
    int p, q, k;
    //generating two prime random numbers
    do
    {
        p = rand()%100;
    }while(!isPrime(p));
    do
    {
        q = rand()%150;
    }while(!isPrime(q) || q == p);
    int* publicKey = generatePublicKey(p, q, &k);
    int* privateKey = generatePrivateKey(p, q, k);

    printf("Public Key (e,n): (%d,%d)\n", publicKey[0], publicKey[1]);
    printf("Private Key (d,n): (%d,%d)\n", privateKey[0], privateKey[1]);

    char msg[100], encMsg[100], decMsg[100];
    int i;

    printf("\nEnter message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strlen(msg)-1] = '\0';

    for(i=0;i<strlen(msg);i++)
        encMsg[i] = (char)pow(msg[i], publicKey[0]) % publicKey[1];

    encMsg[i] = '\0';
    printf("\nEncrypted Message: %s\n", encMsg);

    for(i=0;i<strlen(msg);i++)
        decMsg[i] = (char)pow(encMsg[i], privateKey[0]) % privateKey[1];

    decMsg[i] = '\0';
    printf("\nDecrypted Message: %s\n", decMsg);

    return 0;
}