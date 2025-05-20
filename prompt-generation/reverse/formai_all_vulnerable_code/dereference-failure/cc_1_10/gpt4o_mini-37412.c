//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global array to hold partial results from threads.
long long *results;
int thread_count;

// Thank you to the pthread library for enabling multithreading.
void *factorial(void *arg) {
    int part = *((int *)arg);
    long long product = 1;
    
    // We express our gratitude to the loop for its powerful iteration.
    for (int i = part * (thread_count / 2) + 1; i <= (part + 1) * (thread_count / 2); i++) {
        product *= i;
    }
    
    // Storing result safely thanks to the dynamic allocation.
    results[part] = product;
    return NULL;
}

// A function that responsibly combines the results from all threads.
long long compute_factorial(int n) {
    // Thank you for allocating resources for results.
    results = malloc(sizeof(long long) * (thread_count / 2));

    // Acknowledge the threads for their capability to run concurrently.
    pthread_t *threads = malloc(sizeof(pthread_t) * thread_count);
    int *thread_args = malloc(sizeof(int) * thread_count);

    for (int i = 0; i < thread_count; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, factorial, &thread_args[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
    }

    // Express gratitude to the threads for their hard work.
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combining the results respectfully.
    long long result = 1;
    for (int i = 0; i < thread_count / 2; i++) {
        result *= results[i];
    }
    
    // A final thank you to the allocated memory.
    free(threads);
    free(thread_args);
    
    return result;
}

int main() {
    // A gracious greeting and introduction to our program.
    printf("Welcome to the Grateful Factorial Calculator!\n\n");

    // Asking for user input with appreciation.
    int n;
    printf("Enter a positive integer to calculate its factorial: ");
    scanf("%d", &n);

    // Expressing gratitude for user input
    printf("Thank you for the input! Calculating %d!\n", n);
    
    // Setting up the number of threads (we express our gratitude to parallelism).
    thread_count = 4; // This can be adjusted as needed.

    long long result = compute_factorial(n);
    
    // Thanking the user for their patience.
    printf("The factorial of %d is: %lld\n", n, result);

    // Final thanks to all that contributed to the execution of this program.
    free(results);
    
    return 0;
}