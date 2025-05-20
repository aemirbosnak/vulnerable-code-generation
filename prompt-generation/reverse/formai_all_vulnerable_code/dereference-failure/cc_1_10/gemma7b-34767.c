//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* newNode = malloc(sizeof(Node));
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

    // Print the maze
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Find the route
    current = head;
    int target = 5;
    while (current) {
        if (current->data == target) {
            printf("The target data is found at node %d.\n", current->data);
            break;
        } else if (current->next) {
            current = current->next;
        } else {
            printf("The target data is not found.\n");
            break;
        }
    }

    return 0;
}