//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

char line[MAX_LINE_LENGTH];
WordCount words[MAX_WORDS];
int numWords;

void addWord(char* word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strncpy(words[numWords].word, word, MAX_WORD_LENGTH);
    words[numWords].count = 1;
    numWords++;
}

void printWords() {
    int i;
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* file;
    char* buffer;
    size_t length;
    int i;

    numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    buffer = (char*) malloc(MAX_LINE_LENGTH);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    while ((length = fread(buffer, sizeof(char), MAX_LINE_LENGTH, file)) > 0) {
        buffer[length] = '\0';
        line[0] = '\0';
        i = 0;
        while (i < length) {
            if (isspace(buffer[i])) {
                addWord(line);
                line[0] = '\0';
            } else {
                strncat(line, &buffer[i], sizeof(char));
            }
            i++;
        }
        addWord(line);
        line[0] = '\0';
    }

    fclose(file);

    printWords();

    return 0;
}