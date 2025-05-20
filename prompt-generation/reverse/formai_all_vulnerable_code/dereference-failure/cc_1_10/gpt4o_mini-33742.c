//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define COST 10
#define DIAGONAL_COST 14

typedef struct Node {
    int x, y;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node* parent;
} Node;

Node* open_list[GRID_SIZE * GRID_SIZE];
Node* closed_list[GRID_SIZE * GRID_SIZE];
int open_list_size = 0;
int closed_list_size = 0;

int grid[GRID_SIZE][GRID_SIZE] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
};

int heuristics(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

Node* create_node(int x, int y, int g_cost, int h_cost, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->g_cost = g_cost;
    new_node->h_cost = h_cost;
    new_node->f_cost = g_cost + h_cost;
    new_node->parent = parent;
    return new_node;
}

bool is_in_list(Node** list, int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (list[i]->x == x && list[i]->y == y) {
            return true;
        }
    }
    return false;
}

void add_to_open_list(Node* node) {
    open_list[open_list_size++] = node;
}

Node* get_lowest_f_cost_node() {
    Node* lowest = open_list[0];
    for (int i = 1; i < open_list_size; i++) {
        if (open_list[i]->f_cost < lowest->f_cost) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

void remove_from_open_list(Node* node) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i] == node) {
            open_list[i] = open_list[--open_list_size];
            break;
        }
    }
}

void add_to_closed_list(Node* node) {
    closed_list[closed_list_size++] = node;
}

void reconstruct_path(Node* node) {
    printf("Path: ");
    while (node) {
        printf("(%d, %d) ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

void a_star_algorithm(int start_x, int start_y, int goal_x, int goal_y) {
    Node* start_node = create_node(start_x, start_y, 0, heuristics(start_x, start_y, goal_x, goal_y), NULL);
    add_to_open_list(start_node);

    while (open_list_size > 0) {
        Node* current_node = get_lowest_f_cost_node();

        if (current_node->x == goal_x && current_node->y == goal_y) {
            reconstruct_path(current_node);
            return;
        }

        remove_from_open_list(current_node);
        add_to_closed_list(current_node);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the current node

                int new_x = current_node->x + dx;
                int new_y = current_node->y + dy;

                if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) continue; // Out of bounds
                if (grid[new_y][new_x] == 1) continue; // Obstacle
                if (is_in_list(closed_list, closed_list_size, new_x, new_y)) continue; // Already closed

                int g_cost = current_node->g_cost + ((dx != 0 && dy != 0) ? DIAGONAL_COST : COST);
                Node* neighbor_node = create_node(new_x, new_y, g_cost, heuristics(new_x, new_y, goal_x, goal_y), current_node);

                if (is_in_list(open_list, open_list_size, new_x, new_y)) {
                    bool better_path = false;
                    for (int i = 0; i < open_list_size; i++) {
                        if (open_list[i]->x == new_x && open_list[i]->y == new_y && open_list[i]->g_cost > g_cost) {
                            better_path = true;
                            break;
                        }
                    }

                    if (better_path) {
                        remove_from_open_list(neighbor_node);
                        add_to_open_list(neighbor_node);
                    }
                } else {
                    add_to_open_list(neighbor_node);
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int start_x = 0, start_y = 0;
    int goal_x = 9, goal_y = 9;

    a_star_algorithm(start_x, start_y, goal_x, goal_y);

    // Free memory
    for (int i = 0; i < open_list_size; i++) {
        free(open_list[i]);
    }
    for (int i = 0; i < closed_list_size; i++) {
        free(closed_list[i]);
    }

    return 0;
}