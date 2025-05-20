//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void printMap(int** map, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%d ", map[r][c]);
        }
        printf("\n");
    }
}

void findPath(int** map, int size, int x, int y) {
    Node* head = NULL;
    Node* tail = NULL;

    map[x][y] = 2;

    // Check if the cell is already visited or is a wall
    if (map[x][y] == 2) {
        return;
    } else if (map[x][y] == 1) {
        return;
    }

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    // If the head is NULL, make the new node the head
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    // Recursively find the path
    findPath(map, size, x - 1, y);
    findPath(map, size, x + 1, y);
    findPath(map, size, x, y - 1);
    findPath(map, size, x, y + 1);

    // Print the map after finding the path
    printMap(map, size);
}

int main() {
    int** map = (int**)malloc(MAX_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_SIZE; i++) {
        map[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    map[0][0] = 1;
    map[0][1] = 1;
    map[1][0] = 1;
    map[1][1] = 0;

    findPath(map, MAX_SIZE, 0, 0);

    return 0;
}