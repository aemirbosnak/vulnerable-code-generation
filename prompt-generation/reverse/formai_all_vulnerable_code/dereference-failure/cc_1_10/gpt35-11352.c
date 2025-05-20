//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 512
#define MAX_WORD_LENGTH 25

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    char* inputString = (char*)calloc(MAX_BUFFER_SIZE, sizeof(char));
    Word* wordList = (Word*)malloc(MAX_BUFFER_SIZE * sizeof(Word));
    char* token;

    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        wordList[i].count = 0;
        memset(wordList[i].word, '\0', MAX_WORD_LENGTH);
    }

    printf("Enter string to evaluate word count: ");
    fgets(inputString, MAX_BUFFER_SIZE, stdin);

    token = strtok(inputString, " \r\n");

    while (token != NULL) {
        bool newWord = true;

        for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
            if (strcmp(wordList[i].word, token) == 0) {
                wordList[i].count += 1;
                newWord = false;
                break;
            }

            if (strlen(wordList[i].word) == 0) {
                strcpy(wordList[i].word, token);
                wordList[i].count += 1;
                newWord = false;
                break;
            }
        }

        if (newWord) {
            printf("Word list overflow.\n");
            break;
        }

        token = strtok(NULL, " \r\n");
    }

    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if (strlen(wordList[i].word) == 0) {
            break;
        }

        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    free(inputString);
    free(wordList);

    return 0;
}