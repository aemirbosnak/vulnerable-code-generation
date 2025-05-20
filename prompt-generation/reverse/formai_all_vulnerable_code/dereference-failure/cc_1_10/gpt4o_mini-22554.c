//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'
#define OPEN 'O'
#define CLOSED 'X'

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point point;
    int g; // Cost from start
    int h; // Heuristic cost to end
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->g = parent ? parent->g + 1 : 0;
    node->h = abs(x - (WIDTH - 1)) + abs(y - (HEIGHT - 1));
    node->parent = parent;
    return node;
}

void freeNode(Node* node) {
    free(node);
}

bool isValid(int x, int y, char grid[HEIGHT][WIDTH]) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && 
           (grid[y][x] == PATH || grid[y][x] == END);
}

void printGrid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        { PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH },
        { PATH, WALL, WALL, WALL, WALL, PATH, WALL, WALL, WALL, PATH },
        { PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH },
        { PATH, WALL, WALL, PATH, WALL, WALL, WALL, PATH, WALL, PATH },
        { PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH },
        { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH },
        { PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH },
        { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH },
        { PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, WALL, PATH },
        { PATH, WALL, WALL, WALL, WALL, WALL, PATH, END, PATH, PATH },
    };

    Point start = { 0, 0 };
    grid[start.y][start.x] = START;

    Node* openSet[WIDTH * HEIGHT];
    int openCount = 0;

    openSet[openCount++] = createNode(start.x, start.y, NULL);

    while (openCount > 0) {
        // Find the node in openSet with the smallest f (g + h)
        int indexOfBestNode = 0;
        for (int i = 1; i < openCount; i++) {
            if ((openSet[i]->g + openSet[i]->h) < (openSet[indexOfBestNode]->g + openSet[indexOfBestNode]->h)) {
                indexOfBestNode = i;
            }
        }

        Node* current = openSet[indexOfBestNode];

        // Check if we've reached the end
        if (current->point.x == WIDTH - 1 && current->point.y == HEIGHT - 1) {
            // Trace back the path
            Node* pathNode = current;
            while (pathNode != NULL) {
                if (grid[pathNode->point.y][pathNode->point.x] != START) {
                    grid[pathNode->point.y][pathNode->point.x] = OPEN;
                }
                pathNode = pathNode->parent;
            }
            grid[start.y][start.x] = START;
            grid[HEIGHT-1][WIDTH-1] = END;
            printGrid(grid);
            break;
        }

        // Remove current from openSet
        openCount--;
        openSet[indexOfBestNode] = openSet[openCount];

        // Expand neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                int neighborX = current->point.x + dx;
                int neighborY = current->point.y + dy;
                
                if (isValid(neighborX, neighborY, grid)) {
                    bool inOpenSet = false;
                    for (int i = 0; i < openCount; i++) {
                        if (openSet[i]->point.x == neighborX && openSet[i]->point.y == neighborY) {
                            inOpenSet = true;
                            break;
                        }
                    }
                    if (!inOpenSet) {
                        openSet[openCount++] = createNode(neighborX, neighborY, current);
                    }
                }
            }
        }
    }

    // Cleanup
    for (int i = 0; i < openCount; i++) {
        freeNode(openSet[i]);
    }
    
    return 0;
}