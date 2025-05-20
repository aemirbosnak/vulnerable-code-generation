//FormAI DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for an indexed record
struct IndexedRecord {
    int index;
    char name[50];
    char address[100];
};

// Define a struct for a node in the binary search tree
struct Node {
    struct IndexedRecord record;
    struct Node *left;
    struct Node *right;
};

// Function to insert a record into the binary search tree
void insert(struct Node **root_ptr, struct IndexedRecord new_record) {
    // If the root is null, create a new node and make it the root
    if (*root_ptr == NULL) {
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->record = new_record;
        new_node->left = NULL;
        new_node->right = NULL;
        *root_ptr = new_node;
        return;
    }
    // If the new record's index is less than the current node's index, insert it in the left subtree
    if (new_record.index < (*root_ptr)->record.index) {
        insert(&((*root_ptr)->left), new_record);
    }
    // If the new record's index is greater than or equal to the current node's index, insert it in the right subtree
    else {
        insert(&((*root_ptr)->right), new_record);
    }
}

// Function to print the records in the binary search tree in order of index
void print_in_order(struct Node *root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("Index: %d, Name: %s, Address: %s\n", root->record.index, root->record.name, root->record.address);
        print_in_order(root->right);
    }
}

int main() {
    // Create an array of sample records
    struct IndexedRecord records[] = {
        {3, "John Smith", "123 Main St."},
        {1, "Jane Doe", "456 Walnut St."},
        {5, "Robert Johnson", "789 Elm St."},
        {4, "Emily Davis", "567 Oak St."},
        {2, "Michael Lee", "234 Maple St."}
    };
    int num_records = sizeof(records) / sizeof(records[0]);

    // Create an empty root node for the binary search tree
    struct Node *root = NULL;

    // Insert each record in the array into the binary search tree
    for (int i = 0; i < num_records; i++) {
        insert(&root, records[i]);
    }

    // Print the records in the binary search tree in order of index
    print_in_order(root);

    return 0;
}