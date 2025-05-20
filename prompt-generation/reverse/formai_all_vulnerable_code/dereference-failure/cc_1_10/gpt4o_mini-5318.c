//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_OPEN_NODES 100
#define INFINITY 999999

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    float g; // Cost from start to current node
    float h; // Heuristic cost from current node to end
    float f; // Total cost (g + h)
    bool inOpen; // Is the node in the open list
    bool inClosed; // Is the node in the closed list
    struct Node* parent; // Parent node for path reconstruction
} Node;

Node* openList[MAX_OPEN_NODES];
int openCount = 0;
int grid[HEIGHT][WIDTH]; // 0 for free space, 1 for obstacles
Node* nodes[HEIGHT][WIDTH]; // Stores all nodes

Position start, end;

float heuristic(Position a, Position b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

void initializeGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = 0; // Free space
            nodes[y][x] = (Node *)malloc(sizeof(Node));
            nodes[y][x]->pos.x = x;
            nodes[y][x]->pos.y = y;
            nodes[y][x]->g = INFINITY;
            nodes[y][x]->h = INFINITY;
            nodes[y][x]->f = INFINITY;
            nodes[y][x]->parent = NULL; 
            nodes[y][x]->inOpen = false;
            nodes[y][x]->inClosed = false;
        }
    }

    // Create obstacles
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[4][5] = 1;
    grid[5][5] = 1;
}

void addToOpen(Node* node) {
    openList[openCount++] = node;
    node->inOpen = true;
}

void removeFromOpen(Node* node) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i] == node) {
            openList[i] = openList[--openCount]; // Swap with the last element
            node->inOpen = false;
            break;
        }
    }
}

Node* getLowestCostNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openCount; i++) {
        if (lowest == NULL || openList[i]->f < lowest->f) {
            lowest = openList[i];
        }
    }
    return lowest;
}

bool isWalkable(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] == 0;
}

void aStar() {
    Node* startNode = nodes[start.y][start.x];
    Node* endNode = nodes[end.y][end.x];
    
    startNode->g = 0;
    startNode->h = heuristic(startNode->pos, endNode->pos);
    startNode->f = startNode->g + startNode->h;
    
    addToOpen(startNode);

    while (openCount > 0) {
        Node* currentNode = getLowestCostNode();
        
        if (currentNode == endNode) {
            // Path found
            Node* temp = currentNode;
            while (temp) {
                printf("Path: (%d, %d)\n", temp->pos.x, temp->pos.y);
                temp = temp->parent;
            }
            return;
        }

        removeFromOpen(currentNode);
        currentNode->inClosed = true;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (fabs(dx) + fabs(dy) != 1) continue; // Only consider adjacent squares
                int nx = currentNode->pos.x + dx;
                int ny = currentNode->pos.y + dy;

                if (!isWalkable(nx, ny) || (nodes[ny][nx]->inClosed)) {
                    continue; // Not walkable or already evaluated
                }

                Node* neighborNode = nodes[ny][nx];

                float tentativeG = currentNode->g + 1; // Assuming uniform cost
                if (!neighborNode->inOpen) {
                    addToOpen(neighborNode);
                } else if (tentativeG >= neighborNode->g) {
                    continue; // Not a better path
                }

                neighborNode->parent = currentNode;
                neighborNode->g = tentativeG;
                neighborNode->h = heuristic(neighborNode->pos, endNode->pos);
                neighborNode->f = neighborNode->g + neighborNode->h;
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    start.x = 0; start.y = 0; // Starting position
    end.x = 9; end.y = 9; // Ending position

    initializeGrid();
    aStar();

    // Clean up dynamically allocated memory
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            free(nodes[y][x]);
        }
    }

    return 0;
}