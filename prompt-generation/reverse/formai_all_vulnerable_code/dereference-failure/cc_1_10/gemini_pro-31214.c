//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g, h, f;
    struct Node* parent;
} Node;

Node* open_set[GRID_WIDTH * GRID_HEIGHT];
Node* closed_set[GRID_WIDTH * GRID_HEIGHT];
Node* grid[GRID_WIDTH * GRID_HEIGHT];

int cost(Node* a, Node* b) {
    return (a->point.x - b->point.x) * (a->point.x - b->point.x) + (a->point.y - b->point.y) * (a->point.y - b->point.y);
}

int heuristic(Node* a, Node* b) {
    return (b->point.x - a->point.x) * (b->point.x - a->point.x) + (b->point.y - a->point.y) * (b->point.y - a->point.y);
}

Node* find_lowest_f() {
    Node* lowest = NULL;
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        if (open_set[i] != NULL && (lowest == NULL || open_set[i]->f < lowest->f)) {
            lowest = open_set[i];
        }
    }
    return lowest;
}

void remove_from_open_set(Node* node) {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        if (open_set[i] == node) {
            open_set[i] = NULL;
            break;
        }
    }
}

void add_to_closed_set(Node* node) {
    closed_set[node->point.x + node->point.y * GRID_WIDTH] = node;
}

bool is_in_closed_set(Node* node) {
    return closed_set[node->point.x + node->point.y * GRID_WIDTH] != NULL;
}

bool is_in_open_set(Node* node) {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        if (open_set[i] == node) {
            return true;
        }
    }
    return false;
}

void add_to_open_set(Node* node) {
    if (!is_in_open_set(node)) {
        int i = 0;
        while (i < GRID_WIDTH * GRID_HEIGHT && open_set[i] != NULL) {
            i++;
        }
        open_set[i] = node;
    }
}

Node* create_node(Point point) {
    Node* node = malloc(sizeof(Node));
    node->point = point;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = NULL;
    return node;
}

Node* find_path(Point start, Point end) {
    Node* start_node = create_node(start);
    Node* end_node = create_node(end);
    add_to_open_set(start_node);

    while (open_set[0] != NULL) {
        Node* current_node = find_lowest_f();
        remove_from_open_set(current_node);
        add_to_closed_set(current_node);
        if (current_node->point.x == end_node->point.x && current_node->point.y == end_node->point.y) {
            return current_node;
        }
        for (int i = 0; i < 4; i++) {
            int dx = i % 2 == 0 ? 1 : -1;
            int dy = i % 2 == 1 ? 1 : -1;
            Point neighbour_point = {current_node->point.x + dx, current_node->point.y + dy};
            if (neighbour_point.x >= 0 && neighbour_point.x < GRID_WIDTH &&
                neighbour_point.y >= 0 && neighbour_point.y < GRID_HEIGHT) {
                Node* neighbour = grid[neighbour_point.x + neighbour_point.y * GRID_WIDTH];
                if (neighbour != NULL && !is_in_closed_set(neighbour)) {
                    int new_g = current_node->g + 1;
                    if (!is_in_open_set(neighbour) || new_g < neighbour->g) {
                        neighbour->g = new_g;
                        neighbour->h = heuristic(neighbour, end_node);
                        neighbour->f = neighbour->g + neighbour->h;
                        neighbour->parent = current_node;
                        add_to_open_set(neighbour);
                    }
                }
            }
        }
    }
    return NULL;
}

int main() {
    // Create the grid
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        grid[i] = create_node((Point){i % GRID_WIDTH, i / GRID_WIDTH});
    }

    // Set the start and end points
    Point start = {0, 0};
    Point end = {GRID_WIDTH - 1, GRID_HEIGHT - 1};

    // Find the path
    Node* path = find_path(start, end);

    // Print the path
    Node* current_node = path;
    while (current_node != NULL) {
        printf("(%d, %d)\n", current_node->point.x, current_node->point.y);
        current_node = current_node->parent;
    }

    return 0;
}