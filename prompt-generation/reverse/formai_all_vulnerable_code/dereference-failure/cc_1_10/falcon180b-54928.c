//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for threads to wait on
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Array of strings to be checked for palindromes
char *strings[MAX_THREADS];

// Array of thread IDs
pthread_t threads[MAX_THREADS];

// Function to check if a string is a palindrome
void *palindrome_checker(void *arg) {
    int id = *((int *) arg);
    char *string = strings[id];

    // Check if string is a palindrome
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        if (string[i]!= string[length - 1 - i]) {
            printf("String %d is not a palindrome\n", id);
            pthread_exit(NULL);
        }
    }

    printf("String %d is a palindrome\n", id);
    pthread_exit(NULL);
}

// Main function to create threads and join them
int main() {
    // Initialize strings array with example strings
    strings[0] = "racecar";
    strings[1] = "level";
    strings[2] = "deified";
    strings[3] = "A man a plan a canal Panama";

    // Create threads for each string
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, palindrome_checker, (void *) &i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}