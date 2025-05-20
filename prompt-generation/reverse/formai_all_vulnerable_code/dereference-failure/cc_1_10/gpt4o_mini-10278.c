//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define FREE_SPACE '.'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    float g_cost; // Cost from start to this node
    float h_cost; // Heuristic cost to the end node
    float f_cost; // Total cost
    struct Node* parent;
} Node;

Node* create_node(int x, int y, float g, float h, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->position.x = x;
    node->position.y = y;
    node->g_cost = g;
    node->h_cost = h;
    node->f_cost = g + h;
    node->parent = parent;
    return node;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool is_valid(int x, int y, char grid[HEIGHT][WIDTH]) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE);
}

void print_path(Node* node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d) ", node->position.x, node->position.y);
}

void free_nodes(Node** nodes, int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        {'.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '.', '#', '#', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.', '#', '.', 'E', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '.', '.', '.'},
        {'.', '.', '.', '.', '#', '.', '#', '#', '#', '#'},
        {'S', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '#', '.', '#', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.'},
        {'.', '#', '#', '#', '#', '#', '.', '#', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    Point start = {0, 5};  // Starting point 'S'
    Point end = {8, 2};    // Ending point 'E'
    
    Node* open_set[WIDTH * HEIGHT];
    int open_set_size = 0;
    Node* closed_set[WIDTH * HEIGHT];
    int closed_set_size = 0;

    open_set[open_set_size++] = create_node(start.x, start.y, 0.0, heuristic(start, end), NULL);

    while (open_set_size > 0) {
        int current_index = -1;
        float lowest_f_cost = INFINITY;

        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i]->f_cost < lowest_f_cost) {
                lowest_f_cost = open_set[i]->f_cost;
                current_index = i;
            }
        }

        Node* current_node = open_set[current_index];

        if (current_node->position.x == end.x && current_node->position.y == end.y) {
            printf("Path found: ");
            print_path(current_node);
            printf("\n");
            free_nodes(open_set, open_set_size);
            free_nodes(closed_set, closed_set_size);
            return 0;
        }

        // Move current node to closed set
        closed_set[closed_set_size++] = current_node;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue;  // Skip diagonal moves

                int new_x = current_node->position.x + dx;
                int new_y = current_node->position.y + dy;

                if (is_valid(new_x, new_y, grid)) {
                    bool in_closed_set = false;
                    for (int j = 0; j < closed_set_size; j++) {
                        if (closed_set[j]->position.x == new_x && closed_set[j]->position.y == new_y) {
                            in_closed_set = true;
                            break;
                        }
                    }
                    if (in_closed_set) continue;

                    float new_g_cost = current_node->g_cost + 1;
                    float new_h_cost = heuristic((Point){new_x, new_y}, end);
                    bool in_open_set = false;

                    for (int j = 0; j < open_set_size; j++) {
                        if (open_set[j]->position.x == new_x && open_set[j]->position.y == new_y) {
                            in_open_set = true;
                            if (new_g_cost < open_set[j]->g_cost) {
                                open_set[j]->g_cost = new_g_cost;
                                open_set[j]->f_cost = new_g_cost + new_h_cost;
                                open_set[j]->parent = current_node;
                            }
                            break;
                        }
                    }

                    if (!in_open_set) {
                        open_set[open_set_size++] = create_node(new_x, new_y, new_g_cost, new_h_cost, current_node);
                    }
                }
            }
        }

        // Remove the current node from the open set
        for (int i = current_index; i < open_set_size - 1; i++) {
            open_set[i] = open_set[i + 1];
        }
        open_set_size--;
    }

    printf("Path not found!\n");
    free_nodes(open_set, open_set_size);
    free_nodes(closed_set, closed_set_size);
    return 1;
}