//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Function to check if a number is prime or not.
int isPrime(int n){
    if(n==1||n==0){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

//Function to compute gcd
int gcd(int a, int h){
    if(h==0){
        return a;
    }
    return gcd(h,a%h);
}

int main(){

    //Generating 2 prime numbers p and q randomly
    srand(time(NULL));
    int p = rand()%100;
    while(!isPrime(p)){
        p = rand()%100;
    }
    int q = rand()%100;
    while(!isPrime(q)){
        q = rand()%100;
    }

    int n = p*q;    //Computing n
    int phi = (p-1)*(q-1);   //Computing phi of n
    
    //Generating a random number e which is coprime to phi
    int e = rand()%phi;
    while(gcd(e,phi)!=1){
        e = rand()%phi;
    }

    //Computing d
    int k=2;    //A constant value
    int d = (k*phi + 1)/e;

    //Displaying the Public and Private keys
    printf("Public Key: {%d, %d}\n", n, e);
    printf("Private Key: {%d, %d}\n", n, d);

    return 0;
}