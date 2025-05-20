//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node *parent;
} Node;

typedef struct Heap {
    int size;
    Node **nodes;
} Heap;

Heap *heap_create(void) {
    Heap *heap = malloc(sizeof(Heap));
    heap->size = 0;
    heap->nodes = malloc(sizeof(Node *) * 1024);
    return heap;
}

void heap_push(Heap *heap, Node *node) {
    heap->nodes[heap->size] = node;
    heap->size++;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->nodes[i]->f < heap->nodes[parent]->f) {
            Node *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[parent];
            heap->nodes[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

Node *heap_pop(Heap *heap) {
    Node *node = heap->nodes[0];
    heap->size--;
    heap->nodes[0] = heap->nodes[heap->size];
    int i = 0;
    while (i < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->nodes[left]->f < heap->nodes[smallest]->f) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right]->f < heap->nodes[smallest]->f) {
            smallest = right;
        }
        if (smallest != i) {
            Node *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[smallest];
            heap->nodes[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return node;
}

bool heap_empty(Heap *heap) {
    return heap->size == 0;
}

Node *node_create(int x, int y, int g, int h, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

Node **grid_create(int width, int height) {
    Node **grid = malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i + j * width] = node_create(i, j, INF, 0, NULL);
        }
    }
    return grid;
}

void grid_destroy(Node **grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            free(grid[i + j * width]);
        }
    }
    free(grid);
}

void a_star(Node **grid, int width, int height, int start_x, int start_y, int end_x, int end_y) {
    Heap *open = heap_create();
    heap_push(open, grid[start_x + start_y * width]);
    while (!heap_empty(open)) {
        Node *current = heap_pop(open);
        if (current->x == end_x && current->y == end_y) {
            break;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                if (x >= 0 && x < width && y >= 0 && y < height) {
                    Node *neighbor = grid[x + y * width];
                    int g = current->g + 1;
                    int h = manhattan_distance(x, y, end_x, end_y);
                    int f = g + h;
                    if (f < neighbor->f) {
                        neighbor->g = g;
                        neighbor->h = h;
                        neighbor->f = f;
                        neighbor->parent = current;
                        if (!neighbor->h) {
                            heap_push(open, neighbor);
                        }
                    }
                }
            }
        }
    }
    if (grid[end_x + end_y * width]->f != INF) {
        Node *node = grid[end_x + end_y * width];
        while (node) {
            printf("(%d, %d)\n", node->x, node->y);
            node = node->parent;
        }
    }
}

int main(void) {
    Node **grid = grid_create(10, 10);
    a_star(grid, 10, 10, 0, 0, 9, 9);
    grid_destroy(grid, 10, 10);
    return 0;
}