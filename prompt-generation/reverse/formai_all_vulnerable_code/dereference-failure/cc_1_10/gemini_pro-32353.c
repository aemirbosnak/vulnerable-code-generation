//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char *value;
    struct node *next;
} node_t;

typedef struct index {
    int key;
    node_t *value;
    struct index *next;
} index_t;

node_t *create_node(int key, char *value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

index_t *create_index(int key, node_t *value) {
    index_t *index = malloc(sizeof(index_t));
    index->key = key;
    index->value = value;
    index->next = NULL;
    return index;
}

void insert_node(node_t **head, node_t *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

void insert_index(index_t **head, index_t *index) {
    if (*head == NULL) {
        *head = index;
    } else {
        index->next = *head;
        *head = index;
    }
}

node_t *find_node(node_t *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

index_t *find_index(index_t *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void print_node(node_t *node) {
    printf("%d: %s\n", node->key, node->value);
}

void print_index(index_t *index) {
    printf("%d: %p\n", index->key, index->value);
}

void print_list(node_t *head) {
    while (head != NULL) {
        print_node(head);
        head = head->next;
    }
}

void print_index_list(index_t *head) {
    while (head != NULL) {
        print_index(head);
        head = head->next;
    }
}

int main() {
    node_t *head = NULL;
    index_t *index_head = NULL;

    insert_node(&head, create_node(1, "one"));
    insert_node(&head, create_node(2, "two"));
    insert_node(&head, create_node(3, "three"));
    insert_node(&head, create_node(4, "four"));
    insert_node(&head, create_node(5, "five"));

    insert_index(&index_head, create_index(1, find_node(head, 1)));
    insert_index(&index_head, create_index(2, find_node(head, 2)));
    insert_index(&index_head, create_index(3, find_node(head, 3)));
    insert_index(&index_head, create_index(4, find_node(head, 4)));
    insert_index(&index_head, create_index(5, find_node(head, 5)));

    print_list(head);
    printf("\n");
    print_index_list(index_head);

    return 0;
}