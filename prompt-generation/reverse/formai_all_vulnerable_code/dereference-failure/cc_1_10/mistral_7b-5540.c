//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define WORD_COUNT_SIZE 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main(int argc, char **argv) {
    FILE *file;
    char filename[100];
    char line[1024];
    char word[MAX_WORD_LEN];
    WordCount wordCounts[WORD_COUNT_SIZE];
    int wordIndex = 0;

    if (argc != 2) {
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
        toLower(line);
        char *token = strtok(line, " \t\n");

        if (token == NULL) {
            continue;
        }

        int wordIndex = -1;
        for (int i = 0; i < WORD_COUNT_SIZE; i++) {
            if (strcmp(wordCounts[i].word, token) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex == -1) {
            if (wordIndex >= WORD_COUNT_SIZE) {
                WordCount newWordCount;
                strcpy(newWordCount.word, token);
                newWordCount.count = 1;

                for (int i = 0; i < wordIndex; i++) {
                    wordCounts[i] = wordCounts[i + 1];
                }

                wordCounts[wordIndex] = newWordCount;
            } else {
                wordCounts[wordIndex].count++;
            }
        }
    }

    fclose(file);

    printf("\nWord count:\n");
    for (int i = 0; i < WORD_COUNT_SIZE; i++) {
        if (wordCounts[i].count > 0) {
            printf("%-20s : %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    return 0;
}