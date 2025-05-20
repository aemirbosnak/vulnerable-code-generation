//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    Word *word_list = (Word*)malloc(MAX_WORDS * sizeof(Word));
    int num_words = 0;
    int total_words = 0;
    int i;

    fp = fopen("spam.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        total_words += count_words(line, word_list, &num_words);
    }

    fclose(fp);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }

    free(word_list);

    return 0;
}

int count_words(char *line, Word *word_list, int *num_words) {
    char *token;
    int i;

    token = strtok(line, " \t\n\r\f");
    while (token!= NULL) {
        for (i = 0; i < *num_words; i++) {
            if (strcmp(token, word_list[i].word) == 0) {
                word_list[i].count++;
                break;
            }
        }

        if (i == *num_words) {
            if (*num_words >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(1);
            }

            strncpy(word_list[*num_words].word, token, MAX_WORD_LENGTH);
            word_list[*num_words].count = 1;
            (*num_words)++;
        }

        token = strtok(NULL, " \t\n\r\f");
    }

    return *num_words;
}