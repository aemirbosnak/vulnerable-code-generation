//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE '.'

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point point;
    int g; // cost from start
    int h; // heuristic
    int f; // total cost (g + h)
    struct Node* parent;
} Node;

char grid[HEIGHT][WIDTH] = {
    {'.', '.', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '#', '.', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '.', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'}
};

void printGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point point) {
    return (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT && grid[point.y][point.x] != OBSTACLE);
}

Node* createNode(Point point, int g, int h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point = point;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
}

void reconstructPath(Node* node) {
    if (node == NULL) {
        return;
    }
    reconstructPath(node->parent);
    printf("(%d, %d) ", node->point.x, node->point.y);
}

Node** createNodeList(int capacity) {
    Node** nodes = (Node**)malloc(capacity * sizeof(Node*));
    for (int i = 0; i < capacity; i++) {
        nodes[i] = NULL;
    }
    return nodes;
}

void freeNodeList(Node** nodes, int capacity) {
    for (int i = 0; i < capacity; i++) {
        freeNode(nodes[i]);
    }
    free(nodes);
}

bool findPath(Point start, Point goal) {
    int openCapacity = WIDTH * HEIGHT;
    Node** openList = createNodeList(openCapacity);
    int openCount = 0;

    Node* startNode = createNode(start, 0, heuristic(start, goal), NULL);
    openList[openCount++] = startNode;

    while (openCount > 0) {
        Node* currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            printf("\n");
            freeNodeList(openList, openCapacity);
            return true;
        }

        openCount--;
        for (int i = currentIndex; i < openCount; i++) {
            openList[i] = openList[i + 1];
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue; // Skip diagonal movements
                Point neighbor = {currentNode->point.x + dx, currentNode->point.y + dy};

                if (!isValid(neighbor)) continue;

                int tentativeG = currentNode->g + 1;

                bool inOpen = false;
                for (int i = 0; i < openCount; i++) {
                    if (openList[i]->point.x == neighbor.x && openList[i]->point.y == neighbor.y) {
                        inOpen = true;
                        if (tentativeG < openList[i]->g) {
                            openList[i]->g = tentativeG;
                            openList[i]->f = tentativeG + heuristic(neighbor, goal);
                            openList[i]->parent = currentNode;
                        }
                        break;
                    }
                }

                if (!inOpen) {
                    Node* neighborNode = createNode(neighbor, tentativeG, heuristic(neighbor, goal), currentNode);
                    openList[openCount++] = neighborNode;
                }
            }
        }
    }

    printf("No path found\n");
    freeNodeList(openList, openCapacity);
    return false;
}

int main() {
    printf("Initial Grid:\n");
    printGrid();
    
    Point start = {0, 0};
    Point goal = {9, 9};

    findPath(start, goal);
    
    return 0;
}