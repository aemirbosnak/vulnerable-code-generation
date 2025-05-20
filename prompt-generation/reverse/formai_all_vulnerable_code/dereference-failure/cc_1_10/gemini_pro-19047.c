//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node_t;

node_t *dictionary;

void insert_word(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = dictionary;
    dictionary = new_node;
}

bool load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return false;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(word);
    }

    fclose(fp);
    return true;
}

bool is_word_in_dictionary(char *word) {
    node_t *current = dictionary;
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void spell_check(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert the word to lowercase.
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is in the dictionary.
        if (!is_word_in_dictionary(word)) {
            printf("%s is not in the dictionary.\n", word);
        }
    }

    fclose(fp);
}

int main() {
    // Load the dictionary.
    if (!load_dictionary("dictionary.txt")) {
        return 1;
    }

    // Spell-check the text file.
    spell_check("text.txt");

    return 0;
}