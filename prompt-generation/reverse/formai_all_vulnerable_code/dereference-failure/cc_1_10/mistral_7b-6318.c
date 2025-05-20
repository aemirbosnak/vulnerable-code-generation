//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct Node {
    int key;
    char name[32];
    struct Node* left;
    struct Node* right;
} Node;

Node* NewNode(int key, char* name) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Insert(Node* root, int key, char* name) {
    if (root == NULL) {
        return NewNode(key, name);
    }

    if (key < root->key) {
        root->left = Insert(root->left, key, name);
    } else if (key > root->key) {
        root->right = Insert(root->right, key, name);
    } else {
        fprintf(stderr, "Error: Key %d already exists.\n", key);
        return root;
    }

    return root;
}

void InOrderTraversal(Node* root, int fileDescriptor) {
    if (root == NULL) {
        return;
    }

    InOrderTraversal(root->left, fileDescriptor);
    fprintf(fdopen(fileDescriptor, "w"), "%s %d %s\n", root->name, root->key, root->name);
    InOrderTraversal(root->right, fileDescriptor);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <tree_size> <output_file>\n", argv[0]);
        return 1;
    }

    int treeSize = atoi(argv[1]);
    int fileDescriptor = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    Node* root = NULL;

    for (int i = 0; i < treeSize; i++) {
        int key = rand() % 100 + 1;
        char name[32];
        snprintf(name, sizeof(name), "Name%d", i);
        root = Insert(root, key, name);
    }

    InOrderTraversal(root, fileDescriptor);
    close(fileDescriptor);

    printf("Binary Search Tree built and saved to file '%s'.\n", argv[2]);

    return 0;
}