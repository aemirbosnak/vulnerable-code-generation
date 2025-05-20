//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct Word {
    char str[WORD_SIZE];
    int count;
} Word;

Word wordList[MAX_WORDS];
int numWords = 0;

int isAlphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

void addWord(char *word) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (strcmp(wordList[i].str, word) == 0) {
            wordList[i].count++;
            return;
        }
    }

    strcpy(wordList[numWords].str, word);
    wordList[numWords].count = 1;
    numWords++;
}

void processLine(char *line) {
    char word[WORD_SIZE];
    int i, length;

    for (i = 0; i < strlen(line); i++) {
        if (isAlphanumeric(line[i])) {
            word[i] = tolower(line[i]);
            if (i > 0 && !isAlphanumeric(line[i - 1])) {
                word[i - 1] = ' ';
                word[i - 1 + 1] = '\0';
                addWord(word);
            }
        }
    }

    addWord(word);
}

int main(int argc, char **argv) {
    char *line;
    size_t len = 0;
    ssize_t read;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        processLine(line);
    }

    fclose(fp);
    free(line);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].str, wordList[i].count);
    }

    return 0;
}