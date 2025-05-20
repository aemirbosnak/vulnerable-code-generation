//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'
#define VISITED 'o'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g; // Cost from start to current point
    int h; // Heuristic cost estimate to end point
    int f; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan distance
}

bool isValid(int grid[HEIGHT][WIDTH], bool visited[HEIGHT][WIDTH], int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != WALL && !visited[y][x]);
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    if (node->parent != NULL) {
        printf("-> ");
    }
    printf("(%d, %d) ", node->point.x, node->point.y);
}

void freePath(Node* node) {
    if (node == NULL) return;
    freePath(node->parent);
    free(node);
}

void AStar(int grid[HEIGHT][WIDTH], Point start, Point end) {
    Node* openList[WIDTH * HEIGHT];
    bool visited[HEIGHT][WIDTH] = {false};
    int openCount = 0;

    openList[openCount++] = createNode(start.x, start.y, NULL);

    while (openCount > 0) {
        int lowestIndex = 0;

        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        // Remove currentNode from openList
        for (int i = lowestIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        // If we reached the target
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            freePath(currentNode);
            return;
        }

        visited[currentNode->point.y][currentNode->point.x] = true;

        // Neighbors
        Point neighbors[4] = {
            {currentNode->point.x + 1, currentNode->point.y},
            {currentNode->point.x - 1, currentNode->point.y},
            {currentNode->point.x, currentNode->point.y + 1},
            {currentNode->point.x, currentNode->point.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            int neighborX = neighbors[i].x;
            int neighborY = neighbors[i].y;

            if (isValid(grid, visited, neighborX, neighborY)) {
                Node* neighborNode = createNode(neighborX, neighborY, currentNode);
                neighborNode->g = currentNode->g + 1;
                neighborNode->h = heuristic(neighbors[i], end);
                neighborNode->f = neighborNode->g + neighborNode->h;

                // If the neighbor is already in the open list with a lower f cost, skip it
                bool found = false;
                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->point.x == neighborX && openList[j]->point.y == neighborY && openList[j]->f <= neighborNode->f) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    openList[openCount++] = neighborNode;
                } else {
                    free(neighborNode);
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, '#', '#', '#', '#', '#', '#', 0, 0, 0},
        {0, '#', 0, 0, 0, 0, '#', 0, 0, 0},
        {0, '#', 0, '#', '#', 0, '#', '#', '#', 0},
        {0, 0, 0, 0, '#', 0, 0, 0, 0, 0},
        {0, '#', '#', 0, '#', '#', '#', '#', 0, 0},
        {0, 0, 0, 0, 0, '#', 0, 0, 0, 0},
        {'#', '#', '#', '#', 0, '#', '#', '#', '#', 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 'E'},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Point start = {0, 0}; // Start point
    Point end = {9, 9};   // End point

    grid[start.y][start.x] = START; // Marking start point
    grid[end.y][end.x] = END; // Marking end point

    AStar(grid, start, end);

    return 0;
}