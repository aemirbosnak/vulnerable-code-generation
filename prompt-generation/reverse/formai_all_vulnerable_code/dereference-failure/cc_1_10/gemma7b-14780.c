//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
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

void findRoute(Node* head) {
    int visited[MAX_SIZE] = {0};
    visited[head->data] = 1;

    // Traverse the maze
    while (head) {
        // If the node has not been visited and its data is not the end of the maze
        if (!visited[head->data] && head->data != MAX_SIZE) {
            // Mark the node as visited
            visited[head->data] = 1;

            // Recursively find the route
            findRoute(head->next);

            // Print the node's data
            printf("%d ", head->data);
        }
        head = head->next;
    }

    // Print the end of the route
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes into the maze
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

    // Find the route
    findRoute(head);

    return 0;
}