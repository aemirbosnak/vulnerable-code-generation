//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define WALL '#'
#define PATH '.'
#define START 'S'
#define GOAL 'G'

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point pos;
    struct Node* parent;
    float g; // Cost from start to this node
    float h; // Heuristic cost to goal
    float f; // Total cost
} Node;

Node* createNode(int x, int y, Node* parent, float g, float h) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pos.x = x;
    newNode->pos.y = y;
    newNode->parent = parent;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    return newNode;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isValid(int x, int y, char grid[HEIGHT][WIDTH]) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != WALL);
}

void printPath(Node* node) {
    if (node == NULL)
        return;
    
    printPath(node->parent);
    printf("Step: (%d, %d)\n", node->pos.x, node->pos.y);
}

void aStar(char grid[HEIGHT][WIDTH], Point start, Point goal) {
    Node* openList[WIDTH * HEIGHT];  
    int openCount = 0;

    Node* closedList[WIDTH * HEIGHT];
    int closedCount = 0;

    openList[openCount++] = createNode(start.x, start.y, NULL, 0.0f, heuristic(start, goal));

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];
        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            printf("Path found:\n");
            printPath(currentNode);
            return;
        }

        openList[lowestIndex] = openList[--openCount];
        closedList[closedCount++] = currentNode;

        int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->pos.x + directions[i][0];
            int newY = currentNode->pos.y + directions[i][1];

            if (isValid(newX, newY, grid)) {
                Node* neighbor = createNode(newX, newY, currentNode, currentNode->g + 1.0f, heuristic((Point){newX, newY}, goal));

                bool inClosedList = false;
                for (int j = 0; j < closedCount; j++) {
                    if (closedList[j]->pos.x == neighbor->pos.x && closedList[j]->pos.y == neighbor->pos.y) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) {
                    free(neighbor);
                    continue;
                }

                bool inOpenList = false;
                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->pos.x == neighbor->pos.x && openList[j]->pos.y == neighbor->pos.y) {
                        inOpenList = true;
                        if (neighbor->g < openList[j]->g) {
                            openList[j]->g = neighbor->g;
                            openList[j]->f = neighbor->g + openList[j]->h;
                            openList[j]->parent = currentNode;
                        }
                        free(neighbor);
                        break;
                    }
                }
                if (!inOpenList) {
                    openList[openCount++] = neighbor;
                }
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, START, PATH, PATH, PATH, WALL, WALL, WALL, WALL, WALL},
        {WALL, PATH, WALL, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, PATH, WALL, PATH, PATH, PATH, PATH, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, PATH, WALL, WALL, WALL},
        {WALL, WALL, PATH, PATH, PATH, PATH, PATH, PATH, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    };

    Point start = {1, 1};
    Point goal = {8, 5};

    printf("Starting A* pathfinding from (%d, %d) to (%d, %d)\n", start.x, start.y, goal.x, goal.y);
    aStar(grid, start, goal);

    return 0;
}