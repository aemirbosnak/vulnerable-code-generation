//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE -1
#define EMPTY 0
#define START 1
#define GOAL 2

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node position;
    int g_cost;
    int h_cost;
    int f_cost;
    Node* parent;
} AStarNode;

int grid[GRID_SIZE][GRID_SIZE] = {
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY },
    { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY },
    { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Node start = {0, 0};
Node goal = {9, 9};

int calculate_h(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool is_node_valid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] != OBSTACLE);
}

void trace_path(AStarNode* node) {
    if (node == NULL) return;
    trace_path(node->parent);
    printf("Step to: (%d, %d)\n", node->position.x, node->position.y);
}

void a_star_search() {
    AStarNode* open_set[GRID_SIZE * GRID_SIZE] = { NULL };
    int open_set_size = 0;
    AStarNode* closed_set[GRID_SIZE * GRID_SIZE] = { NULL };
    int closed_set_size = 0;

    AStarNode* start_node = (AStarNode*)malloc(sizeof(AStarNode));
    start_node->position = start;
    start_node->g_cost = 0;
    start_node->h_cost = calculate_h(start, goal);
    start_node->f_cost = start_node->g_cost + start_node->h_cost;
    start_node->parent = NULL;

    open_set[open_set_size++] = start_node;

    while (open_set_size > 0) {
        // Find node with the lowest f_cost
        int lowest_index = 0;
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f_cost < open_set[lowest_index]->f_cost) {
                lowest_index = i;
            }
        }

        AStarNode* current_node = open_set[lowest_index];

        // Check for goal node
        if (current_node->position.x == goal.x && current_node->position.y == goal.y) {
            printf("Path found:\n");
            trace_path(current_node);
            break;
        }

        // Remove current node from open set and add to closed set
        open_set[lowest_index] = open_set[--open_set_size];
        closed_set[closed_set_size++] = current_node;

        Node neighbors[4] = {
            { current_node->position.x + 1, current_node->position.y },
            { current_node->position.x - 1, current_node->position.y },
            { current_node->position.x, current_node->position.y + 1 },
            { current_node->position.x, current_node->position.y - 1 }
        };

        for (int i = 0; i < 4; i++) {
            Node neighbor_pos = neighbors[i];

            if (!is_node_valid(neighbor_pos.x, neighbor_pos.y)) continue;

            bool in_closed_set = false;
            for (int j = 0; j < closed_set_size; j++) {
                if (closed_set[j]->position.x == neighbor_pos.x && closed_set[j]->position.y == neighbor_pos.y) {
                    in_closed_set = true;
                    break;
                }
            }
            if (in_closed_set) continue;

            int g_cost = current_node->g_cost + 1; // Assuming cost is 1 for each step
            int h_cost = calculate_h(neighbor_pos, goal);
            int f_cost = g_cost + h_cost;

            AStarNode* neighbor_node = NULL;

            for (int j = 0; j < open_set_size; j++) {
                if (open_set[j]->position.x == neighbor_pos.x && open_set[j]->position.y == neighbor_pos.y) {
                    neighbor_node = open_set[j];
                    break;
                }
            }

            if (neighbor_node == NULL) {
                // Not in open set, create new node
                neighbor_node = (AStarNode*)malloc(sizeof(AStarNode));
                neighbor_node->position = neighbor_pos;
                neighbor_node->g_cost = g_cost;
                neighbor_node->h_cost = h_cost;
                neighbor_node->f_cost = f_cost;
                neighbor_node->parent = current_node;

                open_set[open_set_size++] = neighbor_node;
            } else if (g_cost < neighbor_node->g_cost) {
                // Update costs and parent
                neighbor_node->g_cost = g_cost;
                neighbor_node->f_cost = f_cost;
                neighbor_node->parent = current_node;
            }
        }
    }

    // Clear the memory
    for (int i = 0; i < open_set_size; i++) {
        free(open_set[i]);
    }
    for (int i = 0; i < closed_set_size; i++) {
        free(closed_set[i]);
    }
}

int main() {
    a_star_search();
    return 0;
}