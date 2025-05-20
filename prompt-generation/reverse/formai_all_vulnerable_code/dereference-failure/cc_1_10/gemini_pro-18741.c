//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEURISTIC(x1, y1, x2, y2) (fabs(x1 - x2) + fabs(y1 - y2))

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g, h, f;
} Node;

typedef struct {
    Node *nodes;
    int size, capacity;
} PriorityQueue;

void init_priority_queue(PriorityQueue *pq, int capacity) {
    pq->nodes = malloc(sizeof(Node) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
}

void destroy_priority_queue(PriorityQueue *pq) {
    free(pq->nodes);
}

void insert_priority_queue(PriorityQueue *pq, Node *node) {
    int i;
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->nodes = realloc(pq->nodes, sizeof(Node) * pq->capacity);
    }
    for (i = pq->size - 1; i >= 0; i--) {
        if (pq->nodes[i].f > node->f) {
            pq->nodes[i + 1] = pq->nodes[i];
        } else {
            break;
        }
    }
    pq->nodes[i + 1] = *node;
    pq->size++;
}

Node *remove_priority_queue(PriorityQueue *pq) {
    if (pq->size == 0) {
        return NULL;
    }
    pq->size--;
    return &pq->nodes[pq->size];
}

int is_in_priority_queue(PriorityQueue *pq, Node *node) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (pq->nodes[i].point.x == node->point.x && pq->nodes[i].point.y == node->point.y) {
            return 1;
        }
    }
    return 0;
}

int a_star(Point start, Point end, char **map, int width, int height) {
    PriorityQueue open, closed;
    Node *current, *neighbor;
    int i, j, g, h, f;
    init_priority_queue(&open, 1000);
    init_priority_queue(&closed, 1000);
    current = malloc(sizeof(Node));
    current->point = start;
    current->g = 0;
    current->h = HEURISTIC(current->point.x, current->point.y, end.x, end.y);
    current->f = current->g + current->h;
    insert_priority_queue(&open, current);
    while (open.size > 0) {
        current = remove_priority_queue(&open);
        if (current->point.x == end.x && current->point.y == end.y) {
            return current->g;
        }
        insert_priority_queue(&closed, current);
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                neighbor = malloc(sizeof(Node));
                neighbor->point.x = current->point.x + i;
                neighbor->point.y = current->point.y + j;
                if (neighbor->point.x >= 0 && neighbor->point.x < width && neighbor->point.y >= 0 && neighbor->point.y < height && map[neighbor->point.x][neighbor->point.y] != '1' && !is_in_priority_queue(&closed, neighbor)) {
                    g = current->g + 1;
                    h = HEURISTIC(neighbor->point.x, neighbor->point.y, end.x, end.y);
                    f = g + h;
                    if (!is_in_priority_queue(&open, neighbor) || f < neighbor->f) {
                        neighbor->g = g;
                        neighbor->h = h;
                        neighbor->f = f;
                        insert_priority_queue(&open, neighbor);
                    } else {
                        free(neighbor);
                    }
                } else {
                    free(neighbor);
                }
            }
        }
    }
    destroy_priority_queue(&open);
    destroy_priority_queue(&closed);
    return -1;
}

int main() {
    char map[10][10] = {
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
    };
    Point start = {0, 0};
    Point end = {9, 9};
    int path_length = a_star(start, end, map, 10, 10);
    if (path_length == -1) {
        printf("No path found.\n");
    } else {
        printf("Path length: %d\n", path_length);
    }
    return 0;
}