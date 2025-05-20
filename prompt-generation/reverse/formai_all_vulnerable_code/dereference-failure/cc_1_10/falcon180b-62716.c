//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

bool isWord(char c) {
    return isalpha(c);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1000];
    char *word;
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: word too long.\n");
                return 1;
            }
            for (i = 0; i < strlen(word); i++) {
                if (!isWord(tolower(word[i]))) {
                    printf("Error: invalid character in word.\n");
                    return 1;
                }
            }
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                return 1;
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}