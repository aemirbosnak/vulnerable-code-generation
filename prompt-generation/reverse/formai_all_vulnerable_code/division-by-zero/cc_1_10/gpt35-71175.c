//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int primes[1000];
int num_primes = 0;

void *find_primes(void *thread_id)
{
    int id = *((int *)thread_id);
    int start = id * 200;
    int end = start + 200;
    
    // Loop through all numbers in the thread's range
    for (int i = start; i < end; i++) {
        int is_prime = 1;
        
        // Check if the number is divisible by any previous prime numbers
        for (int j = 0; j < num_primes; j++) {
            if (i % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        
        // If the number is prime, add it to the list of primes
        if (is_prime) {
            primes[num_primes] = i;
            num_primes++;
        }
    }
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    // Create threads to find primes
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, find_primes, (void *)&thread_ids[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Display all prime numbers found
    printf("Prime numbers found:\n");
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    
    return 0;
}