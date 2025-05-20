//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

int grid[ROWS][COLS] = {0}; // initialize grid values

typedef struct node {
    int x;
    int y;
    int distance;
    struct node* parent;
} Node;

Node* start, * end;

/**
 * Function to check if the given (x, y) coordinate is valid or not.
 * Returns 1 if the coordinate is valid, and 0 otherwise.
 */
int isValid(int x, int y) {
    if (x < 0 || x >= ROWS) {
        return 0;
    }
    if (y < 0 || y >= COLS) {
        return 0;
    }
    if (grid[x][y] != 0) {
        return 0; // wall present
    }
    return 1;
}

/**
 * Function to add a new node to the queue and mark it as visited.
 */
Node* enqueue(int x, int y, int distance, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->distance = distance;
    node->parent = parent;
    grid[x][y] = 2; // mark as visited
    return node;
}

/**
 * Function to find the shortest path from the start to the end node using the A*
 * pathfinding algorithm.
 * Returns the distance of the shortest path, and updates the parent pointers of
 * the nodes along the path.
 */
int findShortestPath() {
    // initialize start and end nodes
    start = enqueue(0, 0, 0, NULL);
    end = enqueue(ROWS-1, COLS-1, 0, NULL);

    Node* queue[ROWS*COLS];
    int front = 0;
    int rear = 0;

    // add start node to the queue
    queue[rear++] = start;

    // neighbors of a node (directions: up, right, down, left, diagonal)
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
    int i;

    // loop until the end node is found or the queue is empty
    while (front < rear) {
        Node* curr = queue[front++];
        if (curr == end) {
            return curr->distance; // shortest path found
        }
        // search all the neighboring nodes
        for (i = 0; i < 8; i++) {
            int nx = curr->x + dx[i];
            int ny = curr->y + dy[i];
            if (isValid(nx, ny)) {
                // add neighboring node to the queue
                queue[rear++] = enqueue(nx, ny, curr->distance+1, curr);
            }
        }
    }
    return -1; // end node not reachable
}

/**
 * Function to print the shortest path found by the A* pathfinding algorithm.
 */
void printShortestPath() {
    Node* curr = end;
    while (curr != NULL) {
        printf("(%d,%d) ", curr->x, curr->y);
        curr = curr->parent;
    }
}

/**
 * Function to print the grid.
 */
void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == start->x && j == start->y) {
                printf("S ");
            } else if (i == end->x && j == end->y) {
                printf("E ");
            } else if (grid[i][j] == 1) {
                printf("* ");
            } else if (grid[i][j] == 2) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    // mark the walls (representing obstacles)
    grid[2][1] = grid[2][2] = grid[2][3] = grid[2][4] = 1;
    grid[3][4] = grid[4][4] = grid[5][4] = 1;

    int shortestDistance = findShortestPath();
    printf("Shortest distance: %d\n", shortestDistance);
    printf("Shortest path:");
    printShortestPath();

    printf("\n\nGrid:\n");
    printGrid();

    return 0;
}