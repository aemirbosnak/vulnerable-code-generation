//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRIME 1000000

typedef struct PrimeNode {
    int prime;
    struct PrimeNode *next;
} PrimeNode;

PrimeNode *prime_list = NULL;

void generate_primes() {
    int i, j;
    PrimeNode *new_node;

    for (i = 2; i <= MAX_PRIME; i++) {
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i)) {
            new_node = (PrimeNode *) malloc(sizeof(PrimeNode));
            new_node->prime = i;
            new_node->next = prime_list;
            prime_list = new_node;
        }
    }
}

void print_primes() {
    PrimeNode *current = prime_list;

    while (current != NULL) {
        printf("%d ", current->prime);
        current = current->next;
    }
    printf("\n");
}

int is_prime(int n) {
    PrimeNode *current = prime_list;
    int i;

    while (current != NULL) {
        if (n == current->prime)
            return 1;
        current = current->next;
    }

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int n;

    generate_primes();

    printf("Enter a number to check if it is prime: ");
    scanf("%d", &n);

    if (is_prime(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    printf("Here is the list of primes up to %d:\n", MAX_PRIME);
    print_primes();

    return 0;
}