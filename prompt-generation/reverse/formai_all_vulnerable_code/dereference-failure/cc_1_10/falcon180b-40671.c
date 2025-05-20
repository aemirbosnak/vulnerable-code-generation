//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount *word_counts, int num_words) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words!\n");
                exit(1);
            }
            word_counts[num_words].word[0] = '\0';
            num_words++;
        } else {
            strcat(word_counts[num_words-1].word, &ch);
        }
    }
}

void count_words(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    read_file(fp, word_counts, num_words);
    fclose(fp);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    count_words(word_counts, num_words);
    print_word_counts(word_counts, num_words);

    return 0;
}