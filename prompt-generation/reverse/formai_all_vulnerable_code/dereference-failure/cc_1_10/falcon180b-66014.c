//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_WORDS_PER_THREAD 1000
#define NUM_THREADS 4

typedef struct {
    char word[50];
    int count;
} word_count_t;

void *thread_func(void *arg) {
    FILE *fp = (FILE *) arg;
    char line[100];
    word_count_t words[MAX_WORDS_PER_THREAD];
    int num_words = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, ",\n");
        while (word!= NULL) {
            int len = strlen(word);
            if (len > 0 && isalpha(word[0])) {
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (num_words < MAX_WORDS_PER_THREAD) {
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
            word = strtok(NULL, ",\n");
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return NULL;
}

int main() {
    char filename[50] = "input.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, fp);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}