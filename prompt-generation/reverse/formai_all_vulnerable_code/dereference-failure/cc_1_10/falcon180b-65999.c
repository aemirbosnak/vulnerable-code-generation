//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void loadWords(FILE* fp, Word words[MAX_WORDS]) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void spellCheck(FILE* fp, Word words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    while (fscanf(fp, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        bool found = false;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Unknown word: %s\n", word);
        }
    }
}

void printWords(Word words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary> <text>\n", argv[0]);
        return 1;
    }

    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    loadWords(fp1, words);
    spellCheck(fp2, words);
    printWords(words);

    fclose(fp1);
    fclose(fp2);

    return 0;
}