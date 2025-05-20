//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void findRoute(Node* head) {
    char** maze = malloc(MAX_SIZE * sizeof(char*));
    for (int i = 0; i < MAX_SIZE; i++) {
        maze[i] = malloc(MAX_SIZE * sizeof(char));
    }

    // Create the maze
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    // Mark the path
    Node* current = head;
    while (current) {
        maze[current->data][current->data] = 'o';
        current = current->next;
    }

    // Print the maze
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    findRoute(head);

    return 0;
}