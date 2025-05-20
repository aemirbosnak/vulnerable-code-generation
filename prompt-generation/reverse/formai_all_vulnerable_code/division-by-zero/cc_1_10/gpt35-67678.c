//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long int gcd(long long int a, long long int b) {
    long long int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long int power(long long int a, long long int b, long long int mod) {
    long long int ans = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

int main() {
    long long int p,q,n,totient,e,d,plainText,cipherText;

    printf("Enter two prime numbers (p and q): ");
    scanf("%lld %lld", &p, &q);
    n = p * q;
    totient = (p-1) * (q-1);

    do {
        srand(time(NULL));
        e = rand() % totient;
    }while(gcd(e, totient) != 1);

    d = 1;
    do {
        d += 1;
    }while((d * e) % totient != 1);

    printf("Public Key: %lld\n", e);
    printf("Private Key: %lld\n", d);

    printf("Enter a number to encrypt: ");
    scanf("%lld", &plainText);

    cipherText = power(plainText, e, n);

    printf("Cipher Text: %lld\n", cipherText);

    plainText = power(cipherText, d, n);

    printf("Plain Text: %lld\n", plainText);

    return 0;
}