//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Forest {
    Node** nodes;
    int size;
} Forest;

Forest* createForest() {
    Forest* forest = (Forest*)malloc(sizeof(Forest));
    forest->nodes = (Node**)malloc(MAX_SIZE * sizeof(Node));
    forest->size = 0;
    return forest;
}

void insertNode(Forest* forest, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (forest->size == MAX_SIZE) {
        printf("Error: Forest is full!\n");
        return;
    }

    if (forest->size == 0) {
        forest->nodes[0] = newNode;
    } else {
        Node* current = forest->nodes[0];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    forest->size++;
}

void traverseForest(Forest* forest) {
    for (int i = 0; i < forest->size; i++) {
        Node* current = forest->nodes[i];
        printf("Node data: %d, ", current->data);
        printf("Next node: %p, ", current->next);
        printf("\n");
    }
}

int main() {
    Forest* forest = createForest();
    insertNode(forest, 10);
    insertNode(forest, 20);
    insertNode(forest, 30);
    insertNode(forest, 40);
    traverseForest(forest);

    return 0;
}