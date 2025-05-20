//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node *next;
} node_t;

typedef struct index {
    int key;
    node_t *head;
} index_t;

index_t *create_index(int key) {
    index_t *index = malloc(sizeof(index_t));
    index->key = key;
    index->head = NULL;
    return index;
}

void insert_index(index_t *index, int key) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->next = index->head;
    index->head = node;
}

int search_index(index_t *index, int key) {
    node_t *node = index->head;
    while (node != NULL) {
        if (node->key == key) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void print_index(index_t *index) {
    node_t *node = index->head;
    while (node != NULL) {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}

void free_index(index_t *index) {
    node_t *node = index->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node);
        node = next;
    }
    free(index);
}

int main() {
    index_t *index = create_index(1);
    insert_index(index, 2);
    insert_index(index, 3);
    insert_index(index, 4);
    insert_index(index, 5);
    print_index(index);
    printf("%d\n", search_index(index, 3));
    printf("%d\n", search_index(index, 6));
    free_index(index);
    return 0;
}