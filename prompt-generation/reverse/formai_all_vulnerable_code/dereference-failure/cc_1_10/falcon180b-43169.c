//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void tokenize(char *text, char **tokens) {
    char *token = strtok(text, ",.?!;:\"'");
    int i = 0;

    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.?!;:\"'");
    }

    tokens[i] = NULL;
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *text = NULL;
    size_t len = 0;
    WordFrequency *wordFrequencies = NULL;
    int numWords = 0;

    file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (getline(&line, &len, file)!= -1) {
        text = realloc(text, len + strlen(line) + 1);
        strcat(text, line);
    }

    fclose(file);

    tokenize(text, (char **)&wordFrequencies);

    for (int i = 0; i < numWords; i++) {
        wordFrequencies[i].count = 1;
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareStrings);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    free(text);

    return 0;
}