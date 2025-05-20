//Falcon-180B DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH - 1) {
                printf("Error: Word %s is too long\n", filename);
                exit(1);
            }
            strcat(filename, &ch);
            i++;
        } else {
            filename[i] = '\0';
            i = 0;
        }
    }
}

void count_words(char *filename, WordCount *word_counts, int num_words) {
    FILE *fp;
    char ch;
    int i = 0;
    bool found = false;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH - 1) {
                printf("Error: Word is too long\n");
                exit(1);
            }
            strcat(word_counts[num_words].word, &ch);
            i++;
        } else {
            word_counts[num_words].word[i] = '\0';
            i = 0;
            found = true;
            num_words++;
        }
    }
    if (!found) {
        printf("Error: File is empty\n");
        exit(1);
    }
    fclose(fp);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    printf("Enter filename: ");
    read_file(stdin, filename);
    count_words(filename, word_counts, num_words);
    print_word_counts(word_counts, num_words);
    return 0;
}