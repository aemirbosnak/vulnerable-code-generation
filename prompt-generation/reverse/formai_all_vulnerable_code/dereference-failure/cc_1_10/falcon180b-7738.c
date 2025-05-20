//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORDS];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORDS - 1) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }
            strcpy(filename + i*MAX_WORDS, &ch);
            i++;
        }
    }
    filename[i*MAX_WORDS] = '\0';
}

void count_words(char *filename, WordCount *word_count) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(fp, filename);
    fclose(fp);

    for (i = 0; i < strlen(filename); i++) {
        if (isalpha(filename[i])) {
            word_count[i].count++;
        }
    }
}

void print_word_counts(WordCount *word_count, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_count[i].word, word_count[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORDS];
    read_file(stdin, filename);

    WordCount word_count[MAX_WORDS];
    count_words(filename, word_count);

    print_word_counts(word_count, MAX_WORDS);

    return 0;
}