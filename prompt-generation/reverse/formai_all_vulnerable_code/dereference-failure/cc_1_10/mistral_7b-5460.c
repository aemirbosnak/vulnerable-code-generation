//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node *left, *right;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
    } else {
        if (strcmp(newNode->name, root->name) < 0) {
            root->left = insertNode(root->left, newNode);
        } else {
            root->right = insertNode(root->right, newNode);
        }
    }
    return root;
}

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s (%d)\n", root->name, root->age);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main() {
    srand(time(NULL));

    printf("Let's create a cheerful binary search tree!\n");

    Node* root = NULL;

    for (int i = 0; i < 10; i++) {
        int age = rand() % 100 + 1;
        char name[50];
        sprintf(name, "Person %d", i + 1);
        Node* newNode = createNode(name, age);
        root = insertNode(root, newNode);
    }

    printf("Our binary search tree is ready! Let's print it out and see the cheerfulness:\n");

    printTree(root, 0);

    return 0;
}