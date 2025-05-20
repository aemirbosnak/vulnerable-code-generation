//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    char line[WORD_LENGTH];
    char *word = NULL;
    int i = 0;

    while (fgets(line, WORD_LENGTH, file)) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            if (i < MAX_WORDS) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            } else {
                printf("Error: Too many words.\n");
                exit(1);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void countWords(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    char line[WORD_LENGTH];
    char *word = NULL;
    int i = 0;

    while (fgets(line, WORD_LENGTH, file)) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            for (int j = 0; j < i; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (i < MAX_WORDS) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            } else {
                printf("Error: Too many words.\n");
                exit(1);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void printWords(WordCount *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    WordCount words[MAX_WORDS];

    loadWords(filename, words);
    countWords(filename, words);
    printWords(words);

    return 0;
}