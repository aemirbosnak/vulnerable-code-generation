//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    float g, h, f;
    point position;
} node;

bool inList(node *list, int size, point point) {
    for (int i = 0; i < size; i++) {
        if (list[i].position.x == point.x && list[i].position.y == point.y) {
            return true;
        }
    }

    return false;
}

int heuristic(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int min(int a, int b) {
    return a < b ? a : b;
}

void swap(node *a, node *b) {
    node temp = *a;
    *a = *b;
    *b = temp;
}

node *sortList(node *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].f > list[j + 1].f) {
                swap(&list[j], &list[j + 1]);
            }
        }
    }

    return list;
}

node *getNeighbors(point current, int width, int height, int **grid) {
    node *neighbors = malloc(8 * sizeof(node));
    int index = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            point neighbor = {current.x + i, current.y + j};

            if (neighbor.x >= 0 && neighbor.x < width && neighbor.y >= 0 && neighbor.y < height && grid[neighbor.y][neighbor.x] != 1) {
                neighbors[index] = (node) {0.0, 0.0, 0.0, neighbor};
                index++;
            }
        }
    }

    return neighbors;
}

node *initList(point start, point end, int width, int height, int **grid) {
    node *list = malloc(width * height * sizeof(node));
    int index = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            list[index] = (node) {0.0, 0.0, 0.0, {x, y}};

            if (start.x == x && start.y == y) {
                list[index].g = 0;
                list[index].h = heuristic(start, end);
                list[index].f = list[index].g + list[index].h;
            } else if (grid[y][x] == 1) {
                list[index].g = INT_MAX;
                list[index].h = INT_MAX;
                list[index].f = INT_MAX;
            }

            index++;
        }
    }

    return list;
}

node *findPath(point start, point end, int width, int height, int **grid) {
    node *openList = initList(start, end, width, height, grid);
    node *closedList = malloc(width * height * sizeof(node));
    int closedListSize = 0;

    while (!inList(openList, width * height, end)) {
        openList = sortList(openList, width * height);

        node current = openList[0];

        closedList[closedListSize] = current;
        closedListSize++;

        for (node *neighbors = getNeighbors(current.position, width, height, grid); neighbors; neighbors++) {
            if (!inList(closedList, closedListSize, neighbors->position)) {
                float tentative_gScore = current.g + 1;

                if (!inList(openList, width * height, neighbors->position) || tentative_gScore < openList[inList(openList, width * height, neighbors->position)].g) {
                    neighbors->g = tentative_gScore;
                    neighbors->h = heuristic(neighbors->position, end);
                    neighbors->f = neighbors->g + neighbors->h;

                    if (!inList(openList, width * height, neighbors->position)) {
                        openList[width * height] = *neighbors;
                    }
                }
            }
        }
    }

    return &closedList[closedListSize - 1];
}

void printPath(node *path, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (path->position.x == x && path->position.y == y) {
                printf("%c", 'S');
            } else if (inList(path, width * height, (point) {x, y})) {
                printf("%c", 'P');
            } else {
                printf("%c", ' ');
            }
        }

        printf("\n");
    }
}

int main() {
    int width = 10, height = 10;
    int grid[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    point start = {0, 0};
    point end = {9, 9};

    node *path = findPath(start, end, width, height, grid);

    printf("Path found:\n");
    printPath(path, width, height);

    return 0;
}