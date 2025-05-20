//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    int g;  // Cost from the start point
    int h;  // Heuristic cost to the end point
    int f;  // Total cost (g + h)
    struct Node *parent;
} Node;

typedef struct {
    Node **nodes;
    int width;
    int height;
} Grid;

Node *create_node(Point point, Node *parent, int g, int h) {
    Node *node = malloc(sizeof(Node));
    node->point = point;
    node->parent = parent;
    node->g = g;
    node->h = h;
    node->f = node->g + node->h;
    return node;
}

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = malloc(sizeof(Node *) * grid->width * grid->height);
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            grid->nodes[y * grid->width + x] = create_node((Point) {x, y}, NULL, INT_MAX, 0);
        }
    }
    return grid;
}

void set_heuristic(Grid *grid, Point end) {
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            Point point = {x, y};
            grid->nodes[y * grid->width + x]->h = abs(point.x - end.x) + abs(point.y - end.y);
        }
    }
}

void add_neighbors(Grid *grid, Node *node) {
    Point point = node->point;
    int width = grid->width;
    int height = grid->height;

    if (point.x > 0) {
        grid->nodes[point.y * width + point.x - 1]->parent = node;
    }
    if (point.x < width - 1) {
        grid->nodes[point.y * width + point.x + 1]->parent = node;
    }
    if (point.y > 0) {
        grid->nodes[(point.y - 1) * width + point.x]->parent = node;
    }
    if (point.y < height - 1) {
        grid->nodes[(point.y + 1) * width + point.x]->parent = node;
    }
}

Node *get_lowest_f_node(Grid *grid) {
    Node *lowest_f_node = NULL;
    int lowest_f = INT_MAX;

    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            Node *node = grid->nodes[y * grid->width + x];
            if (node->f < lowest_f) {
                lowest_f_node = node;
                lowest_f = node->f;
            }
        }
    }

    return lowest_f_node;
}

bool is_in_grid(Grid *grid, Point point) {
    return point.x >= 0 && point.x < grid->width && point.y >= 0 && point.y < grid->height;
}

bool is_walkable(Grid *grid, Point point) {
    return grid->nodes[point.y * grid->width + point.x]->g != INT_MAX;
}

bool is_end(Grid *grid, Node *node, Point end) {
    return node->point.x == end.x && node->point.y == end.y;
}

void calculate_path(Grid *grid, Point start, Point end) {
    Node *start_node = grid->nodes[start.y * grid->width + start.x];
    Node *end_node = grid->nodes[end.y * grid->width + end.x];

    start_node->g = 0;
    start_node->h = abs(start.x - end.x) + abs(start.y - end.y);
    start_node->f = start_node->g + start_node->h;

    while (!is_end(grid, start_node, end)) {
        add_neighbors(grid, start_node);

        start_node = get_lowest_f_node(grid);

        for (int y = 0; y < grid->height; y++) {
            for (int x = 0; x < grid->width; x++) {
                Node *node = grid->nodes[y * grid->width + x];
                if (node->parent == start_node) {
                    Point point = node->point;
                    int g = start_node->g + 1;
                    int h = abs(point.x - end.x) + abs(point.y - end.y);
                    int f = g + h;

                    if (f < node->f) {
                        node->g = g;
                        node->h = h;
                        node->f = f;
                        node->parent = start_node;
                    }
                }
            }
        }
    }

    Node *node = start_node;
    while (node != NULL) {
        printf("(%d, %d)\n", node->point.x, node->point.y);
        node = node->parent;
    }
}

int main() {
    Grid *grid = create_grid(10, 10);
    Point start = {0, 0};
    Point end = {9, 9};

    set_heuristic(grid, end);
    calculate_path(grid, start, end);

    return 0;
}