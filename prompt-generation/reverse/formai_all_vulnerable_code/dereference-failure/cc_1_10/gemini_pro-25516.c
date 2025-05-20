//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Global variables
char *text;
int text_len;
int num_threads;
pthread_t *threads;
int *results;

// Thread function
void *thread_func(void *arg) {
    // Get the thread id
    int id = *(int *)arg;

    // Calculate the start and end indices of the text for this thread
    int start = id * text_len / num_threads;
    int end = (id + 1) * text_len / num_threads;

    // Count the number of characters typed correctly
    int count = 0;
    for (int i = start; i < end; i++) {
        if (text[i] == getchar()) {
            count++;
        }
    }

    // Store the result
    results[id] = count;

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Get the text and its length
    printf("Enter the text to be typed: ");
    text = malloc(1000);
    fgets(text, 1000, stdin);
    text_len = strlen(text);

    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create the threads
    threads = malloc(sizeof(pthread_t) * num_threads);
    results = malloc(sizeof(int) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, thread_func, arg);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the total number of characters typed correctly
    int total_count = 0;
    for (int i = 0; i < num_threads; i++) {
        total_count += results[i];
    }

    // Print the results
    printf("Total characters typed correctly: %d\n", total_count);
    printf("Typing speed: %f characters per second\n", (double)total_count / text_len * 60);

    // Free the allocated memory
    free(text);
    free(threads);
    free(results);

    return 0;
}