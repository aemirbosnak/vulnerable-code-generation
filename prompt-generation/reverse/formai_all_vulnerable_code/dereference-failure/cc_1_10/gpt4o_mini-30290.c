//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define DIAGONAL_COST 14
#define STRAIGHT_COST 10

typedef struct Node {
    int x, y;
    int g_cost; // Cost from start to this node
    int h_cost; // Heuristic cost to end node
    int f_cost; // Total cost
    struct Node* parent;
} Node;

Node* open_list[WIDTH * HEIGHT];
int open_list_size = 0;

bool grid[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 1, 0}
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void add_to_open_list(Node* node) {
    open_list[open_list_size++] = node;
}

Node* get_best_node() {
    Node* best_node = open_list[0];
    for (int i = 1; i < open_list_size; i++) {
        if (open_list[i]->f_cost < best_node->f_cost) {
            best_node = open_list[i];
        }
    }
    return best_node;
}

void remove_from_open_list(Node* node) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i] == node) {
            open_list[i] = open_list[--open_list_size];
            break;
        }
    }
}

bool is_in_open_list(Node* node) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i]->x == node->x && open_list[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

bool is_walkable(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return false;
    }
    return grid[x][y] == 0;
}

void reconstruct_path(Node* node) {
    if (node == NULL) return;
    reconstruct_path(node->parent);
    printf("-> (%d, %d) ", node->x, node->y);
}

void a_star(int start_x, int start_y, int target_x, int target_y) {
    Node* start_node = (Node*)malloc(sizeof(Node));
    start_node->x = start_x;
    start_node->y = start_y;
    start_node->g_cost = 0;
    start_node->h_cost = heuristic(start_x, start_y, target_x, target_y);
    start_node->f_cost = start_node->h_cost;
    start_node->parent = NULL;

    add_to_open_list(start_node);

    while (open_list_size > 0) {
        Node* current_node = get_best_node();
        remove_from_open_list(current_node);

        if (current_node->x == target_x && current_node->y == target_y) {
            printf("Path found: ");
            reconstruct_path(current_node);
            printf("\n");
            free(current_node);
            return;
        }

        int directions[8][2] = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        for (int i = 0; i < 8; i++) {
            int neighbor_x = current_node->x + directions[i][0];
            int neighbor_y = current_node->y + directions[i][1];

            if (!is_walkable(neighbor_x, neighbor_y)) continue;

            int g_cost = current_node->g_cost + (i < 4 ? STRAIGHT_COST : DIAGONAL_COST);
            Node* neighbor_node = (Node*)malloc(sizeof(Node));
            neighbor_node->x = neighbor_x;
            neighbor_node->y = neighbor_y;
            neighbor_node->g_cost = g_cost;
            neighbor_node->h_cost = heuristic(neighbor_x, neighbor_y, target_x, target_y);
            neighbor_node->f_cost = g_cost + neighbor_node->h_cost;
            neighbor_node->parent = current_node;

            if (!is_in_open_list(neighbor_node)) {
                add_to_open_list(neighbor_node);
            } else {
                free(neighbor_node);
            }
        }
    }

    printf("No path found.\n");
    free(start_node);
}

int main() {
    int start_x = 0, start_y = 0;
    int target_x = 9, target_y = 9;
    a_star(start_x, start_y, target_x, target_y);
    return 0;
}