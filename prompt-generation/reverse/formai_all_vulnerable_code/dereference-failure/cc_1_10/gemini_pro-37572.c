//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} word_t;

word_t dictionary[MAX_WORDS];
int num_words = 0;

pthread_mutex_t lock;

void *spellcheck(void *arg) {
    char *text = (char *)arg;

    char *word;
    while ((word = strtok(text, " ,;:\n\t")) != NULL) {
        pthread_mutex_lock(&lock);
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                dictionary[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            dictionary[num_words].word = strdup(word);
            dictionary[num_words].count = 1;
            num_words++;
        }
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s text_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *text = malloc(file_size + 1);
    if (text == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

     fread(text, 1, file_size, fp);
    text[file_size] = '\0';

    pthread_t tid[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid[i], NULL, spellcheck, text);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }

    qsort(dictionary, num_words, sizeof(word_t),
          (int (*)(const void *, const void *))strcmp);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
        free(dictionary[i].word);
    }

    free(text);
    fclose(fp);

    return EXIT_SUCCESS;
}