//Falcon-180B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalpha(ch)) {
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        } else if (isspace(ch)) {
            continue;
        } else {
            printf("Invalid character: %c\n", ch);
            exit(1);
        }
    }
}

void count_words(WordCount words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;

    read_file(fp, words);
    count_words(words, num_words);
    print_word_counts(words, num_words);

    fclose(fp);
    return 0;
}