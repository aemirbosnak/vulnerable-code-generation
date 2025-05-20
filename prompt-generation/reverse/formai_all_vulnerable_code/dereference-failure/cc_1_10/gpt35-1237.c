//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define record struct
typedef struct record {
    int id;
    char name[50];
    int age;
} Record;

// Define node struct
typedef struct node {
    Record data;
    struct node* left;
    struct node* right;
} Node;

// Define functions to insert and search for nodes in tree
void insertNode(Node** tree, Record data) {
    if (*tree == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        *tree = newNode;
    } else {
        if (data.id < (*tree)->data.id) {
            insertNode(&(*tree)->left, data);
        } else if (data.id > (*tree)->data.id) {
            insertNode(&(*tree)->right, data);
        }
    }
}

Node* searchNode(Node* tree, int id) {
    if (tree == NULL || tree->data.id == id) {
        return tree;
    }
    if (id < tree->data.id) {
        return searchNode(tree->left, id);
    } else {
        return searchNode(tree->right, id);
    }
}

// Define indexing function to print nodes in order
void printTree(Node* tree) {
    if (tree != NULL) {
        printTree(tree->left);
        printf("ID: %d, Name: %s, Age: %d\n", tree->data.id, tree->data.name, tree->data.age);
        printTree(tree->right);
    }
}

// Define main function to test program
int main() {
    Node* index = NULL;
    Record r1 = {1, "John", 25};
    Record r2 = {2, "Jane", 30};
    Record r3 = {3, "Bob", 45};
    
    insertNode(&index, r1);
    insertNode(&index, r2);
    insertNode(&index, r3);
    
    printf("Index:\n");
    printTree(index);
    
    Node* foundNode = searchNode(index, 2);
    if (foundNode != NULL) {
        printf("\nFound node:\n");
        printf("ID: %d, Name: %s, Age: %d\n", foundNode->data.id, foundNode->data.name, foundNode->data.age);
    } else {
        printf("\nNode not found.\n");
    }
    
    return 0;
}