//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int generate_prime(int n) {
    int prime = 0;
    int i;

    for (i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime++;
        }
    }

    return prime;
}

int main() {
    int n;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    int count = 0;
    int prime_numbers[n];

    while (count < n) {
        int num = rand() % 1000;
        if (is_prime(num)) {
            prime_numbers[count] = num;
            count++;
        }
    }

    printf("The %d prime numbers generated are:\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", prime_numbers[i]);
    }

    return 0;
}