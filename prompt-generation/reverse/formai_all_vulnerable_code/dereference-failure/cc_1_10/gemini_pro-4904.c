//GEMINI-pro DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads to use
#define NUM_THREADS 4

// Define the file to be read
#define FILENAME "data.txt"

// Define the buffer size
#define BUFFER_SIZE 1024

// Define the structure to be used for the thread arguments
typedef struct {
    int start_index;
    int end_index;
} thread_args;

// Define the thread function
void *thread_function(void *args) {
    // Get the thread arguments
    thread_args *arguments = (thread_args *)args;

    // Open the file
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Seek to the start of the thread's range
    fseek(file, arguments->start_index, SEEK_SET);

    // Read the thread's range of data
    char buffer[BUFFER_SIZE];
    int num_bytes_read = fread(buffer, 1, arguments->end_index - arguments->start_index, file);
    if (num_bytes_read < 0) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(file);

    // Print the thread's range of data
    printf("Thread %d: %s\n", pthread_self(), buffer);

    // Free the thread arguments
    free(arguments);

    // Exit the thread
    pthread_exit(NULL);
}

// Define the main function
int main() {
    // Get the file size
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fclose(file);

    // Create the thread pool
    pthread_t threads[NUM_THREADS];

    // Create the thread arguments
    thread_args *args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i] = malloc(sizeof(thread_args));
        args[i]->start_index = i * (file_size / NUM_THREADS);
        args[i]->end_index = (i + 1) * (file_size / NUM_THREADS);
    }

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, (void *)args[i]) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error joining thread");
            exit(EXIT_FAILURE);
        }
    }

    // Exit the program
    exit(EXIT_SUCCESS);
}