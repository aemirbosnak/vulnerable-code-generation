//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>

typedef struct index_node {
    int key;
    int value;
    struct index_node *next;
} index_node;

typedef struct index {
    int size;
    index_node *head;
} index;

index *create_index() {
    index *new_index = malloc(sizeof(index));
    new_index->size = 0;
    new_index->head = NULL;
    return new_index;
}

void insert_index(index *index, int key, int value) {
    index_node *new_node = malloc(sizeof(index_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (index->size == 0) {
        index->head = new_node;
    } else {
        index_node *current_node = index->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    index->size++;
}

int search_index(index *index, int key) {
    index_node *current_node = index->head;
    while (current_node != NULL) {
        if (current_node->key == key) {
            return current_node->value;
        }
        current_node = current_node->next;
    }
    return -1;
}

void delete_index(index *index) {
    index_node *current_node = index->head;
    while (current_node != NULL) {
        index_node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(index);
}

int main() {
    index *my_index = create_index();
    insert_index(my_index, 1, 10);
    insert_index(my_index, 2, 20);
    insert_index(my_index, 3, 30);

    printf("Value for key 1: %d\n", search_index(my_index, 1));
    printf("Value for key 2: %d\n", search_index(my_index, 2));
    printf("Value for key 3: %d\n", search_index(my_index, 3));
    printf("Value for key 4: %d\n", search_index(my_index, 4));

    delete_index(my_index);
    return 0;
}