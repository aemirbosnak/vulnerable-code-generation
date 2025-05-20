//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LENGTH 1024
#define THREAD_COUNT 4

typedef struct {
    char *input;
    char *output;
    int start;
    int end;
} RLEArgs;

void *run_length_encode(void *args) {
    RLEArgs *rle_args = (RLEArgs *)args;
    char *input = rle_args->input;
    char *output = rle_args->output;
    int start = rle_args->start;
    int end = rle_args->end;

    int count = 1;
    int output_index = 0;

    for (int i = start; i < end; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output_index += sprintf(output + output_index, "%d%c", count, input[i]);
            count = 1;
        }
    }

    output[output_index] = '\0'; // Null-terminate the output string
    return NULL;
}

void compress(const char *input, char *output) {
    pthread_t threads[THREAD_COUNT];
    RLEArgs args[THREAD_COUNT];

    int length = strlen(input);
    int part_length = length / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; i++) {
        args[i].input = (char *)input;
        args[i].output = output + (i * part_length * 2); // Each character can be represented by two characters max
        args[i].start = i * part_length;
        args[i].end = (i == THREAD_COUNT - 1) ? length : (i + 1) * part_length;
        pthread_create(&threads[i], NULL, run_length_encode, &args[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char *input = (char *)malloc(MAX_LENGTH);
    char *output = (char *)malloc(MAX_LENGTH * 2); // Allocate extra space for output

    printf("Enter input string (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    compress(input, output);

    printf("Compressed Output: %s\n", output);

    free(input);
    free(output);
    return 0;
}