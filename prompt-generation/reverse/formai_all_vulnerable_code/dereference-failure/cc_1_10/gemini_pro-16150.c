//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 10000
#define MAX_THREADS 16

typedef struct {
    char *word;
    int count;
} word_count;

word_count word_counts[MAX_WORDS];
int num_words = 0;

pthread_mutex_t lock;

void *count_words(void *arg) {
    char *text = (char *)arg;

    char *word = strtok(text, " ");
    while (word != NULL) {
        pthread_mutex_lock(&lock);

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words < MAX_WORDS) {
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
        }

        pthread_mutex_unlock(&lock);

        word = strtok(NULL, " ");
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(size + 1);
    fread(text, 1, size, file);
    fclose(file);

    pthread_t threads[MAX_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_mutex_init(&lock, NULL);

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], &attr, count_words, text);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&lock);

    qsort(word_counts, num_words, sizeof(word_count),
            (int (*)(const void *, const void *))strcmp);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}