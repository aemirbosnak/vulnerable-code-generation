//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4

// Mutex to protect shared data
pthread_mutex_t mutex;

// Condition variable to signal when data is ready
pthread_cond_t cond_var;

// Shared data
char *plaintext;
int plaintext_len;
char *ciphertext;
int ciphertext_len;

// Function to encrypt data
void *encrypt(void *args) {
    // Get thread ID
    int thread_id = *(int *)args;

    // Allocate memory for thread-specific variables
    char *local_plaintext = malloc(plaintext_len);
    char *local_ciphertext = malloc(plaintext_len);

    // Copy shared data to thread-specific variables
    pthread_mutex_lock(&mutex);
    memcpy(local_plaintext, plaintext, plaintext_len);
    pthread_mutex_unlock(&mutex);

    // Encrypt data
    for (int i = 0; i < plaintext_len; i++) {
        local_ciphertext[i] = local_plaintext[i] + thread_id;
    }

    // Copy thread-specific ciphertext to shared data
    pthread_mutex_lock(&mutex);
    memcpy(ciphertext + thread_id * plaintext_len, local_ciphertext, plaintext_len);
    pthread_mutex_unlock(&mutex);

    // Signal that data is ready
    pthread_cond_signal(&cond_var);

    // Free thread-specific memory
    free(local_plaintext);
    free(local_ciphertext);

    return NULL;
}

int main() {
    // Initialize shared data
    plaintext = malloc(1000);
    plaintext_len = strlen(plaintext);
    ciphertext = malloc(plaintext_len * NUM_THREADS);
    ciphertext_len = 0;

    // Initialize mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);

    // Create threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, encrypt, &thread_ids[i]);
    }

    // Wait for threads to finish
    pthread_cond_wait(&cond_var, &mutex);

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Free shared data
    free(plaintext);
    free(ciphertext);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    return 0;
}