//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 10

typedef struct {
    double value;
    int freq;
    char name[MAX_NAME_LENGTH];
    struct StatisticalTree *left, *right;
} StatisticalTreeNode;

void displayStatisticalTree(StatisticalTreeNode *node, int level) {
    int i;

    if (node == NULL) {
        return;
    }

    for (i = 0; i < level; i++) {
        printf("    ");
    }

    printf("-(%s) : %lf, %d\n", node->name, node->value, node->freq);
    displayStatisticalTree(node->left, level + 1);
    displayStatisticalTree(node->right, level + 1);
}

StatisticalTreeNode *createNode(const char *name, double value) {
    StatisticalTreeNode *newNode = (StatisticalTreeNode *) malloc(sizeof(StatisticalTreeNode));

    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->value = value;
    newNode->freq = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

StatisticalTreeNode *insertNode(StatisticalTreeNode *root, const char *name, double value) {
    if (root == NULL) {
        root = createNode(name, value);
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, value);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name, value);
    } else {
        root->freq++;
    }

    return root;
}

int main() {
    StatisticalTreeNode *root = NULL;

    root = insertNode(root, "Apple", 1.2);
    root = insertNode(root, "Banana", 2.5);
    root = insertNode(root, "Apple", 1.5);
    root = insertNode(root, "Orange", 3.2);
    root = insertNode(root, "Apple", 2.0);

    displayStatisticalTree(root, 0);

    return 0;
}