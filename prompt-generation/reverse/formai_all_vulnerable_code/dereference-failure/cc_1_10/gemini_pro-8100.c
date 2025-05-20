//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// A struct to hold the prime numbers we find
typedef struct {
    size_t count;
    uint64_t *primes;
} prime_list;

// Initialize a prime list
void prime_list_init(prime_list *list) {
    list->count = 0;
    list->primes = NULL;
}

// Free the memory used by a prime list
void prime_list_free(prime_list *list) {
    free(list->primes);
    list->count = 0;
    list->primes = NULL;
}

// Add a prime number to the list
void prime_list_add(prime_list *list, uint64_t prime) {
    list->primes = realloc(list->primes, (list->count + 1) * sizeof(uint64_t));
    list->primes[list->count++] = prime;
}

// Check if a number is prime
int is_prime(uint64_t n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    uint64_t i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
        i += 6;
    }
    
    return 1;
}

// Generate the first n prime numbers
void generate_primes(prime_list *list, size_t n) {
    uint64_t i = 2;
    while (list->count < n) {
        if (is_prime(i)) {
            prime_list_add(list, i);
        }
        i++;
    }
}

// Print the prime numbers in the list
void print_primes(prime_list *list) {
    for (size_t i = 0; i < list->count; i++) {
        printf("%llu ", list->primes[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the prime list
    prime_list list;
    prime_list_init(&list);
    
    // Generate the first 1000 prime numbers
    generate_primes(&list, 1000);
    
    // Print the prime numbers
    print_primes(&list);
    
    // Free the memory used by the prime list
    prime_list_free(&list);
    
    return 0;
}