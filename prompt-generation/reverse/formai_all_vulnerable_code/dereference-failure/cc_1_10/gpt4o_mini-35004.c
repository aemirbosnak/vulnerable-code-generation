//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE -1
#define EMPTY 0
#define PATH 1

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *nodes;
    int count;
    int capacity;
} NodeList;

typedef struct {
    Node node;
    int g_cost; // Cost from start to current node
    int h_cost; // Estimated cost from current node to goal
    int f_cost; // Total cost
} AStarNode;

NodeList* create_node_list(int capacity) {
    NodeList* list = malloc(sizeof(NodeList));
    list->nodes = malloc(sizeof(Node) * capacity);
    list->count = 0;
    list->capacity = capacity;
    return list;
}

void add_node(NodeList* list, Node node) {
    if (list->count < list->capacity) {
        list->nodes[list->count++] = node;
    }
}

bool in_list(NodeList* list, Node node) {
    for (int i = 0; i < list->count; i++) {
        if (list->nodes[i].x == node.x && list->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void print_grid(int grid[HEIGHT][WIDTH], Node path[], int path_length) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool is_path = false;
            for (int p = 0; p < path_length; p++) {
                if (path[p].x == x && path[p].y == y) {
                    is_path = true;
                    break;
                }
            }
            if (is_path) {
                printf(" * ");
            } else if (grid[y][x] == OBSTACLE) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void a_star(int grid[HEIGHT][WIDTH], Node start, Node goal) {
    NodeList *open_set = create_node_list(WIDTH * HEIGHT);
    NodeList *closed_set = create_node_list(WIDTH * HEIGHT);
    AStarNode *nodes = malloc(sizeof(AStarNode) * WIDTH * HEIGHT);

    add_node(open_set, start);
    int path_length = 0;
    Node path[WIDTH * HEIGHT];

    while (open_set->count > 0) {
        Node current = open_set->nodes[0];
        AStarNode current_node = { .node = current, .g_cost = 0, .h_cost = heuristic(current, goal), .f_cost = 0 };

        // Calculate costs for the current node
        for (int i = 0; i < open_set->count; i++) {
            if (open_set->nodes[i].x == current.x && open_set->nodes[i].y == current.y) {
                current_node.g_cost = current_node.g_cost;
                current_node.f_cost = current_node.g_cost + current_node.h_cost;
                break;
            }
        }

        // Check if we reached the goal
        if (current.x == goal.x && current.y == goal.y) {
            // Reconstruct path (here we just save the last node)
            path[path_length++] = current;
            break;
        }

        // Move current node to closed set
        add_node(closed_set, current);
        
        Node neighbors[4] = {
            { current.x + 1, current.y },
            { current.x - 1, current.y },
            { current.x, current.y + 1 },
            { current.x, current.y - 1 }
        };

        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];
            if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT) continue; // Out of bounds
            if (grid[neighbor.y][neighbor.x] == OBSTACLE) continue; // Is an obstacle
            if (in_list(closed_set, neighbor)) continue; // Already evaluated

            int tentative_g_cost = current_node.g_cost + 1; // Assume cost between neighbors is 1

            if (!in_list(open_set, neighbor) || tentative_g_cost < current_node.g_cost) {
                nodes[neighbor.y * WIDTH + neighbor.x] = (AStarNode){ .node = neighbor, .g_cost = tentative_g_cost, .h_cost = heuristic(neighbor, goal) };
                // Add neighbor to open set if not already present
                if (!in_list(open_set, neighbor)) {
                    add_node(open_set, neighbor);
                }
            }
        }
    }

    print_grid(grid, path, path_length);
    free(open_set->nodes);
    free(open_set);
    free(closed_set->nodes);
    free(closed_set);
    free(nodes);
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY },
        { OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, OBSTACLE },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY },
        { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE },
        { EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
    };

    Node start = { 0, 0 };
    Node goal = { 9, 9 };

    a_star(grid, start, goal);

    return 0;
}