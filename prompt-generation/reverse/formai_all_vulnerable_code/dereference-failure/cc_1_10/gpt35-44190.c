//FormAI DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_BUFFER_SIZE 256

typedef struct {
    char *filename;
    int count;
} WordCountResult;

void *countWords(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide filenames as arguments.\n");
        exit(1);
    }

    int numFiles = argc - 1;
    char **files = &argv[1];

    pthread_t threads[MAX_THREADS];
    int threadCount = numFiles < MAX_THREADS ? numFiles : MAX_THREADS;
    WordCountResult results[threadCount];

    int currentThreadIndex = 0;
    for (int i = 0; i < numFiles; i++) {
        if (currentThreadIndex == threadCount) {
            currentThreadIndex = 0;
        }

        void *arg = malloc(sizeof(char *));
        *((char **) arg) = files[i];
        pthread_create(&threads[currentThreadIndex], NULL, countWords, arg);

        currentThreadIndex++;
    }

    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }

    int totalCount = 0;
    for (int i = 0; i < threadCount; i++) {
        totalCount += results[i].count;
        printf("%s: %d words\n", results[i].filename, results[i].count);
    }

    printf("Total word count: %d\n", totalCount);

    return 0;
}

void *countWords(void *arg) {
    char *filename = *((char **) arg);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        pthread_exit(NULL);
    }

    char buffer[MAX_BUFFER_SIZE];
    int count = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        char *token = strtok(buffer, " \t\n\r");  // Splitting by spaces, tabs, and newlines
        while (token != NULL) {
            count++;
            token = strtok(NULL, " \t\n\r");
        }
    }

    WordCountResult *result = malloc(sizeof(WordCountResult));
    result->filename = filename;
    result->count = count;

    pthread_exit(result);
}