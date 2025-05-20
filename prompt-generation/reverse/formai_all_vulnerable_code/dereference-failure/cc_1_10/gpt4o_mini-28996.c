//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 100
#define ASCII_ART_SCALE 6
#define THREAD_COUNT 4

typedef struct {
    char *input;
    int thread_id;
} thread_data_t;

void *convert_to_ascii_art(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    char *input = data->input;
    int thread_id = data->thread_id;

    printf("Thread %d processing: %s\n", thread_id, input);

    // Convert each character to ASCII art
    for (int i = 0; i < strlen(input); i++) {
        // Simple representation of an ASCII character as blocks
        if (input[i] == ' ') {
            printf("  \n"); // Two spaces for a space character
        } else {
            for (int j = 0; j < ASCII_ART_SCALE; j++) {
                printf("%c ", input[i]);
            }
            printf("\n");
        }
        usleep(100000); // Simulate some processing delay
    }

    return NULL;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    pthread_t threads[THREAD_COUNT];
    thread_data_t thread_data[THREAD_COUNT];
    int str_length = strlen(input);
    int chunk_size = str_length / THREAD_COUNT;
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].input = (char *)malloc(chunk_size + 1);
        
        // Assign chunk of input to thread
        strncpy(thread_data[i].input, input + i * chunk_size, chunk_size);
        
        // Add remaining characters to the last thread
        if (i == THREAD_COUNT - 1) {
            strcpy(thread_data[i].input + chunk_size, input + i * chunk_size + chunk_size);
        }
        
        pthread_create(&threads[i], NULL, convert_to_ascii_art, (void *)&thread_data[i]);
    }

    // Join all threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        free(thread_data[i].input); // Free the allocated memory
    }

    printf("ASCII Art generation complete!\n");
    return 0;
}