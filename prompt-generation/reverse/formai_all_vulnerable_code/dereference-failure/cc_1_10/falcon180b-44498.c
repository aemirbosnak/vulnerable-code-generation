//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word length exceeds maximum limit.\n");
                exit(1);
            }
            words[i].word[i] = tolower(ch);
            i++;
        } else if (i > 0) {
            words[i-1].word[i-1] = '\0';
            i = 0;
        }
    }
    if (i > 0) {
        words[i-1].word[i-1] = '\0';
        i = 0;
    }
}

void count_words(WordCount words[MAX_WORDS], int num_words, char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(file, words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <word1> <word2>...\n", argv[0]);
        exit(1);
    }
    int num_words = argc - 2;
    WordCount words[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        strcpy(words[i].word, argv[i+2]);
        words[i].count = 0;
    }
    count_words(words, num_words, argv[1]);
    return 0;
}