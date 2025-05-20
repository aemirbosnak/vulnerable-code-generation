//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char word[50];
    int count;
} Word;

void toLowerCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *) a)->word, ((Word *) b)->word);
}

void addWord(Word **words, int *numWords, char *word) {
    int i = 0;
    for (i = 0; i < *numWords; i++) {
        if (strcmp((*words)[i].word, word) == 0) {
            (*words)[i].count++;
            return;
        }
    }

    *words = realloc(*words, sizeof(Word) * (*numWords + 1));

    strcpy((*words)[*numWords].word, word);
    (*words)[*numWords].count = 1;
    (*numWords)++;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    Word *words = NULL;
    int numWords = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        toLowerCase(line);
        char *token = strtok(line, " ");
        while (token != NULL) {
            addWord(&words, &numWords, token);
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    free(words);

    return 0;
}