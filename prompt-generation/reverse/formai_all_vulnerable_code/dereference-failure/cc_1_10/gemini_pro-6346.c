//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insert_word(char *word) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

bool check_spelling(char *word) {
    node *current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return true;
        }
        current_node = current_node->next;
    }

    return false;
}

int main() {
    // Load the dictionary into the hash table.
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary, "%s", word) != EOF) {
        insert_word(word);
    }

    fclose(dictionary);

    // Check the spelling of a user-entered word.
    printf("Enter a word to check its spelling: ");
    scanf("%s", word);

    if (check_spelling(word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    return EXIT_SUCCESS;
}