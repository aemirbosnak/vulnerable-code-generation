//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char *key;
    int value;
    struct node *next;
} node_t;

typedef struct index {
    char *key;
    node_t *node;
    struct index *next;
} index_t;

node_t *create_node(char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

index_t *create_index(char *key, node_t *node) {
    index_t *index = malloc(sizeof(index_t));
    index->key = strdup(key);
    index->node = node;
    index->next = NULL;
    return index;
}

void insert(node_t **head, char *key, int value) {
    node_t *new_node = create_node(key, value);
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

void insert_index(index_t **head, char *key, node_t *node) {
    index_t *new_index = create_index(key, node);
    if (*head == NULL) {
        *head = new_index;
    } else {
        index_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_index;
    }
}

node_t *find(node_t *head, char *key) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

node_t *find_by_index(index_t *head, char *key) {
    index_t *current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->node;
        }
        current = current->next;
    }
    return NULL;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->key, current->value);
        current = current->next;
    }
}

void print_index(index_t *head) {
    index_t *current = head;
    while (current != NULL) {
        printf("%s: %p\n", current->key, current->node);
        current = current->next;
    }
}

int main() {
    // Create a linked list of nodes
    node_t *head = NULL;
    insert(&head, "foo", 1);
    insert(&head, "bar", 2);
    insert(&head, "baz", 3);

    // Create an index for the linked list
    index_t *index = NULL;
    insert_index(&index, "foo", find(head, "foo"));
    insert_index(&index, "bar", find(head, "bar"));
    insert_index(&index, "baz", find(head, "baz"));

    // Print the linked list
    printf("Linked list:\n");
    print_list(head);

    // Print the index
    printf("\nIndex:\n");
    print_index(index);

    // Find a node by key using the linked list
    node_t *node1 = find(head, "foo");
    printf("\nNode found by key using the linked list: %s\n", node1->key);

    // Find a node by key using the index
    node_t *node2 = find_by_index(index, "foo");
    printf("\nNode found by key using the index: %s\n", node2->key);

    return 0;
}