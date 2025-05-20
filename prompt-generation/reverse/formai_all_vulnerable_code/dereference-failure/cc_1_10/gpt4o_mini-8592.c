//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node node;
    int g_cost; // Cost from start to node
    int h_cost; // Heuristic cost to end
    int f_cost; // g + h
    Node* parent;
} PathNode;

PathNode* open_set[WIDTH * HEIGHT];
int open_set_count = 0;
bool closed_set[WIDTH][HEIGHT] = { false };

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void add_to_open_set(PathNode* newNode) {
    open_set[open_set_count++] = newNode;
}

bool node_in_open_set(Node node) {
    for (int i = 0; i < open_set_count; i++) {
        if (open_set[i]->node.x == node.x && open_set[i]->node.y == node.y) {
            return true;
        }
    }
    return false;
}

void remove_from_open_set(Node node) {
    for (int i = 0; i < open_set_count; i++) {
        if (open_set[i]->node.x == node.x && open_set[i]->node.y == node.y) {
            free(open_set[i]);
            open_set[i] = open_set[--open_set_count];
            return;
        }
    }
}

PathNode* find_path(Node start, Node end) {
    PathNode* start_node = malloc(sizeof(PathNode));
    start_node->node = start;
    start_node->g_cost = 0;
    start_node->h_cost = heuristic(start, end);
    start_node->f_cost = start_node->g_cost + start_node->h_cost;
    start_node->parent = NULL;

    add_to_open_set(start_node);

    while (open_set_count > 0) {
        PathNode* current_node = open_set[0];

        // Find node with lowest f_cost
        for (int i = 1; i < open_set_count; i++) {
            if (open_set[i]->f_cost < current_node->f_cost) {
                current_node = open_set[i];
            }
        }

        if (current_node->node.x == end.x && current_node->node.y == end.y) {
            return current_node; // Path found
        }

        remove_from_open_set(current_node->node);
        closed_set[current_node->node.x][current_node->node.y] = true;

        // Generate neighbors (up, down, left, right)
        Node neighbors[4] = {
            {current_node->node.x, current_node->node.y - 1}, // Up
            {current_node->node.x, current_node->node.y + 1}, // Down
            {current_node->node.x - 1, current_node->node.y}, // Left
            {current_node->node.x + 1, current_node->node.y}  // Right
        };

        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];
            if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT) {
                continue; // Out of bounds
            }
            if (closed_set[neighbor.x][neighbor.y]) {
                continue; // Already evaluated
            }

            // Calculate costs
            int new_g_cost = current_node->g_cost + 1; // Assuming uniform cost
            PathNode* neighbor_node = malloc(sizeof(PathNode));
            neighbor_node->node = neighbor;
            neighbor_node->g_cost = new_g_cost;
            neighbor_node->h_cost = heuristic(neighbor, end);
            neighbor_node->f_cost = neighbor_node->g_cost + neighbor_node->h_cost;
            neighbor_node->parent = current_node;

            if (node_in_open_set(neighbor) && new_g_cost >= current_node->g_cost) {
                free(neighbor_node); // We already have a better route
                continue;
            }

            add_to_open_set(neighbor_node);
        }
    }
    return NULL; // No path found
}

void print_path(PathNode* node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("-> [%d, %d] ", node->node.x, node->node.y);
}

int main() {
    Node start = {0, 0};
    Node end = {7, 7};

    printf("Initiating A* Pathfinding through the neon-lit streets of the cyber city...\n");
    PathNode* path = find_path(start, end);

    if (path) {
        printf("Path found: ");
        print_path(path);
        printf(" (End)\n");
        free(path);
    } else {
        printf("No path found through the neon maze!\n");
    }
    return 0;
}