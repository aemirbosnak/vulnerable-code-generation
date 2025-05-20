//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Function to check if a number is prime
int isPrime(int num){
    int i;
    if(num == 2 || num == 3){
        return 1;
    }
    if(num%2 == 0){
        return 0;
    }
    for(i=3; i<=sqrt(num); i+=2){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

//Function for calculating gcd of two numbers
int gcd(int a, int b){
    int temp;
    while(b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main(){
    srand(time(NULL));

    //Generating two prime numbers p and q
    int p, q;
    do{
        p = rand()%100 + 1;
    }while(!isPrime(p));
    do{
        q = rand()%100 + 1;
    }while(!isPrime(q));

    //Calculating n and phi(n)
    int n = p*q;
    int phi_n = (p-1)*(q-1);

    //Generating an integer e such that gcd(e,phi_n) = 1
    int e;
    do{
        e = rand()%phi_n + 1;
    }while(gcd(e,phi_n) != 1);

    //Calculating d such that (d*e) mod phi_n = 1
    int d = 1;
    while(((d*e)%phi_n) != 1){
        d++;
    }

    //Printing the public and private keys
    printf("Public Key: (%d,%d)\n", e, n);
    printf("Private Key: (%d,%d)\n", d, n);

    return 0;
}