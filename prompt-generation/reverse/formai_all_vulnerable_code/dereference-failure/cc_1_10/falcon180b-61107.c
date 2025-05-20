//Falcon-180B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word_count words[MAX_WORDS]) {
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

void count_words(struct word_count words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].count = 0;
    }
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            words[i].count = 1;
        }
    }
    for (i = 1; i < MAX_WORDS; i++) {
        if (strcmp(words[i - 1].word, words[i].word) == 0) {
            words[i - 1].count++;
        }
    }
}

void print_word_counts(struct word_count words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    struct word_count words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    read_file(fp, words);
    count_words(words);
    print_word_counts(words);

    fclose(fp);
    return 0;
}