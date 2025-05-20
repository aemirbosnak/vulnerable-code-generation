//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0';
            i++;
        } else {
            strncat(words[i].word, &ch, 1);
        }
    }
    words[i].word[strlen(words[i].word) - 1] = '\0';
    i++;
}

void count_words(WordCount words[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        exit(2);
    }

    WordCount words[MAX_WORDS];
    int n = 0;

    read_file(fp, argv[1], words);

    for (int i = 0; i < n; i++) {
        words[i].count = 1;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[j].count = 1;
            }
        }
    }

    count_words(words, n);

    fclose(fp);
    return 0;
}