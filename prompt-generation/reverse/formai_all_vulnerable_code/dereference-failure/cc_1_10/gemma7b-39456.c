//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *word_list;

void count_words(char *text) {
    char *words = strtok(text, " ");
    Word *current_word = word_list;

    while (words) {
        int found = 0;
        for (Word *word = word_list; word; word++) {
            if (strcmp(words, word->word) == 0) {
                word->frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            word_list = realloc(word_list, (word_list->frequency + 1) * sizeof(Word));
            current_word = word_list->word = malloc(20 * sizeof(char));
            strcpy(current_word, words);
            current_word->frequency = 1;
        }
        words = strtok(NULL, " ");
    }
}

int main() {
    word_list = malloc(MAX_WORDS * sizeof(Word));
    word_list->frequency = 0;

    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    count_words(text);

    for (Word *word = word_list; word; word++) {
        printf("%s: %d\n", word->word, word->frequency);
    }

    return 0;
}