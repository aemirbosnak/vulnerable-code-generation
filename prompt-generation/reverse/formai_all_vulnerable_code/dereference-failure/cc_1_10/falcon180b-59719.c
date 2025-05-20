//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_freq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

struct word_freq words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].freq++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].freq = 1;
    num_words++;
}

void print_word_freq(FILE *fp) {
    int i;
    for (i = 0; i < num_words; i++) {
        fprintf(fp, "%s: %d\n", words[i].word, words[i].freq);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    char ch;

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(word, "");
            do {
                strcat(word, tolower(ch));
                ch = fgetc(fp);
            } while (isalpha(ch));
            add_word(word);
        }
        ungetc(ch, fp);
    }

    print_word_freq(stdout);

    return 0;
}