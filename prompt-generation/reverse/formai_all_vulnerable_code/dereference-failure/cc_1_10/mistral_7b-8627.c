//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char *word;
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

int is_word_starts_with_c(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        return 0;
    }

    int len = strlen(word);
    if (len > 0 && isalpha(word[0]) && toupper(word[0]) == 'C') {
        words[num_words].word = malloc(len + 1);
        strncpy(words[num_words].word, word, len + 1);
        words[num_words].count = 1;
        num_words++;
        return 1;
    }

    return 0;
}

void increment_word_count(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
}

int main() {
    char line[1024];
    char *token;

    printf("Counting words starting with 'C' from input:\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        token = strtok(line, " ");
        while (token != NULL) {
            if (is_word_starts_with_c(token)) {
                increment_word_count(words[num_words - 1].word);
            }
            token = strtok(NULL, " ");
        }
    }

    printf("\nWord frequencies:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}