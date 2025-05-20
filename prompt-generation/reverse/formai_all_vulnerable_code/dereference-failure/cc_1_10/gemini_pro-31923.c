//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

enum {
    TILE_EMPTY,
    TILE_WALL,
    TILE_START,
    TILE_END
};

struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node *parent;
};

struct PriorityQueue {
    struct Node **nodes;
    int size;
    int capacity;
};

struct PriorityQueue *create_priority_queue(int capacity) {
    struct PriorityQueue *queue = malloc(sizeof(struct PriorityQueue));
    queue->nodes = malloc(sizeof(struct Node *) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void destroy_priority_queue(struct PriorityQueue *queue) {
    free(queue->nodes);
    free(queue);
}

void insert_priority_queue(struct PriorityQueue *queue, struct Node *node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->nodes = realloc(queue->nodes, sizeof(struct Node *) * queue->capacity);
    }
    queue->nodes[queue->size++] = node;
}

struct Node *pop_priority_queue(struct PriorityQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    int min_index = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i]->f < queue->nodes[min_index]->f) {
            min_index = i;
        }
    }

    struct Node *node = queue->nodes[min_index];
    queue->nodes[min_index] = queue->nodes[queue->size - 1];
    queue->size--;
    return node;
}

int is_valid_position(int x, int y) {
    return x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT;
}

int is_empty_tile(int x, int y, int **map) {
    return map[y][x] == TILE_EMPTY;
}

struct Node *create_node(int x, int y, int g, int h, struct Node *parent) {
    struct Node *node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

struct Node *find_path(int **map, int start_x, int start_y, int end_x, int end_y) {
    struct PriorityQueue *open_set = create_priority_queue(100);
    struct Node *start_node = create_node(start_x, start_y, 0, 0, NULL);
    insert_priority_queue(open_set, start_node);

    while (open_set->size > 0) {
        struct Node *current_node = pop_priority_queue(open_set);
        if (current_node->x == end_x && current_node->y == end_y) {
            return current_node;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int x = current_node->x + dx;
                int y = current_node->y + dy;

                if (!is_valid_position(x, y) || !is_empty_tile(x, y, map)) {
                    continue;
                }

                struct Node *neighbor_node = create_node(x, y, current_node->g + 1, 0, current_node);
                neighbor_node->h = abs(x - end_x) + abs(y - end_y);
                insert_priority_queue(open_set, neighbor_node);
            }
        }
    }

    return NULL;
}

void print_map(int **map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            switch (map[y][x]) {
                case TILE_EMPTY:
                    printf(" ");
                    break;
                case TILE_WALL:
                    printf("#");
                    break;
                case TILE_START:
                    printf("S");
                    break;
                case TILE_END:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a map
    int **map = malloc(sizeof(int *) * MAP_HEIGHT);
    for (int y = 0; y < MAP_HEIGHT; y++) {
        map[y] = malloc(sizeof(int) * MAP_WIDTH);
    }

    // Set the map to be empty
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = TILE_EMPTY;
        }
    }

    // Set the start and end positions
    int start_x = 0;
    int start_y = 0;
    int end_x = MAP_WIDTH - 1;
    int end_y = MAP_HEIGHT - 1;

    // Set some walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        map[y][0] = TILE_WALL;
        map[y][MAP_WIDTH - 1] = TILE_WALL;
    }
    for (int x = 0; x < MAP_WIDTH; x++) {
        map[0][x] = TILE_WALL;
        map[MAP_HEIGHT - 1][x] = TILE_WALL;
    }

    // Find the path
    struct Node *path = find_path(map, start_x, start_y, end_x, end_y);

    // Print the map with the path
    map[start_y][start_x] = TILE_START;
    map[end_y][end_x] = TILE_END;
    while (path != NULL) {
        map[path->y][path->x] = TILE_WALL;
        path = path->parent;
    }
    print_map(map);

    // Free the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        free(map[y]);
    }
    free(map);

    return 0;
}