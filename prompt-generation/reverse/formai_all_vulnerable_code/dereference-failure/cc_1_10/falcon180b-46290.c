//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Buffer overflow!\n");
            exit(1);
        }

        if (isalpha(ch)) {
            buffer[index++] = tolower(ch);
        }
    }

    buffer[index] = '\0';
}

void tokenize(char *buffer, WordFrequency *frequencies, int numWords) {
    char *token = strtok(buffer, ",.!?;:\"'");

    while (token!= NULL && numWords > 0) {
        int i;

        for (i = 0; i < numWords; i++) {
            if (strcmp(frequencies[i].word, token) == 0) {
                frequencies[i].count++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached!\n");
                exit(1);
            }

            strncpy(frequencies[numWords].word, token, MAX_WORD_LENGTH);
            frequencies[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, ",.!?;:\"'");
    }
}

void printFrequencies(WordFrequency *frequencies, int numWords) {
    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    readFile(file, buffer);
    tokenize(buffer, frequencies, numWords);
    printFrequencies(frequencies, numWords);

    fclose(file);

    return 0;
}