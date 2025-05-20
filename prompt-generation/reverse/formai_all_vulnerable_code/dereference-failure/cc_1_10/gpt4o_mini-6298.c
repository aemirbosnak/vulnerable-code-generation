//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE ' '
#define START 'S'
#define GOAL 'G'

typedef struct Node {
    int x, y;
    float f, g, h;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->parent = parent;
    return newNode;
}

float heuristic(Node* a, Node* b) {
    return fabs(a->x - b->x) + fabs(a->y - b->y);
}

void printGrid(char grid[HEIGHT][WIDTH], Node* path[], int pathLength) {
    // Copy path to a grid to visualize
    char displayGrid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            displayGrid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < pathLength; i++) {
        displayGrid[path[i]->y][path[i]->x] = '*';
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", displayGrid[i][j]);
        }
        printf("\n");
    }
}

bool isInList(Node** list, int count, Node* node) {
    for (int i = 0; i < count; i++) {
        if (list[i]->x == node->x && list[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

Node** findPath(char grid[HEIGHT][WIDTH], Node* start, Node* goal, int* pathLength) {
    Node** openList = (Node**)malloc(sizeof(Node*) * WIDTH * HEIGHT);
    Node** closedList = (Node**)malloc(sizeof(Node*) * WIDTH * HEIGHT);
    int openCount = 0, closedCount = 0;

    openList[openCount++] = start;

    while (openCount > 0) {
        Node* current = openList[0];

        // Find node with lowest f in openList
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < current->f) {
                current = openList[i];
            }
        }

        if (current->x == goal->x && current->y == goal->y) {
            *pathLength = 0;
            Node** path = (Node**)malloc(sizeof(Node*) * WIDTH * HEIGHT);
            while (current) {
                path[(*pathLength)++] = current;
                current = current->parent;
            }
            free(openList);
            free(closedList);
            return path;
        }

        // Move current node from open to closed
        for (int i = 0; i < openCount; i++) {
            if (openList[i] == current) {
                openList[i] = openList[--openCount];
                break;
            }
        }
        closedList[closedCount++] = current;

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonal moves

                int newX = current->x + dx;
                int newY = current->y + dy;

                if (newX < 0 || newY < 0 || newX >= WIDTH || newY >= HEIGHT || 
                    grid[newY][newX] == OBSTACLE || isInList(closedList, closedCount, createNode(newX, newY, NULL))) {
                    continue;
                }

                Node* neighbor = createNode(newX, newY, current);
                neighbor->g = current->g + 1;
                neighbor->h = heuristic(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;

                if (!isInList(openList, openCount, neighbor)) {
                    openList[openCount++] = neighbor;
                } else {
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->x == neighbor->x && openList[i]->y == neighbor->y && 
                            openList[i]->g > neighbor->g) {
                            openList[i] = neighbor;
                            break;
                        }
                    }
                }
            }
        }
    }

    free(openList);
    free(closedList);
    return NULL;
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' '},
        {' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', '#', '#', '#', 'G', ' '}
    };

    Node* start = createNode(0, 0, NULL);
    Node* goal = createNode(9, 8, NULL);

    int pathLength;
    Node** path = findPath(grid, start, goal, &pathLength);

    if (path) {
        printGrid(grid, path, pathLength);
        for (int i = 0; i < pathLength; i++) {
            free(path[i]);
        }
        free(path);
    } else {
        printf("No path found.\n");
    }

    free(start);
    free(goal);
    return 0;
}