//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

struct word_t {
    char word[WORD_LENGTH];
    int count;
};

void load_words(struct word_t *words, int num_words) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", words[i].word)!= EOF && i < num_words) {
        i++;
    }

    fclose(fp);
}

void count_words(struct word_t *words, int num_words, char *text) {
    int i = 0;
    while (i < num_words) {
        if (strstr(text, words[i].word)!= NULL) {
            words[i].count++;
        }
        i++;
    }
}

void print_word_counts(struct word_t *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <text_file> <words_file>\n", argv[0]);
        exit(1);
    }

    char *text = NULL;
    size_t text_size = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error loading text file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    text_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    text = malloc(text_size + 1);
    if (text == NULL) {
        printf("Memory error.\n");
        exit(1);
    }

    fread(text, text_size, 1, fp);
    fclose(fp);

    struct word_t words[MAX_WORDS];
    int num_words = 0;

    load_words(words, MAX_WORDS);
    count_words(words, num_words, text);
    print_word_counts(words, num_words);

    free(text);
    return 0;
}