//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// function to generate random prime number
int genPrime()
{
    int num = rand() % 100; // range of the prime number generated
    if (num < 2) num += 2; // make sure the number is not less than 2
    int i;
    for(i=2; i<=sqrt(num); i++) {
        if(num%i == 0) break; // if it is divisible, break
    }
    if(i > sqrt(num)) return num; // if it is prime, return
    else return genPrime(); // if not, generate again
}

int generateKeys(int p, int q, int *n, int *e, int *d)
{
    *n = p*q;
    int phi = (p-1)*(q-1);
    do {
        *e = rand() % phi; // choose a random number 1<e<phi
    } while(gcd(*e, phi) != 1); // make sure they are coprime
    int k = 1;
    while(1) {
        if(((k*phi)+1)%*e == 0) break; // calculate the d value
        k++; 
    }
    *d = ((k*phi)+1)/(*e);
}

int encrypt(int m, int e, int n)
{
    int st = m, ct = 1;
    for(int i=0; i<e; i++) {
        ct = (ct*st) % n;
    }
    return ct;
}

int decrypt(int ct, int d, int n)
{
    int st = ct, dt = 1;
    for(int i=0; i<d; i++) {
        dt = (dt*st) % n; // compute the message
    }
    return dt;
}

int main()
{
    srand(time(NULL));
    int p = genPrime(); // generate a large prime number
    int q = genPrime(); // repeat for a second prime number
    int n,e,d;
    generateKeys(p,q,&n,&e,&d);

    char msg[100];
    printf("Enter Message: ");
    fgets(msg, 100, stdin); // take input message

    int len = strlen(msg);
    int cipher[len];
    for(int i=0; i<len; i++) {
        cipher[i] = encrypt((int)msg[i], e, n); // encrypt each character of the message
    }

    printf("Encrypted message: ");
    for(int i=0; i<len; i++) {
        printf("%d ", cipher[i]); // print the encrypted message (cipher)
    }

    printf("\nDecrypted message: ");
    for(int i=0; i<len; i++) {
        printf("%c", (char)decrypt(cipher[i], d, n)); // print the decrypted message
    }
    return 0;
}