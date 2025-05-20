//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define INF INT_MAX

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int gCost;
    int hCost;
    int fCost;
} Node;

Node* createNode(int x, int y, int gCost, int hCost) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->position.x = x;
    node->position.y = y;
    node->gCost = gCost;
    node->hCost = hCost;
    node->fCost = gCost + hCost;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int isValid(int grid[HEIGHT][WIDTH], int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] == 0);
}

void printGrid(int grid[HEIGHT][WIDTH], Point start, Point goal, Node* path[], int pathLength) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == start.x && y == start.y)
                printf(" S ");
            else if (x == goal.x && y == goal.y)
                printf(" G ");
            else {
                int isPath = 0;
                for(int i = 0; i < pathLength; i++) {
                    if (path[i] && path[i]->position.x == x && path[i]->position.y == y) {
                        isPath = 1;
                        break;
                    }
                }
                printf(isPath ? " * " : " . ");
            }
        }
        printf("\n");
    }
}

void aStar(int grid[HEIGHT][WIDTH], Point start, Point goal) {
    Node* openList[WIDTH * HEIGHT] = { NULL };
    Node* closedList[WIDTH * HEIGHT] = { NULL };
    int openCount = 0, closedCount = 0;

    openList[openCount++] = createNode(start.x, start.y, 0, heuristic(start, goal));

    while (openCount > 0) {
        // Find the node with the lowest fCost
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];
        
        // Check if we've reached the goal
        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            printf("Path found:\n");
            Node* path[WIDTH * HEIGHT] = { NULL };
            int pathLength = 0;

            while (currentNode) {
                path[pathLength++] = currentNode;
                // For a real implementation, backtracking to the parent would be necessary
                currentNode = NULL; // Stop condition for this example
            }

            printGrid(grid, start, goal, path, pathLength);
            return;
        }

        // Move currentNode to closedList
        closedList[closedCount++] = currentNode;
        for (int i = lowestIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        // Generate neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                int neighborX = currentNode->position.x + dx;
                int neighborY = currentNode->position.y + dy;

                if (isValid(grid, neighborX, neighborY)) {
                    int gCost = currentNode->gCost + 1;
                    Node* neighborNode = createNode(neighborX, neighborY, gCost, heuristic((Point){neighborX, neighborY}, goal));

                    int skip = 0;
                    for (int i = 0; i < closedCount; i++) {
                        if (closedList[i]->position.x == neighborNode->position.x &&
                            closedList[i]->position.y == neighborNode->position.y) {
                            skip = 1;
                            free(neighborNode);
                            break;
                        }
                    }

                    if (skip) continue;

                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->position.x == neighborNode->position.x &&
                            openList[i]->position.y == neighborNode->position.y && 
                            openList[i]->gCost <= neighborNode->gCost) {
                            skip = 1;
                            free(neighborNode);
                            break;
                        }
                    }

                    if (!skip) {
                        openList[openCount++] = neighborNode;
                    } else {
                        free(neighborNode);
                    }
                }
            }
        }
    }
    printf("No path found.\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {9, 9};

    aStar(grid, start, goal);
    
    // Clean up, free memory, etc.
    
    return 0;
}