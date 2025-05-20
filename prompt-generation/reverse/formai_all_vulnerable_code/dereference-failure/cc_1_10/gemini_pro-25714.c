//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when data is ready
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Data structure to hold input data
typedef struct {
    char *input;
    int length;
} input_data_t;

// Thread function to get input from the user
void *get_input(void *arg) {
    input_data_t *data = (input_data_t *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Get input from the user
    printf("Enter input: ");
    data->input = malloc(1024);
    fgets(data->input, 1024, stdin);
    data->length = strlen(data->input);

    // Signal that data is ready
    pthread_cond_signal(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Thread function to sanitize input
void *sanitize_input(void *arg) {
    input_data_t *data = (input_data_t *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for data to be ready
    pthread_cond_wait(&cond, &mutex);

    // Sanitize input
    for (int i = 0; i < data->length; i++) {
        if (data->input[i] == '<' || data->input[i] == '>') {
            data->input[i] = ' ';
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Main function
int main() {
    // Create thread to get input from the user
    pthread_t input_thread;
    input_data_t input_data;
    pthread_create(&input_thread, NULL, get_input, &input_data);

    // Create thread to sanitize input
    pthread_t sanitize_thread;
    pthread_create(&sanitize_thread, NULL, sanitize_input, &input_data);

    // Join threads
    pthread_join(input_thread, NULL);
    pthread_join(sanitize_thread, NULL);

    // Print sanitized input
    printf("Sanitized input: %s", input_data.input);

    // Free allocated memory
    free(input_data.input);

    return 0;
}