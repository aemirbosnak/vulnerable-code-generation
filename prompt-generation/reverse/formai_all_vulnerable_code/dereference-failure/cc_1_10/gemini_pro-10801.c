//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Prime Number Sieve
static uint32_t *PrimeSieve(uint32_t limit)
{
    uint32_t *sieve = calloc(limit / 32 + 1, sizeof(uint32_t));
    if (!sieve)
        return NULL;

    uint32_t sqrtLimit = sqrtf(limit);
    for (uint32_t i = 2; i <= sqrtLimit; i++)
    {
        if (!(sieve[i / 32] & (1 << (i % 32))))
        {
            for (uint32_t j = i * i; j <= limit; j += i)
                sieve[j / 32] |= (1 << (j % 32));
        }
    }
    return sieve;
}

// Euler's Totient Function
static uint32_t Phi(uint32_t n)
{
    uint32_t result = n;
    uint32_t p = 2;
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
        p++;
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Carmichael Function
static uint32_t Lambda(uint32_t n)
{
    uint32_t phi = Phi(n);
    uint32_t p = 2;
    while (p * p <= phi)
    {
        if (phi % p == 0)
        {
            while (phi % p == 0)
                phi /= p;
            phi -= phi / p;
        }
        p++;
    }
    if (phi > 1)
        phi -= phi / phi;
    return phi;
}

// Möbius Function
static int8_t Mu(uint32_t n)
{
    if (n == 1)
        return 1;

    uint32_t p = 2;
    uint32_t count = 0;
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            if (n / p == p)
                return 0;
            count++;
            while (n % p == 0)
                n /= p;
        }
        p++;
    }
    if (n > 1)
        count++;
    return (count & 1) ? -1 : 1;
}

int main()
{
    uint32_t limit = 1000000;
    uint32_t *sieve = PrimeSieve(limit);

    printf("Number of primes up to %u: %u\n", limit, sieve[limit / 32] & (1 << (limit % 32)));

    printf("Totient of 100: %u\n", Phi(100));

    printf("Carmichael of 100: %u\n", Lambda(100));

    printf("Möbius of 100: %d\n", Mu(100));

    free(sieve);
    return 0;
}