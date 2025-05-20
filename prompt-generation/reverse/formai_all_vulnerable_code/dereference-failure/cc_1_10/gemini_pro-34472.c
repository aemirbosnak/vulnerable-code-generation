//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} word_count;

word_count *word_counts;
int num_words;

pthread_mutex_t lock;

void *count_words(void *arg) {
    char *text = (char *)arg;

    char *word;
    while ((word = strtok(text, " ,;:.?!()[]{}")) != NULL) {
        pthread_mutex_lock(&lock);
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            word_counts = realloc(word_counts, sizeof(word_count) * (num_words + 1));
            word_counts[num_words].word = strdup(word);
            word_counts[num_words].count = 1;
            num_words++;
        }
        pthread_mutex_unlock(&lock);

        text = NULL;
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
        perror("fopen");
        return 1;
    }

    char *text = malloc(100000);
    fread(text, 1, 100000, file);
    fclose(file);

    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, count_words, text);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(text);
    free(word_counts);

    return 0;
}