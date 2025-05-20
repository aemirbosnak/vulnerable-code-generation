//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
} node;

node *head = NULL;

void add_word(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->next = head;
    head = new_node;
}

int is_correct(char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    add_word("aardvark");
    add_word("abacus");
    add_word("abbey");
    add_word("abbreviate");
    add_word("abdomen");
    add_word("aberrant");
    add_word("abhor");
    add_word("abide");
    add_word("ability");
    add_word("abject");

    char *input = "I'm sorry, I don't understand";

    while (strcmp(input, "exit") != 0) {
        printf("Enter a word to check: ");
        scanf("%s", input);

        if (is_correct(input)) {
            printf("That's a real word!\n");
        } else {
            printf("I don't think that's a real word.\n");
        }
    }

    return 0;
}