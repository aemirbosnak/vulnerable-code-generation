//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 4
#define MAX_INPUT_SIZE 1024

struct input_data {
    char *input;
    int input_size;
    int thread_id;
};

void *sanitize_input(void *arg) {
    struct input_data *data = (struct input_data *)arg;

    // Convert the input to lowercase
    for (int i = 0; i < data->input_size; i++) {
        data->input[i] = tolower(data->input[i]);
    }

    // Remove any non-alphanumeric characters
    char *sanitized_input = malloc(data->input_size);
    int sanitized_input_size = 0;
    for (int i = 0; i < data->input_size; i++) {
        if (isalnum(data->input[i])) {
            sanitized_input[sanitized_input_size++] = data->input[i];
        }
    }

    // Free the original input
    free(data->input);

    // Update the input data with the sanitized input
    data->input = sanitized_input;
    data->input_size = sanitized_input_size;

    // Print the sanitized input
    printf("Thread %d: %s\n", data->thread_id, data->input);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct input_data data[MAX_THREADS];

    // Read the input from the user
    char *input = malloc(MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Split the input into tokens
    char *tokens[MAX_THREADS];
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Create a thread for each token
    for (int i = 0; i < num_tokens; i++) {
        data[i].input = tokens[i];
        data[i].input_size = strlen(tokens[i]);
        data[i].thread_id = i;
        pthread_create(&threads[i], NULL, sanitize_input, &data[i]);
    }

    // Join all the threads
    for (int i = 0; i < num_tokens; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the input and tokens
    free(input);
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }

    return 0;
}