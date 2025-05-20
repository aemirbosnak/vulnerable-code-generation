//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *fp, char *filename, WordFrequency *word_frequencies) {
    char line[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int j;
            for (j = 0; j < i; j++) {
                if (strcmp(word_frequencies[j].word, token) == 0) {
                    word_frequencies[j].frequency++;
                    break;
                }
            }
            if (j == i) {
                strcpy(word_frequencies[i].word, token);
                word_frequencies[i].frequency = 1;
                i++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    read_file(fp, filename, word_frequencies);
    fclose(fp);

    num_words = sizeof(word_frequencies) / sizeof(WordFrequency);
    printf("Word frequencies:\n");
    print_word_frequencies(word_frequencies, num_words);

    return 0;
}