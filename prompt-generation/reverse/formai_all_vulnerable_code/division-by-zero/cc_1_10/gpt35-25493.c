//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PUBLIC_KEY 93563
#define PRIVATE_KEY 68

int inverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
       x1 += m0;

    return x1;
}

int power(int x, unsigned int y, int p)
{
    int res = 1;  
    x = x % p; 

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}

int main()
{
    int message, ciphertext, plaintext;
    int p = 607, q = 151, n, phi, e, d;
    srand(time(NULL));
    message = rand() % 1000;

    n = p * q;
    phi = (p-1) * (q-1);

    do {
        e = rand() % phi;
    } while (e<=1 || e>=phi || inverse(e,phi)!=1);

    d = inverse(e,phi);

    ciphertext = power(message, e, n);
    plaintext = power(ciphertext, d, n);

    printf("Public Key: %d\n", PUBLIC_KEY);
    printf("Private Key: %d\n", PRIVATE_KEY);
    printf("Message: %d\n", message);
    printf("Encrypted Message: %d\n", ciphertext);
    printf("Decrypted Message: %d\n", plaintext);
}