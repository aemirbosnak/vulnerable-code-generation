//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node *left, *right;
} Node;

Node* newNode(char name[], int age) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, char name[], int age) {
    if (root == NULL) {
        root = newNode(name, age);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, age);
    } else {
        root->right = insert(root->right, name, age);
    }
    return root;
}

void inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s, %d\n", root->name, root->age);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node *sherlock = NULL;
    char suspects[10][50] = {
        "John Watson",
        "James Moriarty",
        "Irene Adler",
        "Mary Morstan",
        "Mrs. Hudson",
        "Dr. Roylott",
        "Professor Moriarty",
        "Colonel Sebastian Moran",
        "Lestrade",
        "Mrs. Hudson"
    };
    int ages[10] = {
        27,
        45,
        31,
        25,
        48,
        53,
        47,
        42,
        38,
        50
    };

    for (int i = 0; i < 10; i++) {
        sherlock = insert(sherlock, suspects[i], ages[i]);
    }

    printf("Sherlock Holmes's analysis:\n");
    inOrderTraversal(sherlock);

    return 0;
}