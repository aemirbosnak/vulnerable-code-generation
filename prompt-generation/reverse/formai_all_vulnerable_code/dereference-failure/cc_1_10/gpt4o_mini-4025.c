//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#define GRID_SIZE 10
#define OBSTACLES 15
#define MAX_RETRIES 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node* nodes;
    int size;
} NodeList;

typedef struct {
    Node node;
    int gCost;
    int hCost;
    int fCost;
    Node* parent;
} AStarNode;

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

NodeList* createNodeList(int size) {
    NodeList* list = malloc(sizeof(NodeList));
    list->nodes = malloc(size * sizeof(Node));
    list->size = size;
    return list;
}

void addNode(NodeList* list, Node node, int index) {
    list->nodes[index] = node;
}

bool isInList(NodeList* list, Node node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i].x == node.x && list->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

int getLowestFCostIndex(AStarNode* openList, int openCount) {
    int lowestIndex = 0;
    for (int i = 1; i < openCount; i++) {
        if (openList[i].fCost < openList[lowestIndex].fCost) {
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Node start, end;
    NodeList* obstacles = createNodeList(OBSTACLES);
    AStarNode openList[GRID_SIZE * GRID_SIZE];
    AStarNode closedList[GRID_SIZE * GRID_SIZE];
    int openCount = 0, closedCount = 0;

    // Initialize grid with open paths
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Randomly generate obstacles
    for (int i = 0; i < OBSTACLES; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = '#';
            addNode(obstacles, (Node){.x = x, .y = y}, i);
        }
    }

    // Define start and end nodes
    start = (Node){0, 0};  // Top-left corner
    end = (Node){GRID_SIZE - 1, GRID_SIZE - 1};  // Bottom-right corner

    // A* Pathfinding Algorithm
    openList[openCount++] = (AStarNode){.node = start, .gCost = 0, .hCost = heuristic(start, end), .fCost = heuristic(start, end), .parent = NULL};

    while (openCount > 0) {
        int currentIndex = getLowestFCostIndex(openList, openCount);
        AStarNode currentNode = openList[currentIndex];

        // Check if we reached the end
        if (currentNode.node.x == end.x && currentNode.node.y == end.y) {
            printf("Path found!\n");
            AStarNode* backtrack = &currentNode;
            printf("Path: ");
            while (backtrack != NULL) {
                printf("(%d, %d) ", backtrack->node.x, backtrack->node.y);
                backtrack = backtrack->parent;
            }
            printf("\n");
            return 0;
        }

        // Move current node to closed list
        for (int i = currentIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount++;
        closedList[closedCount++] = currentNode;

        // Generate neighbors (4-directional)
        Node neighbors[4] = {
            {currentNode.node.x - 1, currentNode.node.y}, // Up
            {currentNode.node.x + 1, currentNode.node.y}, // Down
            {currentNode.node.x, currentNode.node.y - 1}, // Left
            {currentNode.node.x, currentNode.node.y + 1}  // Right
        };

        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];
            if (neighbor.x < 0 || neighbor.x >= GRID_SIZE || neighbor.y < 0 || neighbor.y >= GRID_SIZE) {
                continue; // Skip out of bounds
            }
            if (grid[neighbor.x][neighbor.y] == '#') {
                continue; // Skip obstacles
            }
            if (isInList(closedCount, neighbor)) {
                continue; // Skip already evaluated
            }

            int tentativeGCost = currentNode.gCost + 1;
            bool inOpenList = isInList(openCount, neighbor); // Check if it's in the open list
            if (!inOpenList || tentativeGCost < openList[openCount].gCost) {
                AStarNode neighborNode = {.node = neighbor, .gCost = tentativeGCost, .hCost = heuristic(neighbor, end), .fCost = tentativeGCost + heuristic(neighbor, end), .parent = &currentNode};

                if (!inOpenList) {
                    openList[openCount++] = neighborNode;
                } else {
                    openList[openCount - 1] = neighborNode; // Update the existing node
                }
            }
        }
    }

    printf("No path found!\n");
    return 1;
}