//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 10000 // The upper limit for prime numbers.
// By program's end, only primes below MAX_NUM will have survived.

void find_primes(int *primes, int *count);
void print_primes(const int *primes, int count);
bool is_prime(int number);
void survival_update(int *primes, int *count);

int main() {
    int *primes = (int *)malloc(MAX_NUM * sizeof(int));
    int count = 0;

    // The wasteland is quiet, save for the sound of our survival.
    printf("The year is 3030. The world as we knew it has long fallen apart.\n");
    printf("Yet amid the chaos, we seek wisdom in the numbers.\n");
    printf("Searching for the prime numbers that have survived the apocalypse...\n");

    find_primes(primes, &count);
    survival_update(primes, &count);
    print_primes(primes, count);

    free(primes);
    return 0;
}

void find_primes(int *primes, int *count) {
    printf("Finding surviving primes...\n");
    for (int i = 2; i < MAX_NUM; i++) {
        if (is_prime(i)) {
            primes[(*count)++] = i; // Storing the prime number in the survivor list.
        }
    }
}

bool is_prime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= sqrt(number); i++) { // Checking primality.
        if (number % i == 0) {
            return false; // Not prime, a number from the old world.
        }
    }
    return true; // A number worthy of the new world.
}

void print_primes(const int *primes, int count) {
    printf("\nList of surviving prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 20 == 0) { // Pause every 20 for effect.
            printf("\n");
        }
    }
    printf("\nEnd of the line for surviving primes.\n");
}

void survival_update(int *primes, int *count) {
    // A grim reminder that not all numbers make it through the apocalypse.
    printf("\nRunning survival update on the list of primes...\n");
    for (int i = 0; i < *count; i++) {
        if (primes[i] % 3 == 0) {
            printf("Prime %d fell to the shadows, no longer fits the criteria of survival.\n", primes[i]);
            // Remove the prime from the list if it is divisible by 3. Keeping our numbers pure.
            for (int j = i; j < *count - 1; j++) {
                primes[j] = primes[j + 1];
            }
            (*count)--;
            i--; // Adjust index after removal.
        }
    }
    printf("Survival update complete. Current count of primes: %d\n", *count);
}