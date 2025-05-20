//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 128
#define NUM_THREADS 2

// Struct to hold thread arguments
typedef struct thread_args_s {
    int number;
    char *binary_string;
} thread_args_t;

// Function to be run by the converting threads
void *convert_to_binary(void *arg) {
    thread_args_t *args = (thread_args_t*) arg;
    int num = args->number;
    char *binary = args->binary_string;
    int i = 0;

    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num /= 2;
    }
    binary[i] = '\0';
    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread_ids[NUM_THREADS];
    thread_args_t thread_args[NUM_THREADS];
    char buffer[BUFFER_SIZE];

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Enter a number to convert to binary: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        int num = atoi(buffer);
        thread_args[i].number = num;
        thread_args[i].binary_string = malloc(sizeof(char) * 33);
        
        // Create the thread
        int rc = pthread_create(&thread_ids[i], NULL, convert_to_binary, (void*) &thread_args[i]);

        if (rc) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
            exit(-1);
        }
    }

    // Wait for the threads to finish before printing binary strings
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
        printf("%d in binary: %s\n", thread_args[i].number, thread_args[i].binary_string);
        free(thread_args[i].binary_string);
    }

    return 0;
}