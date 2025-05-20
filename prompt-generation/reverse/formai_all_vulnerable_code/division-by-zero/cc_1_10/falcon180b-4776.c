//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 256
#define P (N - 1)
#define Q (P - 1)
#define G 2
#define X 5
#define Y (P - 1)
#define Z (Q - 1)
#define E 65537
#define D (E - 1)

int is_prime(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int i;
    for (i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int gcd(int a, int b) {
    return (b == 0)? a : gcd(b, a % b);
}

int inverse(int a, int m) {
    int x, y, d;
    if (a == 0)
        return 0;
    do {
        x = a % m;
        y = m % x;
        d = y;
        a = x;
        m = y;
    } while (x!= 0);
    return d;
}

int power(int a, int b, int m) {
    int r = 1;
    while (b > 0) {
        if (b % 2 == 1)
            r = (r * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return r;
}

void generate_keys() {
    int p = 0, q = 0, g = 0;
    while (!is_prime(p))
        p = rand() % N;
    while (!is_prime(q))
        q = rand() % N;
    g = power(G, X, P);
    printf("Public key: (%d, %d)\n", p, g);
    printf("Private key: (%d, %d)\n", q, inverse(g, P));
}

int main() {
    srand(time(NULL));
    generate_keys();
    return 0;
}