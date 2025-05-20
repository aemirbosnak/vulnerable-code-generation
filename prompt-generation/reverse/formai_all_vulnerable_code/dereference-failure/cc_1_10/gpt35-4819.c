//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_WORD_SIZE 100
#define MAX_THREADS 10
#define BUFFER_SIZE 1000

int wordCount = 0;
char buffer[BUFFER_SIZE];
int bufferSize = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

bool isDelimiter(char ch) {
    return !(isalnum(ch) || ch == '-');
}

void incrementWordCount(char* word) {
    pthread_mutex_lock(&mutex);
    wordCount++;
    printf("%s\n", word);
    pthread_mutex_unlock(&mutex);
}

void* threadFunction(void* args) {
    while (true) {
        pthread_mutex_lock(&mutex);
        int start = bufferSize;
        bool wordStarted = false;
        
        while (isDelimiter(buffer[bufferSize])) {
            if (buffer[bufferSize] == '\0') {
                pthread_mutex_unlock(&mutex);
                return NULL;
            }
            bufferSize++;
            start++;
        }
        
        while (!isDelimiter(buffer[bufferSize])) {
            wordStarted = true;
            bufferSize++;
        }
        
        if (wordStarted) {
            char word[MAX_WORD_SIZE];
            strncpy(word, buffer + start, bufferSize - start);
            word[bufferSize - start] = '\0';
            incrementWordCount(word);
        }
        
        pthread_mutex_unlock(&mutex);
    }
}

void startWordCountThreads(int numThreads) {
    pthread_t threads[numThreads];
    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, threadFunction, NULL);
    }
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void readInputFromFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    while (!feof(file)) {
        int bytesRead = fread(buffer + bufferSize, 1, BUFFER_SIZE - bufferSize, file);
        bufferSize += bytesRead;
    }
    buffer[bufferSize] = '\0';
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./wordcount <file_name> <num_threads>\n");
        return EXIT_FAILURE;
    }
    
    int numThreads = atoi(argv[2]);
    if (numThreads > MAX_THREADS) {
        printf("Maximum number of threads is %d\n", MAX_THREADS);
        return EXIT_FAILURE;
    }
    
    readInputFromFile(argv[1]);
    startWordCountThreads(numThreads);
    
    printf("Total word count: %d\n", wordCount);
    
    return EXIT_SUCCESS;
}