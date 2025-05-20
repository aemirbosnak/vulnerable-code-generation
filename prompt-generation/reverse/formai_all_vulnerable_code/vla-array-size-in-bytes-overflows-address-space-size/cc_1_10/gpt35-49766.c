//FormAI DATASET v1.0 Category: Scientific ; Style: thoughtful
/* 
   This program generates all the prime numbers within a range using the Sieve of Eratosthenes algorithm
   and saves them in a newly created file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000000    // Maximum size of the range

int main() {
    unsigned long long int n;
    printf("Please enter the upper limit of the range: ");
    scanf("%llu", &n);

    printf("Generating the prime numbers within the range...\n");

    // Creating an array to store the status of all the numbers from 2 to n
    bool is_prime[n+1];
    for (unsigned long long int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }

    // Finding the prime numbers using the Sieve of Eratosthenes algorithm
    for (unsigned long long int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (unsigned long long int j = i*i; j <= n; j += i) {   // Marking all the multiples of i as composite
                is_prime[j] = false;
            }
        }
    }

    // Saving the prime numbers in a file named primes.txt
    FILE *fout;
    fout = fopen("primes.txt", "w");

    if (fout == NULL) {
        printf("Error: Could not create file!");
        exit(1);
    }

    fprintf(fout, "Prime numbers within the range 2 - %llu:\n\n", n);

    for (unsigned long long int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            fprintf(fout, "%llu\n", i);
        }
    }

    fclose(fout);

    printf("The prime numbers have been saved to a file named primes.txt\n");

    return 0;
}