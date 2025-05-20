//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Struct for each node in the grid
struct Node {
    int x, y;
    int dist;
    bool visited;
    struct Node* parent;
};

// Function to check if a given node is valid
bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Function to check if the given node is blocked or not
bool isBlocked(int grid[][COLS], int x, int y) {
    return (grid[x][y] == 1);
}

// Function to check if we have reached the destination
bool isDestination(int x, int y, int destX, int destY) {
    return (x == destX && y == destY);
}

// Function to calculate the distance between two nodes
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Function to print the path from start to end node
void printPath(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d) ", node->x, node->y);
}

// Main function to find the shortest path
void findShortestPath(int grid[][COLS], int srcX, int srcY, int destX, int destY) {
    // Create a queue to store nodes to be visited
    struct Node* queue[ROWS * COLS];
    int front = -1, rear = -1;

    // Create the source node and add it to the queue
    struct Node* srcNode = (struct Node*)malloc(sizeof(struct Node));
    srcNode->x = srcX;
    srcNode->y = srcY;
    srcNode->dist = 0;
    srcNode->visited = true;
    srcNode->parent = NULL;
    queue[++rear] = srcNode;

    // Loop until the queue is empty
    while (front != rear) {
        // Dequeue a node from the front of the queue
        struct Node* currNode = queue[++front];

        // Check if we have reached the destination
        if (isDestination(currNode->x, currNode->y, destX, destY)) {
            printf("Shortest path found: ");
            printPath(currNode);
            printf("\n");
            return;
        }

        // Explore the adjacent nodes
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                // Skip the current node and the diagonal nodes
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i != 0 && j != 0) {
                    continue;
                }

                // Calculate the coordinates of the adjacent node
                int adjX = currNode->x + i;
                int adjY = currNode->y + j;

                // Check if the adjacent node is valid and not blocked
                if (isValid(adjX, adjY) && !isBlocked(grid, adjX, adjY)) {
                    // Calculate the distance of the adjacent node from the source node
                    int adjDist = currNode->dist + calculateDistance(currNode->x, currNode->y, adjX, adjY);

                    // Create the adjacent node, set its properties and add it to the queue
                    struct Node* adjNode = (struct Node*)malloc(sizeof(struct Node));
                    adjNode->x = adjX;
                    adjNode->y = adjY;
                    adjNode->dist = adjDist;
                    adjNode->visited = true;
                    adjNode->parent = currNode;
                    queue[++rear] = adjNode;
                }
            }
        }
    }

    // If the queue is empty and we haven't found the destination, then there is no path
    printf("No path found.\n");
}

// Driver program
int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    int srcX = 0, srcY = 0;
    int destX = 9, destY = 9;

    findShortestPath(grid, srcX, srcY, destX, destY);

    return 0;
}