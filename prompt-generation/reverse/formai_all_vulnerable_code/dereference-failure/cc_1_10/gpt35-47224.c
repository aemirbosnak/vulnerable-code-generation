//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Data structure to store a cell of the grid
struct Cell {
    int x, y, distance;
};

// queue node used in BFS
struct Node {
    struct Cell cell;
    struct Node* next;
};

// Create a new node for a BFS queue
struct Node* newNode(struct Cell cell, struct Node* next) {
    struct Node* node = malloc(sizeof(struct Node));
    node->cell = cell;
    node->next = next;

    return node;
}

// Function to add an element to the BFS queue
void enqueue(struct Node **head, struct Node **tail, struct Cell cell) {
    struct Node* node = newNode(cell, NULL);

    if (*tail) {
        (*tail)->next = node;
    }

    *tail = node;

    if (!*head) {
        *head = *tail;
    }
}

// Function to check whether given cell (row, col) is a valid cell or not
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Array of four directions to move in the grid
int rowMoves[] = {-1, 0, 1, 0};
int colMoves[] = {0, 1, 0, -1};

// Function to find the shortest path between given source cell and destination cell in the grid
void BFS(int grid[][COL], struct Cell source, struct Cell dest) {
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    visited[source.x][source.y] = true;

    struct Node *head = NULL, *tail = NULL;
    enqueue(&head, &tail, source);

    while (head) {
        struct Cell curr = head->cell;

        if (curr.x == dest.x && curr.y == dest.y) {
            printf("The shortest path has length %d\n", curr.distance);
            return;
        }

        head = head->next;

        for (int i = 0; i < 4; i++) {
            int row = curr.x + rowMoves[i];
            int col = curr.y + colMoves[i];

            if (isValid(row, col) && grid[row][col] && !visited[row][col]) {
                visited[row][col] = true;
                enqueue(&head, &tail, (struct Cell){row, col, curr.distance + 1});
            }
        }
    }

    printf("Destination cell cannot be reached\n");
}

int main() {
    int grid[][COL] = {
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
    };

    BFS(grid, (struct Cell){0, 0, 0}, (struct Cell){ROW-1, COL-1, 0});

    return 0;
}