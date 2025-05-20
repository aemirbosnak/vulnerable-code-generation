//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

// Structure to store the word count for each thread
typedef struct {
    pthread_t thread_id;
    int word_count;
} WordCount;

// Mutex to protect the shared word count
pthread_mutex_t mutex;

// Function to count the words in a given string
void *count_words(void *arg) {
    // Get the string to count words from
    char *string = (char *)arg;

    // Initialize the word count for this thread
    int word_count = 0;

    // Tokenize the string into words
    char *token = strtok(string, " ");
    while (token != NULL) {
        // Increment the word count for this thread
        word_count++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Lock the mutex to protect the shared word count
    pthread_mutex_lock(&mutex);

    // Add the word count for this thread to the shared word count
    ((WordCount *)arg)->word_count += word_count;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Return NULL to indicate successful completion
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string to count words in>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread to count the words in the given string
    WordCount word_count;
    pthread_create(&word_count.thread_id, NULL, count_words, argv[1]);

    // Wait for the thread to complete
    pthread_join(word_count.thread_id, NULL);

    // Print the total word count
    printf("Total word count: %d\n", word_count.word_count);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}