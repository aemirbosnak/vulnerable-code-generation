//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 50

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int isPrime(int num){
    int i;
    for(i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int generatePrime(){
    int randNum = rand()%MAX + 1;
    while(!isPrime(randNum)){
        randNum = rand()%MAX + 1;
    }
    return randNum;
}

int powermod(int x, unsigned long int y, int p){
    int res = 1;
    x = x%p;
    while(y>0){
        if(y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int p,q,n,z,d,e,flag=0;
    char msg[MAX];
    int cipher[MAX],decrypted[MAX];
    int i;
    srand(time(NULL));
    p = generatePrime();
    q = generatePrime();
    while(p==q){
        q = generatePrime();
    }
    n = p*q;
    z = (p-1)*(q-1);
    do{
        e = rand()%z;
    }while(gcd(e,z)!=1);
    for(d=1;d<z;d++){
        if((e*d)%z==1){
            flag = 1;
            break;
        }
    }
    printf("Enter message to be encrypted: ");
    fgets(msg,MAX,stdin);
    for(i=0;i<MAX;i++){
        cipher[i] = powermod(msg[i],e,n);
        decrypted[i] = powermod(cipher[i],d,n);
    }
    printf("Original message: %s\n",msg);
    printf("Encrypted message: ");
    for(i=0;i<MAX;i++){
        printf("%d ",cipher[i]);
    }
    printf("\nDecrypted message: ");
    for(i=0;i<MAX;i++){
        printf("%c",decrypted[i]);
    }
    printf("\n");
    return 0;
}