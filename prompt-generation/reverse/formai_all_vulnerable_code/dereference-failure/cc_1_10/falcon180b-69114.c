//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words == MAX_WORDS) {
        printf("Error: maximum number of words reached\n");
        exit(1);
    }
    words[num_words].word = malloc(strlen(word) + 1);
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_word_counts() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            word[word_length++] = tolower(ch);
        } else if (in_word) {
            in_word = 0;
            word[word_length] = '\0';
            add_word(word);
            word_length = 0;
        }
    }
    if (in_word) {
        in_word = 0;
        word[word_length] = '\0';
        add_word(word);
    }

    fclose(fp);
    print_word_counts();

    return 0;
}