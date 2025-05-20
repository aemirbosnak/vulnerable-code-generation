//FormAI DATASET v1.0 Category: Database Indexing System ; Style: satisfied
// Unique C Database Indexing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structure for the Indexing System
typedef struct {
    char name[50];
    int id;
    float score;
} Student;

// Define data structure for Binary Search Tree
typedef struct node {
    Student data;
    struct node *left;
    struct node *right;
} Node;

// Global variable for root of the Binary Search Tree
Node *root = NULL;

// Function to create a new node for Binary Search Tree
Node* createNode(Student data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into Binary Search Tree
Node* insertNode(Node *node, Student data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (strcmp(data.name, node->data.name) < 0) {
        node->left = insertNode(node->left, data);
    } else if (strcmp(data.name, node->data.name) > 0) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

// Function to search for a node in Binary Search Tree
Node* searchNode(Node *node, char *name) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(name, node->data.name) < 0) {
        return searchNode(node->left, name);
    } else if (strcmp(name, node->data.name) > 0) {
        return searchNode(node->right, name);
    } else {
        return node;
    }
}

// Function to display data of a node
void displayNode(Node *node) {
    printf("Name: %s\n", node->data.name);
    printf("ID: %d\n", node->data.id);
    printf("Score: %.2f\n", node->data.score);
    printf("\n");
}

// Function to traverse Binary Search Tree in order
void traverseInOrder(Node *node) {
    if (node != NULL) {
        traverseInOrder(node->left);
        displayNode(node);
        traverseInOrder(node->right);
    }
}

int main() {
    // Create and insert nodes into Binary Search Tree
    Student s1 = {"John", 1001, 80.5};
    root = insertNode(root, s1);
    Student s2 = {"Mary", 1002, 85.5};
    root = insertNode(root, s2);
    Student s3 = {"Tom", 1003, 90.0};
    root = insertNode(root, s3);
    Student s4 = {"Alice", 1004, 95.5};
    root = insertNode(root, s4);

    // Display all nodes in Binary Search Tree
    traverseInOrder(root);

    // Search for a node by name
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    Node *searchResult = searchNode(root, searchName);
    if (searchResult != NULL) {
        printf("Search Result:\n");
        displayNode(searchResult);
    } else {
        printf("No record found for '%s'.\n", searchName);
    }

    return 0;
}