//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LEN 64

typedef struct {
    char word[WORD_LEN];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words) {
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        while (i < strlen(line)) {
            char *word = strtok_r(line + i, " \t\n\r\f\v", &line[i]);
            if (word!= NULL && strlen(word) > 0) {
                int len = strlen(word);
                if (len > WORD_LEN - 1) {
                    len = WORD_LEN - 1;
                }
                strncpy(words[i].word, word, len);
                words[i].word[len] = '\0';
                i++;
            }
        }
    }
}

void sortWords(WordFrequency *words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(words[j].word, words[j + 1].word) > 0) {
                WordFrequency temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void printWords(WordFrequency *words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    WordFrequency *words = malloc(MAX_WORDS * sizeof(WordFrequency));
    int n = 0;

    readWords(file, words);
    sortWords(words, n);
    printWords(words, n);

    free(words);
    fclose(file);

    return 0;
}