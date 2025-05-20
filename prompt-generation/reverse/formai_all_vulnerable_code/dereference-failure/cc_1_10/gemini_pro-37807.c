//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when summary is ready
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Shared data: the input text and the output summary
char *text;
char *summary;

// Thread function to summarize text
void *summarize(void *arg) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Allocate memory for the summary
    summary = malloc(strlen(text) / 2 + 1);

    // Summarize the text
    // ...

    // Signal that the summary is ready
    pthread_cond_signal(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char **argv) {
    // Check if input text is provided
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the input text
    text = malloc(strlen(argv[1]) + 1);

    // Copy the input text into the shared data
    strcpy(text, argv[1]);

    // Create a thread to summarize the text
    pthread_t thread;
    pthread_create(&thread, NULL, summarize, NULL);

    // Wait for the summary to be ready
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}