//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void findMazeRoute(Node* head) {
    Node* current = head;
    int visited[MAX_SIZE] = {0};

    while (current) {
        if (visited[current->data] == 0) {
            visited[current->data] = 1;

            // Print the current node's data
            printf("%d ", current->data);

            // Recursively find the route for the next node
            findMazeRoute(current->next);
        }
    }
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