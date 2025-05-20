//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024
#define MAX_DEPTH 10

typedef struct node {
    char *word;
    int frequency;
    struct node *next;
} node_t;

node_t *create_node(char *word, int frequency) {
    node_t *node = malloc(sizeof(node_t));
    node->word = word;
    node->frequency = frequency;
    node->next = NULL;
    return node;
}

void insert_node(node_t **head_ref, char *word, int frequency) {
    node_t *node = create_node(word, frequency);
    if (*head_ref == NULL) {
        *head_ref = node;
    } else {
        node->next = *head_ref;
        *head_ref = node;
    }
}

void search_node(node_t **head_ref, char *word) {
    node_t *current = *head_ref;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            printf("Found %s with frequency %d\n", current->word, current->frequency);
            return;
        }
        current = current->next;
    }
    printf("Not found\n");
}

void free_nodes(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    srand(time(NULL));

    node_t *head = NULL;

    for (int i = 0; i < 100; i++) {
        char *word = malloc(rand() % 10 + 1);
        int frequency = rand() % 10 + 1;
        insert_node(&head, word, frequency);
    }

    char search_word[10];
    int search_frequency;

    printf("Enter word to search: ");
    fgets(search_word, 10, stdin);
    search_frequency = atoi(search_word);

    search_node(&head, search_word);

    free_nodes(head);

    return 0;
}