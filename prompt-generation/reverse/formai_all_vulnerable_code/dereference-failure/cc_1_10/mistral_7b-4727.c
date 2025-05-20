//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
    } else if (strcmp(newNode->name, root->name) < 0) {
        root->left = insertNode(root->left, newNode);
    } else {
        root->right = insertNode(root->right, newNode);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("\nName: %s, Age: %d", root->name, root->age);
        inOrderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    int numPeople = 10;
    char names[numPeople][50];

    printf("Creating %d random people for the binary search tree...\n", numPeople);

    for (int i = 0; i < numPeople; i++) {
        int randomAge = 1 + rand() % 100;
        char tempName[50];
        sprintf(tempName, "Person %d", i + 1);
        strcpy(names[i], tempName);
        Node* newPerson = createNode(names[i], randomAge);
        root = insertNode(root, newPerson);
    }

    printf("\nBinary Search Tree:\n");
    inOrderTraversal(root);

    return 0;
}