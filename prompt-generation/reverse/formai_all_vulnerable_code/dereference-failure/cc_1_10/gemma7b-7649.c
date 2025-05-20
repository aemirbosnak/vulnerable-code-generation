//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i + 1;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        } else {
            (*head)->next = newNode;
            *head = newNode;
        }
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    // Randomly choose a starting point and end point
    int start = rand() % MAX;
    int end = rand() % MAX;

    // Traverse the maze
    Node* current = head;
    while (current) {
        // If the current node is the starting point, print it
        if (current->data == start) {
            printf("Starting point: %d\n", current->data);
        }

        // If the current node is the end point, print it
        if (current->data == end) {
            printf("End point: %d\n", current->data);
        }

        // Move to the next node
        current = current->next;
    }

    return 0;
}