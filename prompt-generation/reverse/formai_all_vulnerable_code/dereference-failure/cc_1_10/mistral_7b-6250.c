//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_CHILDREN 10

typedef struct Node {
    char name[MAX_NAME_LEN];
    int childrenCount;
    struct Node *children[MAX_CHILDREN];
} Node;

void printSpaghettiTree(Node *root, int level) {
    int i;

    // Print horizontal lines based on level
    for (i = 0; i < level; i++) {
        printf("--");
    }

    // Print node name
    printf("%s\n", root->name);

    // Recursively print children
    for (i = 0; i < root->childrenCount; i++) {
        printSpaghettiTree(root->children[i], level + 1);
    }
}

int main() {
    Node *root, *child1, *child2, *child3;

    // Allocate memory for nodes
    root = (Node *)malloc(sizeof(Node));
    child1 = (Node *)malloc(sizeof(Node));
    child2 = (Node *)malloc(sizeof(Node));
    child3 = (Node *)malloc(sizeof(Node));

    // Initialize nodes
    strcpy(root->name, "Root");
    root->childrenCount = 3;

    strcpy(child1->name, "Child 1");
    root->children[0] = child1;
    child1->childrenCount = 0;

    strcpy(child2->name, "Child 2");
    root->children[1] = child2;
    child2->childrenCount = 2;

    strcpy(child3->name, "Child 3");
    root->children[2] = child3;
    child3->childrenCount = 1;

    // Allocate memory for child 2's children
    Node *grandchild1 = (Node *)malloc(sizeof(Node));
    Node *grandchild2 = (Node *)malloc(sizeof(Node));

    // Initialize grandchildren
    strcpy(grandchild1->name, "Grandchild 1");
    child2->children[0] = grandchild1;
    grandchild1->childrenCount = 0;

    strcpy(grandchild2->name, "Grandchild 2");
    child2->children[1] = grandchild2;
    grandchild2->childrenCount = 0;

    // Print spaghetti tree
    printSpaghettiTree(root, 0);

    // Free memory
    free(grandchild2);
    free(grandchild1);
    free(child3);
    free(child2);
    free(child1);
    free(root);

    return 0;
}