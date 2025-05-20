//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 99999

typedef struct Node {
    int x, y;
    int g_cost; // Cost from start to node
    int h_cost; // Heuristic cost to goal
    int f_cost; // Total cost
    struct Node* parent;
    bool traversable;
} Node;

Node* createNode(int x, int y, bool traversable) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g_cost = INF;
    node->h_cost = INF;
    node->f_cost = INF;
    node->parent = NULL;
    node->traversable = traversable;
    return node;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void reconstructPath(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

Node* grid[WIDTH][HEIGHT];
Node* openSet[WIDTH * HEIGHT];
int openSetSize = 0;

void addNodeToOpenSet(Node* node) {
    openSet[openSetSize++] = node;
}

bool removeNodeFromOpenSet(Node* node) {
    for (int i = 0; i < openSetSize; i++) {
        if (openSet[i] == node) {
            openSet[i] = openSet[--openSetSize];
            return true;
        }
    }
    return false;
}

Node* findLowestFCostNode() {
    Node* lowest = openSet[0];
    for (int i = 1; i < openSetSize; i++) {
        if (openSet[i]->f_cost < lowest->f_cost) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

void aStar(Node* start, Node* goal) {
    start->g_cost = 0;
    start->h_cost = heuristic(start, goal);
    start->f_cost = start->h_cost;
    addNodeToOpenSet(start);

    while (openSetSize > 0) {
        Node* current = findLowestFCostNode();
        
        if (current == goal) {
            printf("Path found: ");
            reconstructPath(current);
            return;
        }

        removeNodeFromOpenSet(current);

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the current node
                if (abs(dx) + abs(dy) == 2) continue; // Skip diagonal movement

                int newX = current->x + dx;
                int newY = current->y + dy;

                if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                    Node* neighbor = grid[newX][newY];
                    if (!neighbor->traversable) continue;

                    int tentative_g_cost = current->g_cost + 1;
                    if (tentative_g_cost < neighbor->g_cost) {
                        neighbor->parent = current;
                        neighbor->g_cost = tentative_g_cost;
                        neighbor->h_cost = heuristic(neighbor, goal);
                        neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                        if (removeNodeFromOpenSet(neighbor))
                            addNodeToOpenSet(neighbor);
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    // Initializing a simple grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            bool traversable = true;
            if (i == 5 && j < 5) traversable = false; // Add obstacle
            grid[i][j] = createNode(i, j, traversable);
        }
    }

    Node* start = grid[0][0];
    Node* goal = grid[9][9];

    aStar(start, goal);

    // Free allocated memory (for this example, no free is shown to keep it simple)
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            free(grid[i][j]);
        }
    }

    return 0;
}