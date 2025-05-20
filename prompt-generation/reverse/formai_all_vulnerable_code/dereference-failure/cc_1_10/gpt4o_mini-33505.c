//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES WIDTH * HEIGHT

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    float g; // Cost from start to the node
    float h; // Heuristic cost to the goal
    float f; // Total cost
    struct Node* parent;
} Node;

Node* nodes[MAX_NODES];
int nodeCount = 0;

float heuristic(Position a, Position b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

bool isValid(int x, int y, int grid[HEIGHT][WIDTH]) {
    return (x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT) && (grid[y][x] == 0); // 0 indicates walkable
}

void addNode(Position pos, float g, float h, Node* parent) {
    nodes[nodeCount] = (Node*)malloc(sizeof(Node));
    nodes[nodeCount]->pos = pos;
    nodes[nodeCount]->g = g;
    nodes[nodeCount]->h = h;
    nodes[nodeCount]->f = g + h;
    nodes[nodeCount]->parent = parent;
    nodeCount++;
}

int getLowestFNodeIndex() {
    int lowestIndex = -1;
    float lowestF = INFINITY;

    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i]->f < lowestF) {
            lowestF = nodes[i]->f;
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

void cleanup() {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

void retracePath(Node* node) {
    printf("Path: ");
    while (node != NULL) {
        printf("(%d, %d) ", node->pos.x, node->pos.y);
        node = node->parent;
    }
    printf("\n");
}

void AStar(int grid[HEIGHT][WIDTH], Position start, Position goal) {
    addNode(start, 0, heuristic(start, goal), NULL);

    while (nodeCount > 0) {
        int currentIndex = getLowestFNodeIndex();
        Node* currentNode = nodes[currentIndex];

        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            retracePath(currentNode);
            cleanup();
            return;
        }

        // Remove currentNode
        nodes[currentIndex] = nodes[nodeCount - 1];
        nodeCount--;

        Position neighbors[4] = {{currentNode->pos.x + 1, currentNode->pos.y}, 
                                  {currentNode->pos.x - 1, currentNode->pos.y},
                                  {currentNode->pos.x, currentNode->pos.y + 1}, 
                                  {currentNode->pos.x, currentNode->pos.y - 1}};

        for (int i = 0; i < 4; i++) {
            Position newPos = neighbors[i];
            if (isValid(newPos.x, newPos.y, grid)) {
                float newG = currentNode->g + 1;
                float newH = heuristic(newPos, goal);

                bool alreadyExists = false;
                for (int j = 0; j < nodeCount; j++) {
                    if (nodes[j]->pos.x == newPos.x && nodes[j]->pos.y == newPos.y) {
                        alreadyExists = true;
                        if (newG < nodes[j]->g) {
                            nodes[j]->g = newG;
                            nodes[j]->h = newH;
                            nodes[j]->f = newG + newH;
                            nodes[j]->parent = currentNode;
                        }
                        break;
                    }
                }

                if (!alreadyExists) {
                    addNode(newPos, newG, newH, currentNode);
                }
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    Position start = {0, 0};
    Position goal = {9, 9};

    AStar(grid, start, goal);

    return 0;
}