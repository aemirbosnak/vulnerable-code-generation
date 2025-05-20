//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 200

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void init_word_count(WordCount* wc, const char* word) {
    strcpy(wc->word, word);
    wc->count = 0;
}

void count_word(WordCount* wc, const char* text) {
    char* p = strtok(text, ",.?!;:");
    while (p!= NULL) {
        if (strcmp(wc->word, p) == 0) {
            wc->count++;
        }
        p = strtok(NULL, ",.?!;:");
    }
}

void print_word_counts(const WordCount* wc, int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", wc[i].word, wc[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <word1> <word2>...\n", argv[0]);
        return 1;
    }

    int num_words = argc - 2;
    WordCount wc[num_words];

    for (int i = 0; i < num_words; i++) {
        init_word_count(&wc[i], argv[i + 2]);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    char text[MAX_WORD_LEN];
    while (fgets(text, MAX_WORD_LEN, fp)!= NULL) {
        for (int i = 0; i < num_words; i++) {
            count_word(&wc[i], text);
        }
    }

    fclose(fp);

    print_word_counts(wc, num_words);

    return 0;
}