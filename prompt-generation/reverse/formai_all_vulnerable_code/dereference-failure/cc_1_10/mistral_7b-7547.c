//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void encodeMessage(char *message, Word table[]) {
    int length = strlen(message), i, j;
    char temp;

    for(i = 0; i < length; i++) {
        if(isalpha(message[i])) {
            for(j = 0; j < MAX_WORDS; j++) {
                if(strncmp(table[j].word, &message[i], 1) == 0) {
                    message[i] = table[j].word[strlen(table[j].word)];
                    table[j].count++;
                    break;
                }
            }
        }
    }
}

void decodeMessage(char *message, Word table[]) {
    int length = strlen(message), i, j;
    char temp;

    for(i = 0; i < length; i++) {
        if(isalpha(message[i])) {
            for(j = 0; j < MAX_WORDS; j++) {
                if(message[i] == table[j].word[strlen(table[j].word) - 1]) {
                    printf("%s ", table[j].word);
                    break;
                }
            }
        } else {
            printf("%c ", message[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int i, wordsCount = 0;
    Word wordTable[MAX_WORDS];

    if(argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    strcpy(wordTable[0].word, "");
    wordTable[0].count = 0;

    for(i = 0; i < strlen(argv[1]); i++) {
        if(isalpha(argv[1][i])) {
            int j;

            for(j = 0; j < wordsCount; j++) {
                if(strncmp(wordTable[j].word, &argv[1][i], 1) == 0) {
                    wordTable[j].count++;
                    break;
                }
            }

            if(j == wordsCount) {
                strncpy(wordTable[wordsCount].word, &argv[1][i], 1 + rand() % 50);
                wordTable[wordsCount++].count = 1;
            }
        }
    }

    encodeMessage(argv[1], wordTable);

    printf("Encoded message:\n");
    for(i = 0; i < wordsCount; i++) {
        printf("%c%s", wordTable[i].word[0], wordTable[i].word + strlen(wordTable[i].word));
    }
    printf("\n");

    printf("Word count table:\n");
    for(i = 0; i < wordsCount; i++) {
        printf("%s: %d\n", wordTable[i].word, wordTable[i].count);
    }

    decodeMessage(argv[1], wordTable);

    return 0;
}