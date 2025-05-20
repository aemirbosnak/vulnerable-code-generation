//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void traverse(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    // Create a linked list
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    // Traverse the linked list
    traverse(head);

    // Find the maze route
    int route[] = {1, 2, 3, 4, 5};
    int i = 0;
    for (i = 0; route[i] != -1; i++) {
        printf("Go to node %d\n", route[i]);
    }

    return 0;
}