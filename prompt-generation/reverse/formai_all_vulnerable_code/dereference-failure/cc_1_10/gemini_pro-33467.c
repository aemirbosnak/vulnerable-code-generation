//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *create_node(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node_t **head, char *word) {
    node_t *new_node = create_node(word);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int find_node(node_t *head, char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    node_t *head = NULL;
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *words = strtok(text, " ");
    while (words != NULL) {
        int count = find_node(head, words);
        if (count == 0) {
            insert_node(&head, words);
        } else {
            node_t *current = head;
            while (current != NULL) {
                if (strcmp(current->word, words) == 0) {
                    current->count++;
                    break;
                }
                current = current->next;
            }
        }
        words = strtok(NULL, " ");
    }

    print_list(head);
    free_list(head);

    return 0;
}