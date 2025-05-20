//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Declare the thread arguments structure
typedef struct thread_args {
    int start;
    int end;
    int *array;
    int *result;
} thread_args;

// The thread function to convert a range of numbers from decimal to binary
void *convert_to_binary(void *args) {
    // Get the thread arguments
    thread_args *arguments = (thread_args *)args;

    // Convert the numbers in the specified range to binary
    for (int i = arguments->start; i < arguments->end; i++) {
        int num = arguments->array[i];
        int binary[32];
        int index = 0;

        // Convert the number to binary
        while (num > 0) {
            binary[index++] = num % 2;
            num /= 2;
        }

        // Reverse the binary array
        for (int j = 0; j < index / 2; j++) {
            int temp = binary[j];
            binary[j] = binary[index - j - 1];
            binary[index - j - 1] = temp;
        }

        // Store the binary representation in the result array
        arguments->result[i] = binary[0];
        for (int j = 1; j < index; j++) {
            arguments->result[i] = arguments->result[i] * 10 + binary[j];
        }
    }

    return NULL;
}

int main() {
    // Get the input array
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    // Allocate memory for the result array
    int *result = malloc(sizeof(int) * size);

    // Create the thread arguments
    thread_args arguments[2];
    arguments[0].start = 0;
    arguments[0].end = size / 2;
    arguments[0].array = array;
    arguments[0].result = result;

    arguments[1].start = size / 2;
    arguments[1].end = size;
    arguments[1].array = array;
    arguments[1].result = result;

    // Create the threads
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, convert_to_binary, &arguments[0]);
    pthread_create(&threads[1], NULL, convert_to_binary, &arguments[1]);

    // Wait for the threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    // Print the result array
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}