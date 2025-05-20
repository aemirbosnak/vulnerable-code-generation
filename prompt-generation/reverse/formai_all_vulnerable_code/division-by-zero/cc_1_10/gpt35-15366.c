//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Function checks if the given number is prime
int isPrime(unsigned long int n){
    if(n <= 1) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

// Function returns the gcd of two numbers
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// Function returns the power of a given number
int power(int x, unsigned int y, int p){
    int res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    unsigned int p, q, n, phi_n, e, d;
    int flag = 1;

    // Generate 2 random prime numbers
    srand(time(0));
    while(flag){
        p = rand() % 500 + 1;
        q = rand() % 500 + 1;
        if(isPrime(p) && isPrime(q)) flag = 0;
    }

    // Calculate n = p*q
    n = p*q;

    // Calculate phi_n = (p-1)*(q-1)
    phi_n = (p-1)*(q-1);

    // Choose an integer e such that 1 < e < phi_n and gcd(e, phi_n) = 1
    srand(time(0));
    flag = 1;
    while(flag){
        e = rand() % phi_n;
        if(gcd(e,phi_n) == 1) flag = 0;
    }

    // Calculate d such that d*e = 1 (mod phi_n)
    int k = 1;
    while(1){
        if((k*phi_n + 1) % e == 0){
            d = (k*phi_n + 1)/e;
            break;
        }
        k++;
    }

    printf("Public Key: (%d,%d)\n", e, n);
    printf("Private Key: (%d,%d)\n", d, n);

    int message;
    printf("Enter the message to be sent (should be less than %d): ", n);
    scanf("%d", &message);

    // Encryption
    int cipherText = power(message, e, n);
    printf("Encrypted Message is: %d\n", cipherText);

    // Decryption
    int plainText = power(cipherText, d, n);
    printf("Decrypted Message is: %d\n", plainText);

    return 0;
}