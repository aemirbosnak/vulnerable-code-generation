//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
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
#define PATH '*'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    float gCost, hCost;
    float fCost;
    struct Node* parent;
} Node;

Node* openSet[WIDTH * HEIGHT];
int openSetSize = 0;

char grid[HEIGHT][WIDTH] = {
    {'.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '#', '.', '#', '#', '#', '.', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'.', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '#', '#', '#', '#', '#', 'E', '.', '.'},
};

void addOpenSet(Node* node) {
    openSet[openSetSize++] = node;
}

bool containsPoint(Point p) {
    for (int i = 0; i < openSetSize; i++) {
        if (openSet[i]->point.x == p.x && openSet[i]->point.y == p.y) {
            return true;
        }
    }
    return false;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isWalkable(Point p) {
    if (p.x < 0 || p.x >= WIDTH || p.y < 0 || p.y >= HEIGHT) return false;
    return grid[p.y][p.x] != OBSTACLE;
}

Node* createNode(Point point, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->point = point;
    node->parent = parent;
    node->gCost = parent ? parent->gCost + 1 : 0;
    node->hCost = heuristic(point, (Point){WIDTH-1, HEIGHT-1});
    node->fCost = node->gCost + node->hCost;
    return node;
}

void createPath(Node* node) {
    while (node) {
        grid[node->point.y][node->point.x] = PATH;
        node = node->parent;
    }
}

void findPath() {
    Point start = {0, 0};
    Point end = {7, 9};
    addOpenSet(createNode(start, NULL));

    while (openSetSize > 0) {
        Node* current = openSet[0];
        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i]->fCost < current->fCost) {
                current = openSet[i];
            }
        }

        if (current->point.x == end.x && current->point.y == end.y) {
            createPath(current);
            return;
        }

        for (int i = 0; i < openSetSize; i++) {
            if (openSet[i] == current) {
                openSet[i] = openSet[--openSetSize];
                break;
            }
        }

        Point directions[] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (int d = 0; d < 4; d++) {
            Point neighbor = {current->point.x + directions[d].x, current->point.y + directions[d].y};

            if (isWalkable(neighbor) && !containsPoint(neighbor)) {
                addOpenSet(createNode(neighbor, current));
            }
        }
    }
    printf("No path found!\n");
}

void printGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

int main() {
    grid[0][0] = START;
    grid[HEIGHT-1][WIDTH-1] = END;
    findPath();
    printGrid();
    return 0;
}