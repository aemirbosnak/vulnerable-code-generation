//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL '#'
#define PATH '.'
#define START 'S'
#define END 'E'
#define OPEN 'O'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    float f, g, h;
    struct Node* parent;
} Node;

Node* createNode(Point point, float g, float h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point = point;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isValidMove(char grid[HEIGHT][WIDTH], int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != WALL);
}

void reconstructPath(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) ", node->point.x, node->point.y);
        node = node->parent;
    }
    printf("\n");
}

void aStar(char grid[HEIGHT][WIDTH], Point start, Point end) {
    Node* openSet[WIDTH * HEIGHT];
    int openCount = 0;

    Node* startNode = createNode(start, 0, heuristic(start, end), NULL);
    openSet[openCount++] = startNode;

    while (openCount > 0) {
        // Find node with lowest f
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openSet[i]->f < openSet[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openSet[lowestIndex];

        // Goal check
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            free(currentNode);
            return;
        }

        // Remove current node from open set
        openSet[lowestIndex] = openSet[--openCount];
        
        // Neighboring offsets
        Point neighbors[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->point.x + neighbors[i].x;
            int newY = currentNode->point.y + neighbors[i].y;
            Point neighborPoint = {newX, newY};

            if (isValidMove(grid, newX, newY)) {
                float gScore = currentNode->g + 1;
                bool inOpenSet = false;
                
                for (int j = 0; j < openCount; j++) {
                    if (openSet[j]->point.x == newX && openSet[j]->point.y == newY) {
                        inOpenSet = true;
                        break;
                    }
                }

                if (!inOpenSet) {
                    Node* neighborNode = createNode(neighborPoint, gScore, heuristic(neighborPoint, end), currentNode);
                    openSet[openCount++] = neighborNode;
                }
            }
        }
        
        free(currentNode);
    }

    printf("No path found\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {'.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '.', '#', '#', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.', '#', 'E', '.', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
        {'.', '.', '.', 'S', '.', '.', '.', '.', '.', '.'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    };

    Point start = {3, 4};
    Point end = {7, 2};

    aStar(grid, start, end);
    return 0;
}