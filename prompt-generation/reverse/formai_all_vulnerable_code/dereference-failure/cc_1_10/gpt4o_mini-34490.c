//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int gCost; // Cost from start
    int hCost; // Heuristic cost to goal
    int fCost; // Total cost
    struct Node* parent;
} Node;

Node* nodes[MAX_NODES];
bool openSet[MAX_NODES];
bool closedSet[MAX_NODES];
Point start = {0, 0};
Point end = {9, 9};

// Heuristic function: Manhattan distance
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Initializes a node
void initializeNode(Node* n, int x, int y) {
    n->pos.x = x;
    n->pos.y = y;
    n->gCost = INF;
    n->hCost = INF;
    n->fCost = INF;
    n->parent = NULL;
}

// Returns the node index based on position
int getNodeIndex(Point p) {
    return p.y * WIDTH + p.x;
}

// Checks if a point is within the grid bounds
bool isInBounds(Point p) {
    return p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT;
}

// Checks if a node is in the open set
bool isOpen(Node* node) {
    return openSet[getNodeIndex(node->pos)];
}

// Checks if a node is in the closed set
bool isClosed(Node* node) {
    return closedSet[getNodeIndex(node->pos)];
}

// Add node to open set
void addToOpen(Node* node) {
    openSet[getNodeIndex(node->pos)] = true;
}

// Remove node from open set
void removeFromOpen(Node* node) {
    openSet[getNodeIndex(node->pos)] = false;
}

// Add node to closed set
void addToClosed(Node* node) {
    closedSet[getNodeIndex(node->pos)] = true;
}

// Compare nodes for fCost
int compareNodes(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return nodeA->fCost - nodeB->fCost;
}

// A* Pathfinding algorithm
bool AStar() {
    Node* startNode = malloc(sizeof(Node));
    initializeNode(startNode, start.x, start.y);
    startNode->gCost = 0;
    startNode->hCost = heuristic(startNode->pos, end);
    startNode->fCost = startNode->gCost + startNode->hCost;

    addToOpen(startNode);
    
    while (true) {
        int currentIndex = -1;
        Node* currentNode = NULL;

        for (int i = 0; i < MAX_NODES; i++) {
            if (openSet[i]) {
                if (currentNode == NULL || nodes[i]->fCost < currentNode->fCost) {
                    currentNode = nodes[i];
                    currentIndex = i;
                }
            }
        }

        if (currentNode == NULL) {
            printf("No path found!\n");
            return false;
        }

        if (currentNode->pos.x == end.x && currentNode->pos.y == end.y) {
            printf("Path found:\n");
            Node* pathNode = currentNode;
            while (pathNode) {
                printf("(%d, %d) ", pathNode->pos.x, pathNode->pos.y);
                pathNode = pathNode->parent;
            }
            printf("\n");
            return true;
        }

        removeFromOpen(currentNode);
        addToClosed(currentNode);
        
        const int movements[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W

        for (int i = 0; i < 4; i++) {
            Point neighbor = {currentNode->pos.x + movements[i][0], currentNode->pos.y + movements[i][1]};

            if (!isInBounds(neighbor) || isClosed(nodes[getNodeIndex(neighbor)]))
                continue;

            int newGCost = currentNode->gCost + 1;
            Node* neighborNode = nodes[getNodeIndex(neighbor)];

            if (!isOpen(neighborNode) || newGCost < neighborNode->gCost) {
                neighborNode->gCost = newGCost;
                neighborNode->hCost = heuristic(neighborNode->pos, end);
                neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                neighborNode->parent = currentNode;

                if (!isOpen(neighborNode)) {
                    addToOpen(neighborNode);
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the nodes
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            nodes[getNodeIndex((Point){x, y})] = malloc(sizeof(Node));
            initializeNode(nodes[getNodeIndex((Point){x, y})], x, y);
        }
    }

    // Perform A* Pathfinding
    if (!AStar()) {
        fprintf(stderr, "An error occurred during pathfinding.\n");
    }

    // Clean up
    for (int i = 0; i < MAX_NODES; i++) {
        free(nodes[i]);
    }

    return 0;
}