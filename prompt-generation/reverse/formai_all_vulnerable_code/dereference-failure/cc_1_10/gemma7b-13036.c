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

    head = newNode;
}

void findMazeRoute(Node* head) {
    int visited[MAX_SIZE] = {0};
    visited[head->data] = 1;

    while (head) {
        if (visited[head->next->data] == 0) {
            findMazeRoute(head->next);
        }

        printf("%d ", head->data);
        visited[head->data] = 1;

        head = head->next;
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

    findMazeRoute(head);

    return 0;
}