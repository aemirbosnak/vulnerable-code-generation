//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_LENGTH 16
#define MIN_LENGTH 8

pthread_mutex_t mutex;

void *generatePassword(void *args) {
    int length = *(int *) args;
    srand(time(NULL));

    // Generate a random password
    char password[MAX_LENGTH+1];
    for(int i = 0; i < length; i++) {
        int type = rand() % 3;
        if(type == 0) {
            password[i] = rand() % 10 + '0'; // Digit (0-9)
        } else if(type == 1) {
            password[i] = rand() % 26 + 'a'; // Lowercase letter (a-z)
        } else {
            password[i] = rand() % 26 + 'A'; // Uppercase letter (A-Z)
        }
    }
    password[length] = '\0';

    // Print the generated password
    pthread_mutex_lock(&mutex);
    printf("Generated password (length %d): %s\n", length, password);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Get number of passwords to generate from arguments
    if(argc != 2) {
        printf("Usage: %s <number of passwords to generate>\n", argv[0]);
        return 1;
    }
    int numPasswords = atoi(argv[1]);

    // Create threads to generate passwords
    pthread_t threads[numPasswords];
    for(int i = 0; i < numPasswords; i++) {
        int length = rand() % (MAX_LENGTH-MIN_LENGTH+1) + MIN_LENGTH;
        pthread_create(&threads[i], NULL, generatePassword, &length);
    }

    // Wait for threads to finish
    for(int i = 0; i < numPasswords; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}