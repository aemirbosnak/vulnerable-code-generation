//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 2147483647

unsigned long long powmod(unsigned long long a, unsigned long long b, unsigned long long n)
{
    unsigned long long result = 1, exp = 1;

    while (exp <= b)
    {
        if (exp % 2 == 0)
        {
            result *= a;
            result %= n;
            exp *= 2;
        }
        else
        {
            result *= a;
            result %= n;
            exp++;
        }
    }

    return result;
}

int main()
{
    unsigned long long n, e, d, msg;

    printf("Enter the modulus: ");
    scanf("%llu", &n);

    printf("Enter the public key exponent: ");
    scanf("%llu", &e);

    printf("Enter the private key exponent: ");
    scanf("%llu", &d);

    printf("Enter the message: ");
    scanf("%llu", &msg);

    unsigned long long enc_msg = powmod(msg, e, n);

    printf("The encrypted message is: %llu\n", enc_msg);

    unsigned long long dec_msg = powmod(enc_msg, d, n);

    printf("The decrypted message is: %llu\n", dec_msg);

    return 0;
}