//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_X 100
#define MAX_Y 100

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t point;
    int g;
    int h;
    int f;
} node_t;

typedef struct {
    node_t *nodes;
    int size;
    int capacity;
} heap_t;

heap_t *heap_create(int capacity) {
    heap_t *heap = malloc(sizeof(heap_t));
    heap->nodes = malloc(sizeof(node_t) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_destroy(heap_t *heap) {
    free(heap->nodes);
    free(heap);
}

void heap_insert(heap_t *heap, node_t *node) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->nodes = realloc(heap->nodes, sizeof(node_t) * heap->capacity);
    }

    int i = heap->size++;
    while (i > 0 && heap->nodes[(i - 1) / 2].f > node->f) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->nodes[i] = *node;
}

node_t *heap_pop(heap_t *heap) {
    if (heap->size == 0) {
        return NULL;
    }

    node_t *node = &heap->nodes[0];

    heap->nodes[0] = heap->nodes[--heap->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left >= heap->size) {
            break;
        }

        int min = left;

        if (right < heap->size && heap->nodes[right].f < heap->nodes[left].f) {
            min = right;
        }

        if (heap->nodes[i].f <= heap->nodes[min].f) {
            break;
        }

        node_t temp = heap->nodes[i];
        heap->nodes[i] = heap->nodes[min];
        heap->nodes[min] = temp;

        i = min;
    }

    return node;
}

int manhattan_distance(point_t a, point_t b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int a_star(point_t start, point_t goal, int **map, int width, int height) {
    heap_t *open_set = heap_create(width * height);
    int **closed_set = malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        closed_set[i] = malloc(sizeof(int) * height);
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            closed_set[i][j] = 0;
        }
    }

    node_t start_node = {
        .point = start,
        .g = 0,
        .h = manhattan_distance(start, goal),
        .f = start_node.g + start_node.h
    };

    heap_insert(open_set, &start_node);

    while (open_set->size > 0) {
        node_t *current_node = heap_pop(open_set);

        if (current_node->point.x == goal.x && current_node->point.y == goal.y) {
            heap_destroy(open_set);
            for (int i = 0; i < width; i++) {
                free(closed_set[i]);
            }
            free(closed_set);
            return current_node->g;
        }

        closed_set[current_node->point.x][current_node->point.y] = 1;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                point_t neighbor = {
                    .x = current_node->point.x + i,
                    .y = current_node->point.y + j
                };

                if (neighbor.x < 0 || neighbor.x >= width || neighbor.y < 0 || neighbor.y >= height) {
                    continue;
                }

                if (closed_set[neighbor.x][neighbor.y] || map[neighbor.x][neighbor.y] == 1) {
                    continue;
                }

                int g = current_node->g + 1;
                int h = manhattan_distance(neighbor, goal);
                int f = g + h;

                node_t neighbor_node = {
                    .point = neighbor,
                    .g = g,
                    .h = h,
                    .f = f
                };

                heap_insert(open_set, &neighbor_node);
            }
        }
    }

    heap_destroy(open_set);
    for (int i = 0; i < width; i++) {
        free(closed_set[i]);
    }
    free(closed_set);

    return -1;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <width> <height> <map>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    int **map = malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        map[i] = malloc(sizeof(int) * height);
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fscanf(stdin, "%d", &map[i][j]);
        }
    }

    point_t start = {
        .x = 0,
        .y = 0
    };

    point_t goal = {
        .x = width - 1,
        .y = height - 1
    };

    int result = a_star(start, goal, map, width, height);

    if (result != -1) {
        printf("Path found:\n");
        for (int i = 0; i < result; i++) {
            printf("(%d, %d)\n", start.x, start.y);
            if (start.x != goal.x) {
                start.x += (goal.x - start.x) / abs(goal.x - start.x);
            }
            if (start.y != goal.y) {
                start.y += (goal.y - start.y) / abs(goal.y - start.y);
            }
        }
    } else {
        printf("Path not found.\n");
    }

    for (int i = 0; i < width; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}