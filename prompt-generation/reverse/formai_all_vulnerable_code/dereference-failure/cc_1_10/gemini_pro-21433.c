//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Node {
    int x, y, g, h, f;  // x, y: coordinates, g: g-score, h: h-score, f: f-score
    struct Node *parent;
};

struct PQ {
    struct Node **nodes;
    int size, capacity;
};

struct Node *createNode(int x, int y) {
    struct Node *node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = NULL;
    return node;
}

struct PQ *createPQ(int capacity) {
    struct PQ *pq = malloc(sizeof(struct PQ));
    pq->nodes = malloc(capacity * sizeof(struct Node *));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void push(struct PQ *pq, struct Node *node) {
    pq->nodes[pq->size++] = node;
}

struct Node *pop(struct PQ *pq) {
    if (pq->size == 0) {
        return NULL;
    }
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->nodes[i]->f < pq->nodes[minIndex]->f) {
            minIndex = i;
        }
    }
    struct Node *node = pq->nodes[minIndex];
    pq->nodes[minIndex] = pq->nodes[--pq->size];
    return node;
}

void update(struct PQ *pq, struct Node *node) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->nodes[i] == node) {
            pq->nodes[i] = node;
            break;
        }
    }
}

struct Node **getNeighbors(int x, int y, int **map, int rows, int cols) {
    struct Node **neighbors = malloc(4 * sizeof(struct Node *));  // Up, right, down, left
    int index = 0;
    if (x > 0 && map[x - 1][y] != 0) {  // Up
        neighbors[index++] = createNode(x - 1, y);
    }
    if (y < cols - 1 && map[x][y + 1] != 0) {  // Right
        neighbors[index++] = createNode(x, y + 1);
    }
    if (x < rows - 1 && map[x + 1][y] != 0) {  // Down
        neighbors[index++] = createNode(x + 1, y);
    }
    if (y > 0 && map[x][y - 1] != 0) {  // Left
        neighbors[index++] = createNode(x, y - 1);
    }
    return neighbors;
}

int calculateH(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);  // Manhattan distance
}

struct Node *aStar(int **map, int rows, int cols, int startX, int startY, int endX, int endY) {
    struct Node *startNode = createNode(startX, startY);
    struct Node *endNode = createNode(endX, endY);
    struct PQ *pq = createPQ(rows * cols);
    push(pq, startNode);
    while (pq->size > 0) {
        struct Node *node = pop(pq);
        if (node->x == endX && node->y == endY) {
            return node;
        }
        struct Node **neighbors = getNeighbors(node->x, node->y, map, rows, cols);
        for (int i = 0; i < 4; i++) {
            if (neighbors[i] != NULL) {
                int g = node->g + 1;
                int h = calculateH(neighbors[i]->x, neighbors[i]->y, endX, endY);
                int f = g + h;
                if (neighbors[i]->g > g || neighbors[i]->g == 0) {
                    neighbors[i]->g = g;
                    neighbors[i]->h = h;
                    neighbors[i]->f = f;
                    neighbors[i]->parent = node;
                    update(pq, neighbors[i]);
                }
            }
        }
        free(neighbors);
    }
    return NULL;
}

void printPath(struct Node *node) {
    while (node != NULL) {
        printf("(%d, %d) -> ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

int main() {
    // Map representation: 0 - obstacle, 1 - free space
    int map[][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int rows = 10;
    int cols = 10;
    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;
    struct Node *pathNode = aStar(map, rows, cols, startX, startY, endX, endY);
    if (pathNode != NULL) {
        printPath(pathNode);
    } else {
        printf("No path found.\n");
    }
    return 0;
}