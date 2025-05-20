//FormAI DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct bst {
    Node* root;
    unsigned int size;
} BST;

void initialize(BST* T) {
    T->root = NULL;
    T->size = 0;
}

Node* createNode(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(BST* T, int val) {
    Node* new_node = createNode(val);
    if(T->root == NULL) {
        T->root = new_node;
        T->size++;
        return;
    }
    Node* current = T->root;
    while(true) {
        if(val < current->data) {
            if(current->left == NULL) {
                current->left = new_node;
                T->size++;
                return;
            } else {
                current = current->left;
            }
        } else if(val > current->data) {
            if(current->right == NULL) {
                current->right = new_node;
                T->size++;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void traverseInOrder(Node* current, int depth) {
    if(current == NULL) {
        return;
    }
    traverseInOrder(current->left, depth + 1);
    for(int i = 0; i < depth; i++) {
        printf("      ");
    }
    printf("%d\n", current->data);
    traverseInOrder(current->right, depth + 1);
}

void visualize(BST* T) {
    printf("\nVisualizing Binary Search Tree with %d Nodes:\n\n", T->size);
    traverseInOrder(T->root, 0);
}

int main() {
    BST T;
    initialize(&T);
    insert(&T, 5);
    insert(&T, 3);
    insert(&T, 7);
    insert(&T, 1);
    insert(&T, 4);
    insert(&T, 6);
    insert(&T, 8);
    insert(&T, 2);
    visualize(&T);
    return 0;
}