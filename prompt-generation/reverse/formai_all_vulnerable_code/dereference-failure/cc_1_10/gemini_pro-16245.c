//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *next;
} node;

typedef struct index {
    int key;
    node *head;
} index;

index *create_index(int key) {
    index *idx = malloc(sizeof(index));
    idx->key = key;
    idx->head = NULL;
    return idx;
}

void insert_index(index *idx, int key) {
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->next = idx->head;
    idx->head = new_node;
}

node *find_index(index *idx, int key) {
    node *curr = idx->head;
    while (curr != NULL) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void delete_index(index *idx, int key) {
    node *prev = NULL;
    node *curr = idx->head;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                idx->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    index *idx = create_index(10);
    insert_index(idx, 20);
    insert_index(idx, 30);
    insert_index(idx, 40);

    node *node = find_index(idx, 30);
    if (node != NULL) {
        printf("Found node with key %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    delete_index(idx, 30);

    node = find_index(idx, 30);
    if (node != NULL) {
        printf("Found node with key %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    return 0;
}