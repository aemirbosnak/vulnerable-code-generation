//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct word_node {
    char word[MAX_WORD_LENGTH + 1];
    struct word_node *next;
} word_node_t;

typedef struct dictionary {
    word_node_t *head;
} dictionary_t;

dictionary_t *create_dictionary() {
    dictionary_t *dict = malloc(sizeof(dictionary_t));
    dict->head = NULL;
    return dict;
}

void add_word_to_dictionary(dictionary_t *dict, char *word) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
    strcpy(new_node->word, word);
    new_node->next = dict->head;
    dict->head = new_node;
}

char *translate_word(dictionary_t *dict, char *word) {
    word_node_t *current_node = dict->head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node->word;
        }
        current_node = current_node->next;
    }

    return NULL;
}

int main() {
    dictionary_t *dict = create_dictionary();

    // Add some words to the dictionary
    add_word_to_dictionary(dict, "Earth");
    add_word_to_dictionary(dict, "Moon");
    add_word_to_dictionary(dict, "Sun");
    add_word_to_dictionary(dict, "Mars");
    add_word_to_dictionary(dict, "Jupiter");

    // Get a word from the user
    char word[MAX_WORD_LENGTH + 1];
    printf("Please enter a word to translate: ");
    scanf("%s", word);

    // Translate the word
    char *translated_word = translate_word(dict, word);

    // Print the translated word
    if (translated_word != NULL) {
        printf("The translated word is: %s\n", translated_word);
    } else {
        printf("The word could not be found in the dictionary.\n");
    }

    return 0;
}