//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 4096
#define THREAD_COUNT 4

typedef struct {
    char *word;
    int count;
} word_t;

void *thread_func(void *arg) {
    word_t *words = arg;
    int i = 0;

    while (i < THREAD_COUNT) {
        char *line = words[i].word;
        int len = strlen(line);
        int count = 0;

        for (int j = 0; j < len; j++) {
            if (isalpha(line[j])) {
                count++;
            }
        }

        words[i].count = count;
        i++;
    }

    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    word_t words[THREAD_COUNT];
    sem_t sem;

    // Initialize semaphore
    sem_init(&sem, 0, THREAD_COUNT);

    // Fill word array with words from file
    FILE *file = fopen("words.txt", "r");
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, file)) {
        words[0].word = line;
        words[0].count = 0;
        pthread_create(&threads[0], NULL, thread_func, &words[0]);
        sem_wait(&sem);
    }

    // Start all threads
    for (int i = 1; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, thread_func, &words[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print word counts
    for (int i = 0; i < THREAD_COUNT; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}