//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INF 99999999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g, h, f;
    struct Node *parent;
} Node;

Node *create_node(Point point, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->point = point;
    node->g = INF;
    node->h = INF;
    node->f = INF;
    node->parent = parent;
    return node;
}

void destroy_node(Node *node) {
    free(node);
}

bool is_equal(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int get_distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int heuristic(Point p1, Point p2) {
    return get_distance(p1, p2);
}

Node *find_node(Point point, Node **nodes, int n) {
    for (int i = 0; i < n; i++) {
        if (is_equal(point, nodes[i]->point)) {
            return nodes[i];
        }
    }
    return NULL;
}

void update_node(Node *node, Node *parent, int g) {
    if (g < node->g) {
        node->g = g;
        node->parent = parent;
    }
}

Node **get_neighbors(Point point, int **grid, int width, int height) {
    Node **neighbors = malloc(sizeof(Node *) * 4);
    int i = 0;
    if (point.x > 0 && grid[point.y][point.x - 1] != -1) {
        neighbors[i++] = create_node((Point) {point.x - 1, point.y}, NULL);
    }
    if (point.y > 0 && grid[point.y - 1][point.x] != -1) {
        neighbors[i++] = create_node((Point) {point.x, point.y - 1}, NULL);
    }
    if (point.x < width - 1 && grid[point.y][point.x + 1] != -1) {
        neighbors[i++] = create_node((Point) {point.x + 1, point.y}, NULL);
    }
    if (point.y < height - 1 && grid[point.y + 1][point.x] != -1) {
        neighbors[i++] = create_node((Point) {point.x, point.y + 1}, NULL);
    }
    return neighbors;
}

void destroy_neighbors(Node **neighbors, int n) {
    for (int i = 0; i < n; i++) {
        destroy_node(neighbors[i]);
    }
    free(neighbors);
}

Node *a_star(int **grid, Point start, Point end, int width, int height) {
    Node *open_set[width * height];
    int open_set_size = 0;
    Node *closed_set[width * height];
    int closed_set_size = 0;

    Node *start_node = create_node(start, NULL);
    start_node->g = 0;
    start_node->h = heuristic(start, end);
    start_node->f = start_node->g + start_node->h;
    open_set[open_set_size++] = start_node;

    while (open_set_size > 0) {
        int min_f = INF;
        int min_index = -1;
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i]->f < min_f) {
                min_f = open_set[i]->f;
                min_index = i;
            }
        }

        Node *current_node = open_set[min_index];
        open_set[min_index] = open_set[open_set_size - 1];
        open_set_size--;

        if (is_equal(current_node->point, end)) {
            return current_node;
        }

        closed_set[closed_set_size++] = current_node;

        Node **neighbors = get_neighbors(current_node->point, grid, width, height);
        int n = sizeof(neighbors) / sizeof(neighbors[0]);
        for (int i = 0; i < n; i++) {
            Node *neighbor = neighbors[i];
            if (find_node(neighbor->point, closed_set, closed_set_size) != NULL) {
                continue;
            }
            int g = current_node->g + get_distance(current_node->point, neighbor->point);
            if (find_node(neighbor->point, open_set, open_set_size) == NULL) {
                neighbor->h = heuristic(neighbor->point, end);
                open_set[open_set_size++] = neighbor;
            } else {
                neighbor = find_node(neighbor->point, open_set, open_set_size);
            }
            update_node(neighbor, current_node, g);
        }
        destroy_neighbors(neighbors, n);
    }

    return NULL;
}

void print_path(Node *node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d)\n", node->point.x, node->point.y);
}

int main() {
    int grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, -1, 0, -1, 0},
        {0, 0, 0, 0, 0},
        {0, -1, 0, -1, 0},
        {0, 0, 0, 0, 0}
    };
    Point start = {0, 0};
    Point end = {4, 4};
    int width = 5;
    int height = 5;

    Node *path = a_star(grid, start, end, width, height);
    if (path == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path found:\n");
        print_path(path);
    }

    return 0;
}