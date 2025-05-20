//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE 1
#define PATH 0

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point position;
    int gCost;
    int hCost;
    int fCost;
    struct Node *parent;
} Node;

Node *createNode(Point position, Node *parent, int gCost, int hCost) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->position = position;
    node->parent = parent;
    node->gCost = gCost;
    node->hCost = hCost;
    node->fCost = gCost + hCost;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isInBounds(Point p) {
    return (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT);
}

bool isWalkable(int grid[HEIGHT][WIDTH], Point point) {
    return grid[point.y][point.x] == PATH;
}

void reconstructPath(Node *node) {
    if (node == NULL) return;
    reconstructPath(node->parent);
    printf("(%d, %d) ", node->position.x, node->position.y);
}

void freeNode(Node *node) {
    free(node);
}

void aStarSearch(int grid[HEIGHT][WIDTH], Point start, Point goal) {
    Node *openSet[WIDTH * HEIGHT] = { NULL };
    int openSetSize = 0;

    Node *startNode = createNode(start, NULL, 0, heuristic(start, goal));
    openSet[openSetSize++] = startNode;

    while (openSetSize > 0) {
        Node *currentNode = openSet[0];
        int currentIndex = 0;

        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i]->fCost < currentNode->fCost || 
                (openSet[i]->fCost == currentNode->fCost && openSet[i]->hCost < currentNode->hCost)) {
                currentNode = openSet[i];
                currentIndex = i;
            }
        }

        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            printf("\n");
            freeNode(currentNode);
            for (int i = 0; i < openSetSize; i++) {
                freeNode(openSet[i]);
            }
            return;
        }

        openSet[currentIndex] = openSet[--openSetSize];
        freeNode(currentNode);

        Point neighbors[4] = {
            {currentNode->position.x + 1, currentNode->position.y},
            {currentNode->position.x - 1, currentNode->position.y},
            {currentNode->position.x, currentNode->position.y + 1},
            {currentNode->position.x, currentNode->position.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            if (!isInBounds(neighbor) || !isWalkable(grid, neighbor)) 
                continue;

            int gCost = currentNode->gCost + 1;
            int hCost = heuristic(neighbor, goal);
            bool skipNode = false;

            for (int j = 0; j < openSetSize; j++) {
                if (openSet[j]->position.x == neighbor.x && openSet[j]->position.y == neighbor.y &&
                    gCost >= openSet[j]->gCost) {
                    skipNode = true;
                    break;
                }
            }

            if (skipNode) continue;

            Node *neighborNode = createNode(neighbor, currentNode, gCost, hCost);
            openSet[openSetSize++] = neighborNode;
        }
    }

    printf("No path found.\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {9, 9};

    aStarSearch(grid, start, goal);

    return 0;
}