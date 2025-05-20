//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVE_SEARCH_MAX_LEN 50
#define BRAVE_SEARCH_DEFAULT_LEN 20

typedef struct brave_search_node {
    char *word;
    size_t len;
    struct brave_search_node *next;
} brave_search_node_t;

brave_search_node_t *brave_search_create_node(char *word, size_t len) {
    brave_search_node_t *node = malloc(sizeof(brave_search_node_t));
    node->word = word;
    node->len = len;
    node->next = NULL;
    return node;
}

void brave_search_insert(brave_search_node_t **head_ref, char *word, size_t len) {
    brave_search_node_t *node = brave_search_create_node(word, len);
    if (*head_ref == NULL) {
        *head_ref = node;
    } else {
        brave_search_node_t *current = *head_ref;
        while (current->next != NULL) {
            if (strcmp(current->word, word) > 0) {
                break;
            }
            current = current->next;
        }
        current->next = node;
    }
}

void brave_search_print(brave_search_node_t *head) {
    if (head == NULL) {
        printf("No words found.\n");
        return;
    }
    brave_search_node_t *current = head;
    while (current != NULL) {
        printf("%s (%zu)\n", current->word, current->len);
        current = current->next;
    }
}

int brave_search_len(brave_search_node_t *head) {
    int len = 0;
    brave_search_node_t *current = head;
    while (current != NULL) {
        len += current->len;
        current = current->next;
    }
    return len;
}

int main() {
    brave_search_node_t *head = NULL;

    brave_search_insert(&head, "the", 3);
    brave_search_insert(&head, "quick", 4);
    brave_search_insert(&head, "brown", 5);
    brave_search_insert(&head, "fox", 3);

    brave_search_print(head);

    printf("Total length: %d\n", brave_search_len(head));

    return 0;
}