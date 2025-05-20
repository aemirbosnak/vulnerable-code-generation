//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define EMPTY '.'
#define START 'S'
#define END 'E'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g; // Cost from start to current node
    int h; // Heuristic cost from current node to end
    int f; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int x, int y, char grid[HEIGHT][WIDTH]) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE;
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("-> (%d, %d) ", node->point.x, node->point.y);
}

void aStar(char grid[HEIGHT][WIDTH], Point start, Point end) {
    bool closedList[HEIGHT][WIDTH] = { false };
    Node* openList[WIDTH * HEIGHT];
    int openListSize = 0;

    Node* startNode = createNode(start.x, start.y, 0, heuristic(start, end), NULL);
    openList[openListSize++] = startNode;

    while (openListSize > 0) {
        int currentIndex = -1;
        for (int i = 0; i < openListSize; i++) {
            if (currentIndex == -1 || openList[i]->f < openList[currentIndex]->f) {
                currentIndex = i;
            }
        }

        Node* currentNode = openList[currentIndex];

        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        openList[currentIndex] = openList[--openListSize];
        closedList[currentNode->point.y][currentNode->point.x] = true;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) { // Only consider direct neighbors
                    int newX = currentNode->point.x + dx;
                    int newY = currentNode->point.y + dy;

                    if (isValid(newX, newY, grid) && !closedList[newY][newX]) {
                        int newG = currentNode->g + 1;
                        Node* neighborNode = createNode(newX, newY, newG, heuristic((Point){newX, newY}, end), currentNode);
                        
                        bool foundInOpen = false;
                        for (int i = 0; i < openListSize; i++) {
                            if (openList[i]->point.x == neighborNode->point.x && openList[i]->point.y == neighborNode->point.y) {
                                foundInOpen = true;
                                if (neighborNode->g < openList[i]->g) {
                                    openList[i]->g = neighborNode->g;
                                    openList[i]->f = neighborNode->f;
                                    openList[i]->parent = currentNode;
                                }
                                break;
                            }
                        }
                        if (!foundInOpen) {
                            openList[openListSize++] = neighborNode;
                        } else {
                            free(neighborNode);
                        }
                    }
                }
            }
        }
        free(currentNode); // Free the memory of the current node since we no longer use it
    }
    printf("No path found.\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '#', '#', '#', '#', '#', '#', '#', '#', '.' },
        { '.', '#', '.', '.', '.', '.', '.', '.', '#', '.' },
        { '.', '#', '.', '#', '#', '#', '#', '.', '#', '.' },
        { '.', '#', '.', '.', '.', '.', '.', '.', '#', '.' },
        { '.', '#', '#', '#', '#', '#', '#', '.', '#', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '#', '.' },
        { '#', '#', '#', '#', '#', '#', '#', '.', '#', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '#', '#', '#', '#', '#', '#', '#', 'E', '.' }
    };

    Point start = {0, 0}; // Starting Point
    Point end = {8, 9};   // Ending Point

    grid[start.y][start.x] = START; // Marking start point
    grid[end.y][end.x] = END;        // Marking end point

    aStar(grid, start, end);

    return 0;
}