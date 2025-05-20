//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 10000

typedef struct Word {
    char *word;
    int count;
} Word;

void process_line(char line[], Word words[], int *num_words) {
    char *token;
    int i;

    for (i = 0; i < *num_words; i++) {
        if (strcmp(line, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }

    token = strtok(line, " ");
    if (token == NULL) return;

    words = realloc(words, sizeof(Word) * (*num_words + 1));
    words[*num_words].word = strdup(token);
    words[*num_words].count = 1;
    (*num_words)++;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Word words[MAX_WORDS];
    int num_words = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        process_line(line, words, &num_words);
    }

    fclose(fp);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}