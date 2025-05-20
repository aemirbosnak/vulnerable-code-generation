//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* head = NULL;

void addNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = head;
    head = newNode;

    printf("Allocated memory for new node with value %d at address %p\n", value, newNode);
}

void freeNode() {
    if (head == NULL) {
        printf("No nodes to free\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("Freed memory at address %p\n", temp);
}

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        addNode(i);
    }

    for (i = 0; i < 5; i++) {
        freeNode();
    }

    for (i = 10; i < 15; i++) {
        addNode(i);
    }

    while (head != NULL) {
        freeNode();
    }

    return 0;
}