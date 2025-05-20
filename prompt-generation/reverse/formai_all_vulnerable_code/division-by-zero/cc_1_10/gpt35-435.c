//FormAI DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int data;
    struct Node * next;
};

struct Index {
    int key;
    struct Node * start;
};

struct Index * indices[100]; // maximum of 100 indices
int num_indices = 0;

void insert(int key, int data) {
    // check if corresponding index exists
    int index = key % num_indices;
    struct Index * i = indices[index];
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->data = data;

    if (i == NULL) {
        // index does not exist, create new index and add node
        struct Index * new_index = (struct Index *) malloc(sizeof(struct Index));
        new_index->key = key;
        new_index->start = new_node;
        indices[index] = new_index;
        num_indices++;
    } else {
        // index exists, traverse linked list and insert node in order
        struct Node * curr = i->start;
        struct Node * prev = NULL;
        while (curr != NULL && curr->key < key) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            // insert at start of linked list
            new_node->next = curr;
            i->start = new_node;
        } else {
            // insert after prev in linked list
            new_node->next = prev->next;
            prev->next = new_node;
        }
    }
}

void printAll() {
    for (int i = 0; i < num_indices; i++) {
        struct Index * curr_index = indices[i];
        printf("Index %d: ", curr_index->key);
        struct Node * curr_node = curr_index->start;
        while (curr_node != NULL) {
            printf("(%d,%d) ", curr_node->key, curr_node->data);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

void search(int key) {
    // check if corresponding index exists
    int index = key % num_indices;
    struct Index * i = indices[index];

    if (i == NULL) {
        printf("No record found for key %d\n", key);
    } else {
        // traverse linked list and search for key
        struct Node * curr = i->start;
        while (curr != NULL) {
            if (curr->key == key) {
                printf("Record found: (%d,%d)\n", curr->key, curr->data);
                return;
            }
            curr = curr->next;
        }
        printf("No record found for key %d\n", key);
    }
}

int main() {
    // insert some data
    insert(34, 1);
    insert(20, 2);
    insert(12, 3);
    insert(89, 4);
    insert(45, 5);

    // search for some data
    search(12);
    search(89);
    search(50);

    // print all data
    printAll();

    return 0;
}