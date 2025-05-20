//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void printInOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%s (%d years)\n", node->name, node->age);
        printInOrder(node->right);
    }
}

int main() {
    srand(time(NULL));
    int numPeople = 10;
    Node* root = NULL;

    printf("Creating %d random people...\n", numPeople);
    for (int i = 0; i < numPeople; i++) {
        char name[50];
        int age = rand() % 100 + 1;
        sprintf(name, "Person %d", i + 1);
        Node* newPerson = createNode(name, age);
        root = insertNode(root, newPerson);
    }

    printf("\nPrinting people in order of age:\n");
    printInOrder(root);

    return 0;
}