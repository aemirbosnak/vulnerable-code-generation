//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void prime_sieve(int n) {
    bool *sieve = (bool*) malloc((n+1) * sizeof(bool));
    for (int i = 2; i <= n; i++)
        sieve[i] = true;
    for (int i = 2; i*i <= n; i++) {
        if (sieve[i]) {
            for (int j = i*i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i])
            printf("%d ", i);
    }
    free(sieve);
}

int main() {
    int choice, n;
    printf("MENU:\n");
    printf("1. Use is_prime()\n");
    printf("2. Use prime_sieve()\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            if (is_prime(n))
                printf("%d is prime.\n", n);
            else
                printf("%d is not prime.\n", n);
            break;
        case 2:
            printf("Enter the maximum number: ");
            scanf("%d", &n);
            printf("The prime numbers up to %d are:\n", n);
            prime_sieve(n);
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}