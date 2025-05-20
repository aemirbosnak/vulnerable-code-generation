//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10
#define OBSTACLE -1
#define EMPTY 0
#define START 1
#define END 2

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g_cost; // distance to the start
    int h_cost; // heuristic distance to the end
    int f_cost; // total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent, int g, int h) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->g_cost = g;
    newNode->h_cost = h;
    newNode->f_cost = g + h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && grid[y][x] != OBSTACLE);
}

void printGrid(int grid[GRID_HEIGHT][GRID_WIDTH], Point start, Point end, Point path[], int pathSize) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x] == OBSTACLE) {
                printf("█ ");
            } else if (start.x == x && start.y == y) {
                printf("S "); // Start point
            } else if (end.x == x && end.y == y) {
                printf("E "); // End point
            } else {
                bool onPath = false;
                for (int i = 0; i < pathSize; i++) {
                    if (path[i].x == x && path[i].y == y) {
                        onPath = true;
                        break;
                    }
                }
                printf(onPath ? ". " : ". "); // Path (if any)
            }
        }
        printf("\n");
    }
    printf("\n");
}

void findPath(int grid[GRID_HEIGHT][GRID_WIDTH], Point start, Point end) {
    Node* openList[GRID_WIDTH * GRID_HEIGHT] = {NULL};
    Node* closedList[GRID_WIDTH * GRID_HEIGHT] = {NULL};
    int openIndex = 0, closedIndex = 0;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // Right, Down, Left, Up

    Node* startNode = createNode(start.x, start.y, NULL, 0, heuristic(start, end));
    openList[openIndex++] = startNode;

    while (openIndex > 0) {
        // Find the node with the least f_cost
        Node* currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 1; i < openIndex; i++) {
            if (openList[i]->f_cost < currentNode->f_cost) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Remove currentNode from openList
        for (int i = currentIndex; i < openIndex - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openIndex--;

        // Add currentNode to closedList
        closedList[closedIndex++] = currentNode;

        // Check if we reached the end
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            // Construct path
            Point path[GRID_WIDTH * GRID_HEIGHT];
            int pathSize = 0;
            Node* tempNode = currentNode;

            while (tempNode != NULL) {
                path[pathSize++] = tempNode->point;
                tempNode = tempNode->parent;
            }

            // Print the grid with path
            printGrid(grid, start, end, path, pathSize);
            
            // Free memory
            for (int i = 0; i < openIndex; i++) free(openList[i]);
            for (int i = 0; i < closedIndex; i++) free(closedList[i]);
            return;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->point.x + directions[i][0];
            int newY = currentNode->point.y + directions[i][1];

            if (isValid(grid, newX, newY)) {
                // Check if this node is in closedList
                bool inClosedList = false;
                for (int j = 0; j < closedIndex; j++) {
                    if (closedList[j]->point.x == newX && closedList[j]->point.y == newY) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) continue;

                int newGCost = currentNode->g_cost + 1;
                int newHCost = heuristic((Point){newX, newY}, end);
                Node* neighborNode = createNode(newX, newY, currentNode, newGCost, newHCost);

                // Check if this node is in openList
                bool inOpenList = false;
                for (int j = 0; j < openIndex; j++) {
                    if (openList[j]->point.x == newX && openList[j]->point.y == newY) {
                        if (openList[j]->g_cost <= neighborNode->g_cost) {
                            free(neighborNode);
                            inOpenList = true;
                            break;
                        }
                    }
                }

                if (!inOpenList) {
                    openList[openIndex++] = neighborNode;
                } else {
                    free(neighborNode);
                }
            }
        }
    }

    printf("No path found!\n");
    for (int i = 0; i < openIndex; i++) free(openList[i]);
    for (int i = 0; i < closedIndex; i++) free(closedList[i]);
}

int main() {
    int grid[GRID_HEIGHT][GRID_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -1, -1, -1, 0, 0, 0, -1, -1},
        {0, -1, 0, 0, 0, 0, -1, 0, 0, 0},
        {0, 0, 0, -1, -1, 0, -1, -1, -1, 0},
        {0, -1, -1, -1, 0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, -1, -1, 0, 0, 0},
        {0, -1, -1, -1, -1, -1, -1, -1, -1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, -1, -1, -1, 0, -1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Point start = {0, 0}; // Starting point (top-left corner)
    Point end = {9, 9}; // Ending point (bottom-right corner)

    findPath(grid, start, end);

    return 0;
}