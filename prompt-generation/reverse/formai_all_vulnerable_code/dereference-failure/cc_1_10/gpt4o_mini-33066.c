//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct Node {
    int x, y;
    int gCost; // Distance from start
    int hCost; // Distance to goal
    int fCost; // gCost + hCost
    struct Node* parent;
    bool isWalkable;
} Node;

Node* createNode(int x, int y, bool isWalkable) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = 0;
    node->hCost = 0;
    node->fCost = 0;
    node->parent = NULL;
    node->isWalkable = isWalkable;
    return node;
}

int calculateHeuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

bool isNodeInList(Node* node, Node** list, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == node) {
            return true;
        }
    }
    return false;
}

void tracePath(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) <- ", node->x, node->y);
        node = node->parent;
    }
    printf("Start\n");
}

Node* findLowestFCostNode(Node** openList, int size) {
    Node* lowest = openList[0];
    for (int i = 1; i < size; i++) {
        if (openList[i]->fCost < lowest->fCost) {
            lowest = openList[i];
        }
    }
    return lowest;
}

void aStarSearch(Node* grid[HEIGHT][WIDTH], Node* start, Node* goal) {
    Node* openList[MAX_NODES];
    Node* closedList[MAX_NODES];
    int openListSize = 0;
    int closedListSize = 0;

    openList[openListSize++] = start;

    while (openListSize > 0) {
        Node* currentNode = findLowestFCostNode(openList, openListSize);
        
        if (currentNode == goal) {
            printf("Path found!\n");
            tracePath(currentNode);
            return;
        }

        // Remove current node from open list
        for (int i = 0; i < openListSize; i++) {
            if (openList[i] == currentNode) {
                openList[i] = openList[--openListSize];
                break;
            }
        }
        
        closedList[closedListSize++] = currentNode;

        for (int xOffset = -1; xOffset <= 1; xOffset++) {
            for (int yOffset = -1; yOffset <= 1; yOffset++) {
                if (abs(xOffset) == abs(yOffset)) continue; // Skip diagonals
                int neighborX = currentNode->x + xOffset;
                int neighborY = currentNode->y + yOffset;

                if (neighborX < 0 || neighborX >= WIDTH || neighborY < 0 || neighborY >= HEIGHT) continue; // Out of bounds
                Node* neighbor = grid[neighborY][neighborX];

                if (!neighbor->isWalkable || isNodeInList(neighbor, closedList, closedListSize)) continue; // Blocked or already evaluated
                
                int tentativeGCost = currentNode->gCost + 1;

                if (!isNodeInList(neighbor, openList, openListSize) || tentativeGCost < neighbor->gCost) {
                    neighbor->gCost = tentativeGCost;
                    neighbor->hCost = calculateHeuristic(neighbor, goal);
                    neighbor->fCost = neighbor->gCost + neighbor->hCost;
                    neighbor->parent = currentNode;

                    if (!isNodeInList(neighbor, openList, openListSize)) {
                        openList[openListSize++] = neighbor;
                    }
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    Node* grid[HEIGHT][WIDTH];

    // Creating the grid with walkable and non-walkable nodes
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool walkable = true;
            // Making some random non-walkable nodes for obstacles
            if ((x + y) % 3 == 0) {
                walkable = false;
            }
            grid[y][x] = createNode(x, y, walkable);
        }
    }

    // Declaring start and goal nodes
    Node* start = grid[0][0];
    Node* goal = grid[HEIGHT - 1][WIDTH - 1];

    printf("Starting A* pathfinding from (%d, %d) to (%d, %d)\n", start->x, start->y, goal->x, goal->y);
    aStarSearch(grid, start, goal);

    // Free memory
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            free(grid[y][x]);
        }
    }

    return 0;
}