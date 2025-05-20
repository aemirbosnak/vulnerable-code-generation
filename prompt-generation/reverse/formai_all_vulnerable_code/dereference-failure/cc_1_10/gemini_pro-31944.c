//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int x, y;
    float g, h;
    struct Node* parent;
} Node;

typedef struct PriorityQueue {
    Node** nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->nodes = malloc(sizeof(Node*) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void destroyPriorityQueue(PriorityQueue* pq) {
    free(pq->nodes);
    free(pq);
}

void insertPriorityQueue(PriorityQueue* pq, Node* node) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->nodes = realloc(pq->nodes, sizeof(Node*) * pq->capacity);
    }
    pq->nodes[pq->size] = node;
    pq->size++;
}

Node* popPriorityQueue(PriorityQueue* pq) {
    if (pq->size == 0) {
        return NULL;
    }
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->nodes[i]->g + pq->nodes[i]->h < pq->nodes[minIndex]->g + pq->nodes[minIndex]->h) {
            minIndex = i;
        }
    }
    Node* node = pq->nodes[minIndex];
    pq->nodes[minIndex] = pq->nodes[pq->size - 1];
    pq->size--;
    return node;
}

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

void destroyNode(Node* node) {
    free(node);
}

int** createMap(int width, int height) {
    int** map = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(int) * width);
    }
    return map;
}

void destroyMap(int** map, int height) {
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

int main() {
    int width = 10;
    int height = 10;
    int** map = createMap(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = 0;
        }
    }

    map[0][0] = 1;
    map[0][2] = 1;
    map[0][4] = 1;
    map[0][6] = 1;
    map[0][8] = 1;
    map[1][1] = 1;
    map[1][3] = 1;
    map[1][5] = 1;
    map[1][7] = 1;
    map[1][9] = 1;
    map[2][0] = 1;
    map[2][2] = 1;
    map[2][4] = 1;
    map[2][6] = 1;
    map[2][8] = 1;
    map[3][1] = 1;
    map[3][3] = 1;
    map[3][5] = 1;
    map[3][7] = 1;
    map[3][9] = 1;
    map[4][0] = 1;
    map[4][2] = 1;
    map[4][4] = 1;
    map[4][6] = 1;
    map[4][8] = 1;
    map[5][1] = 1;
    map[5][3] = 1;
    map[5][5] = 1;
    map[5][7] = 1;
    map[5][9] = 1;
    map[6][0] = 1;
    map[6][2] = 1;
    map[6][4] = 1;
    map[6][6] = 1;
    map[6][8] = 1;
    map[7][1] = 1;
    map[7][3] = 1;
    map[7][5] = 1;
    map[7][7] = 1;
    map[7][9] = 1;
    map[8][0] = 1;
    map[8][2] = 1;
    map[8][4] = 1;
    map[8][6] = 1;
    map[8][8] = 1;
    map[9][1] = 1;
    map[9][3] = 1;
    map[9][5] = 1;
    map[9][7] = 1;
    map[9][9] = 1;

    Node* start = createNode(0, 0);
    Node* end = createNode(9, 9);

    PriorityQueue* pq = createPriorityQueue(100);

    insertPriorityQueue(pq, start);

    while (pq->size > 0) {
        Node* node = popPriorityQueue(pq);

        if (node->x == end->x && node->y == end->y) {
            break;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (node->x + i >= 0 && node->x + i < width && node->y + j >= 0 && node->y + j < height && map[node->x + i][node->y + j] == 0) {
                    Node* neighbor = createNode(node->x + i, node->y + j);
                    neighbor->g = node->g + 1;
                    neighbor->h = sqrt(pow(end->x - neighbor->x, 2) + pow(end->y - neighbor->y, 2));
                    neighbor->parent = node;
                    insertPriorityQueue(pq, neighbor);
                }
            }
        }
    }

    Node* current = end;
    while (current != NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }

    destroyPriorityQueue(pq);
    destroyNode(start);
    destroyNode(end);
    destroyMap(map, height);

    return 0;
}