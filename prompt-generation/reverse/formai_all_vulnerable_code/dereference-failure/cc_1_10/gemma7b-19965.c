//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Tree {
    Node* root;
    int size;
} Tree;

Tree* createTree(int size) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->size = size;
    return tree;
}

void insertNode(Tree* tree, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        Node* current = tree->root;
        Node* previous = NULL;
        while (current) {
            if (data < current->data) {
                previous = current;
                current = current->next;
            } else if (data > current->data) {
                previous = current;
                current = current->next;
            } else {
                printf("Error: Data already exists.\n");
                return;
            }
        }

        previous->next = newNode;
    }

    tree->size++;
}

void traverseTree(Tree* tree) {
    Node* current = tree->root;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Tree* tree = createTree(MAX_SIZE);
    insertNode(tree, 'a');
    insertNode(tree, 'b');
    insertNode(tree, 'c');
    insertNode(tree, 'd');
    insertNode(tree, 'e');

    traverseTree(tree);

    return 0;
}