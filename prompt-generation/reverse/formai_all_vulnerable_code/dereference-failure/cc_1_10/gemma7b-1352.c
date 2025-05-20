//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void findRoute(Node* head, int target) {
    Node* current = head;
    while (current) {
        if (current->data == target) {
            printf("Route found: ");
            while (current) {
                printf("%d ", current->data);
                current = current->next;
            }
            printf("\n");
            return;
        } else if (current->data < target) {
            current = current->next;
        }
    }

    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);

    findRoute(head, 8);

    return 0;
}