//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

typedef struct Word {
    char *word;
    int count;
} Word;

void processText(char *text) {
    char words[MAX_LENGTH][50];
    int currentWord = 0;
    int length = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            text[i] = tolower(text[i]);
            words[currentWord][length++] = text[i];
        } else {
            if (length > 0) {
                words[currentWord][length++] = '\0';
                currentWord++;
                length = 0;
            }
            if (currentWord < MAX_LENGTH - 1) {
                continue;
            }
            break;
        }
    }

    if (length > 0) {
        words[currentWord][length++] = '\0';
        currentWord++;
    }

    Word *frequencyTable = malloc(sizeof(Word) * currentWord);

    for (int i = 0; i < currentWord; i++) {
        bool wordExists = false;

        for (int j = 0; j < currentWord; j++) {
            if (strcmp(words[i], frequencyTable[j].word) == 0) {
                wordExists = true;
                frequencyTable[j].count++;
                break;
            }
        }

        if (!wordExists) {
            frequencyTable[i].word = strdup(words[i]);
            frequencyTable[i].count = 1;
        }
    }

    for (int i = 0; i < currentWord; i++) {
        printf("Word: %s, Frequency: %d\n", frequencyTable[i].word, frequencyTable[i].count);
        free(frequencyTable[i].word);
    }

    free(frequencyTable);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    processText(argv[1]);

    return 0;
}