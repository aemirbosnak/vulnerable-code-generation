//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return wc2->count - wc1->count;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount word_counts[100];
    int num_words = 0;
    int i;

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open logfile.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= 100) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}