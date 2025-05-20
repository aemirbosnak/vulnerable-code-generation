//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

// A surreal linked list data structure
struct surrealLinkedList {
    int value;
    struct surrealLinkedList* nextNode;
};

// A surreal queue data structure
struct surrealQueue {
    struct surrealLinkedList* headNode;
    struct surrealLinkedList* tailNode;
};

// A surreal stack data structure
struct surrealStack {
    struct surrealLinkedList* topNode;
};

// A surreal binary search tree data structure
struct surrealBinarySearchTree {
    int value;
    struct surrealBinarySearchTree* leftChild;
    struct surrealBinarySearchTree* rightChild;
};

// A surreal visualization of a linked list
void visualizeLinkedList(struct surrealLinkedList* head) {
    printf("This is a surreal linked list: \n\n");
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->nextNode;
    }
    printf("NULL\n\n");
}

// A surreal visualization of a queue
void visualizeQueue(struct surrealQueue* queue) {
    printf("This is a surreal queue: \n\n");
    visualizeLinkedList(queue->headNode);
}

// A surreal visualization of a stack
void visualizeStack(struct surrealStack* stack) {
    printf("This is a surreal stack: \n\n");
    visualizeLinkedList(stack->topNode);
}

// A surreal visualization of a binary search tree
void visualizeBinarySearchTree(struct surrealBinarySearchTree* root) {
    printf("This is a surreal binary search tree: \n\n");
    if (root == NULL) {
        printf("NULL\n\n");
    }
    else {
        printf("%d\n", root->value);
        printf("  /  \\ \n");
        if (root->leftChild == NULL) {
            printf("NULL ");
        }
        else {
            printf("%d ", root->leftChild->value);
        }
        if (root->rightChild == NULL) {
            printf("NULL\n\n");
        }
        else {
            printf("%d\n\n", root->rightChild->value);
        }
        visualizeBinarySearchTree(root->leftChild);
        visualizeBinarySearchTree(root->rightChild);
    }
}

// A chaotic surreal visualization of each data structure
void surrealVisualization() {
    printf("Welcome to surreal visualization: \n\n");
    struct surrealLinkedList* node1 = malloc(sizeof(struct surrealLinkedList));
    struct surrealLinkedList* node2 = malloc(sizeof(struct surrealLinkedList));
    struct surrealLinkedList* node3 = malloc(sizeof(struct surrealLinkedList));
    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node1->nextNode = node2;
    node2->nextNode = node3;
    node3->nextNode = NULL;
    visualizeLinkedList(node1);

    struct surrealQueue* queue = malloc(sizeof(struct surrealQueue));
    queue->headNode = node1;
    queue->tailNode = node3;
    visualizeQueue(queue);

    struct surrealStack* stack = malloc(sizeof(struct surrealStack));
    stack->topNode = node3;
    visualizeStack(stack);

    struct surrealBinarySearchTree* leaf1 = malloc(sizeof(struct surrealBinarySearchTree));
    struct surrealBinarySearchTree* leaf2 = malloc(sizeof(struct surrealBinarySearchTree));
    struct surrealBinarySearchTree* leaf3 = malloc(sizeof(struct surrealBinarySearchTree));
    struct surrealBinarySearchTree* leaf4 = malloc(sizeof(struct surrealBinarySearchTree));
    struct surrealBinarySearchTree* leaf5 = malloc(sizeof(struct surrealBinarySearchTree));
    leaf1->value = 9;
    leaf2->value = 5;
    leaf3->value = 3;
    leaf4->value = 7;
    leaf5->value = 15;
    leaf1->leftChild = leaf2;
    leaf2->leftChild = leaf3;
    leaf2->rightChild = leaf4;
    leaf1->rightChild = leaf5;
    leaf5->leftChild = NULL;
    leaf5->rightChild = NULL;
    visualizeBinarySearchTree(leaf1);
}

int main() {
    surrealVisualization();
    return 0;
}