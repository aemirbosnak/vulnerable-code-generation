//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)
#define INF INT_MAX

typedef struct Node {
    int x, y;
    int gCost;
    int hCost;
    int fCost;
    struct Node* parent;
} Node;

Node* openList[MAX_NODES];
int openListCount = 0;

bool isInOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->x == node->x && openList[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

void removeFromOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i] == node) {
            openList[i] = openList[--openListCount]; // replace with last and reduce count
            return;
        }
    }
}

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = INF;
    node->hCost = 0;
    node->fCost = INF;
    node->parent = parent;
    return node;
}

void reconstructPath(Node* current) {
    while (current) {
        printf("-> (%d, %d) ", current->x, current->y);
        current = current->parent;
    }
    printf("\n");
}

void aStar(Node* start, Node* goal) {
    start->gCost = 0;
    start->hCost = heuristic(start, goal);
    start->fCost = start->gCost + start->hCost;

    addToOpenList(start);

    while (openListCount > 0) {
        Node* current = openList[0];
        
        // Find the node with the lowest fCost
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->fCost < current->fCost) {
                current = openList[i];
            }
        }

        // If we have reached the goal
        if (current->x == goal->x && current->y == goal->y) {
            printf("Path found: ");
            reconstructPath(current);
            return;
        }

        removeFromOpenList(current);

        // Check neighbors (4 directions: up, down, left, right)
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int neighborX = current->x + directions[i][0];
            int neighborY = current->y + directions[i][1];

            if (neighborX < 0 || neighborY < 0 || neighborX >= WIDTH || neighborY >= HEIGHT) {
                continue; // skip out-of-bounds
            }

            Node* neighbor = createNode(neighborX, neighborY, current);
            int tentativeGCost = current->gCost + 1; // assume cost between neighbors is 1

            if (tentativeGCost < neighbor->gCost) {
                neighbor->gCost = tentativeGCost;
                neighbor->hCost = heuristic(neighbor, goal);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;

                if (!isInOpenList(neighbor)) {
                    addToOpenList(neighbor);
                }
            }
            free(neighbor); // prevent memory leak
        }
    }

    printf("No path found\n");
}

int main() {
    Node* start = createNode(0, 0, NULL);
    Node* goal = createNode(7, 5, NULL);

    aStar(start, goal);

    free(start);
    free(goal);
    return 0;
}