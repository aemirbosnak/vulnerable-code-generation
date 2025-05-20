//FormAI DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// node structure for index
struct index_node {
    int key;
    int value;
    struct index_node* next;
};

// function to insert a new index node
struct index_node* insert(struct index_node* root, int key, int value) {
    struct index_node* new_node = (struct index_node*)malloc(sizeof(struct index_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (root == NULL) {
        // first node to be inserted
        root = new_node;
    }
    else {
        // inserting at the end of linked list
        struct index_node* temp = root;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return root;
}

// function to search for a key in index
struct index_node* search(struct index_node* root, int key) {
    struct index_node* temp = root;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main() {
    struct index_node* index_root = NULL;

    // inserting nodes in index
    index_root = insert(index_root, 10, 100);
    index_root = insert(index_root, 20, 200);
    index_root = insert(index_root, 30, 300);

    // searching for a key
    struct index_node* node = search(index_root, 20);
    if (node != NULL) {
        printf("Key: %d, Value: %d\n", node->key, node->value);
    }
    else {
        printf("Key not found in index!\n");
    }

    return 0;
}