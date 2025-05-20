//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 256

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

void count_words(char *str, int base, int *counter, word_t words[NUM_WORDS]);

int main(int argc, char *argv[]) {
    int i, counter = 0;
    word_t words[NUM_WORDS];
    char filename[100];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    count_words(filename, 0, &counter, words);

    printf("Total words found: %d\n", counter);
    for (i = 0; i < NUM_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}

void count_words(char *str, int base, int *counter, word_t words[NUM_WORDS]) {
    int i, len;
    char c = *str;

    if (*str == '\0') {
        str++;
        if (*str == ' ') {
            str++;
            count_words(str, counter, counter, words);
            return;
        }
        if (base) {
            words[*counter].count++;
            strcpy(words[*counter].word, "");
            *counter = (*counter) + 1;
        }
        return;
    }

    if (isalpha(c)) {
        words[*counter].word[0] = tolower(c);
        len = 1;
    } else if (words[*counter].word[0] != '\0') {
        words[*counter].word[len] = '\0';
        count_words(str, 1, counter, words);
        return;
    }

    if (base) {
        count_words(str + 1, 1, counter, words);
    } else {
        for (i = *counter - 1; i >= 0; i--) {
            if (strcmp(words[i].word, words[*counter].word) == 0) {
                words[i].count++;
                return;
            }
        }
        words[*counter].count = 1;
        strcpy(words[*counter].word, "");
        *counter = (*counter) + 1;
    }

    if (isalnum(c)) {
        words[*counter].word[len++] = c;
        words[*counter].word[len] = '\0';
        count_words(str + 1, 0, counter, words);
    } else {
        if (base) {
            str++;
        }
        if (*str == ' ') {
            str++;
            count_words(str, 0, counter, words);
        }
    }
}