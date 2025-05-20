//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[words[i].frequency] = tolower(ch);
            words[i].frequency++;
        } else if (words[i].frequency > 0) {
            words[i].word[words[i].frequency] = '\0';
            i++;
            if (i >= MAX_WORDS) {
                printf("Reached maximum number of words.\n");
                exit(1);
            }
        }
    }
}

void sort_words(WordFrequency words[MAX_WORDS]) {
    int i, j;
    WordFrequency temp;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, words);
    fclose(file);

    sort_words(words);
    print_word_frequencies(words);

    return 0;
}