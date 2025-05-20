//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void traverseMaze(Node* current) {
    printf("Current position: (%d, %d)\n", current->x, current->y);

    // Check if the current position is the end of the maze
    if (current->x == MAX_SIZE - 1 && current->y == MAX_SIZE - 1) {
        printf("Congratulations! You have reached the end of the maze!\n");
        return;
    }

    // Randomly choose a direction
    int direction = rand() % 4;

    // Move in the chosen direction
    switch (direction) {
        case 0:
            current = current->next = createNode(current->x + 1, current->y);
            break;
        case 1:
            current = current->next = createNode(current->x, current->y + 1);
            break;
        case 2:
            current = current->next = createNode(current->x - 1, current->y);
            break;
        case 3:
            current = current->next = createNode(current->x, current->y - 1);
            break;
    }

    traverseMaze(current);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the start node
    Node* start = createNode(0, 0);

    // Traverse the maze
    traverseMaze(start);

    return 0;
}