//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

long long mod(long long a, long long b, long long c){
    long long res = 1;
    for(int i=0; i<b; i++){
        res = (res*a)%c;
    }
    return res;
}

long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

long long generatePrime(long long n){
    srand(time(NULL));
    long long p = rand()%(n-2) + 2;
    while(gcd(n,p)!=1){
        p = rand()%(n-2) + 2;
    }
    return p;
}

long long extendedEuclid(long long a, long long b, long long *x, long long *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extendedEuclid(b%a, a, &x1, &y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return gcd;
}

long long modInverse(long long a, long long m){
    long long x, y;
    long long gcd = extendedEuclid(a, m, &x, &y);
    if(gcd!=1){
        return -1;
    }
    else{
        return (x+m)%m;
    }
}

int main(){
    long long p,q,n,phi,e,d;
    printf("Enter two prime numbers: ");
    scanf("%lld %lld", &p, &q);
    n = p*q;
    phi = (p-1)*(q-1);
    e = generatePrime(phi);
    d  = modInverse(e, phi);
    printf("Public Key Pair(p, e): (%lld %lld)\n",n,e);
    printf("Sender's Private Key: %lld\n",d);
    printf("Receiver's Public Key: %lld\n",e);
    long long plaintext, ciphertext, decrypted;
    printf("Enter the message(Must be less than %lld): ",n);
    scanf("%lld",&plaintext);
    ciphertext = mod(plaintext, e, n);
    decrypted = mod(ciphertext, d, n);
    if(decrypted==plaintext){
        printf("Message Successfully Decrypted: %lld\n", decrypted);
    }
    else{
        printf("Message Decryption Failed.\n");
    }
    return 0;
}