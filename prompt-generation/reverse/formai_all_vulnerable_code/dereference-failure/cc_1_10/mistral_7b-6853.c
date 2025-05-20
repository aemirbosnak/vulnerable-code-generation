//MISTRAL-7B DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100
#define NUM_OF_WORDS 10

typedef struct Word {
    char *word;
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool isWordDelimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

Word *createWord(char *word) {
    Word *newWord = (Word *)malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->count = 1;
    return newWord;
}

void addWordToTable(Word **table, char *word) {
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        if (!table[i]) {
            table[i] = createWord(word);
            break;
        }
        if (!strcmp(table[i]->word, word)) {
            table[i]->count++;
            free(word);
            return;
        }
    }
}

void processLine(Word **table, char *line) {
    char *token;
    toLowerCase(line);
    token = strtok(line, " \t\n");
    while (token) {
        addWordToTable(table, token);
        token = strtok(NULL, " \t\n");
    }
}

void printTable(Word **table) {
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        if (table[i]) {
            printf("%s: %d\n", table[i]->word, table[i]->count);
            free(table[i]->word);
            free(table[i]);
        }
    }
}

int main(int argc, char **argv) {
    Word *wordsTable[NUM_OF_WORDS];
    char line[MAX_STRING_LENGTH];

    while (gets(line) != NULL) {
        processLine(wordsTable, line);
    }

    printTable(wordsTable);

    return EXIT_SUCCESS;
}