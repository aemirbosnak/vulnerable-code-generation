//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct Word {
    char *word;
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compareWords(const void *a, const void *b) {
    Word *w1 = (Word *) a;
    Word *w2 = (Word *) b;

    int len1 = strlen(w1->word);
    int len2 = strlen(w2->word);

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    return strcmp(w1->word, w2->word);
}

void readWordsFromFile(char *filename, Word words[]) {
    FILE *file = fopen(filename, "r");

    char line[1024];
    char *token = NULL;
    int index = 0;

    if (!file) {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        toLowerCase(line);
        token = strtok(line, " ,.\n");

        if (index >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(EXIT_FAILURE);
        }

        words[index].word = malloc(strlen(token) + 1);
        strcpy(words[index].word, token);
        words[index].count = 1;
        index++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    char filename[256];

    printf("Enter file name: ");
    scanf("%s", filename);

    readWordsFromFile(filename, words);

    qsort(words, MAX_WORDS, sizeof(Word), compareWords);

    printf("\nWord frequencies:\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i].word);
    }

    return EXIT_SUCCESS;
}