//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
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

    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    printList(head);

    // Find the route from the first node to the fifth node
    Node* current = head;
    while (current->next) {
        if (current->data == 1) {
            current = current->next;
            while (current->data != 5) {
                current = current->next;
            }
            printf("The route from the first node to the fifth node is: ");
            printList(current);
        }
    }

    return 0;
}