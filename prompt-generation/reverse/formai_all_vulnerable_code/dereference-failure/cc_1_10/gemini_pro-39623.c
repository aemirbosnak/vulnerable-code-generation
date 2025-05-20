//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_THREADS 10

typedef struct {
    char *word;
    int count;
} word_count;

word_count words[MAX_WORDS];
int num_words = 0;
pthread_mutex_t lock;

void *spell_check(void *arg) {
    int start = (int)arg;
    int end = start + MAX_WORDS / MAX_THREADS;

    for (int i = start; i < end; i++) {
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            pthread_mutex_lock(&lock);
            words[num_words].word = strdup(words[i].word);
            words[num_words].count = 1;
            num_words++;
            pthread_mutex_unlock(&lock);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    char *filename = "dictionary.txt";

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *word = strtok(line, "\n");
        words[num_words].word = strdup(word);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(file);

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, spell_check, (void *)i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}