//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Function to check if a number is prime
bool is_prime(unsigned int num) {
    if (num <= 1) {
        return false;
    }

    for (unsigned int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to print prime numbers using Sieve of Eratosthenes method
void print_primes(unsigned int limit) {
    // Allocate shared memory for sieve array
    int shmid = shmget(IPC_PRIVATE, sizeof(unsigned int*) * limit, IPC_CREAT | 0777);
    unsigned int* sieve = shmat(shmid, NULL, 0);

    // Initialize sieve array
    memset(sieve, 0, sizeof(unsigned int*) * limit);

    // Mark 0 and 1 as non-prime
    sieve[0] = sieve[1] = 0;

    // Sieve of Eratosthenes algorithm
    for (unsigned int i = 2; i * i <= limit; i++) {
        if (sieve[i] == 0) {
            for (unsigned int j = i * i; j <= limit; j += i) {
                sieve[j] = 1;
            }
        }
    }

    // Print prime numbers
    printf("Prime numbers up to %u:\n", limit);
    for (unsigned int i = 2; i <= limit; i++) {
        if (sieve[i] == 0) {
            printf("%u ", i);
        }
    }
    printf("\n");

    // Detach shared memory
    shmdt(sieve);
    shmctl(shmid, IPC_RMID, NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <limit>\n", argv[0]);
        exit(1);
    }

    unsigned int limit = strtoul(argv[1], NULL, 10);

    print_primes(limit);

    return 0;
}