//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_GUESS 10

// Shared data
int secret_number;
int guessed_number = -1;
pthread_mutex_t lock;
pthread_cond_t cond;

// Function for each thread to guess the secret number
void* guesser(void* arg) {
    int thread_id = *(int*)arg;
    free(arg);  // Free the dynamically allocated memory for thread ID

    while (guessed_number == -1) {
        // Generate a random guess
        int guess = rand() % (MAX_GUESS + 1);
        printf("Thread %d guessing %d...\n", thread_id, guess);

        // Locking the mutex for shared access
        pthread_mutex_lock(&lock);
        if (guess == secret_number) {
            guessed_number = guess;
            printf("Thread %d guessed correctly! The secret number is %d.\n", thread_id, guess);
            pthread_cond_broadcast(&cond);  // Notify all threads
        }
        pthread_mutex_unlock(&lock);

        // Sleep a bit to simulate thinking time
        usleep(100000);  // 100 milliseconds
    }
    return NULL;
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    secret_number = rand() % (MAX_GUESS + 1);  // Picking a secret number

    printf("A secret number has been generated between 0 and %d.\n", MAX_GUESS);

    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Creating threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int));
        *thread_id = i + 1;
        pthread_create(&threads[i], NULL, guesser, thread_id);
    }

    // Waiting for the correct guess
    pthread_mutex_lock(&lock);
    while (guessed_number == -1) {
        pthread_cond_wait(&cond, &lock);  // Wait until notified
    }
    pthread_mutex_unlock(&lock);

    // Clean up
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The guessing game is over!\n");
    printf("The secret number was %d.\n", secret_number);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}