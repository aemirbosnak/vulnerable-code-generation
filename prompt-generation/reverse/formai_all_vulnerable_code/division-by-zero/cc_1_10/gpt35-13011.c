//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate random prime number
int generate_prime_number()
{
    int n, i, flag = 0;
    while(1)
    {
        n = rand() % 1000 + 1;
        for(i=2; i<=n/2; i++)
        {
            if(n%i == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return n;
        else
            flag = 0;
    }
}

// Function to calculate power of a number
int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to generate public and private keys
void generate_keys()
{
    int p = generate_prime_number();
    int q = generate_prime_number();
    int n = p * q;
    int phi = (p-1) * (q-1);
    int e = rand() % phi;

    while(phi % e == 0 || e <= 1)
    {
        e = rand() % phi;
    }

    int k = 2;
    int d = (1 + (k * phi)) / e;

    while(d <= 1 || d == e)
    {
        k++;
        d = (1 + (k * phi)) / e;
    }

    printf("The public key is ({%d, %d}) and the private key is ({%d, %d})\n", e, n, d, n);
}

int main()
{
    printf("Welcome to my unique C Public-Key Algorithm Implementation example program!\n\n");
    printf("Generating keys...\n");

    generate_keys();

    printf("\nThanks for using my program!\n");

    return 0;
}