//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/* Node structure */
typedef struct node_t {
    int x, y;
    int f, g, h;
    struct node_t* parent;
} node_t;

/* Open list */
typedef struct open_list_t {
    int count;
    node_t* nodes[MAX_ROWS * MAX_COLS];
} open_list_t;

/* Closed list */
typedef struct closed_list_t {
    int count;
    node_t* nodes[MAX_ROWS * MAX_COLS];
} closed_list_t;

/* Map */
int map[MAX_ROWS][MAX_COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/* Start and end nodes */
node_t* start_node = NULL;
node_t* end_node = NULL;

/* Function prototypes */
int calculate_h(node_t* node);
void calculate_path();
void add_to_open_list(open_list_t* open_list, node_t* node);
void add_to_closed_list(closed_list_t* closed_list, node_t* node);
void remove_from_open_list(open_list_t* open_list, node_t* node);
node_t* get_next_node(open_list_t* open_list);
int is_valid_node(int x, int y);
int is_walkable(int x, int y);
void print_map();
void print_path(node_t* node);

/* Main function */
int main() {
    /* Initialize start and end nodes */
    start_node = (node_t*) malloc(sizeof(node_t));
    start_node->x = 0;
    start_node->y = 0;
    start_node->f = 0;
    start_node->g = 0;
    start_node->h = calculate_h(start_node);
    start_node->parent = NULL;

    end_node = (node_t*) malloc(sizeof(node_t));
    end_node->x = 7;
    end_node->y = 9;
    end_node->f = 0;
    end_node->g = 0;
    end_node->h = calculate_h(end_node);
    end_node->parent = NULL;

    /* Calculate path */
    calculate_path();

    /* Print map and path */
    printf("Map:\n");
    print_map();

    printf("\nPath:\n");
    print_path(end_node);

    /* Free memory */
    free(start_node);
    free(end_node);

    return 0;
}

/* Calculate heuristic value */
int calculate_h(node_t* node) {
    return abs(node->x - end_node->x) + abs(node->y - end_node->y);
}

/* Calculate path */
void calculate_path() {
    open_list_t open_list = {0};
    closed_list_t closed_list = {0};
    node_t* current_node = NULL;
    node_t* neighbor_node = NULL;
    int i;

    /* Add start node to open list */
    add_to_open_list(&open_list, start_node);

    /* Loop until open list is empty or end node is found */
    while (open_list.count > 0) {
        /* Get node with lowest f value */
        current_node = get_next_node(&open_list);

        /* If current node is end node, exit loop */
        if (current_node == end_node) {
            break;
        }

        /* Move current node to closed list */
        add_to_closed_list(&closed_list, current_node);

        /* Add neighbors to open list */
        for (i = -1; i <= 1; i++) {
            if (i == 0) {
                continue;
            }

            if (is_valid_node(current_node->x + i, current_node->y)) {
                neighbor_node = (node_t*) malloc(sizeof(node_t));
                neighbor_node->x = current_node->x + i;
                neighbor_node->y = current_node->y;
                neighbor_node->f = 0;
                neighbor_node->g = 0;
                neighbor_node->h = calculate_h(neighbor_node);
                neighbor_node->parent = current_node;

                add_to_open_list(&open_list, neighbor_node);
            }

            if (is_valid_node(current_node->x, current_node->y + i)) {
                neighbor_node = (node_t*) malloc(sizeof(node_t));
                neighbor_node->x = current_node->x;
                neighbor_node->y = current_node->y + i;
                neighbor_node->f = 0;
                neighbor_node->g = 0;
                neighbor_node->h = calculate_h(neighbor_node);
                neighbor_node->parent = current_node;

                add_to_open_list(&open_list, neighbor_node);
            }
        }
    }
}

/* Add node to open list */
void add_to_open_list(open_list_t* open_list, node_t* node) {
    int i;

    /* Check if node is already in open list */
    for (i = 0; i < open_list->count; i++) {
        if (open_list->nodes[i]->x == node->x && open_list->nodes[i]->y == node->y) {
            free(node);
            return;
        }
    }

    /* Add node to open list */
    open_list->nodes[open_list->count++] = node;
    node->f = node->g + node->h;
}

/* Add node to closed list */
void add_to_closed_list(closed_list_t* closed_list, node_t* node) {
    /* Check if node is already in closed list */
    for (int i = 0; i < closed_list->count; i++) {
        if (closed_list->nodes[i]->x == node->x && closed_list->nodes[i]->y == node->y) {
            return;
        }
    }

    /* Add node to closed list */
    closed_list->nodes[closed_list->count++] = node;
}

/* Remove node from open list */
void remove_from_open_list(open_list_t* open_list, node_t* node) {
    int i, j;

    /* Find node in open list */
    for (i = 0; i < open_list->count; i++) {
        if (open_list->nodes[i]->x == node->x && open_list->nodes[i]->y == node->y) {
            /* Remove node from open list */
            free(open_list->nodes[i]);
            open_list->count--;

            /* Shift remaining nodes to fill gap */
            for (j = i; j < open_list->count; j++) {
                open_list->nodes[j] = open_list->nodes[j+1];
            }
        }
    }
}

/* Get node with lowest f value from open list */
node_t* get_next_node(open_list_t* open_list) {
    int i, lowest_f = 0x7FFFFFFF;
    node_t* lowest_node = NULL;

    /* Find node with lowest f value */
    for (i = 0; i < open_list->count; i++) {
        if (open_list->nodes[i]->f < lowest_f) {
            lowest_f = open_list->nodes[i]->f;
            lowest_node = open_list->nodes[i];
        }
    }

    /* Remove lowest node from open list */
    remove_from_open_list(open_list, lowest_node);

    return lowest_node;
}

/* Check if node is within map boundaries */
int is_valid_node(int x, int y) {
    return x >= 0 && x < MAX_ROWS && y >= 0 && y < MAX_COLS;
}

/* Check if node is walkable */
int is_walkable(int x, int y) {
    return map[x][y] == 0;
}

/* Print map */
void print_map() {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

/* Print path */
void print_path(node_t* node) {
    if (node->parent != NULL) {
        print_path(node->parent);
    }

    printf("(%d, %d)\n", node->x, node->y);
}