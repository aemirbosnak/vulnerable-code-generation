//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    struct node *next;
};

struct node *head = NULL;

void insert(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->next = head;
    head = new_node;
}

int search(char *word) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_list() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

int main() {
    // Insert some words into the dictionary.
    insert("hello");
    insert("world");
    insert("computer");
    insert("science");
    insert("programming");

    // Print the dictionary.
    printf("Dictionary:\n");
    print_list();

    // Check if a word is in the dictionary.
    printf("\nIs \"hello\" in the dictionary? %s\n", search("hello") ? "Yes" : "No");
    printf("Is \"goodbye\" in the dictionary? %s\n", search("goodbye") ? "Yes" : "No");

    return 0;
}