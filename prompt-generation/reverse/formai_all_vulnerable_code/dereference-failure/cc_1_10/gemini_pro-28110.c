//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node *parent;
} Node;

typedef struct PriorityQueue {
    Node *nodes[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue *createPriorityQueue() {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    return queue;
}

void insert(PriorityQueue *queue, Node *node) {
    queue->nodes[queue->size++] = node;
}

Node *pop(PriorityQueue *queue) {
    int minIndex = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i]->f < queue->nodes[minIndex]->f) {
            minIndex = i;
        }
    }
    Node *node = queue->nodes[minIndex];
    queue->nodes[minIndex] = queue->nodes[queue->size - 1];
    queue->size--;
    return node;
}

int isPriorityQueueEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

Node *createNode(int x, int y) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = INT_MAX;
    node->h = INT_MAX;
    node->f = INT_MAX;
    node->parent = NULL;
    return node;
}

int calculateG(Node *node, Node *parent) {
    return parent->g + 1;
}

int calculateH(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

int calculateF(Node *node) {
    return node->g + node->h;
}

Node *findPath(int **map, int mapWidth, int mapHeight, Node *start, Node *goal) {
    PriorityQueue *openSet = createPriorityQueue();
    insert(openSet, start);
    start->g = 0;
    start->h = calculateH(start, goal);
    start->f = calculateF(start);

    while (!isPriorityQueueEmpty(openSet)) {
        Node *current = pop(openSet);

        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = current->x + i;
                int y = current->y + j;

                if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight || map[x][y] == 1) {
                    continue;
                }

                Node *neighbor = createNode(x, y);
                neighbor->g = calculateG(neighbor, current);
                neighbor->h = calculateH(neighbor, goal);
                neighbor->f = calculateF(neighbor);
                neighbor->parent = current;

                if (neighbor->g >= current->g || neighbor->f >= current->f) {
                    continue;
                }

                insert(openSet, neighbor);
            }
        }
    }

    return NULL;
}

void printPath(Node *node) {
    if (node == NULL) {
        printf("No path found.\n");
        return;
    }

    while (node != NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
}

int main() {
    int mapWidth = 10;
    int mapHeight = 10;

    int **map = malloc(sizeof(int *) * mapHeight);
    for (int i = 0; i < mapHeight; i++) {
        map[i] = malloc(sizeof(int) * mapWidth);
    }

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            map[i][j] = 0;
        }
    }

    map[2][2] = 1;
    map[2][3] = 1;
    map[2][4] = 1;
    map[2][5] = 1;
    map[2][6] = 1;
    map[2][7] = 1;
    map[2][8] = 1;
    map[2][9] = 1;
    map[3][2] = 1;
    map[3][9] = 1;
    map[4][2] = 1;
    map[4][9] = 1;
    map[5][2] = 1;
    map[5][9] = 1;
    map[6][2] = 1;
    map[6][9] = 1;
    map[7][2] = 1;
    map[7][9] = 1;
    map[8][2] = 1;
    map[8][7] = 1;
    map[8][8] = 1;
    map[8][9] = 1;
    map[9][2] = 1;
    map[9][3] = 1;
    map[9][4] = 1;
    map[9][5] = 1;
    map[9][6] = 1;
    map[9][7] = 1;
    map[9][8] = 1;
    map[9][9] = 1;

    Node *start = createNode(0, 0);
    Node *goal = createNode(9, 9);
    Node *path = findPath(map, mapWidth, mapHeight, start, goal);
    printPath(path);

    for (int i = 0; i < mapHeight; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}