//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int x, y;
    struct node *parent;
    float g, h, f;
} node;

typedef struct heap {
    node **nodes;
    int size, capacity;
} heap;

heap *heap_init(int capacity) {
    heap *h = malloc(sizeof(heap));
    h->nodes = malloc(sizeof(node *) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heap_push(heap *h, node *n) {
    if (h->size >= h->capacity) {
        h->nodes = realloc(h->nodes, sizeof(node *) * h->capacity * 2);
        h->capacity *= 2;
    }
    h->nodes[h->size++] = n;
    int i = h->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->nodes[parent]->f > h->nodes[i]->f) {
            node *tmp = h->nodes[parent];
            h->nodes[parent] = h->nodes[i];
            h->nodes[i] = tmp;
            i = parent;
        } else {
            break;
        }
    }
}

node *heap_pop(heap *h) {
    if (h->size == 0) {
        return NULL;
    }
    node *n = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size && h->nodes[left]->f < h->nodes[smallest]->f) {
            smallest = left;
        }
        if (right < h->size && h->nodes[right]->f < h->nodes[smallest]->f) {
            smallest = right;
        }
        if (smallest != i) {
            node *tmp = h->nodes[i];
            h->nodes[i] = h->nodes[smallest];
            h->nodes[smallest] = tmp;
            i = smallest;
        } else {
            break;
        }
    }
    return n;
}

bool heap_empty(heap *h) {
    return h->size == 0;
}

node *a_star(int **grid, int width, int height, int start_x, int start_y, int end_x, int end_y) {
    heap *open_set = heap_init(width * height);
    bool *closed_set = malloc(sizeof(bool) * width * height);
    for (int i = 0; i < width * height; i++) {
        closed_set[i] = false;
    }
    node *start = malloc(sizeof(node));
    start->x = start_x;
    start->y = start_y;
    start->parent = NULL;
    start->g = 0;
    start->h = sqrt((end_x - start_x) * (end_x - start_x) + (end_y - start_y) * (end_y - start_y));
    start->f = start->g + start->h;
    heap_push(open_set, start);
    while (!heap_empty(open_set)) {
        node *current = heap_pop(open_set);
        if (current->x == end_x && current->y == end_y) {
            return current;
        }
        closed_set[current->x + current->y * width] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                if (x >= 0 && x < width && y >= 0 && y < height && !closed_set[x + y * width] && grid[x][y] != -1) {
                    node *neighbor = malloc(sizeof(node));
                    neighbor->x = x;
                    neighbor->y = y;
                    neighbor->parent = current;
                    neighbor->g = current->g + 1;
                    neighbor->h = sqrt((end_x - x) * (end_x - x) + (end_y - y) * (end_y - y));
                    neighbor->f = neighbor->g + neighbor->h;
                    heap_push(open_set, neighbor);
                }
            }
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    int width = 100, height = 100;
    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 10;
        }
    }
    int start_x = rand() % width, start_y = rand() % height;
    int end_x = rand() % width, end_y = rand() % height;
    node *path = a_star(grid, width, height, start_x, start_y, end_x, end_y);
    if (path == NULL) {
        printf("No path found.\n");
    } else {
        while (path != NULL) {
            printf("(%d, %d)\n", path->x, path->y);
            path = path->parent;
        }
    }
    return 0;
}