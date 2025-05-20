//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    char *input;
    int length;
} input_data;

void *sanitize_input(void *data) {
    input_data *input = (input_data *)data;

    // Replace all non-alphanumeric characters with spaces
    for (int i = 0; i < input->length; i++) {
        if (!isalnum(input->input[i])) {
            input->input[i] = ' ';
        }
    }

    // Trim leading and trailing spaces
    while (input->input[0] == ' ') {
        input->input++;
        input->length--;
    }
    while (input->input[input->length - 1] == ' ') {
        input->length--;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    // Create an input data structure for each thread
    input_data input_data[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        input_data[i].input = argv[i + 1];
        input_data[i].length = strlen(argv[i + 1]);
    }

    // Create a thread for each input data structure
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, sanitize_input, &input_data[i]);
    }

    // Join all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the sanitized input
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("%s\n", input_data[i].input);
    }

    return 0;
}