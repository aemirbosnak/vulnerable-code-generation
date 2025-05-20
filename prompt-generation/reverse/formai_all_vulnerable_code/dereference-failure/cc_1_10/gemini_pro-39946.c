//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int x, y;
} pos_t;

typedef struct {
    pos_t pos;
    int g, h, f;
} node_t;

typedef struct {
    node_t **nodes;
    int size;
} open_set_t;

typedef struct {
    int **map;
    int width, height;
} map_t;

open_set_t *open_set_init(int size) {
    open_set_t *set = malloc(sizeof(open_set_t));
    set->size = size;
    set->nodes = malloc(sizeof(node_t *) * size);
    return set;
}

void open_set_free(open_set_t *set) {
    for (int i = 0; i < set->size; i++) {
        free(set->nodes[i]);
    }
    free(set->nodes);
    free(set);
}

int open_set_add(open_set_t *set, node_t *node) {
    if (set->size == 0) {
        return -1;
    }

    int index = 0;
    while (index < set->size && set->nodes[index]->f < node->f) {
        index++;
    }

    if (index == set->size) {
        return -1;
    }

    for (int i = set->size - 1; i > index; i--) {
        set->nodes[i] = set->nodes[i - 1];
    }

    set->nodes[index] = node;
    return 0;
}

node_t *open_set_pop(open_set_t *set) {
    if (set->size == 0) {
        return NULL;
    }

    node_t *node = set->nodes[0];

    for (int i = 1; i < set->size; i++) {
        set->nodes[i - 1] = set->nodes[i];
    }

    set->size--;

    return node;
}

map_t *map_init(int width, int height) {
    map_t *map = malloc(sizeof(map_t));
    map->width = width;
    map->height = height;
    map->map = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        map->map[i] = malloc(sizeof(int) * width);
    }
    return map;
}

void map_free(map_t *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->map[i]);
    }
    free(map->map);
    free(map);
}

int map_get(map_t *map, pos_t pos) {
    if (pos.x < 0 || pos.x >= map->width || pos.y < 0 || pos.y >= map->height) {
        return -1;
    }
    return map->map[pos.y][pos.x];
}

void map_set(map_t *map, pos_t pos, int value) {
    if (pos.x < 0 || pos.x >= map->width || pos.y < 0 || pos.y >= map->height) {
        return;
    }
    map->map[pos.y][pos.x] = value;
}

int heuristic(pos_t start, pos_t end) {
    int dx = abs(start.x - end.x);
    int dy = abs(start.y - end.y);
    return dx + dy;
}

int astar(map_t *map, pos_t start, pos_t end) {
    open_set_t *open_set = open_set_init(MAX_SIZE);
    node_t *start_node = malloc(sizeof(node_t));
    start_node->pos = start;
    start_node->g = 0;
    start_node->h = heuristic(start, end);
    start_node->f = start_node->g + start_node->h;
    open_set_add(open_set, start_node);

    while (open_set->size > 0) {
        node_t *current_node = open_set_pop(open_set);

        if (current_node->pos.x == end.x && current_node->pos.y == end.y) {
            open_set_free(open_set);
            return current_node->g;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                pos_t next_pos = {current_node->pos.x + i, current_node->pos.y + j};
                int next_g = current_node->g + 1;
                int next_h = heuristic(next_pos, end);
                int next_f = next_g + next_h;

                if (map_get(map, next_pos) == -1) {
                    continue;
                }

                node_t *next_node = malloc(sizeof(node_t));
                next_node->pos = next_pos;
                next_node->g = next_g;
                next_node->h = next_h;
                next_node->f = next_f;

                open_set_add(open_set, next_node);
            }
        }

        free(current_node);
    }

    open_set_free(open_set);
    return -1;
}

int main() {
    map_t *map = map_init(10, 10);

    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            map_set(map, (pos_t){i, j}, 0);
        }
    }

    map_set(map, (pos_t){1, 2}, -1);
    map_set(map, (pos_t){2, 5}, -1);
    map_set(map, (pos_t){4, 5}, -1);

    int result = astar(map, (pos_t){0, 0}, (pos_t){9, 9});

    if (result == -1) {
        printf("No path found.\n");
    } else {
        printf("Path found with cost %d.\n", result);
    }

    map_free(map);

    return 0;
}