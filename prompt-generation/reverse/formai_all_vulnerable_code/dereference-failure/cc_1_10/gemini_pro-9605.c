//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void add_word(node **head, char *word) {
    node *current = *head;
    if (current == NULL) {
        *head = create_node(word);
        return;
    }
    while (current->next != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    if (strcmp(current->word, word) == 0) {
        current->count++;
    } else {
        current->next = create_node(word);
    }
}

void print_words(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    node *head = NULL;
    char word[100];
    while (scanf("%s", word) != EOF) {
        add_word(&head, word);
    }
    print_words(head);
    return 0;
}