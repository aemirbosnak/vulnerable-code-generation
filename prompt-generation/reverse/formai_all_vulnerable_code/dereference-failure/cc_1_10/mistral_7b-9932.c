//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN + 1];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

void randomizeName(char* name) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        name[i] = rand() % 26 + 'a';
    }
    name[len] = '\0';
}

Node* createNode(char* name, int age) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** root, char* name, int age) {
    if (*root == NULL) {
        *root = createNode(name, age);
    } else if (strcmp((*root)->name, name) > 0) {
        insertNode(&((*root)->left), name, age);
    } else {
        insertNode(&((*root)->right), name, age);
    }
}

void printNode(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%s (%d years)\n", node->name, node->age);
    printNode(node->left);
    printNode(node->right);
}

void destroyTree(Node** root) {
    if (*root == NULL) {
        return;
    }
    destroyTree(&((*root)->left));
    destroyTree(&((*root)->right));
    free(*root);
    *root = NULL;
}

int main() {
    srand(time(NULL));
    Node* root = NULL;

    for (int i = 0; i < 10; i++) {
        char name[MAX_NAME_LEN];
        randomizeName(name);
        int age = rand() % 100 + 1;
        insertNode(&root, name, age);
    }

    printf("Tree:\n");
    printNode(root);

    printf("\nDestroying tree...\n");
    destroyTree(&root);

    return 0;
}