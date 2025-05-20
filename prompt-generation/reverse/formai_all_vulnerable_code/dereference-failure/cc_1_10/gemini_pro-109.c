//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t stdout_lock = PTHREAD_MUTEX_INITIALIZER;

static void *worker_thread(void *arg) {
    char *input = (char *)arg;
    char *output = malloc(strlen(input) + 1);
    if (!output) {
        pthread_mutex_lock(&stdout_lock);
        fprintf(stderr, "Failed to allocate memory for output\n");
        pthread_mutex_unlock(&stdout_lock);
        return NULL;
    }

    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] == '0' || input[i] == '1') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    pthread_mutex_lock(&stdout_lock);
    printf("Converted binary string: %s\n", output);
    pthread_mutex_unlock(&stdout_lock);

    free(output);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s BINARY_STRING\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input = argv[1];
    pthread_t tid;
    int err = pthread_create(&tid, NULL, worker_thread, input);
    if (err != 0) {
        fprintf(stderr, "Failed to create worker thread: %s\n", strerror(err));
        return EXIT_FAILURE;
    }

    pthread_join(tid, NULL);
    return EXIT_SUCCESS;
}