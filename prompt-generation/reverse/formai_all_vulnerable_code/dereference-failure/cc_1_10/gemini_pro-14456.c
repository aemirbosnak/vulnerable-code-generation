//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared data structure
typedef struct {
    char *input;
    char *output;
    int input_len;
    int output_len;
} conversion_data;

// Thread function
void *convert_hex(void *arg) {
    conversion_data *data = (conversion_data *)arg;
    int i;

    // Convert each character to hexadecimal
    for (i = 0; i < data->input_len; i++) {
        if (data->input[i] >= '0' && data->input[i] <= '9') {
            data->output[i] = data->input[i] - '0';
        } else if (data->input[i] >= 'a' && data->input[i] <= 'f') {
            data->output[i] = data->input[i] - 'a' + 10;
        } else if (data->input[i] >= 'A' && data->input[i] <= 'F') {
            data->output[i] = data->input[i] - 'A' + 10;
        } else {
            data->output[i] = -1; // Invalid character
        }
    }

    data->output_len = i;

    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads;
    int input_len;
    char *input;
    char *output;
    conversion_data data;
    pthread_t *threads;
    int i;

    // Get the number of threads
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }
    num_threads = atoi(argv[1]);

    // Get the input string
    printf("Enter the hexadecimal string: ");
    input = malloc(1024);
    fgets(input, 1024, stdin);
    input_len = strlen(input);

    // Allocate memory for the output string
    output = malloc(input_len);

    // Initialize the shared data structure
    data.input = input;
    data.output = output;
    data.input_len = input_len;
    data.output_len = 0;

    // Create the threads
    threads = malloc(num_threads * sizeof(pthread_t));
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, convert_hex, &data);
    }

    // Join the threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the output string
    printf("The hexadecimal string in decimal is: ");
    for (i = 0; i < data.output_len; i++) {
        printf("%d", data.output[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(input);
    free(output);
    free(threads);

    return EXIT_SUCCESS;
}