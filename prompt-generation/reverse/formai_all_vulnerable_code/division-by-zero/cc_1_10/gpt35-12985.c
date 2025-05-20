//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* function to check if a number is prime */
int is_prime(int num)
{
    if(num <= 1) return 0;
    if(num <= 3) return 1;
    if(num % 2 == 0 || num % 3 == 0) return 0;
    for(int i = 5; i * i <= num; i += 6)
        if(num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

/* function to generate a random prime number */
int generate_prime()
{
    int num = rand() % 100 + 1;
    while(!is_prime(num)) num = rand() % 100 + 1;
    return num;
}

/* function to calculate the greatest common divisor of two numbers */
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

/* function to generate a random integer with a given range */
int generate_random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

/* function to calculate x raised to the power of y modulo z */
int power_modulo(int x, int y, int z)
{
    int res = 1;
    x = x % z;
    while(y > 0)
    {
        if(y & 1) res = (res * x) % z;
        y >>= 1;
        x = (x * x) % z;
    }
    return res;
}

int main()
{
    srand(time(NULL));

    /* Generate two random prime numbers */
    int p = generate_prime();
    int q = generate_prime();
    printf("p = %d, q = %d\n", p, q);

    /* Compute N = p * q */
    int N = p * q;
    printf("N = %d\n", N);

    /* Compute phi(n) = (p-1)*(q-1) */
    int phi = (p - 1) * (q - 1);
    printf("phi(N) = %d\n", phi);

    /* Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1 */
    int e = generate_random(2, phi - 1);
    while(gcd(e, phi) != 1) e = generate_random(2, phi - 1);
    printf("e = %d\n", e);

    /* Compute d such that d*e ≡ 1 (mod phi) */
    int k = 1;
    int d = (k * phi + 1) / e;
    while((k * phi + 1) % e != 0 || d <= e) d = (k++ * phi + 1) / e;
    printf("d = %d\n", d);

    /* Choose a message to encrypt */
    int message = generate_random(1, N - 1);
    printf("Message = %d\n", message);

    /* Encrypt the message */
    int cipher = power_modulo(message, e, N);
    printf("Cipher = %d\n", cipher);

    /* Decrypt the cipher */
    int decrypted = power_modulo(cipher, d, N);
    printf("Decrypted message = %d\n", decrypted);

    return 0;
}