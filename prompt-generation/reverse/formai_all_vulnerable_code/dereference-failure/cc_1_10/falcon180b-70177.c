//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE *file, WordFrequency words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    words[i].word[j] = tolower(ch);
                    j++;
                }
            }
            words[i].word[j] = '\0';
            words[i].frequency++;
            i++;
        }
    }
}

void displayWords(WordFrequency words[MAX_WORDS], int numWords, int minFrequency) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (words[i].frequency >= minFrequency) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <min_frequency>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int minFrequency = atoi(argv[2]);

    WordFrequency words[MAX_WORDS];
    readFile(file, words);

    displayWords(words, MAX_WORDS, minFrequency);

    fclose(file);
    return 0;
}