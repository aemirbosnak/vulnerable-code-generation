//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findRoute(Node* head) {
    int visited[MAX] = {0};
    visited[head->data] = 1;

    Node* current = head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        if (visited[next->data] == 0) {
            visited[next->data] = 1;
            current = next;
        } else {
            current = next;
        }
    }

    printf("The route is: ");

    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    findRoute(head);

    return 0;
}