//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define WALL '#'
#define PATH ' '
#define START 'S'
#define GOAL 'G'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int gCost, hCost, fCost;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int gCost, int hCost, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->position.x = x;
    newNode->position.y = y;
    newNode->gCost = gCost;
    newNode->hCost = hCost;
    newNode->fCost = gCost + hCost;
    newNode->parent = parent;
    return newNode;
}

int calculateH(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point point, char grid[HEIGHT][WIDTH]) {
    return point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT && grid[point.y][point.x] != WALL;
}

void tracePath(Node* node) {
    if (node == NULL) return;
    tracePath(node->parent);
    if (node->parent != NULL)
        printf("Move to (%d, %d)\n", node->position.x, node->position.y);
}

void aStar(char grid[HEIGHT][WIDTH], Point start, Point goal) {
    Node* openSet[WIDTH * HEIGHT];
    int openSetSize = 0;
    
    Node* closedSet[WIDTH * HEIGHT];
    int closedSetSize = 0;

    Node* startNode = createNode(start.x, start.y, 0, calculateH(start, goal), NULL);
    openSet[openSetSize++] = startNode;

    while (openSetSize > 0) {
        int lowestIndex = 0;
        for (int i = 0; i < openSetSize; i++) {
            if (openSet[i]->fCost < openSet[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openSet[lowestIndex];

        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            tracePath(currentNode);
            free(currentNode);
            return;
        }

        openSet[lowestIndex] = openSet[openSetSize - 1];
        openSetSize--;

        closedSet[closedSetSize++] = currentNode;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue;

                Point neighbor = { currentNode->position.x + dx, currentNode->position.y + dy };

                if (!isValid(neighbor, grid)) continue;

                bool inClosedSet = false;
                for (int j = 0; j < closedSetSize; j++) {
                    if (closedSet[j]->position.x == neighbor.x && closedSet[j]->position.y == neighbor.y) {
                        inClosedSet = true;
                        break;
                    }
                }

                if (inClosedSet) continue;

                int gCost = currentNode->gCost + 1;
                Node* neighborNode = NULL;

                for (int j = 0; j < openSetSize; j++) {
                    if (openSet[j]->position.x == neighbor.x && openSet[j]->position.y == neighbor.y) {
                        neighborNode = openSet[j];
                        break;
                    }
                }

                if (neighborNode) {
                    if (gCost < neighborNode->gCost) {
                        neighborNode->gCost = gCost;
                        neighborNode->fCost = gCost + neighborNode->hCost;
                        neighborNode->parent = currentNode;
                    }
                } else {
                    neighborNode = createNode(neighbor.x, neighbor.y, gCost, calculateH(neighbor, goal), currentNode);
                    openSet[openSetSize++] = neighborNode;
                }
            }
        }
    }
    
    printf("No path found!\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        { 'S', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', 'G' },
        { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
    };

    Point start = {0, 0};
    Point goal = {9, 0};

    aStar(grid, start, goal);
    return 0;
}