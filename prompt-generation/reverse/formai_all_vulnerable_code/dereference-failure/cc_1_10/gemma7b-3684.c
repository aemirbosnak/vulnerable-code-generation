//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word) {
    Word *new_word = malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->next = NULL;

    if (word_list == NULL) {
        word_list = new_word;
    } else {
        Word *curr = word_list;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_word;
    }
}

int is_spam(char *text) {
    char *words = strtok(text, " ");
    char **word_array = malloc(MAX_WORDS * sizeof(char *));

    int word_count = 0;
    while (words) {
        word_array[word_count++] = strdup(words);
        words = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++) {
        if (word_list) {
            Word *curr = word_list;
            while (curr) {
                if (strcmp(word_array[i], curr->word) == 0) {
                    return 1;
                }
                curr = curr->next;
            }
        }
    }

    return 0;
}

int main() {
    add_word("miracle");
    add_word("free");
    add_word("lottery");
    add_word("prize");
    add_word("spam");

    char *text = "This is a spam message with lots of free prizes!";

    if (is_spam(text)) {
        printf("Text is spam.\n");
    } else {
        printf("Text is not spam.\n");
    }

    return 0;
}