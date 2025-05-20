//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the pattern and its size
typedef struct {
    int size;
    char **pattern;
} Pattern;

// Mutex to protect the shared pattern
pthread_mutex_t pattern_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to generate a random pattern
Pattern *generate_pattern(int size) {
    Pattern *pattern = (Pattern *)malloc(sizeof(Pattern));
    pattern->size = size;
    pattern->pattern = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        pattern->pattern[i] = (char *)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            pattern->pattern[i][j] = (rand() % 2) ? '*' : ' ';
        }
    }
    return pattern;
}

// Function to print the pattern
void print_pattern(Pattern *pattern) {
    pthread_mutex_lock(&pattern_mutex);
    for (int i = 0; i < pattern->size; i++) {
        for (int j = 0; j < pattern->size; j++) {
            printf("%c", pattern->pattern[i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&pattern_mutex);
}

// Function to update the pattern
void *update_pattern(void *arg) {
    Pattern *pattern = (Pattern *)arg;
    while (1) {
        // Sleep for a random amount of time
        sleep(rand() % 3);
        // Update the pattern
        pthread_mutex_lock(&pattern_mutex);
        for (int i = 0; i < pattern->size; i++) {
            for (int j = 0; j < pattern->size; j++) {
                pattern->pattern[i][j] = (rand() % 2) ? '*' : ' ';
            }
        }
        pthread_mutex_unlock(&pattern_mutex);
    }
    return NULL;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random pattern
    Pattern *pattern = generate_pattern(10);

    // Create a thread to update the pattern
    pthread_t update_thread;
    pthread_create(&update_thread, NULL, update_pattern, pattern);

    // Print the pattern until the user presses Enter
    while (getchar() != '\n') {
        print_pattern(pattern);
    }

    // Join the update thread
    pthread_join(update_thread, NULL);

    // Free the pattern
    for (int i = 0; i < pattern->size; i++) {
        free(pattern->pattern[i]);
    }
    free(pattern->pattern);
    free(pattern);

    return 0;
}