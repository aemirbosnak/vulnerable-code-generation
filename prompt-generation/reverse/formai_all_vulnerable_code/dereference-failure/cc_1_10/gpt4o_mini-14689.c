//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int gCost;    // Cost from start to current node
    int hCost;    // Heuristic cost to the end
    int fCost;    // Total cost
    struct Node* parent;
} Node;

Node* openSet[WIDTH * HEIGHT]; // Open set for A*
int openSetCount = 0;
bool closedSet[WIDTH][HEIGHT] = { false };
int grid[WIDTH][HEIGHT]; // Contains 0 for walkable and 1 for obstacles
Point start, end;

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void addToOpenSet(Node* node) {
    openSet[openSetCount++] = node;
}

void removeFromOpenSet(Node* node) {
    for (int i = 0; i < openSetCount; i++) {
        if (openSet[i] == node) {
            openSet[i] = openSet[--openSetCount];
            break;
        }
    }
}

bool isInOpenSet(Point point) {
    for (int i = 0; i < openSetCount; i++) {
        if (openSet[i]->position.x == point.x && openSet[i]->position.y == point.y) {
            return true;
        }
    }
    return false;
}

Node* findLowestFCostNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openSetCount; i++) {
        if (lowest == NULL || openSet[i]->fCost < lowest->fCost) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

bool isWalkable(Point point) {
    return point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT && grid[point.x][point.y] == 0;
}

void reconstructPath(Node* current) {
    printf("Path: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->position.x, current->position.y);
        current = current->parent;
    }
    printf("\n");
}

void pathfinding() {
    Node* startNode = malloc(sizeof(Node));
    startNode->position = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, end);
    startNode->fCost = startNode->hCost;
    startNode->parent = NULL;

    addToOpenSet(startNode);

    while (openSetCount > 0) {
        Node* currentNode = findLowestFCostNode();

        // If we have reached the end
        if (currentNode->position.x == end.x && currentNode->position.y == end.y) {
            reconstructPath(currentNode);
            return;
        }

        // Move current node to closed set
        removeFromOpenSet(currentNode);
        closedSet[currentNode->position.x][currentNode->position.y] = true;

        // Check neighbors
        Point neighbors[4] = {
            {currentNode->position.x + 1, currentNode->position.y},   // right
            {currentNode->position.x - 1, currentNode->position.y},   // left
            {currentNode->position.x, currentNode->position.y + 1},   // down
            {currentNode->position.x, currentNode->position.y - 1}    // up
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            if (!isWalkable(neighbor) || closedSet[neighbor.x][neighbor.y]) {
                continue;
            }

            int newGCost = currentNode->gCost + 1;
            Node* neighborNode = malloc(sizeof(Node));
            neighborNode->position = neighbor;
            neighborNode->gCost = newGCost;
            neighborNode->hCost = heuristic(neighbor, end);
            neighborNode->fCost = newGCost + neighborNode->hCost;
            neighborNode->parent = currentNode;

            if (isInOpenSet(neighbor) && newGCost >= neighborNode->gCost) {
                free(neighborNode);
                continue;
            }

            // Add to open set
            addToOpenSet(neighborNode);
        }
    }

    printf("No path found.\n");
}

int main() {
    // Initialize grid
    memset(grid, 0, sizeof(grid));
    grid[1][0] = grid[1][1] = grid[1][2] = 1;  // Obstacles

    start = (Point) {0, 0};
    end = (Point) {7, 7};

    printf("Starting pathfinding from (%d, %d) to (%d, %d)\n", start.x, start.y, end.x, end.y);
    pathfinding();

    return 0;
}