//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define INITIAL_DICTIONARY_SIZE 10

typedef struct Word {
    char *word;
    int length;
    struct Word *next;
} Word;

Word *dictionary = NULL;
int num_words = 0, num_unique_words = 0;

void add_to_dictionary(char *word) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    new_word->length = strlen(word);
    new_word->word = (char *)malloc((new_word->length + 1) * sizeof(char));
    strcpy(new_word->word, word);
    new_word->next = dictionary;
    dictionary = new_word;
    num_unique_words++;
}

void process_word(char *word) {
    int i;
    for (i = 0; i < num_unique_words; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            // Word already in dictionary, do nothing
            break;
        }
    }

    if (i == num_unique_words) {
        add_to_dictionary(word);
        num_words++;
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    int is_new_word;

    while (fgets(word, MAX_WORD_LENGTH, stdin) != NULL) {
        // Remove trailing newline character
        word[strcspn(word, "\n")] = '\0';

        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Process word
        is_new_word = 1;
        for (Word *current = dictionary; current != NULL; current = current->next) {
            if (strcasecmp(current->word, word) == 0) {
                is_new_word = 0;
                break;
            }
        }

        if (is_new_word) {
            process_word(word);
        }

        num_words++;
    }

    printf("Total words: %d\n", num_words);
    printf("Unique words: %d\n", num_unique_words);

    // Free memory
    for (Word *current = dictionary; current != NULL; current = current->next) {
        free(current->word);
        free(current);
    }

    return 0;
}