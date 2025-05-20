//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_CHARS 1000
#define MAX_WORDS 200

// Global variables
char **words;
int *counts;
int totalWords = 0;
int uniqueWords = 0;

// Struct used to pass arguments to worker functions
typedef struct {
    int start;
    int end;
} WorkerArgs;

// Function to split the words in a string
int splitWords(char *str) {
    int count = 0;
    char *pch = strtok(str, " ,.-\n");

    while (pch != NULL && count < MAX_WORDS) {
        // Convert word to lowercase
        for (int i = 0; pch[i]; i++) {
            pch[i] = tolower(pch[i]);
        }

        // Add word to array if it doesn't exist already
        bool exists = false;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i], pch) == 0) {
                counts[i]++;
                exists = true;
                break;
            }
        }

        if (!exists) {
            words[totalWords] = strdup(pch);
            counts[totalWords]++;
            totalWords++;
            uniqueWords++;
        }

        count++;
        pch = strtok(NULL, " ,.-\n");
    }

    return count;
}

// Function to perform word count on a portion of the string
void *wordCountWorker(void *args) {
    WorkerArgs *workerArgs = (WorkerArgs *) args;
    int count = 0;

    for (int i = workerArgs->start; i <= workerArgs->end; i++) {
        count += splitWords(words[i]);
    }

    pthread_exit((void *) count);
}

// Function to count the words in the string using multiple threads
int wordCount(char *str, int numThreads) {
    // Allocate memory for word and count arrays
    words = calloc(MAX_WORDS, sizeof(char *));
    counts = calloc(MAX_WORDS, sizeof(int));

    // Initialize thread attributes
    pthread_t threads[numThreads];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Determine the size of each portion of the string to be processed by each thread
    int segmentSize = strlen(str) / numThreads;
    WorkerArgs workerArgs[numThreads];

    // Create worker threads and assign portions of the string to each thread
    int start = 0;
    int end = segmentSize;
    int totalCount = 0;

    for (int i = 0; i < numThreads; i++) {
        workerArgs[i].start = start;
        workerArgs[i].end = end;

        if (i == numThreads - 1) {
            // Last thread processes remaining portion of string
            workerArgs[i].end = strlen(str) - 1;
        }

        pthread_create(&threads[i], &attr, wordCountWorker, &workerArgs[i]);

        start = end + 1;
        end += segmentSize;

        // Wait for threads to finish and add their word counts to the total
        void *status;
        pthread_join(threads[i], &status);
        totalCount += (int) status;
    }

    // Clean up thread attributes
    pthread_attr_destroy(&attr);

    // Print total and unique word counts
    printf("Total words: %d\nUnique words: %d\n", totalCount, uniqueWords);

    // Print each word and its count
    for (int i = 0; i < uniqueWords; i++) {
        printf("%s: %d\n", words[i], counts[i]);
        free(words[i]);
    }

    // Free memory used by word and count arrays
    free(words);
    free(counts);

    return totalCount;
}

int main() {
    // Read input from file
    FILE *file = fopen("input.txt", "r");
    char str[MAX_CHARS + 1];
    fread(str, sizeof(char), MAX_CHARS, file);
    fclose(file);

    // Count words using 4 threads
    wordCount(str, 4);

    return 0;
}