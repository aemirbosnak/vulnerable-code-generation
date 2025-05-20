//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLowerCase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void processWord(Word *words, char *word) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    for (i = 99; i > 0 && strcmp(words[i].word, word) < 0; i--) {
        strcpy(words[i + 1].word, words[i].word);
    }

    strcpy(words[0].word, word);
    words[0].count = 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    Word words[MAX_WORDS];
    int numWords = 0;
    char line[1024];
    char word[WORD_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            toLowerCase(token);
            if (isalpha(token[0]) && strlen(token) <= WORD_LENGTH) {
                processWord(words, token);
                numWords++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    printf("Most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%d. %s - %d\n", i + 1, words[i].word, words[i].count);
    }

    return 0;
}