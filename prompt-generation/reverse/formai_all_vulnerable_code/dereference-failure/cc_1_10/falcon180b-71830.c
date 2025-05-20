//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

void *count_words(void *arg) {
    FILE *file = (FILE *) arg;
    char line[256];
    char *word;
    WordCount *word_counts = (WordCount *) malloc(MAX_WORDS * sizeof(WordCount));

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                if (word_counts[0].word == NULL) {
                    strcpy(word_counts[0].word, word);
                } else {
                    printf("Max word limit reached\n");
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[10];
    FILE *file;
    int i;

    file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, count_words, file);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}