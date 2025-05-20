//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FruitNode {
    char name[20];
    float weight;
    struct FruitNode *left, *right;
} FruitNode;

FruitNode* createNode(char* name, float weight) {
    FruitNode* newNode = (FruitNode*) malloc(sizeof(FruitNode));
    strcpy(newNode->name, name);
    newNode->weight = weight;
    newNode->left = newNode->right = NULL;
    return newNode;
}

FruitNode* insertNode(FruitNode* root, char* name, float weight) {
    if (root == NULL) {
        root = createNode(name, weight);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, weight);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name, weight);
    }
    return root;
}

void printTree(FruitNode* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("%s", "   ");
    }
    printf("%s: %.2f kg\n", root->name, root->weight);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main() {
    FruitNode* fruitTree = NULL;
    char fruits[10][20] = {"Apple", "Banana", "Cherry", "Durian", "Elderberry", "Fig", "Grapefruit", "Honeydew", "Kiwi", "Lemon"};
    float weights[10] = {0.1, 0.3, 0.05, 1.5, 0.2, 0.07, 1.2, 1.1, 0.08, 0.15};

    for (int i = 0; i < 10; i++) {
        fruitTree = insertNode(fruitTree, fruits[i], weights[i]);
    }

    printTree(fruitTree, 0);

    return 0;
}