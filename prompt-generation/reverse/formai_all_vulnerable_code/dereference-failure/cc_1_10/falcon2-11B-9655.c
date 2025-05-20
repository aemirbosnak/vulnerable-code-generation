//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

typedef struct node {
    int value;
    struct node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void hanoi(int n, Node* source, Node* auxiliary, Node* destination) {
    if (n > 0) {
        hanoi(n - 1, source, destination, auxiliary);
        printf("%d\n", source->value);
        source->next = destination;
        destination = source;
        hanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    Node* source = createNode(1);
    Node* auxiliary = createNode(2);
    Node* destination = createNode(3);

    hanoi(5, source, auxiliary, destination);

    printList(head);

    free(head);
    free(source);
    free(auxiliary);
    free(destination);

    return 0;
}