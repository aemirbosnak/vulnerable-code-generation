//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define WORD_LENGTH_MAX 50

typedef struct {
    char word[WORD_LENGTH_MAX];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a file path\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return -1;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char ch;
    bool inWord = false;
    char word[WORD_LENGTH_MAX] = {0};
    int wordIndex = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!inWord) {
                inWord = true;
                word[0] = tolower(ch);
                wordIndex = 1;
            } else {
                strcat(word, &ch);
            }
        } else {
            inWord = false;
            if (wordIndex > 0) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            word[0] = '\0';
            wordIndex = 0;
        }
    }

    if (inWord) {
        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}