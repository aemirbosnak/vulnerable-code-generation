//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Pattern dimensions
#define ROWS 10
#define COLS 10

// Character to print
#define CHAR '*'

// Thread data structure
typedef struct {
    int row;
    int col;
    char* pattern;
} thread_data;

// Thread function
void* print_pattern(void* arg) {
    thread_data* data = (thread_data*)arg;

    // Print the character at the specified position
    data->pattern[data->row * COLS + data->col] = CHAR;

    // Return NULL to indicate successful execution
    return NULL;
}

int main() {
    // Allocate memory for the pattern
    char* pattern = (char*)malloc(ROWS * COLS * sizeof(char));

    // Initialize the pattern with spaces
    for (int i = 0; i < ROWS * COLS; i++) {
        pattern[i] = ' ';
    }

    // Create threads to print the pattern
    pthread_t threads[ROWS * COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            thread_data* data = (thread_data*)malloc(sizeof(thread_data));
            data->row = i;
            data->col = j;
            data->pattern = pattern;
            pthread_create(&threads[i * COLS + j], NULL, print_pattern, data);
        }
    }

    // Join all threads
    for (int i = 0; i < ROWS * COLS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the pattern
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", pattern[i * COLS + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the pattern
    free(pattern);

    return 0;
}