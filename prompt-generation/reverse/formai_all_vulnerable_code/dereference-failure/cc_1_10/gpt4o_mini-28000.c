//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int gCost;
    int hCost;
    int fCost;
    bool inClosedList;
    bool inOpenList;
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[MAX_SIZE];
    int size;
} OpenList;

Node* grid[WIDTH][HEIGHT];

// Function to initialize the grid
void initializeGrid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = malloc(sizeof(Node));
            grid[i][j]->position.x = i;
            grid[i][j]->position.y = j;
            grid[i][j]->gCost = 0;
            grid[i][j]->hCost = 0;
            grid[i][j]->fCost = 0;
            grid[i][j]->inClosedList = false;
            grid[i][j]->inOpenList = false;
            grid[i][j]->parent = NULL;
        }
    }
}

// Function to calculate heuristic (Manhattan distance)
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to add a node to the open list
void addToOpenList(OpenList* openList, Node* node) {
    openList->nodes[openList->size++] = node;
    node->inOpenList = true;
}

// Function to remove a node from the open list
void removeFromOpenList(OpenList* openList, Node* node) {
    for (int i = 0; i < openList->size; i++) {
        if (openList->nodes[i] == node) {
            openList->nodes[i] = openList->nodes[--openList->size];
            node->inOpenList = false;
            return;
        }
    }
}

// Function to find the node with the lowest fCost
Node* getLowestFCostNode(OpenList* openList) {
    Node* lowest = openList->nodes[0];
    for (int i = 1; i < openList->size; i++) {
        if (openList->nodes[i]->fCost < lowest->fCost) {
            lowest = openList->nodes[i];
        }
    }
    return lowest;
}

// Function to get neighboring nodes
void getNeighbors(Node* node, Node* neighbors[]) {
    int idx = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip the current node

            if (abs(dx) + abs(dy) == 1) { // Only cardinal directions
                int newX = node->position.x + dx;
                int newY = node->position.y + dy;
                if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                    neighbors[idx++] = grid[newX][newY];
                }
            }
        }
    }
}

// A* pathfinding algorithm
bool aStar(Point start, Point goal) {
    OpenList openList;
    openList.size = 0;
    
    // Initialize start node
    Node* startNode = grid[start.x][start.y];
    Node* goalNode = grid[goal.x][goal.y];

    addToOpenList(&openList, startNode);

    while (openList.size > 0) {
        Node* currentNode = getLowestFCostNode(&openList);

        // If we have reached the goal
        if (currentNode == goalNode) {
            // Construct the path
            Node* pathNode = goalNode;
            printf("Path: ");
            while (pathNode) {
                printf("(%d, %d) ", pathNode->position.x, pathNode->position.y);
                pathNode = pathNode->parent;
            }
            printf("\n");
            return true;
        }

        removeFromOpenList(&openList, currentNode);
        currentNode->inClosedList = true;

        Node* neighbors[4];
        getNeighbors(currentNode, neighbors);

        for (int i = 0; i < 4; i++) {
            if (!neighbors[i] || neighbors[i]->inClosedList) continue;

            int tentativeGCost = currentNode->gCost + 1; // Assuming cost between nodes is 1

            if (!neighbors[i]->inOpenList || tentativeGCost < neighbors[i]->gCost) {
                neighbors[i]->gCost = tentativeGCost;
                neighbors[i]->hCost = heuristic(neighbors[i]->position, goalNode->position);
                neighbors[i]->fCost = neighbors[i]->gCost + neighbors[i]->hCost;
                neighbors[i]->parent = currentNode;

                if (!neighbors[i]->inOpenList) {
                    addToOpenList(&openList, neighbors[i]);
                }
            }
        }
    }

    printf("Path not found\n");
    return false;
}

// Clean up function to free memory
void cleanup() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            free(grid[i][j]);
        }
    }
}

// Main function
int main() {
    initializeGrid();

    Point start = {0, 0};
    Point goal = {7, 7};

    if (aStar(start, goal)) {
        printf("Pathfinding complete!\n");
    } else {
        printf("Could not find a path from (%d, %d) to (%d, %d)\n", start.x, start.y, goal.x, goal.y);
    }

    cleanup();
    return 0;
}