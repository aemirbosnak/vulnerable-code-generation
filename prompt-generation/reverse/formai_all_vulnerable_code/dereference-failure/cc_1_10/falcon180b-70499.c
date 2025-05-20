//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].frequency = 1;
    num_words++;
}

void print_words(FILE* out) {
    int i;
    for (i = 0; i < num_words; i++) {
        fprintf(out, "%s %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char** argv) {
    FILE* in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }
    FILE* out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(in, "%s", word)!= EOF) {
        add_word(word);
    }
    fclose(in);
    print_words(out);
    fclose(out);
    return 0;
}