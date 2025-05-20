//Falcon-180B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            printf("%c", ch);
        }
    }
}

int is_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void count_words(char *filename) {
    FILE *fp;
    WordCount words[MAX_WORDS];
    int i, j, num_words = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    read_file(fp, filename);

    for (i = 0; i < strlen(filename); i++) {
        if (isalpha(filename[i])) {
            words[num_words].word[0] = tolower(filename[i]);
            words[num_words].count = 1;
            num_words++;
        }
    }

    for (i = 0; i < strlen(filename); i++) {
        if (isalpha(filename[i])) {
            for (j = 0; j < num_words; j++) {
                if (tolower(filename[i]) == words[j].word[0]) {
                    words[j].count++;
                }
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    count_words(argv[1]);

    return 0;
}