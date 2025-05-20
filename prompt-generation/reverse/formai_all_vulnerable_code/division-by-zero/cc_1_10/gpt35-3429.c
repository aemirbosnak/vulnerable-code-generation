//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

/* Function to compress the data */
void compress(char *input, char *output, int chunk_size) {
    int i, j;
    char prev_char, curr_char;
    int count;
    int output_index = 0;
    int input_index = 0;
    while (input[input_index]) {
        // Get the current character
        curr_char = input[input_index];
        count = 1;
        // Get the number of consecutive characters
        for (j = input_index + 1; j < (input_index + chunk_size); j++) {
            if (curr_char != input[j] || !input[j]) {
                break;
            }
            count++;
        }
        // If the count is more than 3, then compress the characters
        if (count > 3) {
            output[output_index++] = curr_char;
            output[output_index++] = count + '0';
            input_index += count;
        } 
        // If not, then just copy the character(s)
        else {
            for (j = input_index; j < (input_index + count); j++) {
                output[output_index++] = input[j];
            }
            input_index += count;
        }
    }
    // Add the null terminator to the output string
    output[output_index] = '\0';
}

/* Thread function to compress data */
void *compress_thread(void *arg) {
    char *input = (char *) arg;
    char output[BUFFER_SIZE];
    compress(input, output, 4);
    char *result = (char *) malloc(strlen(output) + 1);
    strcpy(result, output);
    pthread_exit((void *) result);
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int num_threads;
    int i;
    // Get the input from the user
    printf("Enter the input data: ");
    fgets(input, BUFFER_SIZE, stdin);
    // Get the number of threads
    printf("Enter the number of threads (<= %d): ", strlen(input));
    scanf("%d", &num_threads);
    // Create an array of threads
    pthread_t threads[num_threads];
    // Split the input into chunks and create threads for each chunk
    int chunk_size = strlen(input) / num_threads;
    int start_index = 0;
    for (i = 0; i < num_threads; i++) {
        char *input_chunk = (char *) malloc(chunk_size + 1);
        strncpy(input_chunk, input + start_index, chunk_size);
        input_chunk[chunk_size] = '\0';
        start_index += chunk_size;
        pthread_create(&threads[i], NULL, compress_thread, input_chunk);
    }
    // Wait for all threads to finish and concatenate the compressed data
    char *result;
    for (i = 0; i < num_threads; i++) {
        char *thread_result;
        pthread_join(threads[i], (void **) &thread_result);
        strcat(output, thread_result);
        free(thread_result);
    }
    // Print the compressed data
    printf("Compressed data: %s\n", output);
    return 0;
}