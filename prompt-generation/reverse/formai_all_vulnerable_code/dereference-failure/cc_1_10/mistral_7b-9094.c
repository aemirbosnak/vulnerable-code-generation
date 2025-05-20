//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    int count;
} Word;

void countWords(char *input, Word words[]) {
    int i, j;
    int numWords = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            if (numWords < MAX_WORDS) {
                for (j = 0; words[numWords].str[j] != '\0'; j++) {
                    if (strcmp(words[numWords].str, &input[i-1]) == 0) {
                        words[numWords].count++;
                        return;
                    }
                }
                strncpy(words[numWords].str, &input[i+1], WORD_LENGTH);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    if (numWords < MAX_WORDS) {
        strncpy(words[numWords].str, &input[i], WORD_LENGTH);
        words[numWords].count = 1;
    }
}

int main() {
    char input[1024];
    Word words[MAX_WORDS];

    printf("Enter text: \n");
    fgets(input, sizeof(input), stdin);
    input[strlen(input)] = '\0';

    countWords(input, words);

    printf("\nWord count:\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].str, words[i].count);
        }
    }

    return 0;
}