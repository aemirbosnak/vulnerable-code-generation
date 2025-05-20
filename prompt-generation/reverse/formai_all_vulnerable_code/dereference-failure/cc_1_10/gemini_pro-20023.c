//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *pos;
    int g, h, f;
    struct Node *parent;
} Node;

typedef struct {
    Node **nodes;
    int width, height;
} Grid;

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width * height; i++) {
        grid->nodes[i] = malloc(sizeof(Node));
        grid->nodes[i]->pos = malloc(sizeof(Point));
    }
    return grid;
}

void free_grid(Grid *grid) {
    for (int i = 0; i < grid->width * grid->height; i++) {
        free(grid->nodes[i]->pos);
        free(grid->nodes[i]);
    }
    free(grid->nodes);
    free(grid);
}

void set_obstacle(Grid *grid, int x, int y) {
    grid->nodes[y * grid->width + x]->g = -1;
}

int heuristic(Point *a, Point *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

Node *find_lowest_f(Node **nodes, int size) {
    Node *lowest = NULL;
    for (int i = 0; i < size; i++) {
        if (nodes[i] && (!lowest || nodes[i]->f < lowest->f)) {
            lowest = nodes[i];
        }
    }
    return lowest;
}

Node **find_neighbors(Grid *grid, Node *node) {
    Node **neighbors = malloc(sizeof(Node *) * 8);
    int index = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
                continue;
            }
            int nx = node->pos->x + x;
            int ny = node->pos->y + y;
            if (nx >= 0 && nx < grid->width && ny >= 0 && ny < grid->height && grid->nodes[ny * grid->width + nx]->g != -1) {
                neighbors[index++] = grid->nodes[ny * grid->width + nx];
            }
        }
    }
    return neighbors;
}

void free_neighbors(Node **neighbors, int size) {
    free(neighbors);
}

Node *a_star(Grid *grid, Point *start, Point *end) {
    Node *start_node = grid->nodes[start->y * grid->width + start->x];
    Node *end_node = grid->nodes[end->y * grid->width + end->x];
    start_node->g = 0;
    start_node->h = heuristic(start, end);
    start_node->f = start_node->g + start_node->h;

    Node **open_set = malloc(sizeof(Node *) * grid->width * grid->height);
    int open_set_size = 1;
    open_set[0] = start_node;

    while (open_set_size > 0) {
        Node *current = find_lowest_f(open_set, open_set_size);
        if (current == end_node) {
            return current;
        }

        open_set_size--;
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current) {
                open_set[i] = open_set[open_set_size];
                break;
            }
        }

        Node **neighbors = find_neighbors(grid, current);
        int num_neighbors = 0;
        while (neighbors[num_neighbors]) {
            num_neighbors++;
        }

        for (int i = 0; i < num_neighbors; i++) {
            Node *neighbor = neighbors[i];
            int tentative_g = current->g + 1;

            if (tentative_g < neighbor->g || neighbor->g == -1) {
                neighbor->parent = current;
                neighbor->g = tentative_g;
                neighbor->h = heuristic(neighbor->pos, end);
                neighbor->f = neighbor->g + neighbor->h;
                if (!neighbor->g) {
                    open_set[open_set_size++] = neighbor;
                }
            }
        }
        free_neighbors(neighbors, num_neighbors);
    }

    free(open_set);
    return NULL;
}

void print_path(Node *node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d, %d)\n", node->pos->x, node->pos->y);
}

int main() {
    Grid *grid = create_grid(10, 10);

    Point start = {0, 0};
    Point end = {9, 9};

    set_obstacle(grid, 4, 4);
    set_obstacle(grid, 5, 4);
    set_obstacle(grid, 4, 5);
    set_obstacle(grid, 5, 5);

    Node *path = a_star(grid, &start, &end);

    if (path) {
        printf("Path found:\n");
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    free_grid(grid);
    return 0;
}