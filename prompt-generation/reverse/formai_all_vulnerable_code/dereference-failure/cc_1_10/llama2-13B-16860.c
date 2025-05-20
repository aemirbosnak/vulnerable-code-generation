//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define WORDS_PER_THREAD 10

sem_t *sem;
pthread_t threads[5];

void *word_counter(void *arg) {
    char *text = arg;
    int i, words = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            words++;
        }
    }

    sem_post(sem);
    pthread_exit(NULL);
}

int main() {
    sem_init(sem, 0, 5);

    char text[] = "The quick brown fox jumps over the lazy dog";
    char *words[5];

    for (int i = 0; i < 5; i++) {
        words[i] = text + (i * WORDS_PER_THREAD);
    }

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, word_counter, words[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_words = 0;
    for (int i = 0; i < 5; i++) {
        total_words += words[i];
    }

    printf("Total words: %d\n", total_words);

    sem_destroy(sem);

    return 0;
}