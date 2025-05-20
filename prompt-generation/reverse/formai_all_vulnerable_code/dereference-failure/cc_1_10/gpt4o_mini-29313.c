//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_WORDS 1000

typedef struct {
    char *buffer;   // Pointer to the text buffer
    int start;      // Starting index of the chunk
    int end;        // Ending index of the chunk
    int wordCount;  // Result: word count for this chunk
} ThreadData;

void *count_words(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int count = 0;
    int inWord = 0;

    for (int i = data->start; i < data->end; i++) {
        if (data->buffer[i] == ' ' || data->buffer[i] == '\n' || data->buffer[i] == '\t') {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    // Final check for the last word in the chunk
    if (inWord) {
        count++;
    }

    data->wordCount = count;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fileSize + 1);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Null-terminate the string
    fclose(file);

    pthread_t threads[MAX_THREADS];
    ThreadData threadData[MAX_THREADS];

    int chunkSize = fileSize / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        threadData[i].buffer = buffer;
        threadData[i].start = i * chunkSize;
        threadData[i].end = (i == MAX_THREADS - 1) ? fileSize : (i + 1) * chunkSize;
        threadData[i].wordCount = 0;

        pthread_create(&threads[i], NULL, count_words, (void *) &threadData[i]);
    }

    int totalWords = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        totalWords += threadData[i].wordCount;
    }

    printf("Total word count: %d\n", totalWords);

    free(buffer);
    return EXIT_SUCCESS;
}