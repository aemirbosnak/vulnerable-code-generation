//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE '.'
#define START 'S'
#define GOAL 'G'
#define PATH '*'

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point pos;
    float gCost; // Cost from start to node
    float hCost; // Heuristic cost to goal
    float fCost; // Total cost
    struct Node *parent;
} Node;

Node *createNode(Point pos, float g, float h, Node *parent) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->pos = pos;
    newNode->gCost = g;
    newNode->hCost = h;
    newNode->fCost = g + h;
    newNode->parent = parent;
    return newNode;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void printGrid(char grid[HEIGHT][WIDTH], Point path[], int pathLength) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            bool isPath = false;
            for (int k = 0; k < pathLength; k++) {
                if (path[k].x == i && path[k].y == j) {
                    isPath = true;
                    break;
                }
            }
            if (isPath) {
                printf("%c ", PATH);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int AStar(Point start, Point goal, char grid[HEIGHT][WIDTH]) {
    Node *openList[WIDTH * HEIGHT];
    Node *closedList[WIDTH * HEIGHT];
    int openCount = 0, closedCount = 0;

    openList[openCount++] = createNode(start, 0, heuristic(start, goal), NULL);

    while (openCount > 0) {
        // Find node with lowest fCost in openList
        int currentIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[currentIndex]->fCost) {
                currentIndex = i;
            }
        }
        Node *currentNode = openList[currentIndex];

        // Goal check
        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            // Construct path
            Point path[WIDTH * HEIGHT];
            int pathLength = 0;
            Node *temp = currentNode;
            while (temp != NULL) {
                path[pathLength++] = temp->pos;
                temp = temp->parent;
            }
            // Print the path on the grid
            printGrid(grid, path, pathLength);
            return 0; // Path found
        }

        // Move current node from open to closed list
        for (int i = currentIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;
        closedList[closedCount++] = currentNode;

        // Check the 4 neighbors (up, down, left, right)
        Point neighbors[4] = { {currentNode->pos.x - 1, currentNode->pos.y},
                                {currentNode->pos.x + 1, currentNode->pos.y},
                                {currentNode->pos.x, currentNode->pos.y - 1},
                                {currentNode->pos.x, currentNode->pos.y + 1} };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            // Check bounds and if it is walkable
            if (neighbor.x < 0 || neighbor.x >= HEIGHT || 
                neighbor.y < 0 || neighbor.y >= WIDTH ||
                grid[neighbor.x][neighbor.y] == OBSTACLE) {
                continue;
            }

            // Check if in closed list
            bool inClosed = false;
            for (int j = 0; j < closedCount; j++) {
                if (closedList[j]->pos.x == neighbor.x && closedList[j]->pos.y == neighbor.y) {
                    inClosed = true;
                    break;
                }
            }
            if (inClosed) continue;

            // Calculate costs
            float gCost = currentNode->gCost + 1;
            float hCost = heuristic(neighbor, goal);
            float fCost = gCost + hCost;

            // Check for existing node in open list
            bool inOpen = false;
            for (int j = 0; j < openCount; j++) {
                if (openList[j]->pos.x == neighbor.x && openList[j]->pos.y == neighbor.y) {
                    inOpen = true;
                    // If this path is better, update the node
                    if (fCost < openList[j]->fCost) {
                        openList[j]->gCost = gCost;
                        openList[j]->hCost = hCost;
                        openList[j]->fCost = fCost;
                        openList[j]->parent = currentNode;
                    }
                    break;
                }
            }

            // If it's not in open list, add it
            if (!inOpen) {
                openList[openCount++] = createNode(neighbor, gCost, hCost, currentNode);
            }
        }
    }

    printf("No path found!\n");
    return -1; // No path found
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {FREE, FREE, FREE, FREE, OBSTACLE, FREE, FREE, FREE, OBSTACLE, FREE},
        {FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, FREE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, OBSTACLE, FREE, GOAL},
        {START, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, FREE, FREE, FREE, FREE, FREE},
        {FREE, FREE, FREE, OBSTACLE, FREE, FREE, FREE, OBSTACLE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, FREE, OBSTACLE, FREE, FREE},
        {FREE, FREE, FREE, FREE, OBSTACLE, FREE, FREE, OBSTACLE, FREE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE}
    };
    
    Point start = {5, 0};
    Point goal = {4, 9};

    AStar(start, goal, grid);

    return 0;
}