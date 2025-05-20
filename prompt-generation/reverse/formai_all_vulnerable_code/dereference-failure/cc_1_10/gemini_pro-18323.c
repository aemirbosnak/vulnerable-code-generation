//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ken Thompson
// a* pathfinding algorithm in ken thompson style

#include <stdlib.h>
#include <stdio.h>

#define FREE 0
#define WALL 1

typedef struct point {
    int x, y;
} point;

typedef struct node {
    point position;
    int g_score, f_score;
    struct node *parent;
} node;

typedef struct heap {
    node *nodes;
    int size, capacity;
} heap;

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->nodes[left].f_score < h->nodes[smallest].f_score) {
        smallest = left;
    }

    if (right < h->size && h->nodes[right].f_score < h->nodes[smallest].f_score) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->nodes[i], &h->nodes[smallest]);
        heapify(h, smallest);
    }
}

void push(heap *h, node *n) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->nodes = realloc(h->nodes, h->capacity * sizeof(node));
    }

    h->nodes[h->size] = *n;
    h->size++;

    int i = h->size - 1;
    while (i > 0 && h->nodes[i].f_score < h->nodes[(i - 1) / 2].f_score) {
        swap(&h->nodes[i], &h->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node pop(heap *h) {
    node n = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;

    heapify(h, 0);

    return n;
}

int manhattan_distance(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

node *find_path(point start, point end, int **grid, int width, int height) {
    heap open_set;
    open_set.capacity = 100;
    open_set.size = 0;
    open_set.nodes = malloc(open_set.capacity * sizeof(node));

    node **closed_set = malloc(width * height * sizeof(node *));

    for (int i = 0; i < width * height; i++) {
        closed_set[i] = NULL;
    }

    node *start_node = malloc(sizeof(node));
    start_node->position = start;
    start_node->g_score = 0;
    start_node->f_score = manhattan_distance(start, end);
    start_node->parent = NULL;

    push(&open_set, start_node);

    while (open_set.size > 0) {
        node *current_node = &open_set.nodes[0];
        pop(&open_set);

        if (current_node->position.x == end.x && current_node->position.y == end.y) {
            return current_node;
        }

        closed_set[current_node->position.x + current_node->position.y * width] = current_node;

        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int x = current_node->position.x + dx[i];
            int y = current_node->position.y + dy[i];

            if (x >= 0 && x < width && y >= 0 && y < height && grid[x][y] == FREE && closed_set[x + y * width] == NULL) {
                node *neighbor = malloc(sizeof(node));
                neighbor->position.x = x;
                neighbor->position.y = y;
                neighbor->g_score = current_node->g_score + 1;
                neighbor->f_score = neighbor->g_score + manhattan_distance(neighbor->position, end);
                neighbor->parent = current_node;

                push(&open_set, neighbor);
            }
        }
    }

    return NULL;
}

int main() {
    int grid[5][5] = {
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0 },
        { 1, 1, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
    };

    point start = { 0, 0 };
    point end = { 4, 4 };

    node *path = find_path(start, end, grid, 5, 5);

    if (path) {
        while (path) {
            printf("(%d, %d)\n", path->position.x, path->position.y);
            path = path->parent;
        }
    } else {
        printf("No path found.\n");
    }

    return 0;
}