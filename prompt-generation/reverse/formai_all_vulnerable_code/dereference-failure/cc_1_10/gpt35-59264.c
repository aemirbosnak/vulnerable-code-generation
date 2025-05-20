//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

// Struct to hold thread-specific data
typedef struct ThreadData {
    char *word;
    char **fileContents;
    int startIndex;
    int endIndex;
    int *results;
} ThreadData;

// Function that each thread will run
void *countWords(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // Iterate through the specified range of lines in the file
    for (int i = data->startIndex; i <= data->endIndex; i++) {
        char *line = data->fileContents[i];
        char *wordCopy = malloc((strlen(data->word) + 1) * sizeof(char));
        strcpy(wordCopy, data->word);

        // Iterate through the line, checking for matches
        char *tok = strtok(line, " .,;:");
        while (tok != NULL) {
            if (strcmp(tok, wordCopy) == 0) {
                data->results[i]++;
            }
            tok = strtok(NULL, " .,;:");
        }

        free(wordCopy);
    }

    pthread_exit(NULL);
}

int main() {
    // Read in the file
    FILE *fp = fopen("input.txt", "r");
    char **fileContents = malloc(1000 * sizeof(char *));
    for (int i = 0; i < 1000; i++) {
        char *line = malloc(100 * sizeof(char));
        if (fgets(line, 100, fp) != NULL) {
            fileContents[i] = line;
        } else {
            break;
        }
    }
    fclose(fp);

    // Prompt the user for the word to count
    char word[100];
    printf("Enter the word to count: ");
    scanf("%s", word);

    // Initialize the results array
    int *results = malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++) {
        results[i] = 0;
    }

    // Split up the work among threads
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int linesPerThread = 250;
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].word = word;
        threadData[i].fileContents = fileContents;
        threadData[i].startIndex = i * linesPerThread;
        threadData[i].endIndex = (i + 1) * linesPerThread - 1;
        if (i == NUM_THREADS - 1) {
            threadData[i].endIndex = 999;
        }
        threadData[i].results = results;
        pthread_create(&threads[i], NULL, countWords, (void *)&threadData[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    printf("The word '%s' appears in the file as follows:\n", word);
    for (int i = 0; i < 1000; i++) {
        if (results[i] > 0) {
            printf("Line %d: %d occurrences\n", i + 1, results[i]);
        }
    }

    // Clean up memory
    for (int i = 0; i < 1000; i++) {
        free(fileContents[i]);
    }
    free(fileContents);
    free(results);

    return 0;
}