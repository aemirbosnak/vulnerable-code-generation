//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_word(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int is_word_in_dictionary(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void check_spelling(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is in dictionary
        if (!is_word_in_dictionary(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(fp);
}

int main() {
    // Insert words into dictionary
    insert_word("hello");
    insert_word("world");
    insert_word("computer");
    insert_word("science");
    insert_word("programming");

    // Check spelling of words in a file
    check_spelling("test.txt");

    return 0;
}