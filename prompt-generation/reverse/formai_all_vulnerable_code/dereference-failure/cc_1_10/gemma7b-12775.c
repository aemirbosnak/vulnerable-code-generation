//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void findMazeRoute(Node* head) {
    int visited[MAX_SIZE][MAX_SIZE] = {{0}};
    visited[head->x][head->y] = 1;

    // Breadth-first search
    Node* current = head;
    Node* next = NULL;
    while (current) {
        next = NULL;
        if (visited[current->x][current->y] == 0) {
            visited[current->x][current->y] = 1;

            // Check four directions
            if (current->x > 0) {
                next = createNode(current->x - 1, current->y);
                insertNode(next, current->x - 1, current->y);
            }
            if (current->x < MAX_SIZE - 1) {
                next = createNode(current->x + 1, current->y);
                insertNode(next, current->x + 1, current->y);
            }
            if (current->y > 0) {
                next = createNode(current->x, current->y - 1);
                insertNode(next, current->x, current->y - 1);
            }
            if (current->y < MAX_SIZE - 1) {
                next = createNode(current->x, current->y + 1);
                insertNode(next, current->x, current->y + 1);
            }
        }
        current = next;
    }

    // Print the route
    printf("Maze route:\n");
    current = head;
    while (current) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }
}

int main() {
    Node* head = createNode(0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);

    findMazeRoute(head);

    return 0;
}