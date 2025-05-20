//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a % b);
}

int power(int a, int b, int mod){
    int p = 1;
    a = a % mod;
    while(b > 0){
        if(b & 1)
            p = (p*a) % mod;
        b = b>>1;
        a = (a*a) % mod;
    }
    return p;
}

int isPrime(int num){
    if(num==1 || num==0)
        return 0;

    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int generatePrime(){
    int num;
    do{
        num = rand()%1000;
    }while(!isPrime(num));
    return num;
}

int main(){
    int p = generatePrime();
    int q = generatePrime();

    int n = p*q;
    int phi = (p-1)*(q-1);

    srand(time(0));
    int e;
    do{
        e = rand()%(phi-2)+2;
    }while(gcd(e, phi)!=1);

    int d;
    for(int i=1;i<phi;i++){
        if((i*e)%phi==1){
            d = i;
            break;
        }
    }

    printf("p: %d, q: %d, n: %d, phi(n): %d, e: %d, d: %d\n", p, q, n, phi, e, d);

    int msg;
    printf("Enter Message: ");
    scanf("%d", &msg);

    int encrypted_msg = power(msg, e, n);
    printf("Encrypted Message: %d\n", encrypted_msg);

    int decrypted_msg = power(encrypted_msg, d, n);
    printf("Decrypted Message: %d\n", decrypted_msg);

    return 0;
}