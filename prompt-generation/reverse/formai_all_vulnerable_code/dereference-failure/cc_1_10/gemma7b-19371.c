//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: careful
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
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    printList(head);

    // Find the route from node 10 to node 40
    Node* current = head;
    while (current) {
        if (current->data == 10) {
            current = current->next;
            while (current) {
                if (current->data == 40) {
                    printf("The route from node 10 to node 40 is: ");
                    printList(current);
                    return 0;
                }
                current = current->next;
            }
        }
        current = current->next;
    }

    printf("No route found.\n");
    return 0;
}