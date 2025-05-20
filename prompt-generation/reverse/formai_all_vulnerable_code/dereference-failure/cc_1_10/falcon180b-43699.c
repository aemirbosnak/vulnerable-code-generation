//Falcon-180B DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char data[100];
    int count;
    struct node* left;
    struct node* right;
};

struct node* createNode(char* data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, char* data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (strcmp(root->data, data) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(data, root->data) < 0) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void traverse(struct node* root, void (*visit)(char*)) {
    if (root == NULL) {
        return;
    }

    visit(root->data);

    traverse(root->left, visit);
    traverse(root->right, visit);
}

void printData(char* data) {
    printf("%s %d\n", data, strlen(data));
}

int main() {
    struct node* root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "cherry");

    traverse(root, printData);

    return 0;
}